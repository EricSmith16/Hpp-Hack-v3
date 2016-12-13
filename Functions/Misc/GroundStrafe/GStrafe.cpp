#include "GStrafe.h"

namespace Functions
{
	namespace Misc
	{
		bool GStrafe::GroundStrafeActive, GStrafe::StandUpActive;

		float GStrafe::DistanceInFrames ( float frametime )
		{
			if ( Information::g_Local.GroundAngle > 0 && Information::g_Local.GroundAngle <= 45 )
			{
				return abs ( Information::g_Local.Height / Engine::g_pPlayerMove->flFallVelocity / frametime * 2 );
			}
			else
			{
				return abs ( Information::g_Local.Height / frametime * 0.01f );
			}
		}

		float GStrafe::Distance ( )
		{
			return abs ( Information::g_Local.Height / Engine::g_pPlayerMove->flFallVelocity / 0.01f * 2 );
		}

		float GStrafe::DistanceType ( )
		{
			if ( g_Vars.gstrafe.distance_type == 2 )
			{
				static float CurrDistance, PrevDistance;

				static int Choice;

				PrevDistance = CurrDistance;

				CurrDistance = StandUpActive ? Engine::g_Engine.pfnRandomFloat ( g_Vars.gstrafe.distance[0] + 2, g_Vars.gstrafe.distance[1] + 2 ) :
					Engine::g_Engine.pfnRandomFloat ( g_Vars.gstrafe.distance[0], g_Vars.gstrafe.distance[1] );

				Choice = Engine::g_Engine.pfnRandomLong ( 1, 2 );

				if ( Choice == 1 )
				{
					return Engine::g_Engine.pfnRandomFloat ( g_Vars.gstrafe.distance[0], CurrDistance );
				}
				else if ( Choice == 2 )
				{
					return Engine::g_Engine.pfnRandomFloat ( CurrDistance, g_Vars.gstrafe.distance[1] );
				}
			}

			return StandUpActive ? Engine::g_Engine.pfnRandomFloat ( g_Vars.gstrafe.distance[0] + 2, g_Vars.gstrafe.distance[1] + 2 ) :
				Engine::g_Engine.pfnRandomFloat ( g_Vars.gstrafe.distance[0], g_Vars.gstrafe.distance[1] );
		}

		void GStrafe::GroundStrafe ( float frametime, usercmd_s *cmd )
		{
			static int State, Count;

			if ( Count )
			{
				if ( State == 1 )
				{
					if ( g_Vars.gstrafe.slowdown_scale != 1 && Information::g_Local.GroundAngle <= 45 && Engine::g_pPlayerMove->flags & FL_ONGROUND )
					{
						g_Speed.AdjustSpeed ( g_Vars.gstrafe.slowdown_scale <= 0 ? 0.000001f : g_Vars.gstrafe.slowdown_scale );
					}

					if ( !g_Vars.gstrafe.mouse_wheel_emulation )
					{
						cmd->buttons &= ~IN_DUCK;
					}

					--Count;

					State = 2;

					return;
				}
				else if ( State == 2 )
				{
					if ( g_Vars.gstrafe.slowdown_scale != 1 && Information::g_Local.GroundAngle <= 45 && Engine::g_pPlayerMove->flags & FL_ONGROUND )
					{
						g_Speed.AdjustSpeed ( g_Vars.gstrafe.slowdown_scale <= 0 ? 0.000001f : g_Vars.gstrafe.slowdown_scale );
					}

					g_Vars.gstrafe.mouse_wheel_emulation ?
						mouse_event ( MOUSEEVENTF_WHEEL, 0, 0, g_Vars.gstrafe.mouse_wheel_direction > 1000 ? 120 : -120, 0 ) : cmd->buttons |= IN_DUCK;

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

			if ( g_Vars.gstrafe.fallrun && Engine::g_pPlayerMove->flFallVelocity > 0 &&
				( Information::g_Local.GroundAngle >= 28.5f && Information::g_Local.GroundAngle <= 45 ) )
			{
				cmd->buttons |= IN_DUCK;

				return;
			}

			if ( !State && !Count && ( Engine::g_pPlayerMove->flags & FL_ONGROUND || ( g_Vars.gstrafe.mouse_wheel_emulation ?
				Distance ( ) : DistanceInFrames ( frametime ) ) <= DistanceType ( ) ) )
			{
				if ( g_Vars.gstrafe.slowdown_scale != 1 && Information::g_Local.GroundAngle <= 45 && Engine::g_pPlayerMove->flags & FL_ONGROUND )
				{
					g_Speed.AdjustSpeed ( g_Vars.gstrafe.slowdown_scale <= 0 ? 0.000001f : g_Vars.gstrafe.slowdown_scale );
				}

				g_Vars.gstrafe.mouse_wheel_emulation ?
					mouse_event ( MOUSEEVENTF_WHEEL, 0, 0, g_Vars.gstrafe.mouse_wheel_direction > 1000 ? 120 : -120, 0 ) : cmd->buttons |= IN_DUCK;

				Count = Engine::g_Engine.pfnRandomLong ( g_Vars.gstrafe.count[0], g_Vars.gstrafe.count[1] );
				State = 1;

				return;
			}
		}

		void GStrafe::StandUp ( usercmd_s *cmd )
		{
			if ( Engine::g_pPlayerMove->flFallVelocity >= g_Vars.gstrafe.standup_fallvelocity &&
				Engine::g_pPlayerMove->movetype != 5 && Engine::g_pPlayerMove->waterlevel < 2 )
			{
				if ( !Information::g_Local.GroundAngle && ( Engine::g_pPlayerMove->flFallVelocity >= 220 || Information::g_Local.Height >= 30 ) )
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