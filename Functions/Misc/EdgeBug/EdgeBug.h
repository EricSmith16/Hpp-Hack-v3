#pragma once

#include "Main.h"

namespace Functions
{
	namespace Misc
	{
		class EBug
		{
		private:
			static int State;

			inline float CurrentFrameZDist ( float frametime );

			inline void Auto ( float frametime );
			inline void EdgeBug ( float frametime );

		public:
			static bool EdgeBugActive, EdgeBugAuto;

			void _fastcall CL_CreateMove ( float frametime );
		};

		extern EBug g_EdgeBug;
	}
}