#pragma once

#include "Main.h"

namespace Renderer
{
	class Font
	{
	private:
		static GLuint g_FontListID;

		static int cHeight, cWidth[255];

		static void _fastcall Render ( float x, float y, BYTE r, BYTE g, BYTE b, BYTE a, char *String );

	public:
		static void InitText ( char* Font, int Height, int Width );

		static void _fastcall Print ( float x, float y, BYTE r, BYTE g, BYTE b, BYTE a, BYTE Flags, char *String, ... );
	};

	extern Font g_Font, g_Verdana;
}