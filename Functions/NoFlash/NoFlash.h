#pragma once

#include "Main.h"

namespace Functions
{
	class NoFlash
	{
	private:
		inline static void GetColor ( int Percentage );
		inline static void SetFadeColor ( );
		inline static void SetFadeColorRandom ( float Flashed );
		inline static void PrintFlashed ( int Percentage );
		inline static void PrintFlashedBox ( int Percentage );	

	public:
		static void HUD_Redraw ( );
	};

	extern NoFlash g_NoFlash;

	struct noflash_s
	{
		BYTE color[2];
	};

	extern noflash_s noflash;
}