#include "NoFlash.h"

#pragma warning (disable: 4244)
#pragma warning (disable: 4701)

namespace Functions
{
	enum color
	{
		RED, LIGHT_RED, GREEN, LIGHT_GREEN, BLUE, LIGHT_BLUE, AQUAMARINE, HELIOTROPE
	};

	void NoFlash::GetColor ( int Percentage )
	{
		noflash.color[0] = Percentage >= 50 ? 255 : g_Util.Interp ( 0, Percentage, 50, 0, 255 );
		noflash.color[1] = Percentage <= 50 ? 255 : g_Util.Interp ( 50, Percentage, 100, 255, 0 );
	}

	void NoFlash::SetFadeColor ( )
	{
		Engine::g_pScreenFade->fader = Files::g_IniRead.noflash.fade_color[0];
		Engine::g_pScreenFade->fadeg = Files::g_IniRead.noflash.fade_color[1];
		Engine::g_pScreenFade->fadeb = Files::g_IniRead.noflash.fade_color[2];
	}

	void NoFlash::SetFadeColorRandom ( float Flashed )
	{
		int Color;

		static bool SetColor = true;

		if ( Flashed && SetColor )
		{
			Color = Engine::g_Engine.pfnRandomLong ( 0, 7 );

			switch ( Color )
			{
			case RED:
				Engine::g_pScreenFade->fader = 255;
				Engine::g_pScreenFade->fadeg = 0;
				Engine::g_pScreenFade->fadeb = 0;

				break;
			case LIGHT_RED:
				Engine::g_pScreenFade->fader = 255;
				Engine::g_pScreenFade->fadeg = 100;
				Engine::g_pScreenFade->fadeb = 100;

				break;
			case GREEN:
				Engine::g_pScreenFade->fader = 0;
				Engine::g_pScreenFade->fadeg = 255;
				Engine::g_pScreenFade->fadeb = 0;

				break;
			case LIGHT_GREEN:
				Engine::g_pScreenFade->fader = 100;
				Engine::g_pScreenFade->fadeg = 255;
				Engine::g_pScreenFade->fadeb = 100;

				break;
			case BLUE:
				Engine::g_pScreenFade->fader = 0;
				Engine::g_pScreenFade->fadeg = 0;
				Engine::g_pScreenFade->fadeb = 255;

				break;
			case LIGHT_BLUE:
				Engine::g_pScreenFade->fader = 100;
				Engine::g_pScreenFade->fadeg = 100;
				Engine::g_pScreenFade->fadeb = 255;

				break;
			case AQUAMARINE:
				Engine::g_pScreenFade->fader = 127;
				Engine::g_pScreenFade->fadeg = 255;
				Engine::g_pScreenFade->fadeb = 212;

				break;
			case HELIOTROPE:
				Engine::g_pScreenFade->fader = 200;
				Engine::g_pScreenFade->fadeg = 90;
				Engine::g_pScreenFade->fadeb = 255;

				break;
			}

			SetColor = false;
		}

		if ( !Flashed )
		{
			SetColor = true;
		}
	}

	void NoFlash::PrintFlashed ( int Percentage )
	{
		float x = Engine::g_Screen.iWidth / 2;
		float y = Engine::g_Screen.iHeight / 6;

		Renderer::g_Font.Print ( ( int )x, ( int )y, noflash.color[0], noflash.color[1], 0, 255,
			Files::g_IniRead.noflash.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, FLASHED, Percentage );

		if ( Percentage > 80 )
		{
			Renderer::g_Font.Print ( ( int )x, ( int )y + 13, 255, 0, 0, 255,
				Files::g_IniRead.noflash.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, DONTSEE );
		}
	}

	void NoFlash::PrintFlashedBox ( int Percentage )
	{
		float x = Engine::g_Screen.iWidth / 2;
		float y = Engine::g_Screen.iHeight / 6.2f;

		Renderer::g_Drawing.DrawBox ( ( int )x - 101, ( int )y - 9, 202, 18, 1, 0, 0, 0, 255 );

		Renderer::g_Drawing.FillArea ( ( int )x - 100, ( int )y - 8, 200, 16, noflash.color[0], noflash.color[1], 0, 200 );

		Renderer::g_Font.Print ( ( int )x, ( int )y + 4, 255, 255, 255, 255, Files::g_IniRead.noflash.font_outline ?
			FL_CENTER | FL_OUTLINE : FL_CENTER, FLASHED, ( int )Percentage );

		if ( Percentage > 80 )
		{
			Renderer::g_Font.Print ( ( int )x, ( int )y + 23, 255, 0, 0,
				255, Files::g_IniRead.noflash.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, DONTSEE );
		}
	}

	void NoFlash::HUD_Redraw ( )
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

		SetFadeColorRandom ( Flashed );

		float Percentage = ( Flashed / 255 ) * 100;

		if ( Files::g_IniRead.noflash.show_percentage && Percentage >= 1 )
		{
			GetColor ( ( int )Percentage );

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

	NoFlash g_NoFlash;

	noflash_s noflash;
}