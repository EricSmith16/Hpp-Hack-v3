#include "BHop.h"

namespace Functions
{
	namespace Misc
	{
		bool BHop::BunnyHopActive, BHop::inWaterBHop, BHop::StandUpActive;

		float BHop::DistanceInFrames ( float frametime )
		{
			if ( g_Vars.bhop.noslowdown )
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
			else
			{
				return abs ( Information::g_Local.Height / Engine::g_pPlayerMove->flFallVelocity / frametime * 2 );
			}
		}

		float BHop::Distance ( )
		{
			return abs ( Information::g_Local.Height / Engine::g_pPlayerMove->flFallVelocity / 0.01f * 2 );
		}

		float BHop::DistanceType ( )
		{
			if ( g_Vars.bhop.distance_type == 2 )
			{
				static float CurrDistance, PrevDistance;

				static int Choice;

				PrevDistance = CurrDistance;

				CurrDistance = Engine::g_Engine.pfnRandomFloat ( g_Vars.bhop.distance[0], g_Vars.bhop.distance[1] );

				Choice = Engine::g_Engine.pfnRandomLong ( 1, 2 );

				if ( Choice == 1 )
				{
					return Engine::g_Engine.pfnRandomFloat ( g_Vars.bhop.distance[0], CurrDistance );
				}
				else if ( Choice == 2 )
				{
					return Engine::g_Engine.pfnRandomFloat ( CurrDistance, g_Vars.bhop.distance[1] );
				}
			}

			return Engine::g_Engine.pfnRandomFloat ( g_Vars.bhop.distance[0], g_Vars.bhop.distance[1] );
		}

		void BHop::BunnyHop ( float frametime, usercmd_s *cmd )
		{
			static int State, inAirBHopCount;

			bool isJumped = false;

			if ( inWaterBHop )
			{
				cmd->buttons |= IN_JUMP;

				return;
			}

			if ( State )
			{
				State = 0;

				return;
			}

			if ( g_Vars.bhop.in_water && Engine::g_pPlayerMove->waterlevel >= 2 )
			{
				cmd->buttons |= IN_JUMP;

				inWaterBHop = true;

				return;
			}

			if ( g_Vars.bhop.on_ladder && Engine::g_pPlayerMove->movetype == 5 && Engine::g_pPlayerMove->flFallVelocity >= 0 )
			{
				cmd->buttons |= IN_JUMP;

				return;
			}

			if ( g_Vars.bhop.noslowdown && !g_Vars.bhop.mouse_wheel_emulation )
			{
				static int GroundFrame;

				if ( !State && ( Engine::g_pPlayerMove->flags & FL_ONGROUND ||
					DistanceInFrames ( frametime ) >= 5 && DistanceInFrames ( frametime ) <= 18 ) )
				{
					if ( g_Vars.bhop.noslowdown == 1 )
					{
						cmd->buttons |= IN_JUMP;

						State = 1;

						return;
					}
					else if ( g_Vars.bhop.noslowdown == 2 )
					{
						if ( Engine::g_pPlayerMove->velocity.Length2D ( ) < Engine::g_pPlayerMove->maxspeed * 1.2f )
						{
							cmd->buttons |= IN_JUMP;

							State = 1;

							return;
						}
						else
						{
							if ( GroundFrame < 2 )
							{
								++GroundFrame;

								return;
							}
							else
							{
								cmd->buttons |= IN_JUMP;

								State = 1;
								GroundFrame = 0;

								return;
							}
						}
					}
				}
			}
			else
			{
				if ( !State && ( Engine::g_pPlayerMove->flags & FL_ONGROUND || ( g_Vars.bhop.mouse_wheel_emulation ?
					Distance ( ) : DistanceInFrames ( frametime ) ) <= DistanceType ( ) ) )
				{
					g_Vars.bhop.mouse_wheel_emulation ?
						mouse_event ( MOUSEEVENTF_WHEEL, 0, 0, g_Vars.bhop.mouse_wheel_direction > 1000 ? 120 : -120, 0 ) : cmd->buttons |= IN_JUMP;

					State = 1;

					{
						inAirBHopCount = 4;
						isJumped = true;
					}

					if ( !g_Vars.bhop.mouse_wheel_emulation )
					{
						return;
					}
				}
			}

			if ( g_Vars.bhop.mouse_wheel_emulation && !isJumped && inAirBHopCount > 0 )
			{
				if ( inAirBHopCount % 2 == 0 )
				{
					mouse_event ( MOUSEEVENTF_WHEEL, 0, 0, g_Vars.bhop.mouse_wheel_direction > 1000 ? 120 : -120, 0 );
				}

				--inAirBHopCount;

				return;
			}
		}

		void BHop::StandUp ( usercmd_s *cmd )
		{
			if ( Engine::g_pPlayerMove->flFallVelocity >= g_Vars.bhop.standup_fallvelocity && !Information::g_Local.FallDamage &&
				Information::g_Local.GroundAngle < g_Vars.bhop.standup_groundangle && Engine::g_pPlayerMove->movetype != 5 )
			{
				cmd->buttons |= IN_DUCK;
			}
		}

		void _fastcall BHop::CL_CreateMove ( float frametime, usercmd_s *cmd )
		{
			if ( BunnyHopActive )
			{
				BunnyHop ( frametime, cmd );

				if ( g_Vars.bhop.standup || StandUpActive )
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