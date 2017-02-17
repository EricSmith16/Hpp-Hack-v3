#pragma once

#include "Main.h"

namespace Functions
{
	namespace Visuals
	{
		class NoFlash
		{
		private:
			float CurStateFlashed, PrevStateFlashed;

			inline void GetColor ( uint8 Percentage );

			inline void SetFadeColor ( );
			inline void SetFadeColorRandom ( );

			inline void PrintFlashed ( uint8 Percentage );
			inline void PrintFlashedBox ( uint8 Percentage );

		public:
			NoFlash ( );

			BYTE NoFlashColor[2], FadeColor[3];

			void _fastcall HUD_Redraw ( );
		};

		extern NoFlash g_NoFlash;
	}
}