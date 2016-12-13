#pragma once

#include "Main.h"

namespace Functions
{
	namespace Visuals
	{
		class NoFlash
		{
		private:
			float CurStateFlashed;
			float PrevStateFlashed;

			inline void GetColor ( int Percentage );

			inline void SetFadeColor ( );
			inline void SetFadeColorRandom ( );

			inline void PrintFlashed ( int Percentage );
			inline void PrintFlashedBox ( int Percentage );

		public:
			NoFlash ( );

			BYTE NoFlashColor[2];
			BYTE FadeColor[3];

			void HUD_Redraw ( );
		};

		extern NoFlash g_NoFlash;
	}
}