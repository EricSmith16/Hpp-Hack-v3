#include "BunnyHop.h"

namespace Functions
{
	namespace Misc
	{
		bool BHop::BunnyHopActive, BHop::inWaterBHop, BHop::StandUpActive;

		float BHop::Distance ( float frametime )
		{
			if ( g_Vars.BHop.ScrollEmulation )
			{
				return abs ( Info::g_Local.Height / Engine::g_pPlayerMove->flFallVelocity / 0.01f * 2 );
			}
			else
			{
				if ( g_Vars.BHop.NoSlowDown )
				{
					if ( Info::g_Local.GroundAngle > 0 && Info::g_Local.GroundAngle <= 45 )
					{
						return abs ( Info::g_Local.Height / Engine::g_pPlayerMove->flFallVelocity / frametime * 2 );
					}
					else
					{
						return abs ( Info::g_Local.Height / frametime * 0.01f );
					}
				}
				else
				{
					return abs ( Info::g_Local.Height / Engine::g_pPlayerMove->flFallVelocity / frametime * 2 );
				}
			}
		}

		void BHop::BunnyHop ( float frametime, usercmd_s *cmd )
		{
			static uint8 inAirBHopCount;

			static bool State;

			if ( inWaterBHop )
			{
				cmd->buttons |= IN_JUMP;

				return;
			}

			if ( State )
			{
				State = false;

				return;
			}

			if ( Engine::g_pPlayerMove->waterlevel >= 2 )
			{
				cmd->buttons |= IN_JUMP;

				inWaterBHop = true;

				return;
			}

			if ( g_Vars.BHop.OnLadder && Engine::g_pPlayerMove->movetype == 5 && Engine::g_pPlayerMove->flFallVelocity >= 0 )
			{
				cmd->buttons |= IN_JUMP;

				return;
			}

			if ( g_Vars.BHop.NoSlowDown )
			{
				static uint8 GroundFrame;

				if ( !State && ( Engine::g_pPlayerMove->flags & FL_ONGROUND ||
					( Distance ( frametime ) >= 5 && Distance ( frametime ) <= 18 ) ) )
				{
					if ( Engine::g_pPlayerMove->velocity.Length2D ( ) < Engine::g_pPlayerMove->maxspeed * 1.2f )
					{
						cmd->buttons |= IN_JUMP;

						State = true;

						return;
					}
					else
					{
						if ( Engine::g_pPlayerMove->flags & FL_ONGROUND )
						{
							if ( GroundFrame < 2 )
							{
								++GroundFrame;

								return;
							}
							else
							{
								cmd->buttons |= IN_JUMP;

								State = true;

								GroundFrame = 0;

								return;
							}
						}
					}
				}
			}
			else
			{
				if ( !State && ( Engine::g_pPlayerMove->flags & FL_ONGROUND || Distance ( frametime )
					<= Engine::g_Engine.pfnRandomFloat ( g_Vars.BHop.Distance[0], g_Vars.BHop.Distance[1] ) ) )
				{
					g_Vars.BHop.ScrollEmulation ?
						mouse_event ( MOUSEEVENTF_WHEEL, 0, 0, g_Vars.BHop.ScrollDirection > 1000 ? 120 : -120, 0 ) : cmd->buttons |= IN_JUMP;

					State = true;

					inAirBHopCount = 4;

					if ( !g_Vars.BHop.ScrollEmulation )
					{
						return;
					}
				}
			}

			if ( g_Vars.BHop.ScrollEmulation && inAirBHopCount > 0 )
			{
				if ( inAirBHopCount % 2 == 0 )
				{
					mouse_event ( MOUSEEVENTF_WHEEL, 0, 0, g_Vars.BHop.ScrollDirection > 1000 ? 120 : -120, 0 );
				}

				--inAirBHopCount;
			}
		}

		void BHop::StandUp ( usercmd_s *cmd )
		{
			if ( Engine::g_pPlayerMove->flFallVelocity >= g_Vars.BHop.StandUpFallVelocity && !Info::g_Local.FallDamage &&
				Info::g_Local.GroundAngle < 28 && Engine::g_pPlayerMove->movetype != 5 )
			{
				cmd->buttons |= IN_DUCK;
			}
		}

		void _fastcall BHop::CL_CreateMove ( float frametime, usercmd_s *cmd )
		{
			if ( BunnyHopActive )
			{
				BunnyHop ( frametime, cmd );

				if ( g_Vars.BHop.StandUpAuto || StandUpActive )
				{
					StandUp ( cmd );
				}
			}
			else
			{
				inWaterBHop = false;
			}
		}

		BHop g_BHop;
	}
}