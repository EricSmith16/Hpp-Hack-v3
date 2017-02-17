#include "EdgeBug.h"

namespace Functions
{
	namespace Misc
	{
		uint8 EBug::State;

		bool EBug::EdgeBugActive;

		float EBug::CurrentFrameZDist ( float frametime )
		{
			return abs ( ( Engine::g_pPlayerMove->flFallVelocity + 800 * frametime ) * frametime );
		}

		bool EBug::Auto ( float frametime )
		{
			return ( g_Vars.EdgeBug.AutoEnable && Info::g_Local.FallDamage >= g_Vars.EdgeBug.AutoDamage && !Info::g_Local.GroundAngle ) &&
				( Info::g_Local.Height - ( Engine::g_pPlayerMove->flFallVelocity * frametime * 15 ) <= 0 );
		}

		void EBug::EdgeBug ( float frametime )
		{
			float pSpeed = Engine::g_pPlayerMove->velocity.Length2D ( ) == 0 ? 1 : Engine::g_pPlayerMove->velocity.Length2D ( );
			float pFallspeed = Engine::g_pPlayerMove->flFallVelocity == 0 ? 1 : Engine::g_pPlayerMove->flFallVelocity;
			float pHeight = Info::g_Local.Height == 0 ? 1 : Info::g_Local.Height;

			float EdgeOffset = abs ( ( Info::g_Local.EdgeDistance / pSpeed ) / ( Info::g_Local.EdgeDistance / pFallspeed ) *
				( Info::g_Local.EdgeDistance / pHeight ) );

			float lo1x = abs ( ( frametime * Info::g_Local.EdgeDistance * Engine::g_pPlayerMove->flFallVelocity ) /
				Engine::g_pPlayerMove->velocity.Length2D ( ) );

			switch ( State )
			{
			case 0:
				if ( abs ( Info::g_Local.Height - CurrentFrameZDist ( frametime ) * 1.5f ) <= 22 && CurrentFrameZDist ( frametime ) > 0 )
				{
					float NeedSpeed = Info::g_Local.Height - 1;
					float Scale = NeedSpeed / CurrentFrameZDist ( frametime );

					*Info::g_Local.g_Net += EdgeOffset * Scale * g_Vars.EdgeBug.SpeedFinal *
						( Engine::g_pPlayerMove->flFallVelocity / ( Info::g_Local.Height * Engine::g_pPlayerMove->velocity.Length2D ( ) ) ) *
						( Info::g_Local.Height / Engine::g_pPlayerMove->flFallVelocity ) *
						( Engine::g_pPlayerMove->velocity.Length2D ( ) / Engine::g_pPlayerMove->flFallVelocity ) *
						( lo1x * Engine::g_pPlayerMove->flFallVelocity - ( -1 * lo1x ) ) * frametime / 10;

					State = 1;
				}

				break;

			case 1:
				*Info::g_Local.g_Net += ( g_Vars.EdgeBug.Speed + EdgeOffset * g_Vars.EdgeBug.SpeedOffset ) * frametime / 10;

				State = 2;

				break;

			case 2:
				*Info::g_Local.g_Net += EdgeOffset * g_Vars.EdgeBug.SpeedFinal * frametime / 10;

				State = 0;

				break;
			}
		}

		void _fastcall EBug::CL_CreateMove ( float frametime )
		{
			if ( Engine::g_pPlayerMove->flFallVelocity > 0 && Engine::g_pPlayerMove->velocity.Length2D ( ) >= 100 && !Info::g_Local.GroundAngle )
			{
				if ( ( Auto ( frametime ) || EdgeBugActive ) && Info::g_Local.EdgeDistance <=
					Engine::g_pPlayerMove->velocity.Length2D ( ) / 5 && Info::g_Local.EdgeDistance > 0 && !Info::g_Local.GroundAngle )
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