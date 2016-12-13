#include "EdgeBug.h"

namespace Functions
{
	namespace Misc
	{
		int EBug::State;

		bool EBug::EdgeBugActive, EBug::EdgeBugAuto;

		float EBug::CurrentFrameZDist ( float frametime )
		{
			return abs ( ( Engine::g_pPlayerMove->flFallVelocity + 800 * frametime ) * frametime );
		}

		void EBug::Auto ( float frametime )
		{
			if ( ( g_Vars.edgebug.auto_enable && Information::g_Local.FallDamage >= g_Vars.edgebug.auto_damage ) &&
				( Information::g_Local.Height - ( Engine::g_pPlayerMove->flFallVelocity * frametime / 1 * 15 ) <= 0 ) )
			{
				EdgeBugAuto = true;
			}
			else
			{
				EdgeBugAuto = false;
			}
		}

		void EBug::EdgeBug ( float frametime )
		{
			float pSpeed = Engine::g_pPlayerMove->velocity.Length2D ( ) == 0 ? 1 : Engine::g_pPlayerMove->velocity.Length2D ( );
			float pFallspeed = Engine::g_pPlayerMove->flFallVelocity == 0 ? 1 : Engine::g_pPlayerMove->flFallVelocity;
			float pHeight = Information::g_Local.Height == 0 ? 1 : Information::g_Local.Height;

			float one = abs ( ( Information::g_Local.EdgeDistance / pSpeed ) / ( Information::g_Local.EdgeDistance / pFallspeed ) *
				( Information::g_Local.EdgeDistance / pHeight ) );

			float lo1x = abs ( ( frametime * Information::g_Local.EdgeDistance * Engine::g_pPlayerMove->flFallVelocity ) /
				Engine::g_pPlayerMove->velocity.Length2D ( ) );

			int eb_speed_final = -2;
			int eb_speed_offset = -1;

			Information::g_Local.EdgeOffset = one;

			switch ( State )
			{
			case 0:
				if ( abs ( Information::g_Local.Height - CurrentFrameZDist ( frametime ) * 1.5f ) <= 22 && CurrentFrameZDist ( frametime ) > 0 )
				{
					float NeedSpeed = Information::g_Local.Height - 1;
					float Scale = NeedSpeed / CurrentFrameZDist ( frametime );

					*Information::g_Local.g_Net += Information::g_Local.EdgeOffset * Scale * eb_speed_final *
						( Engine::g_pPlayerMove->flFallVelocity / ( Information::g_Local.Height * Engine::g_pPlayerMove->velocity.Length2D ( ) ) ) *
						( Information::g_Local.Height / Engine::g_pPlayerMove->flFallVelocity ) *
						( Engine::g_pPlayerMove->velocity.Length2D ( ) / Engine::g_pPlayerMove->flFallVelocity ) *
						( lo1x * Engine::g_pPlayerMove->flFallVelocity - ( -1 * lo1x ) ) * frametime / 10;

					State = 1;
				}

				break;

			case 1:
				*Information::g_Local.g_Net += ( g_Vars.edgebug.speed + Information::g_Local.EdgeOffset * eb_speed_offset ) * frametime / 10;

				State = 2;

				break;

			case 2:
				*Information::g_Local.g_Net += Information::g_Local.EdgeOffset * eb_speed_final * frametime / 10;

				State = 0;

				break;
			}
		}

		void _fastcall EBug::CL_CreateMove ( float frametime )
		{
			if ( Engine::g_pPlayerMove->flFallVelocity > 0 )
			{
				if ( Engine::g_pPlayerMove->velocity.Length2D ( ) < 50 || Information::g_Local.GroundAngle > 0 )
				{
					return;
				}

				Auto ( frametime );

				if ( ( EdgeBugAuto || EdgeBugActive ) && Information::g_Local.EdgeDistance <= ( g_Vars.edgebug.distance_auto ?
					( Engine::g_pPlayerMove->velocity.Length2D ( ) / 10 ) : g_Vars.edgebug.distance ) &&
					Information::g_Local.EdgeDistance >= 0 && Information::g_Local.GroundAngle <= 45 )
				{
					EdgeBug ( frametime );
				}
				else
				{
					State = 0;
				}
			}
		}

		EBug g_EdgeBug;
	}
}