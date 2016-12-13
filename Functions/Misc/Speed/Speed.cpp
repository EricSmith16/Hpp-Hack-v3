#include "Speed.h"

namespace Functions
{
	namespace Misc
	{
		bool Speed::SpeedBoost, Speed::SpeedSlowMo;

		void _fastcall Speed::AdjustSpeed ( double Speed )
		{
			static double LastSpeed = 1;

			if ( !Information::g_Local.Speed )
			{
				Information::g_Local.Speed = Information::g_Local.SpeedPtr;
			}

			if ( Speed != LastSpeed )
			{
				*( double* )Information::g_Local.Speed = Speed * 1000;

				LastSpeed = Speed;
			}
		}

		void Speed::SpeedFunctions ( )
		{
			AdjustSpeed ( g_Vars.speed.value );

			if ( g_Vars.speed.engine_value )
			{
				*Information::g_Local.g_Net += g_Vars.speed.engine_value / 1000;
			}

			if ( g_Vars.speed.speed_type == 1 )
			{
				if ( SpeedBoost )
				{
					if ( g_Vars.speed.boost > 1 )
					{
						AdjustSpeed ( g_Vars.speed.boost );
					}
					else
					{
						AdjustSpeed ( 1 );
					}
				}

				if ( SpeedSlowMo )
				{
					if ( g_Vars.speed.slowmo < 1 )
					{
						AdjustSpeed ( g_Vars.speed.slowmo );
					}
					else
					{
						AdjustSpeed ( 1 );
					}
				}
			}
			else if ( g_Vars.speed.speed_type == 2 )
			{
				if ( SpeedBoost )
				{
					if ( g_Vars.speed.boost > 0 )
					{
						*Information::g_Local.g_Net += g_Vars.speed.boost / 1000;
					}
					else
					{
						*Information::g_Local.g_Net += 0;
					}
				}

				if ( SpeedSlowMo )
				{
					if ( g_Vars.speed.slowmo < 0 )
					{
						*Information::g_Local.g_Net += g_Vars.speed.slowmo / 1000;
					}
					else
					{
						*Information::g_Local.g_Net += 0;
					}
				}
			}
		}

		void _fastcall Speed::CL_CreateMove ( )
		{
			if ( g_Vars.function.speed )
			{
				SpeedFunctions ( );
			}
			else
			{
				AdjustSpeed ( 1 );

				*Information::g_Local.g_Net += 0;
			}	
		}

		Speed g_Speed;
	}
}