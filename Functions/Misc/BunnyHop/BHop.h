#pragma once

#include "Main.h"

namespace Functions
{
	namespace Misc
	{
		class BHop
		{
		private:
			static bool inWaterBHop;

			inline float DistanceInFrames ( float frametime );
			inline float Distance ( );
			inline float DistanceType ( );

			inline void BunnyHop ( float frametime, usercmd_s *cmd );		
			inline void StandUp ( usercmd_s *cmd );

		public:
			static bool BunnyHopActive, StandUpActive;

			void _fastcall CL_CreateMove ( float frametime, usercmd_s *cmd );
		};

		extern BHop g_BHop;
	}
}