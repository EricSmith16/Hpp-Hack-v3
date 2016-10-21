#include "NoFlash.h"

#pragma warning (disable: 4244)
#pragma warning (disable: 4701)

namespace Functions
{
	void NoFlash::PrintFlashed ( int Percentage )
	{
		BYTE color[2];

		color[0] = Percentage >= 50 ? 255 : g_Util.Interp ( 0, Percentage, 50, 0, 255 );
		color[1] = Percentage <= 50 ? 255 : g_Util.Interp ( 50, Percentage, 100, 255, 0 );

		float x = Engine::g_Screen.iWidth / 2;
		float y = Engine::g_Screen.iHeight / 6;

		Renderer::g_Font.Print ( ( int )x, ( int )y, color[0], color[1], 0, 255, 
			Files::g_IniRead.noflash.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, FLASHED, Percentage );

		if ( Percentage > 80 )
		{
			Renderer::g_Font.Print ( ( int )x, ( int )y + 10, 255, 0, 0, 255, 
				Files::g_IniRead.noflash.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, DONTSEE );
		}
	}

	void NoFlash::PrintFlashedBox ( int Percentage )
	{
		BYTE color[2];

		color[0] = Percentage >= 50 ? 255 : g_Util.Interp ( 0, Percentage, 50, 0, 255 );
		color[1] = Percentage <= 50 ? 255 : g_Util.Interp ( 50, Percentage, 100, 255, 0 );

		float x = Engine::g_Screen.iWidth / 2;
		float y = Engine::g_Screen.iHeight / 6.2f;

		Renderer::g_Drawing.DrawBox ( ( int )x - 101, ( int )y - 9, 202, 18, 1, 0, 0, 0, 255 );

		Renderer::g_Drawing.FillArea ( ( int )x - 100, ( int )y - 8, 200, 16, color[0], color[1], 0, 200 );

		Renderer::g_Font.Print ( ( int )x, ( int )y + 4, 255, 255, 255, 255, Files::g_IniRead.noflash.font_outline ?
			FL_CENTER | FL_OUTLINE : FL_CENTER, FLASHED, ( int )Percentage );

		if ( Percentage > 80 )
		{
			Renderer::g_Font.Print ( ( int )x, ( int )y + 20, 255, 0, 0,
				255, Files::g_IniRead.noflash.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, DONTSEE );
		}
	}

	void NoFlash::HUD_Redraw ( )
	{
		if ( Files::g_IniRead.noflash.fade_limit > 0 )
		{
			float FadeEnd, Flashed;

			if ( Engine::g_pScreenFade->fadeEnd > Engine::g_Engine.GetClientTime ( ) )
			{
				FadeEnd = Engine::g_pScreenFade->fadeEnd;

				if ( Files::g_IniRead.noflash.fade_limit > 255 )
				{
					Engine::g_pScreenFade->fadeEnd = 255;
				}
				else if ( Engine::g_pScreenFade->fadealpha > Files::g_IniRead.noflash.fade_limit )
				{
					Engine::g_pScreenFade->fadealpha = Files::g_IniRead.noflash.fade_limit;
				}
			}

			if ( FadeEnd > Engine::g_Engine.GetClientTime ( ) )
			{
				Flashed = ( FadeEnd - Engine::g_Engine.GetClientTime ( ) ) * Engine::g_pScreenFade->fadeSpeed;
			}
			else
			{
				Flashed = 0;
			}

			if ( Flashed > 255 )
			{
				Flashed = 255;
			}

			if ( Flashed < 0 )
			{
				Flashed = 0;
			}

			float Percentage = ( Flashed / 255 ) * 100;

			if ( Files::g_IniRead.noflash.show_percentage && Percentage >= 1 )
			{
				switch ( Files::g_IniRead.noflash.show_percentage )
				{
				case 1:
					PrintFlashed ( ( int )Percentage );

					break;
				case 2:
					PrintFlashedBox ( ( int )Percentage );

					break;
				}
			}
		}
	}

	NoFlash g_NoFlash;
}