#pragma once

#include "Main.h"

namespace Renderer
{
	class Drawing
	{
	public:
		//Fill area
		void FillArea ( float x, float y, float width, float height, BYTE r, BYTE g, BYTE b, BYTE a );
		//Drawing box
		void DrawBox ( float x, float y, float width, float height, float linewidth, BYTE r, BYTE g, BYTE b, BYTE a );
		//Drawing box with outline
		void DrawShadowBox ( float x, float y, float width, float height, float linewidth, BYTE r, BYTE g, BYTE b, BYTE a );
		//Drawing circle
		void DrawCircle ( float x, float y, float rad, int AmountSegments, float linewidth, BYTE r, BYTE g, BYTE b, BYTE a );
	};

	extern Drawing g_Drawing;
}