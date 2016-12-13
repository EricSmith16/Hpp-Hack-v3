#pragma once

#include "Main.h"

namespace Renderer
{
	class Drawing
	{
	public:
		void Fill ( float x, float y, float width, float height, BYTE r, BYTE g, BYTE b, BYTE a );
		void Box ( float x, float y, float width, float height, float linewidth, BYTE r, BYTE g, BYTE b, BYTE a );
		void BoxWithOutLine ( float x, float y, float width, float height, float linewidth, BYTE r, BYTE g, BYTE b, BYTE a );
		void Circle ( float x, float y, float rad, int AmountSegments, float linewidth, BYTE r, BYTE g, BYTE b, BYTE a );
	};

	extern Drawing g_Drawing;
}