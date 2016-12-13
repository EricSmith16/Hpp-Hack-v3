#include "JumpBug.h"

namespace Functions
{
	namespace Misc
	{
		int JBug::State;

		bool JBug::JumpBugActive, JBug::JumpBugAuto, JBug::JumpBugPercent;

		float JBug::CurrentFrameZDist ( float frametime )
		{
			return abs ( ( Engine::g_pPlayerMove->flFallVelocity + 800 * frametime ) * frametime );
		}

		void JBug::Auto ( float frametime )
		{
			if ( ( g_Vars.jumpbug.auto_enable && Information::g_Local.FallDamage >= g_Vars.jumpbug.auto_damage ) &&
				( Information::g_Local.Height - ( Engine::g_pPlayerMove->flFallVelocity * frametime / 1 * 15 ) <= 0 ) )
			{
				JumpBugAuto = true;
			}
			else
			{
				JumpBugAuto = false;
			}
		}

		void JBug::AutoPercentage ( )
		{
			if ( JumpBugAuto )
			{
				if ( g_Vars.jumpbug.auto_percentage >= Engine::g_Engine.pfnRandomLong ( 0, 100 ) )
				{
					JumpBugPercent = true;
				}
				else
				{
					JumpBugPercent = false;
				}
			}
		}

		void JBug::JumpBug ( float frametime, usercmd_s *cmd )
		{
			static float NeedOffset;

			static int Count = 16;
			static int StateJump = 1;

			if ( Information::g_Local.GroundAngle == 45 )
			{
				NeedOffset = 20;
			}
			else if ( Information::g_Local.GroundAngle < 45 )
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
				if ( abs ( Information::g_Local.Height - CurrentFrameZDist ( frametime ) * 1.5f ) <= 20 && CurrentFrameZDist ( frametime ) > 0 )
				{
					float NeedSpeed = abs ( Information::g_Local.Height - NeedOffset );
					float Scale = abs ( NeedSpeed / CurrentFrameZDist ( frametime ) );

					if ( g_Vars.jumpbug.slowmotion )
					{
						g_Speed.AdjustSpeed ( Scale );
					}

					State = 1;
				}

				break;

			case 1:
				cmd->buttons &= ~IN_DUCK;

				if ( ( JumpBugAuto && JumpBugPercent ) || JumpBugActive )
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
			bool CurveAngle = false;

			if ( g_Vars.jumpbug.slowdown && Information::g_Local.GroundAngle > 0 )
			{
				if ( Engine::g_pPlayerMove->velocity.Length2D ( ) > 1 && Information::g_Local.Height <= g_Vars.jumpbug.slowdown_distance *
					4 + ( Engine::g_pPlayerMove->velocity.Length2D ( ) / Engine::g_pPlayerMove->flFallVelocity ) )
				{
					CurveAngle = true;
				}
			}

			if ( g_Vars.jumpbug.slowdown_distance && CurveAngle )
			{
				g_Util.SlowHorizontalVelocity ( 0, frametime, cmd );
			}
		}

		void _fastcall JBug::CL_CreateMove ( float frametime, usercmd_s *cmd )
		{
			if ( g_Vars.function.edgebug && ( g_EdgeBug.EdgeBugActive || g_Vars.edgebug.auto_enable ) &&
				Information::g_Local.EdgeDistance <= g_Vars.edgebug.distance && Information::g_Local.GroundAngle < 5 )
			{
				return;
			}

			Auto ( frametime );
			AutoPercentage ( );

			if ( ( JumpBugAuto || JumpBugActive ) && Engine::g_pPlayerMove->flFallVelocity > 0 && Information::g_Local.GroundAngle <= 45 )
			{
				if ( !Engine::g_pPlayerMove->waterlevel )
				{
					JumpBug ( frametime, cmd );
				}

				SlowDown ( frametime, cmd );
			}
			else
			{
				State = 0;
			}
		}

		JBug g_JumpBug;
	}
}