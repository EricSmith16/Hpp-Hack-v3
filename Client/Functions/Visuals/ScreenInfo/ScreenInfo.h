#pragma once

#include "Main.h"

namespace Functions
{
	namespace Visuals
	{
		class ScreenInfo
		{
		private:
			static bool Forward, Backward;
			static bool MoveLeft, MoveRight;
			static bool Duck, Jump;

			inline void DrawFps ( );
			inline void DrawCopyRight ( );
			inline void DrawTime ( );
			inline void DrawShowKeys ( );
			inline void DrawKreedz ( );

		public:
			void _fastcall HUD_Redraw ( );
			void _fastcall CL_CreateMove ( usercmd_s *cmd );
		};

		extern ScreenInfo g_ScreenInfo;
	}
}