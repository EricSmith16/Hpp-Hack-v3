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

		for ( BYTE i = 0; i < 255; ++i )
		{
			SIZE s;

			char Line[2] = { ( char )i, 0 };

			GetTextExtentPoint ( hDC, Line, 1, &s );

			cWidth[i] = s.cx;
			cHeight = s.cy;
		}

		SelectObject ( hDC, hOldFont );
		DeleteObject ( hFont );
	}

	void Font::Render ( float Pos_x, float Pos_y, BYTE Red, BYTE Green, BYTE Blue, BYTE Alpha, char *String )
	{
		int i;

		for ( i = 0; Pos_x < 0; ++i )
		{
			Pos_x += cWidth[String[i]];

			if ( !String[i] )
			{
				return;
			}
		}

		glColor4ub ( Red, Green, Blue, Alpha );
		glRasterPos2f ( Pos_x, Pos_y );
		glHint ( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
		glPushAttrib ( GL_LIST_BIT );
		glListBase ( g_FontListID );
		glCallLists ( strlen ( String ) - i, GL_UNSIGNED_BYTE, String + i );
		glPopAttrib ( );
	}

	void Font::Print ( float Pos_x, float Pos_y, BYTE Red, BYTE Green, BYTE Blue, BYTE Alpha, BYTE Flags, char *String, ... )
	{
		char Text[256];

		va_list ArgumentPtr;
		va_start ( ArgumentPtr, String );
		vsprintf_s ( Text, String, ArgumentPtr );
		va_end ( ArgumentPtr );

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
			Pos_x -= DrawLen / 2;
		}

		if ( Flags & FL_OUTLINE )
		{
			if ( g_Vars.Main.FontOutLineQuality == 1 )
			{
				Render ( Pos_x + 1, Pos_y + 1, 0, 0, 0, Alpha, Text );
			}
			else if ( g_Vars.Main.FontOutLineQuality == 2 )
			{
				Render ( Pos_x + 1, Pos_y, 0, 0, 0, Alpha, Text );
				Render ( Pos_x + 1, Pos_y + 1, 0, 0, 0, Alpha, Text );
			}
			else if ( g_Vars.Main.FontOutLineQuality == 3 )
			{
				Render ( Pos_x, Pos_y - 1, 0, 0, 0, Alpha, Text );
				Render ( Pos_x, Pos_y + 1, 0, 0, 0, Alpha, Text );
				Render ( Pos_x - 1, Pos_y, 0, 0, 0, Alpha, Text );
				Render ( Pos_x + 1, Pos_y, 0, 0, 0, Alpha, Text );

				Render ( Pos_x - 1, Pos_y - 1, 0, 0, 0, Alpha, Text );
				Render ( Pos_x + 1, Pos_y - 1, 0, 0, 0, Alpha, Text );
				Render ( Pos_x - 1, Pos_y + 1, 0, 0, 0, Alpha, Text );
				Render ( Pos_x + 1, Pos_y + 1, 0, 0, 0, Alpha, Text );
			}
		}

		Render ( Pos_x, Pos_y, Red, Green, Blue, Alpha, Text );

		glDisable ( GL_BLEND );
		glEnable ( GL_TEXTURE_2D );
	}

	Font g_Font, g_Verdana;
}