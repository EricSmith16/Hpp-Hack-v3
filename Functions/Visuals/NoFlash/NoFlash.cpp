#include "NoFlash.h"

namespace Functions
{
	namespace Visuals
	{
		NoFlash::NoFlash ( )
		{
			CurStateFlashed = 0;
			PrevStateFlashed = 0;

			FadeColor[0] = 0;
			FadeColor[1] = 0;
			FadeColor[2] = 0;
		}

		enum color
		{
			RED, LIGHT_RED, GREEN, LIGHT_GREEN, BLUE, LIGHT_BLUE,
			AQUAMARINE, HELIOTROPE, DARKPURPLEVOILET, LASERLEMON,
			BRIGHTGREEN, GREENLAWN, GREENYELLOWKRAYOLA, YELLOW
		};

		void NoFlash::GetColor ( int Percentage )
		{
			NoFlashColor[0] = Percentage >= 50 ? 255 : g_Util.Interp ( 0, Percentage, 50, 0, 255 );
			NoFlashColor[1] = Percentage <= 50 ? 255 : g_Util.Interp ( 50, Percentage, 100, 255, 0 );
		}

		void NoFlash::SetFadeColor ( )
		{
			Engine::g_pScreenFade->fader = g_Vars.noflash.fade_color[0];
			Engine::g_pScreenFade->fadeg = g_Vars.noflash.fade_color[1];
			Engine::g_pScreenFade->fadeb = g_Vars.noflash.fade_color[2];
		}

		void NoFlash::SetFadeColorRandom ( )
		{
			static bool SetColor = true;

			if ( CurStateFlashed && SetColor )
			{
				int Color = Engine::g_Engine.pfnRandomLong ( 0, 13 );

				switch ( Color )
				{
				case RED:
					FadeColor[0] = 255;
					FadeColor[1] = 0;
					FadeColor[2] = 0;

					break;

				case LIGHT_RED:
					FadeColor[0] = 255;
					FadeColor[1] = 100;
					FadeColor[2] = 100;

					break;

				case GREEN:
					FadeColor[0] = 0;
					FadeColor[1] = 255;
					FadeColor[2] = 0;

					break;

				case LIGHT_GREEN:
					FadeColor[0] = 100;
					FadeColor[1] = 255;
					FadeColor[2] = 100;

					break;

				case BLUE:
					FadeColor[0] = 0;
					FadeColor[1] = 0;
					FadeColor[2] = 255;

					break;

				case LIGHT_BLUE:
					FadeColor[0] = 100;
					FadeColor[1] = 100;
					FadeColor[2] = 255;

					break;

				case AQUAMARINE:
					FadeColor[0] = 127;
					FadeColor[1] = 255;
					FadeColor[2] = 212;

					break;

				case HELIOTROPE:
					FadeColor[0] = 200;
					FadeColor[1] = 90;
					FadeColor[2] = 255;

					break;

				case DARKPURPLEVOILET:
					FadeColor[0] = 102;
					FadeColor[1] = 0;
					FadeColor[2] = 153;

					break;

				case LASERLEMON:
					FadeColor[0] = 254;
					FadeColor[1] = 254;
					FadeColor[2] = 34;

					break;

				case BRIGHTGREEN:
					FadeColor[0] = 0;
					FadeColor[1] = 125;
					FadeColor[2] = 52;

					break;

				case GREENLAWN:
					FadeColor[0] = 124;
					FadeColor[1] = 252;
					FadeColor[2] = 0;

					break;

				case GREENYELLOWKRAYOLA:
					FadeColor[0] = 240;
					FadeColor[1] = 232;
					FadeColor[2] = 145;

					break;

				case YELLOW:
					FadeColor[0] = 255;
					FadeColor[1] = 255;
					FadeColor[2] = 0;

					break;
				}

				Engine::g_pScreenFade->fader = FadeColor[0];
				Engine::g_pScreenFade->fadeg = FadeColor[1];
				Engine::g_pScreenFade->fadeb = FadeColor[2];

				SetColor = false;
			}

			if ( CurStateFlashed == 255 && PrevStateFlashed == 255 )
			{
				Engine::g_pScreenFade->fader = FadeColor[0];
				Engine::g_pScreenFade->fadeg = FadeColor[1];
				Engine::g_pScreenFade->fadeb = FadeColor[2];
			}

			if ( !CurStateFlashed || PrevStateFlashed < CurStateFlashed )
			{
				SetColor = true;
			}
		}

