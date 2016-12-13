#pragma once

#include "Main.h"

namespace Functions
{
	namespace Misc
	{
		class JBug
		{
		private:
			static int State;

			inline float CurrentFrameZDist ( float frametime );

			inline void Auto ( float frametime );
			inline void AutoPercentage ( );

			inline void JumpBug ( float frametime, usercmd_s *cmd );
			inline void SlowDown ( float frametime, usercmd_s *cmd );

		public:
			static bool JumpBugActive, JumpBugAuto, JumpBugPercent;

			void _fastcall CL_CreateMove ( float frametime, usercmd_s *cmd );
		};

		extern JBug g_JumpBug;
	}
}