#pragma once

#include "Main.h"

namespace Functions
{
	namespace Misc
	{
		class GStrafe
		{
		private:
			inline float DistanceInFrames ( float frametime );
			inline float Distance ( );
			inline float DistanceType ( );

			inline void GroundStrafe ( float frametime, usercmd_s *cmd );
			inline void StandUp ( usercmd_s *cmd );

		public:
			static bool GroundStrafeActive, StandUpActive;

			void _fastcall CL_CreateMove ( float frametime, usercmd_s *cmd );
		};

		extern GStrafe g_GStrafe;
	}
}