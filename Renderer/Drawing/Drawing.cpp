#include "Drawing.h"

namespace Renderer
{
	void Drawing::FillArea ( float x, float y, float width, float height, BYTE r, BYTE g, BYTE b, BYTE a )
	{
		if ( Engine::g_Offset.HLType != RENDERTYPE_HARDWARE )
		{
			Engine::g_Engine.pfnFillRGBA ( ( int )x, ( int )y, ( int )width, ( int )height, r, g, b, a );
		}
		else
		{
			glPushMatrix ( );
			glLoadIdentity ( );
			glDisable ( GL_TEXTURE_2D );
			glEnable ( GL_BLEND );
			glBlendFunc ( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
			glColor4ub ( r, g, b, a );
			glBegin ( GL_QUADS );
			glVertex2f ( x, y );
			glVertex2f ( x + width, y );
			glVertex2f ( x + width, y + height );
			glVertex2f ( x, y + height );
			glEnd ( );
			glDisable ( GL_BLEND );
			glEnable ( GL_TEXTURE_2D );
			glPopMatrix ( );
		}
	}

	void Drawing::DrawBox ( float x, float y, float width, float height, float linewidth, BYTE r, BYTE g, BYTE b, BYTE a )
	{
		FillArea ( x, y, width, linewidth, r, g, b, a );
		FillArea ( x + width - linewidth, y + linewidth, linewidth, height - linewidth, r, g, b, a );
		FillArea ( x, y + linewidth, linewidth, height - linewidth, r, g, b, a );
		FillArea ( x + linewidth, y + height - linewidth, width - linewidth * 2, linewidth, r, g, b, a );
	}

	void Drawing::DrawShadowBox ( float x, float y, float width, float height, float linewidth, BYTE r, BYTE g, BYTE b, BYTE a )
	{
		DrawBox ( x, y, width, height, linewidth, r, g, b, a );
		DrawBox ( x - 1, y - 1, width + 2, height + 2, 1, 0, 0, 0, a );
		DrawBox ( x + linewidth, y + linewidth, width - linewidth * 2, height - linewidth * 2, 1, 0, 0, 0, a );
	}

	void Drawing::DrawCircle ( float x, float y, float rad, int AmountSegments, float linewidth, BYTE r, BYTE g, BYTE b, BYTE a )
	{
		glDisable ( GL_TEXTURE_2D );
		glEnable ( GL_BLEND );
		glBlendFunc ( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
		glColor4ub ( r, g, b, a );
		glLineWidth ( linewidth );
		glBegin ( GL_LINE_LOOP );

		for ( int i = 0; i < AmountSegments; ++i )
		{
			float angle = 2.0f * 3.1415926f * float ( i ) / float ( AmountSegments );

			float dx = rad * cosf ( angle );
			float dy = rad * sinf ( angle );

			glVertex2f ( x + dx, y + dy );
		}

		glEnd ( );
		glColor3f ( 1.0f, 1.0f, 1.0f );
		glEnable ( GL_TEXTURE_2D );
		glDisable ( GL_BLEND );
	}

	Drawing g_Drawing;
}