#pragma once

#include "Main.h"

namespace Renderer
{
	class Font
	{
	private:
		GLuint g_FontListID;

		int cHeight, cWidth[255];

		inline void Render ( float Pos_x, float Pos_y, BYTE Red, BYTE Green, BYTE Blue, BYTE Alpha, char *String );

	public:
		void _fastcall InitText ( char* Font, int Height, int Width );

		void _fastcall Print ( float Pos_x, float Pos_y, BYTE Red, BYTE Green, BYTE Blue, BYTE Alpha, BYTE Flags, char *String, ... );
	};

	extern Font g_Font, g_Verdana;
}