#include "Speed.h"

namespace Functions
{
	namespace Misc
	{
		bool Speed::SpeedBoost, Speed::SpeedSlowMotion;

		void _fastcall Speed::AdjustSpeed ( double Speed )
		{
			static double LastSpeed = 1;

			if ( !Info::g_Local.Player.Speed )
			{
				Info::g_Local.Player.Speed = Engine::g_Offset.SpeedPtr;
			}

			if ( Speed != LastSpeed )
			{
				*( double* )Info::g_Local.Player.Speed = Speed * 1000;

				LastSpeed = Speed;
			}
		}

		void Speed::SpeedFunctions ( )
		{
			AdjustSpeed ( g_Vars.Speed.Value );

			if ( g_Vars.Speed.EngineValue )
			{
				*Info::g_Local.g_Net += g_Vars.Speed.EngineValue / 1000;
			}

			if ( g_Vars.Speed.SpeedType == 1 )
			{
				if ( SpeedBoost )
				{
					if ( g_Vars.Speed.Boost > 1 )
					{
						AdjustSpeed ( g_Vars.Speed.Boost );
					}
					else
					{
						AdjustSpeed ( 1 );
					}
				}

				if ( SpeedSlowMotion )
				{
					if ( g_Vars.Speed.SlowMotion < 1 )
					{
						AdjustSpeed ( g_Vars.Speed.SlowMotion );
					}
					else
					{
						AdjustSpeed ( 1 );
					}
				}
			}
			else if ( g_Vars.Speed.SpeedType == 2 )
			{
				if ( SpeedBoost )
				{
					if ( g_Vars.Speed.Boost > 0 )
					{
						*Info::g_Local.g_Net += g_Vars.Speed.Boost / 1000;
					}
					else
					{
						*Info::g_Local.g_Net += 0;
					}
				}

				if ( SpeedSlowMotion )
				{
					if ( g_Vars.Speed.SlowMotion < 0 )
					{
						*Info::g_Local.g_Net += g_Vars.Speed.SlowMotion / 1000;
					}
					else
					{
						*Info::g_Local.g_Net += 0;
					}
				}
			}
		}

		void _fastcall Speed::CL_CreateMove ( )
		{
			if ( g_Vars.Function.Speed )
			{
				SpeedFunctions ( );
			}
			else
			{
				AdjustSpeed ( 1 );

				*Info::g_Local.g_Net += 0;
			}	
		}

		Speed g_Speed;
	}
}