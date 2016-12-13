#pragma once

#include "Main.h"

namespace Functions
{
	namespace Visuals
	{
		class ScreenInfo
		{
		private:
			BYTE Color[3];

			static bool Forward, Backward;
			static bool MoveLeft, MoveRight;
			static bool Duck, Jump;

			inline void ForwardPressed ( );
			inline void ForwardNoPressed ( );

			inline void MoveLeftPressed ( );
			inline void MoveLeftNoPressed ( );

			inline void MoveRightPressed ( );
			inline void MoveRightNoPressed ( );

			inline void BackwardPressed ( );
			inline void BackwardNoPressed ( );

			inline void DuckPressed ( );
			inline void DuckNoPressed ( );

			inline void JumpPressed ( );
			inline void JumpNoPressed ( );

			inline void GetColor ( );

			inline void DrawFps ( );
			inline void DrawCopyRight ( );
			inline void DrawTime ( );
			inline void DrawShowKeys ( );
			inline void DrawKreedz ( );

		public:
			ScreenInfo ( );

			void HUD_Redraw ( );
			void CL_CreateMove ( usercmd_s *cmd );
		};

		extern ScreenInfo g_ScreenInfo;
	}
}