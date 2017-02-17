#pragma once

#include "Main.h"

namespace Functions
{
	namespace Misc
	{
		class JBug
		{
		private:
			static uint8 State;

			inline float CurrentFrameZDist ( float frametime );

			inline bool Auto ( float frametime );
			inline bool AutoPercentage ( float frametime );

			inline void JumpBug ( float frametime, usercmd_s *cmd );
			inline void SlowDown ( float frametime, usercmd_s *cmd );

		public:
			static bool JumpBugActive;

			void _fastcall CL_CreateMove ( float frametime, usercmd_s *cmd );
		};

		extern JBug g_JumpBug;
	}
}