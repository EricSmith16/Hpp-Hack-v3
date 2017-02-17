#pragma once

#include "Main.h"

namespace Renderer
{
	class Drawing
	{
	public:
		void _fastcall FillArea ( float Pos_x, float Pos_y, float Width, float Height, BYTE Red, BYTE Green, BYTE Blue, BYTE Alpha );
		void _fastcall Box ( float Pos_x, float Pos_y, float Width, float Height, float LineWidth, BYTE Red, BYTE Green, BYTE Blue, BYTE Alpha );
		void _fastcall BoxOutLine ( float Pos_x, float Pos_y, float Width, float Height, float LineWidth, BYTE Red, BYTE Green, BYTE Blue, BYTE Alpha );
		void _fastcall Circle ( float Pos_x, float Pos_y, float Radius, int Amount, float LineWidth, BYTE Red, BYTE Green, BYTE Blue, BYTE Alpha );
	};

	extern Drawing g_Drawing;
}