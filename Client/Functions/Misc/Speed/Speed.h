#pragma once

#include "Main.h"

namespace Functions
{
	namespace Misc
	{
		class Speed
		{
		private:
			inline void SpeedFunctions ( );

		public:
			static bool SpeedBoost, SpeedSlowMotion;

			void _fastcall AdjustSpeed ( double Speed );

			void _fastcall CL_CreateMove ( );
		};

		extern Speed g_Speed;
	}
}