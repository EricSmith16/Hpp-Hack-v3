#pragma once

#include "Main.h"

namespace Functions
{
	namespace Misc
	{
		class EBug
		{
		private:
			static uint8 State;

			inline float CurrentFrameZDist ( float frametime );

			inline bool Auto ( float frametime );

			inline void EdgeBug ( float frametime );

		public:
			static bool EdgeBugActive;

			void _fastcall CL_CreateMove ( float frametime );
		};

		extern EBug g_EdgeBug;
	}
}