#pragma once

#include "Main.h"

namespace Functions
{
	class NoFlash
	{
	private:
		inline static void PrintFlashed ( int Percentage );
		inline static void PrintFlashedBox ( int Percentage );

	public:
		static void HUD_Redraw ( );
	};

	extern NoFlash g_NoFlash;
}