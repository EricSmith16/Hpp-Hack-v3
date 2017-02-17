#include "GroundStrafe.h"

namespace Functions
{
	namespace Misc
	{
		bool GStrafe::GroundStrafeActive, GStrafe::StandUpActive;

		float GStrafe::Distance ( float frametime )
		{
			if ( g_Vars.GStrafe.ScrollEmulation )
			{
				return abs ( Info::g_Local.Height / Engine::g_pPlayerMove->flFallVelocity / 0.01f * 2 );
			}
			else
			{
				return abs ( Info::g_Local.Height / Engine::g_pPlayerMove->flFallVelocity / frametime * 2 );
			}
		}

		void GStrafe::GroundStrafe ( float frametime, usercmd_s *cmd )
		{
			static uint8 State, Count;

			if ( Count )
			{
				if ( State == 1 )
				{
					if ( g_Vars.GStrafe.SlowDownScale != 1 && Info::g_Local.GroundAngle <= 45 && Engine::g_pPlayerMove->flags & FL_ONGROUND )
					{
						g_Speed.AdjustSpeed ( g_Vars.GStrafe.SlowDownScale <= 0 ? 0.000001 : g_Vars.GStrafe.SlowDownScale );
					}

					--Count;

					State = 2;

					return;
				}
				else if ( State == 2 )
				{
					if ( g_Vars.GStrafe.FallRun && Info::g_Local.GroundAngle >= 28.5f && Info::g_Local.GroundAngle <= 45 )
					{
						mouse_event ( MOUSEEVENTF_WHEEL, 0, 0, g_Vars.GStrafe.ScrollDirection > 1000 ? 120 : -120, 0 );

						State = 1;

						return;
					}

					if ( g_Vars.GStrafe.SlowDownScale != 1 && Info::g_Local.GroundAngle <= 45 && Engine::g_pPlayerMove->flags & FL_ONGROUND )
					{
						g_Speed.AdjustSpeed ( g_Vars.GStrafe.SlowDownScale <= 0 ? 0.000001 : g_Vars.GStrafe.SlowDownScale );
					}

					g_Vars.GStrafe.ScrollEmulation ?
						mouse_event ( MOUSEEVENTF_WHEEL, 0, 0, g_Vars.GStrafe.ScrollDirection > 1000 ? 120 : -120, 0 ) : cmd->buttons |= IN_DUCK;

					State = 1;

					return;
				}
			}
			else
			{
				State = 0;
			}

			if ( Engine::g_pPlayerMove->movetype == 5 && Engine::g_pPlayerMove->waterlevel >= 2 )
			{
				return;
			}

			if ( g_Vars.GStrafe.FallRun && Info::g_Local.GroundAngle >= 28.5f && Info::g_Local.GroundAngle <= 45 )
			{
				if ( Engine::g_pPlayerMove->flFallVelocity > 0 )
				{
					cmd->buttons |= IN_DUCK;

					return;
				}
				else
				{
					Count = Engine::g_Engine.pfnRandomLong ( 2, 3 );
					State = 1;

					return;
				}
			}

			if ( !State && !Count && ( Engine::g_pPlayerMove->flags & FL_ONGROUND || Distance ( frametime ) <=
				Engine::g_Engine.pfnRandomFloat ( g_Vars.GStrafe.Distance[0], g_Vars.GStrafe.Distance[1] ) ) )
			{
				if ( g_Vars.GStrafe.SlowDownScale != 1 && Info::g_Local.GroundAngle <= 45 && Engine::g_pPlayerMove->flags & FL_ONGROUND )
				{
					g_Speed.AdjustSpeed ( g_Vars.GStrafe.SlowDownScale <= 0 ? 0.000001 : g_Vars.GStrafe.SlowDownScale );
				}

				g_Vars.GStrafe.ScrollEmulation ?
					mouse_event ( MOUSEEVENTF_WHEEL, 0, 0, g_Vars.GStrafe.ScrollDirection > 1000 ? 120 : -120, 0 ) : cmd->buttons |= IN_DUCK;

				Count = Engine::g_Engine.pfnRandomLong ( g_Vars.GStrafe.Count[0], g_Vars.GStrafe.Count[1] );
				State = 1;
			}
		}

		void GStrafe::StandUp ( usercmd_s *cmd )
		{
			if ( Engine::g_pPlayerMove->flFallVelocity >= g_Vars.GStrafe.StandUpFallVelocity &&
				Engine::g_pPlayerMove->movetype != 5 && Engine::g_pPlayerMove->waterlevel < 2 )
			{
				if ( !Info::g_Local.GroundAngle && Engine::g_pPlayerMove->flFallVelocity >= 220 )
				{
					return;
				}

				cmd->buttons |= IN_DUCK;
			}
		}

		void _fastcall GStrafe::CL_CreateMove ( float frametime, usercmd_s *cmd )
		{
			if ( GroundStrafeActive || StandUpActive )
			{
				cmd->buttons &= ~IN_JUMP;

				GroundStrafe ( frametime, cmd );

				if ( StandUpActive )
				{
					StandUp ( cmd );
				}
			}
		}

		GStrafe g_GStrafe;
	}
}