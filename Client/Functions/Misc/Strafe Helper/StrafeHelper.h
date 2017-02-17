#pragma once

#include "Main.h"

namespace Functions
{
	namespace Misc
	{
		class StrafeHelper
		{
		private:
			static uint8 Direction;

			inline int MouseDirection ( short check );

			inline void AutoDirection ( usercmd_s *cmd, short check );

			inline void Correct ( short check );
			inline void Filter ( usercmd_s *cmd, short check );
			inline void Data ( usercmd_s *cmd, short check );
			inline void KeyEmulation ( short check );

			inline void StrafeHelperFunc ( usercmd_s *cmd, short check );

		public:
			static bool StrafeHelperActive;

			void _fastcall SetViewAngles ( float *Angles );

			void _fastcall CL_CreateMove ( float frametime, usercmd_s *cmd, short check );
		};

		extern StrafeHelper g_StrafeHelper;
	}
}