#pragma once

#include "Main.h"

namespace Renderer
{
	class Font
	{
	private:
		GLuint g_FontListID;

		int cHeight, cWidth[255];

		void Render ( float x, float y, BYTE r, BYTE g, BYTE b, BYTE a, char *String );

	public:
		void InitText ( char* Font, int Height, int Width );

		void Print ( float x, float y, BYTE r, BYTE g, BYTE b, BYTE a, BYTE Flags, char *String, ... );
	};

	extern Font g_Font, g_Verdana;
}