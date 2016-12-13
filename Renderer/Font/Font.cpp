#include "Font.h"

namespace Renderer
{
	void Font::InitText ( char* Font, int Height, int Width )
	{
		if ( Engine::g_Offset.HLType != RENDERTYPE_HARDWARE )
		{
			return;
		}

		HDC hDC;
		HFONT hFont, hOldFont;

		hDC = wglGetCurrentDC ( );
		g_FontListID = glGenLists ( 256 );

		hFont = CreateFont ( Height, Width, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, RUSSIAN_CHARSET,
			OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, CLEARTYPE_NATURAL_QUALITY, FF_DONTCARE | VARIABLE_PITCH, Font );

		hOldFont = ( HFONT )SelectObject ( hDC, hFont );

		if ( !wglUseFontBitmaps ( hDC, 0, 255, g_FontListID ) )
		{
			wglUseFontBitmaps ( hDC, 0, 255, g_FontListID );
		}

		for ( int i = 0; i < 255; ++i )
		{
			SIZE s;

			char line[2] = { ( char )i, 0 };

			GetTextExtentPoint ( hDC, line, 1, &s );

			cWidth[i] = s.cx;
			cHeight = s.cy;
		}

		SelectObject ( hDC, hOldFont );
		DeleteObject ( hFont );
	}

	void Font::Render ( float x, float y, BYTE r, BYTE g, BYTE b, BYTE a, char *String )
	{
		int i = 0;

		for ( int i = 0; x < 0; ++i )
		{
			x += cWidth[String[i]];

			if ( !String[i] )
			{
				return;
			}
		}

		glColor4ub ( r, g, b, a );
		glRasterPos2f ( x, y );
		glHint ( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
		glPushAttrib ( GL_LIST_BIT );
		glListBase ( g_FontListID );
		glCallLists ( strlen ( String ) - i, GL_UNSIGNED_BYTE, String + i );
		glPopAttrib ( );
	}

	void Font::Print ( float x, float y, BYTE r, BYTE g, BYTE b, BYTE a, BYTE Flags, char *String, ... )
	{
		char Text[256];

		va_list argumentPtr;
		va_start ( argumentPtr, String );
		vsprintf_s ( Text, String, argumentPtr );
		va_end ( argumentPtr );

		glDisable ( GL_TEXTURE_2D );
		glEnable ( GL_BLEND );
		glBlendFunc ( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

		int DrawLen = 0;

		for ( char *p = Text; *p; ++p )
		{
			DrawLen += cWidth[*p];
		}

		if ( Flags & FL_CENTER )
		{
			x -= ( DrawLen / 2 );
		}

		if ( Flags & FL_OUTLINE )
		{
			if ( g_Vars.main.font_outline_quality == 1 )
			{
				Render ( x + 1, y + 1, 0, 0, 0, a, Text );
			}
			else if ( g_Vars.main.font_outline_quality == 2 )
			{
				Render ( x, y + 1, 0, 0, 0, a, Text );
				Render ( x + 1, y, 0, 0, 0, a, Text );
				Render ( x + 1, y + 1, 0, 0, 0, a, Text );
			}
			else if ( g_Vars.main.font_outline_quality == 3 )
			{
				Render ( x, y - 1, 0, 0, 0, a, Text );
				Render ( x, y + 1, 0, 0, 0, a, Text );
				Render ( x - 1, y, 0, 0, 0, a, Text );
				Render ( x + 1, y, 0, 0, 0, a, Text );

				Render ( x - 1, y - 1, 0, 0, 0, a, Text );
				Render ( x + 1, y - 1, 0, 0, 0, a, Text );
				Render ( x - 1, y + 1, 0, 0, 0, a, Text );
				Render ( x + 1, y + 1, 0, 0, 0, a, Text );
			}
		}

		Render ( x, y, r, g, b, a, Text );

		glDisable ( GL_BLEND );
		glEnable ( GL_TEXTURE_2D );
	}

	Font g_Font, g_Verdana;
}