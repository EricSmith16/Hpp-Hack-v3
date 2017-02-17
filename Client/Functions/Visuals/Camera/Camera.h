#pragma once

#include "Main.h"

namespace Functions
{
	namespace Visuals
	{
		class Camera
		{
		private:
			inline void ThirdPerson ( ref_params_s *pparams );

			inline void FreeLook ( ref_params_s *pparams );
			inline void FreeLookCreate ( float frametime, usercmd_s *cmd );

			inline void Spectator ( uint8 ID, ref_params_s *pparams );
			inline void SpectatorCreate ( uint8 ID, usercmd_s *cmd );

		public:
			void _fastcall V_CalcRefdef ( ref_params_s *pparams );
			void _fastcall CL_CreateMove ( float frametime, usercmd_s *cmd );
		};

		extern Camera g_Camera;
	}
}