		void NoFlash::PrintFlashed ( int Percentage )
		{
			Renderer::g_Font.Print ( int ( Engine::g_Screen.iWidth / 2 ), int ( Engine::g_Screen.iHeight / 6 ), NoFlashColor[0], NoFlashColor[1], 0,
				255, g_Vars.noflash.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, FLASHED, Percentage );

			if ( Percentage > 80 )
			{
				Renderer::g_Font.Print ( int ( Engine::g_Screen.iWidth / 2 ), int ( Engine::g_Screen.iHeight / 6 ) + 13, 255, 80, 80, 255,
					g_Vars.noflash.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, DONTSEE );
			}
		}

		void NoFlash::PrintFlashedBox ( int Percentage )
		{
			int PrintFlashedPos_x = int ( Engine::g_Screen.iWidth / 2 );
			int PrintFlashedPos_y = int ( Engine::g_Screen.iHeight / 6.2f );

			Renderer::g_Drawing.Box ( int ( PrintFlashedPos_x - 101 ), int ( PrintFlashedPos_y - 9 ), 202, 18, 1, 20, 20, 20, 225 );

			Renderer::g_Drawing.Fill ( int( PrintFlashedPos_x - 100 ), int ( PrintFlashedPos_y - 8 ), 200, 16, NoFlashColor[0], NoFlashColor[1], 0, 150 );

			Renderer::g_Font.Print ( int( PrintFlashedPos_x ), int( PrintFlashedPos_y + 4 ), 255, 255, 255, 255,
				g_Vars.noflash.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, FLASHED, Percentage );

			if ( Percentage > 80 )
			{
				Renderer::g_Font.Print ( PrintFlashedPos_x, PrintFlashedPos_y + 23, 255, 0, 0, 255,
					g_Vars.noflash.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, DONTSEE );
			}
		}

		void NoFlash::HUD_Redraw ( )
		{
			float FadeEnd;

			PrevStateFlashed = CurStateFlashed;

			if ( Engine::g_pScreenFade->fadeEnd > Engine::g_Engine.GetClientTime ( ) )
			{
				FadeEnd = Engine::g_pScreenFade->fadeEnd;

				if ( g_Vars.noflash.fade_limit > 255 )
				{
					Engine::g_pScreenFade->fadeEnd = 255;
				}
				else if ( Engine::g_pScreenFade->fadealpha > g_Vars.noflash.fade_limit )
				{
					Engine::g_pScreenFade->fadealpha = g_Vars.noflash.fade_limit;
				}
			}

			if ( FadeEnd > Engine::g_Engine.GetClientTime ( ) )
			{
				CurStateFlashed = ( FadeEnd - Engine::g_Engine.GetClientTime ( ) ) * Engine::g_pScreenFade->fadeSpeed;
			}
			else
			{
				CurStateFlashed = 0;
			}

			if ( CurStateFlashed > 255 )
			{
				CurStateFlashed = 255;
			}

			if ( CurStateFlashed < 0 )
			{
				CurStateFlashed = 0;
			}

			g_Vars.noflash.fade_color_random ? SetFadeColorRandom ( ) : SetFadeColor ( );

			int Percentage = ( CurStateFlashed / 255 ) * 100;

			if ( g_Vars.noflash.show_percentage && Percentage >= 1 )
			{
				GetColor ( Percentage );

				switch ( ( int )g_Vars.noflash.show_percentage )
				{
				case 1:
					PrintFlashed ( Percentage );

					break;
				case 2:
					PrintFlashedBox ( Percentage );

					break;
				}
			}
		}

		NoFlash g_NoFlash;
	}
}