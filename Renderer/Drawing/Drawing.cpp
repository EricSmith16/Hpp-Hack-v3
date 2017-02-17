#include "Drawing.h"

namespace Renderer
{
	void _fastcall Drawing::FillArea ( float Pos_x, float Pos_y, float Width, float Height, BYTE Red, BYTE Green, BYTE Blue, BYTE Alpha )
	{
		if ( Engine::g_Offset.HLType != RENDERTYPE_HARDWARE )
		{
			Engine::g_Engine.pfnFillRGBA ( Pos_x, Pos_y, Width, Height, Red, Green, Blue, Alpha );
		}
		else
		{
			glPushMatrix ( );
			glLoadIdentity ( );
			glDisable ( GL_TEXTURE_2D );
			glEnable ( GL_BLEND );
			glBlendFunc ( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
			glColor4ub ( Red, Green, Blue, Alpha );
			glBegin ( GL_QUADS );
			glVertex2f ( Pos_x, Pos_y );
			glVertex2f ( Pos_x + Width, Pos_y );
			glVertex2f ( Pos_x + Width, Pos_y + Height );
			glVertex2f ( Pos_x, Pos_y + Height );
			glEnd ( );
			glDisable ( GL_BLEND );
			glEnable ( GL_TEXTURE_2D );
			glPopMatrix ( );
		}
	}

	void _fastcall Drawing::Box ( float Pos_x, float Pos_y, float Width, float Height, float LineWidth, BYTE Red, BYTE Green, BYTE Blue, BYTE Alpha )
	{
		FillArea ( Pos_x, Pos_y, Width, LineWidth, Red, Green, Blue, Alpha );
		FillArea ( Pos_x + Width - LineWidth, Pos_y + LineWidth, LineWidth, Height - LineWidth, Red, Green, Blue, Alpha );
		FillArea ( Pos_x, Pos_y + LineWidth, LineWidth, Height - LineWidth, Red, Green, Blue, Alpha );
		FillArea ( Pos_x + LineWidth, Pos_y + Height - LineWidth, Width - LineWidth * 2, LineWidth, Red, Green, Blue, Alpha );
	}

	void _fastcall Drawing::BoxOutLine ( float Pos_x, float Pos_y, float Width, float Height, float LineWidth, BYTE Red, BYTE Green, BYTE Blue, BYTE Alpha )
	{
		Box ( Pos_x, Pos_y, Width, Height, LineWidth, Red, Green, Blue, Alpha );
		Box ( Pos_x - 1, Pos_y - 1, Width + 2, Height + 2, 1, 0, 0, 0, Alpha );
		Box ( Pos_x + LineWidth, Pos_y + LineWidth, Width - LineWidth * 2, Height - LineWidth * 2, 1, 0, 0, 0, Alpha );
	}

	void _fastcall Drawing::Circle ( float Pos_x, float Pos_y, float Radius, int Amount, float LineWidth, BYTE Red, BYTE Green, BYTE Blue, BYTE Alpha )
	{
		glDisable ( GL_TEXTURE_2D );
		glEnable ( GL_BLEND );
		glBlendFunc ( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
		glColor4ub ( Red, Green, Blue, Alpha );
		glLineWidth ( LineWidth );
		glBegin ( GL_LINE_LOOP );

		for ( uint8 i = 0; i < Amount; ++i )
		{
			float Angle = 2 * 3.1415926 * float ( i ) / float ( Amount );

			float x = Radius * cosf ( Angle );
			float y = Radius * sinf ( Angle );

			glVertex2f ( Pos_x + x, Pos_y + y );
		}

		glEnd ( );
		glColor3f ( 1.0f, 1.0f, 1.0f );
		glEnable ( GL_TEXTURE_2D );
		glDisable ( GL_BLEND );
	}

	Drawing g_Drawing;
}