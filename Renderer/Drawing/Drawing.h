#pragma once

#include "Main.h"

namespace Renderer
{
	class Drawing
	{
	public:
		static void _fastcall Fill ( float x, float y, float width, float height, BYTE r, BYTE g, BYTE b, BYTE a );
		static void _fastcall Box ( float x, float y, float width, float height, float linewidth, BYTE r, BYTE g, BYTE b, BYTE a );

		static void BoxWithOutLine ( float x, float y, float width, float height, float linewidth, BYTE r, BYTE g, BYTE b, BYTE a );
		static void Circle ( float x, float y, float rad, int AmountSegments, float linewidth, BYTE r, BYTE g, BYTE b, BYTE a );
	};

	extern Drawing g_Drawing;
}