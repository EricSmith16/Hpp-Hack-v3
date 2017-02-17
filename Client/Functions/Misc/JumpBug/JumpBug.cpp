#include "JumpBug.h"

namespace Functions
{
	namespace Misc
	{
		uint8 JBug::State;

		bool JBug::JumpBugActive;

		float JBug::CurrentFrameZDist ( float frametime )
		{
			return abs ( ( Engine::g_pPlayerMove->flFallVelocity + 800 * frametime ) * frametime );
		}

		bool JBug::Auto ( float frametime )
		{
			return ( g_Vars.JumpBug.AutoEnable && Info::g_Local.FallDamage >= g_Vars.JumpBug.AutoDamage ) &&
				( Info::g_Local.Height - ( Engine::g_pPlayerMove->flFallVelocity * frametime * 15 ) <= 0 );
		}

		bool JBug::AutoPercentage ( float frametime )
		{
			return Auto ( frametime ) && g_Vars.JumpBug.AutoPercentage >= Engine::g_Engine.pfnRandomLong ( 0, 100 );
		}

		void JBug::JumpBug ( float frametime, usercmd_s *cmd )
		{
			static float NeedOffset;

			static uint8 Count = 16;
			static uint8 StateJump = 1;

			if ( Info::g_Local.GroundAngle == 45 )
			{
				NeedOffset = 20;
			}
			else if ( Info::g_Local.GroundAngle < 45 )
			{
				if ( Client::BuildInfo.Build > 4554 )
				{
					NeedOffset = 19;
				}
				else
				{
					NeedOffset = 18.2f;
				}
			}

			cmd->buttons |= IN_DUCK;
			cmd->buttons &= ~IN_JUMP;

			switch ( State )
			{
			case 0:
				if ( abs ( Info::g_Local.Height - CurrentFrameZDist ( frametime ) * 1.5f ) <= 20 && CurrentFrameZDist ( frametime ) > 0 )
				{
					float NeedSpeed = abs ( Info::g_Local.Height - NeedOffset );
					float Scale = abs ( NeedSpeed / CurrentFrameZDist ( frametime ) );

					if ( g_Vars.JumpBug.SlowMotion )
					{
						g_Speed.AdjustSpeed ( Scale );
					}

					State = 1;
				}

				break;

			case 1:
				cmd->buttons &= ~IN_DUCK;

				if ( ( Auto ( frametime ) && AutoPercentage ( frametime ) ) || JumpBugActive )
				{
					cmd->buttons |= IN_JUMP;

					if ( Count > 0 )
					{
						if ( StateJump == 1 )
						{
							--Count;

							StateJump = 2;

							return;
						}
						else if ( StateJump == 2 )
						{
							cmd->buttons |= IN_JUMP;

							StateJump = 1;

							return;
						}
					}
					else
					{
						Count = 16;
						StateJump = 1;
					}
				}

				State = 2;

				break;

			case 2:
				State = 0;

				break;
			}
		}

		void JBug::SlowDown ( float frametime, struct usercmd_s *cmd )
		{
			if ( g_Vars.JumpBug.SlowDown && ( Info::g_Local.GroundAngle > 0 && Info::g_Local.GroundAngle <= 45 ) )
			{
				if ( Engine::g_pPlayerMove->velocity.Length2D ( ) > 1 && Info::g_Local.Height <= 50 * 4 +
					( Engine::g_pPlayerMove->velocity.Length2D ( ) / Engine::g_pPlayerMove->flFallVelocity ) )
				{
					g_Util.SlowHorizontalVelocity ( 0, frametime, cmd );
				}
			}
		}

		void _fastcall JBug::CL_CreateMove ( float frametime, usercmd_s *cmd )
		{
			if ( g_Vars.Function.EdgeBug && ( g_EdgeBug.EdgeBugActive || g_Vars.EdgeBug.AutoEnable ) &&
				( Info::g_Local.EdgeDistance <= Engine::g_pPlayerMove->velocity.Length2D ( ) / 10 && !Info::g_Local.GroundAngle ) )
			{
				return;
			}

			if ( ( Auto ( frametime ) || JumpBugActive ) && Engine::g_pPlayerMove->flFallVelocity > 0 )
			{
				SlowDown ( frametime, cmd );

				if ( !Engine::g_pPlayerMove->waterlevel )
				{
					JumpBug ( frametime, cmd );
				}
			}
			else
			{
				State = 0;
			}
		}

		JBug g_JumpBug;
	}
}