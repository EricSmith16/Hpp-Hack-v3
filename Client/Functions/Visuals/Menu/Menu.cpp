#include "Menu.h"

namespace Functions
{
	namespace Visuals
	{
		Menu::Menu ( )
		{
			Visible = false;
			SubMenu = false;

			M_EntryPos = 0;
			M_EntrySize = 0;

			S_EntryPos = 0;
			S_EntrySize = 0;

			Clear ( );
		}

		enum MENU_ENTRY
		{
			MENU_SETTINGS, MAIN_MENU, ESP_MENU, ESP_COLORS_MENU, NOFLASH_MENU, SCREENINFO_MENU,
			CAMERA_MENU, SPEED_MENU, BHOP_MENU, GSTRAFE_MENU, JUMPBUG_MENU, EDGEBUG_MENU,
			STRAFE_HELPER_MENU, LOAD_SETTINGS_MENU, SAVE_SETTINGS_MENU
		};

		void _fastcall Menu::Initialize ( )
		{
			Clear ( );

			Add ( MENU_MENU, 255, 255, 255, false, true );

			Add ( MENU_MAIN, 255, 255, 255, false, true );

			if ( g_Vars.Function.ESP )
			{
				Add ( MENU_ESP, 255, 255, 255, false, true );
				Add ( MENU_ESP_COLORS, 255, 255, 255, false, true );
			}
			else
			{
				Add ( MENU_ESP, 100, 100, 100, false, false );
				Add ( MENU_ESP_COLORS, 100, 100, 100, false, false );
			}

			if ( g_Vars.Function.NoFlash )
			{
				Add ( MENU_NOFLASH, 255, 255, 255, false, true );
			}
			else
			{
				Add ( MENU_NOFLASH, 100, 100, 100, false, false );
			}

			if ( g_Vars.Function.ScreenInfo )
			{
				Add ( MENU_SCREENINFO, 255, 255, 255, false, true );
			}
			else
			{
				Add ( MENU_SCREENINFO, 100, 100, 100, false, false );
			}

			if ( g_Vars.Function.Camera )
			{
				Add ( MENU_CAMERA, 255, 255, 255, false, true );
			}
			else
			{
				Add ( MENU_CAMERA, 100, 100, 100, false, false );
			}

			if ( g_Vars.Function.Speed )
			{
				Add ( MENU_SPEED, 255, 255, 255, false, true );
			}
			else
			{
				Add ( MENU_SPEED, 100, 100, 100, false, false );
			}

			if ( g_Vars.Function.BunnyHop )
			{
				Add ( MENU_BHOP, 255, 255, 255, false, true );
			}
			else
			{
				Add ( MENU_BHOP, 100, 100, 100, false, false );
			}

			if ( g_Vars.Function.GroundStrafe )
			{
				Add ( MENU_GSTRAFE, 255, 255, 255, false, true );
			}
			else
			{
				Add ( MENU_GSTRAFE, 100, 100, 100, false, false );
			}

			if ( g_Vars.Function.JumpBug )
			{
				Add ( MENU_JUMPBUG, 255, 255, 255, false, true );
			}
			else
			{
				Add ( MENU_JUMPBUG, 100, 100, 100, false, false );
			}

			if ( g_Vars.Function.EdgeBug )
			{
				Add ( MENU_EDGEBUG, 255, 255, 255, false, true );
			}
			else
			{
				Add ( MENU_EDGEBUG, 100, 100, 100, false, false );
			}

			if ( g_Vars.Function.StrafeHelper )
			{
				Add ( MENU_STRAFE_HELPER, 255, 255, 255, true, true );
			}
			else
			{
				Add ( MENU_STRAFE_HELPER, 100, 100, 100, true, false );
			}

			Add ( MENU_LOAD_SETTINGS, 255, 255, 255, false, true );
			Add ( MENU_SAVE_SETTINGS, 255, 255, 255, false, true );

			if ( M_EntryPos == MENU_SETTINGS )
			{
				AddSub ( MENU_MENU_POS_X, &g_Vars.Menu.Pos_x, 1, Engine::g_Screen.iWidth, 1, false, false );
				AddSub ( MENU_MENU_POS_Y, &g_Vars.Menu.Pos_y, 1, Engine::g_Screen.iHeight, 1, false, true );

				AddSub ( MENU_MENU_BOX_HEIGHT, &g_Vars.Menu.BoxHeight, 13, 39, 1, false, false );
				AddSub ( MENU_MENU_BOX_WIDTH, &g_Vars.Menu.BoxWidth, 170, 220, 1, false, true );

				AddSub ( MENU_MENU_BOX_COLOR_R, &g_Vars.Menu.BoxColor[0], 0, 255, 1, false, false );
				AddSub ( MENU_MENU_BOX_COLOR_G, &g_Vars.Menu.BoxColor[1], 0, 255, 1, false, false );
				AddSub ( MENU_MENU_BOX_COLOR_B, &g_Vars.Menu.BoxColor[2], 0, 255, 1, false, false );
				AddSub ( MENU_MENU_BOX_COLOR_A, &g_Vars.Menu.BoxColor[3], 0, 255, 1, false, true );

				AddSub ( MENU_MENU_BOXFILL_COLOR_R, &g_Vars.Menu.BoxFillColor[0], 0, 255, 1, false, false );
				AddSub ( MENU_MENU_BOXFILL_COLOR_G, &g_Vars.Menu.BoxFillColor[1], 0, 255, 1, false, false );
				AddSub ( MENU_MENU_BOXFILL_COLOR_B, &g_Vars.Menu.BoxFillColor[2], 0, 255, 1, false, false );
				AddSub ( MENU_MENU_BOXFILL_COLOR_A, &g_Vars.Menu.BoxFillColor[3], 0, 255, 1, false, true );

				AddSub ( MENU_MENU_BOXSELECT_COLOR_R, &g_Vars.Menu.BoxSelectColor[0], 0, 255, 1, false, false );
				AddSub ( MENU_MENU_BOXSELECT_COLOR_G, &g_Vars.Menu.BoxSelectColor[1], 0, 255, 1, false, false );
				AddSub ( MENU_MENU_BOXSELECT_COLOR_B, &g_Vars.Menu.BoxSelectColor[2], 0, 255, 1, false, false );
				AddSub ( MENU_MENU_BOXSELECT_COLOR_A, &g_Vars.Menu.BoxSelectColor[3], 0, 255, 1, false, true );

				AddSub ( MENU_MENU_TEXT_COLOR_R, &g_Vars.Menu.TextColor[0], 0, 255, 1, false, false );
				AddSub ( MENU_MENU_TEXT_COLOR_G, &g_Vars.Menu.TextColor[1], 0, 255, 1, false, false );
				AddSub ( MENU_MENU_TEXT_COLOR_B, &g_Vars.Menu.TextColor[2], 0, 255, 1, false, false );
				AddSub ( MENU_MENU_TEXT_COLOR_A, &g_Vars.Menu.TextColor[3], 0, 255, 1, false, true );
			}

			if ( M_EntryPos == MAIN_MENU )
			{
				AddSub ( MENU_MAIN_PLAYER_VISIBLE_SCAN, &g_Vars.Main.PlayerVisibleScan, 0, 2, 1, false, false );
				AddSub ( MENU_MAIN_PLAYER_VALID_CHECK, &g_Vars.Main.PlayerValidCheck, 1, 2, 1, false, true );

				AddSub ( MENU_MAIN_FONT_OUTLINE_QUALITY, &g_Vars.Main.FontOutLineQuality, 1, 3, 1, false, true );

				AddSub ( MENU_MAIN_ANTISCREEN_ENABLE, &g_Vars.Main.AntiScreenEnable, 0, 1, 1, false, false );
				AddSub ( MENU_MAIN_ANTISCREEN_TIME, &g_Vars.Main.AntiScreenTimer, 1, 25, 1, false, false );
			}

			if ( M_EntryPos == ESP_MENU && g_Vars.Function.ESP )
			{
				AddSub ( MENU_ESP_ENABLE, &g_Vars.ESP.Enable, 0, 1, 1, false, true );

				AddSub ( MENU_ESP_PLAYER, &g_Vars.ESP.Player, 0, 2, 1, false, false );
				AddSub ( MENU_ESP_PLAYER_VISIBLE_ONLY, &g_Vars.ESP.PlayerVisibleOnly, 0, 1, 1, false, true );

				AddSub ( MENU_ESP_PLAYER_BOX, &g_Vars.ESP.PlayerBox, 0, 2, 1, false, false );
				AddSub ( MENU_ESP_PLAYER_BOX_LINEWIDTH, &g_Vars.ESP.PlayerBoxLineWidth, 1, 3, 1, false, false );
				AddSub ( MENU_ESP_PLAYER_NAME, &g_Vars.ESP.PlayerName, 0, 1, 1, false, false );
				AddSub ( MENU_ESP_PLAYER_WEAPON, &g_Vars.ESP.PlayerWeapon, 0, 1, 1, false, false );
				AddSub ( MENU_ESP_PLAYER_DISTANCE, &g_Vars.ESP.PlayerDistance, 0, 2, 1, false, false );
				AddSub ( MENU_ESP_PLAYER_BARREL, &g_Vars.ESP.PlayerBarrel, 0, 1, 1, false, true );

				AddSub ( MENU_ESP_WORLD_ITEMS, &g_Vars.ESP.WorldItems, 0, 1, 1, false, false );
				AddSub ( MENU_ESP_WORLD_NADES, &g_Vars.ESP.WorldNades, 0, 1, 1, false, true );

				AddSub ( MENU_ESP_C4TIMER, &g_Vars.ESP.C4Timer, 0, 2, 1, false, false );
				AddSub ( MENU_ESP_C4TIMER_VALUE, &g_Vars.ESP.C4TimerValue, 1, 100, 1, false, true );

				AddSub ( MENU_ESP_SOUND, &g_Vars.ESP.Sound, 0, 1, 1, false, false );
				AddSub ( MENU_ESP_SOUND_LINEWIDTH, &g_Vars.ESP.SoundLineWidth, 1, 3, 1, false, false );
				AddSub ( MENU_ESP_SOUND_FADE_TIME, &g_Vars.ESP.SoundFadeTime, 100, 5000, 100, false, true );

				AddSub ( MENU_ESP_FONT_OUTLINE, &g_Vars.ESP.FontOutLine, 0, 1, 1, false, false );
			}

			if ( M_EntryPos == ESP_COLORS_MENU && g_Vars.Function.ESP )
			{
				AddSub ( MENU_ESP_COLOR_T_HIDE_R, &g_Vars.ESP.ColorTHide[0], 0, 255, 1, false, false );
				AddSub ( MENU_ESP_COLOR_T_HIDE_G, &g_Vars.ESP.ColorTHide[1], 0, 255, 1, false, false );
				AddSub ( MENU_ESP_COLOR_T_HIDE_B, &g_Vars.ESP.ColorTHide[2], 0, 255, 1, false, true );

				AddSub ( MENU_ESP_COLOR_T_VIS_R, &g_Vars.ESP.ColorTVis[0], 0, 255, 1, false, false );
				AddSub ( MENU_ESP_COLOR_T_VIS_G, &g_Vars.ESP.ColorTVis[1], 0, 255, 1, false, false );
				AddSub ( MENU_ESP_COLOR_T_VIS_B, &g_Vars.ESP.ColorTVis[2], 0, 255, 1, false, true );

				AddSub ( MENU_ESP_COLOR_CT_HIDE_R, &g_Vars.ESP.ColorCTHide[0], 0, 255, 1, false, false );
				AddSub ( MENU_ESP_COLOR_CT_HIDE_G, &g_Vars.ESP.ColorCTHide[1], 0, 255, 1, false, false );
				AddSub ( MENU_ESP_COLOR_CT_HIDE_B, &g_Vars.ESP.ColorCTHide[2], 0, 255, 1, false, true );

				AddSub ( MENU_ESP_COLOR_CT_VIS_R, &g_Vars.ESP.ColorCTVis[0], 0, 255, 1, false, false );
				AddSub ( MENU_ESP_COLOR_CT_VIS_G, &g_Vars.ESP.ColorCTVis[1], 0, 255, 1, false, false );
				AddSub ( MENU_ESP_COLOR_CT_VIS_B, &g_Vars.ESP.ColorCTVis[2], 0, 255, 1, false, true );

				AddSub ( MENU_ESP_SOUND_COLOR_R, &g_Vars.ESP.SoundColor[0], 0, 255, 1, false, false );
				AddSub ( MENU_ESP_SOUND_COLOR_G, &g_Vars.ESP.SoundColor[1], 0, 255, 1, false, false );
				AddSub ( MENU_ESP_SOUND_COLOR_B, &g_Vars.ESP.SoundColor[2], 0, 255, 1, false, true );

				AddSub ( MENU_ESP_FONT_COLOR_R, &g_Vars.ESP.FontColor[0], 0, 255, 1, false, false );
				AddSub ( MENU_ESP_FONT_COLOR_G, &g_Vars.ESP.FontColor[1], 0, 255, 1, false, false );
				AddSub ( MENU_ESP_FONT_COLOR_B, &g_Vars.ESP.FontColor[2], 0, 255, 1, false, false );
			}

			if ( M_EntryPos == NOFLASH_MENU && g_Vars.Function.NoFlash )
			{
				AddSub ( MENU_NOFLASH_ENABLE, &g_Vars.NoFlash.Enable, 0, 1, 1, false, true );

				AddSub ( MENU_NOFLASH_FADE_LIMIT, &g_Vars.NoFlash.FadeLimit, 0, 255, 1, false, true );

				AddSub ( MENU_NOFLASH_FADE_COLOR_R, &g_Vars.NoFlash.FadeColor[0], 0, 255, 1, false, false );
				AddSub ( MENU_NOFLASH_FADE_COLOR_G, &g_Vars.NoFlash.FadeColor[1], 0, 255, 1, false, false );
				AddSub ( MENU_NOFLASH_FADE_COLOR_B, &g_Vars.NoFlash.FadeColor[2], 0, 255, 1, false, false );
				AddSub ( MENU_NOFLASH_FADE_COLOR_RANDOM, &g_Vars.NoFlash.FadeColorRandom, 0, 1, 1, false, true );

				AddSub ( MENU_NOFLASH_SHOWPERCENTAGE, &g_Vars.NoFlash.ShowPercentage, 0, 2, 1, false, true );

				AddSub ( MENU_NOFLASH_FONT_OUTLINE, &g_Vars.NoFlash.FontOutLine, 0, 1, 1, false, false );
			}

			if ( M_EntryPos == SCREENINFO_MENU && g_Vars.Function.ScreenInfo )
			{
				AddSub ( MENU_SCREENINFO_ENABLE, &g_Vars.ScreenInfo.Enable, 0, 1, 1, false, true );

				AddSub ( MENU_SCREENINFO_FPS, &g_Vars.ScreenInfo.FPS, 0, 1, 1, false, false );
				AddSub ( MENU_SCREENINFO_COPYRIGHT, &g_Vars.ScreenInfo.CopyRight, 0, 1, 1, false, false );
				AddSub ( MENU_SCREENINFO_TIME, &g_Vars.ScreenInfo.Time, 0, 1, 1, false, false );
				AddSub ( MENU_SCREENINFO_SHOWKEYS, &g_Vars.ScreenInfo.ShowKeys, 0, 1, 1, false, false );
				AddSub ( MENU_SCREENINFO_KREEDZ, &g_Vars.ScreenInfo.Kreedz, 0, 1, 1, false, true );

				AddSub ( MENU_SCREENINFO_FONT_COLOR_R, &g_Vars.ScreenInfo.FontColor[0], 0, 255, 1, false, false );
				AddSub ( MENU_SCREENINFO_FONT_COLOR_G, &g_Vars.ScreenInfo.FontColor[1], 0, 255, 1, false, false );
				AddSub ( MENU_SCREENINFO_FONT_COLOR_B, &g_Vars.ScreenInfo.FontColor[2], 0, 255, 1, false, true );

				AddSub ( MENU_SCREENINFO_FONT_OUTLINE, &g_Vars.ScreenInfo.FontOutLine, 0, 1, 1, false, false );
			}

			if ( M_EntryPos == CAMERA_MENU && g_Vars.Function.Camera )
			{
				AddSub ( MENU_THIRDPERSON_ENABLE, &g_Vars.Camera.ThirdPersonEnable, 0, 1, 1, false, false );
				AddSub ( MENU_THIRDPERSON_SIDE, &g_Vars.Camera.ThirdPersonSide, -100, 100, 1, false, false );
				AddSub ( MENU_THIRDPERSON_UP, &g_Vars.Camera.ThirdPersonUp, -100, 100, 1, false, false );
				AddSub ( MENU_THIRDPERSON_BACK, &g_Vars.Camera.ThirdPersonBack, 0, 500, 1, false, true );

				AddSub ( MENU_FREELOOK_ENABLE, &g_Vars.Camera.FreeLookEnable, 0, 1, 1, false, false );
				AddSub ( MENU_FREELOOK_SPEED, &g_Vars.Camera.FreeLookSpeed, 0, 1000, 1, false, true );

				AddSub ( MENU_SPECTATOR_ENABLE, &g_Vars.Camera.SpectatorEnable, 0, 1, 1, false, false );
				AddSub ( MENU_SPECTATOR_ID, &g_Vars.Camera.SpectatorID, 0, 32, 1, false, false );
			}

			if ( M_EntryPos == SPEED_MENU && g_Vars.Function.Speed )
			{
				AddSub ( MENU_SPEED_VALUE, &g_Vars.Speed.Value, 0.1f, 1000, 0.1f, true, false );
				AddSub ( MENU_SPEED_ENGINE_VALUE, &g_Vars.Speed.EngineValue, -255, 255, 1, false, true );

				AddSub ( MENU_SPEED_TYPE, &g_Vars.Speed.SpeedType, 1, 2, 1, false, true );

				if ( g_Vars.Speed.SpeedType == 1 )
				{
					if ( g_Vars.Speed.Boost < 1.1f )
					{
						g_Vars.Speed.Boost = 1.1f;
					}

					AddSub ( MENU_SPEED_BOOST, &g_Vars.Speed.Boost, 1.1f, 1000, 0.1f, true, false );
				}
				else if ( g_Vars.Speed.SpeedType == 2 )
				{
					if ( g_Vars.Speed.Boost > 255 )
					{
						g_Vars.Speed.Boost = 255;
					}

					AddSub ( MENU_SPEED_BOOST, &g_Vars.Speed.Boost, 1, 255, 1, false, false );
				}

				if ( g_Vars.Speed.SpeedType == 1 )
				{
					if ( g_Vars.Speed.SlowMotion < 0 )
					{
						g_Vars.Speed.SlowMotion = 0.1f;
					}

					AddSub ( MENU_SPEED_SLOWMO, &g_Vars.Speed.SlowMotion, 0.1f, 0.9f, 0.1f, true, false );
				}
				else if ( g_Vars.Speed.SpeedType == 2 )
				{
					if ( g_Vars.Speed.SlowMotion >= 0 )
					{
						g_Vars.Speed.SlowMotion = -1;
					}

					AddSub ( MENU_SPEED_SLOWMO, &g_Vars.Speed.SlowMotion, -255, -1, 1, false, false );
				}
			}

			if ( M_EntryPos == BHOP_MENU && g_Vars.Function.BunnyHop )
			{
				AddSub ( MENU_BHOP_SCROLL_EMULATION, &g_Vars.BHop.ScrollEmulation, 0, 1, 1, false, false );
				AddSub ( MENU_BHOP_SCROLL_DIRECTION, &g_Vars.BHop.ScrollDirection, 1000, 1001, 1, false, true );

				if ( g_Vars.BHop.Distance[0] > g_Vars.BHop.Distance[1] )
				{
					g_Vars.BHop.Distance[0] = g_Vars.BHop.Distance[1];
				}

				if ( g_Vars.BHop.Distance[1] < g_Vars.BHop.Distance[0] )
				{
					g_Vars.BHop.Distance[1] = g_Vars.BHop.Distance[0];
				}

				AddSub ( MENU_BHOP_DISTANCE_MIN, &g_Vars.BHop.Distance[0], 0, 50, 0.1f, true, false );
				AddSub ( MENU_BHOP_DISTANCE_MAX, &g_Vars.BHop.Distance[1], 0, 50, 0.1f, true, true );

				AddSub ( MENU_BHOP_NOSLOWDOWN, &g_Vars.BHop.NoSlowDown, 0, 1, 1, false, true );

				AddSub ( MENU_BHOP_ONLADDER, &g_Vars.BHop.OnLadder, 0, 1, 1, false, true );

				AddSub ( MENU_BHOP_STANDUP_AUTO, &g_Vars.BHop.StandUpAuto, 0, 1, 1, false, false );
				AddSub ( MENU_BHOP_STANDUP_FALLVELOCITY, &g_Vars.BHop.StandUpFallVelocity, 0, 250, 0.1f, true, false );
			}

			if ( M_EntryPos == GSTRAFE_MENU && g_Vars.Function.GroundStrafe )
			{
				AddSub ( MENU_GSTRAFE_SCROLL_EMULATION, &g_Vars.GStrafe.ScrollEmulation, 0, 1, 1, false, false );
				AddSub ( MENU_GSTRAFE_SCROLL_DIRECTION, &g_Vars.GStrafe.ScrollDirection, 1000, 1001, 1, false, true );

				if ( g_Vars.GStrafe.Distance[0] > g_Vars.GStrafe.Distance[1] )
				{
					g_Vars.GStrafe.Distance[0] = g_Vars.GStrafe.Distance[1];
				}

				AddSub ( MENU_GSTRAFE_DISTANCE_MIN, &g_Vars.GStrafe.Distance[0], 0, 50, 0.1f, true, false );
				AddSub ( MENU_GSTRAFE_DISTANCE_MAX, &g_Vars.GStrafe.Distance[1], 0, 50, 0.1f, true, true );

				if ( g_Vars.GStrafe.Count[0] > g_Vars.GStrafe.Count[1] )
				{
					g_Vars.GStrafe.Count[0] = g_Vars.GStrafe.Count[1];
				}

				AddSub ( MENU_GSTRAFE_COUNT_MIN, &g_Vars.GStrafe.Count[0], 1, 50, 1, false, false );
				AddSub ( MENU_GSTRAFE_COUNT_MAX, &g_Vars.GStrafe.Count[1], 1, 50, 1, false, true );

				AddSub ( MENU_GSTARFE_FALLRUN, &g_Vars.GStrafe.FallRun, 0, 1, 1, false, true );

				AddSub ( MENU_GSTARFE_SLOWDOWN_SCALE, &g_Vars.GStrafe.SlowDownScale, 0, 5, 0.1f, true, true );

				AddSub ( MENU_GSTARFE_STANDUP_VELOCITY, &g_Vars.GStrafe.StandUpFallVelocity, 0, 250, 0.1f, true, false );
			}

			if ( M_EntryPos == JUMPBUG_MENU && g_Vars.Function.JumpBug )
			{
				AddSub ( MENU_JUMPBUG_AUTO, &g_Vars.JumpBug.AutoEnable, 0, 1, 1, false, false );
				AddSub ( MENU_JUMPBUG_AUTO_DAMAGE, &g_Vars.JumpBug.AutoDamage, 1, 100, 1, false, false );
				AddSub ( MENU_JUMPBUG_AUTO_PERCENTAGE, &g_Vars.JumpBug.AutoPercentage, 1, 100, 1, false, true );

				AddSub ( MENU_JUMPBUG_SLOWDOWN, &g_Vars.JumpBug.SlowDown, 0, 1, 1, false, true );

				AddSub ( MENU_JUMPBUG_SLOWMOTION, &g_Vars.JumpBug.SlowMotion, 0, 1, 1, false, false );
			}

			if ( M_EntryPos == EDGEBUG_MENU && g_Vars.Function.EdgeBug )
			{
				AddSub ( MENU_EDGEBUG_AUTO, &g_Vars.EdgeBug.AutoEnable, 0, 1, 1, false, false );
				AddSub ( MENU_EDGEBUG_AUTO_DAMAGE, &g_Vars.EdgeBug.AutoDamage, 1, 100, 1, false, true );

				AddSub ( MENU_EDGEBUG_SPEED, &g_Vars.EdgeBug.Speed, 0, 255, 1, false, false );
				AddSub ( MENU_EDGEBUG_SPEED_FINAL, &g_Vars.EdgeBug.SpeedFinal, -10, 0, 1, false, false );
				AddSub ( MENU_EDGEBUG_SPEED_OFFSET, &g_Vars.EdgeBug.SpeedOffset, -10, 0, 1, false, false );
			}

			if ( M_EntryPos == STRAFE_HELPER_MENU && g_Vars.Function.StrafeHelper )
			{
				AddSub ( MENU_STRAFEHELPER_ACTIVE, &g_Vars.StrafeHelper.Active, 0, 1, 1, false, true );

				AddSub ( MENU_STRAFEHELPER_MODE, &g_Vars.StrafeHelper.Mode, 0, 6, 1, false, false );
				AddSub ( MENU_STRAFEHELPER_TYPE, &g_Vars.StrafeHelper.Type, 1, 2, 1, false, true );

				AddSub ( MENU_STRAFEHELPER_CORRECT_SPEED, &g_Vars.StrafeHelper.CorrectSpeed, 0, 5, 0.1f, true, false );
				AddSub ( MENU_STRAFEHELPER_CORRECT_LIMIT, &g_Vars.StrafeHelper.CorrectLimit, 0, 45, 0.1f, true, false );
				AddSub ( MENU_STRAFEHELPER_CORRECT_SMOTH, &g_Vars.StrafeHelper.CorrectLimitSmooth, 0, 10, 0.1f, true, true );

				AddSub ( MENU_STRAFEHELPER_KEY_EMULATION, &g_Vars.StrafeHelper.KeyEmulation, 0, 1, 1, false, true );

				AddSub ( MENU_STRAFEHELPER_BOOST, &g_Vars.StrafeHelper.Boost, 0, 50, 0.1f, true, true );

				AddSub ( MENU_STRAFEHELPER_MIN_SPEED, &g_Vars.StrafeHelper.MinimalSpeed, 0, 500, 1, false, true );

				AddSub ( MENU_STRAFEHELPER_DIRECTION, &g_Vars.StrafeHelper.Direction, 1, 4, 1, false, false );
				AddSub ( MENU_STRAFEHELPER_DIR_AUTO, &g_Vars.StrafeHelper.DirectionAuto, 0, 2, 1, false, true );

				AddSub ( MENU_STRAFEHELPER_STRAFE_LIMIT, &g_Vars.StrafeHelper.StrafeLimit, 0, 100, 1, false, false );
			}
		}

		void _fastcall Menu::Draw ( int Pos_x, int Pos_y )
		{
			if ( !Visible )
			{
				g_Util.MemorySet ( SubmEntry, sizeof ( SubmEntry ), 0 );
				g_Util.MemorySet ( MenuEntry, sizeof ( MenuEntry ), 0 );

				return;
			}

			Initialize ( );

			Renderer::g_Drawing.Box ( Pos_x, Pos_y, g_Vars.Menu.BoxWidth, g_Vars.Menu.BoxHeight, 1, g_Vars.Menu.BoxColor[0],
				g_Vars.Menu.BoxColor[1], g_Vars.Menu.BoxColor[2], g_Vars.Menu.BoxColor[3] );

			short HeadPos_y = Pos_y;

			short HeadFillWidth = g_Vars.Menu.BoxWidth - 2;
			short HeadFillHeight = g_Vars.Menu.BoxHeight - 2;

			short HeadMenuFillPos_x = Pos_x + 1;
			short HeadMenuFillPos_y = Pos_y + 1;

			Renderer::g_Drawing.FillArea ( HeadMenuFillPos_x, HeadMenuFillPos_y, HeadFillWidth, HeadFillHeight,
				g_Vars.Menu.BoxFillColor[0], g_Vars.Menu.BoxFillColor[1], g_Vars.Menu.BoxFillColor[2], g_Vars.Menu.BoxFillColor[3] );

			short HeadMenuTextPos_x = HeadMenuFillPos_x + ( HeadFillWidth / 2 );
			short HeadMenuTextPos_y = HeadMenuFillPos_y + ( HeadFillHeight / 2 ) + 4;

			Renderer::g_Verdana.Print ( HeadMenuTextPos_x, HeadMenuTextPos_y, g_Vars.Menu.TextColor[0], g_Vars.Menu.TextColor[1],
				g_Vars.Menu.TextColor[2], g_Vars.Menu.TextColor[3], FL_OUTLINE | FL_CENTER, HPP_MESSAGE );

			Pos_y += g_Vars.Menu.BoxHeight + 2;

			short MenuFillPos_x = Pos_x + 1;
			short MenuFillPos_y;

			short MenuTextPos_x = MenuFillPos_x + 6;
			short MenuTextPos_y;

			for ( short i = 0; i < M_EntrySize; ++i )
			{
				MenuFillPos_y = Pos_y + 1;

				MenuTextPos_y = MenuFillPos_y + ( HeadFillHeight / 2 ) + 4;

				Renderer::g_Drawing.Box ( Pos_x, Pos_y, g_Vars.Menu.BoxWidth, g_Vars.Menu.BoxHeight, 1,
					g_Vars.Menu.BoxColor[0], g_Vars.Menu.BoxColor[1], g_Vars.Menu.BoxColor[2], g_Vars.Menu.BoxColor[3] );

				Renderer::g_Drawing.FillArea ( MenuFillPos_x, MenuFillPos_y, HeadFillWidth, HeadFillHeight,
					g_Vars.Menu.BoxFillColor[0], g_Vars.Menu.BoxFillColor[1], g_Vars.Menu.BoxFillColor[2], g_Vars.Menu.BoxFillColor[3] );

				if ( i == M_EntryPos )
				{
					if ( !SubMenu )
					{
						Renderer::g_Drawing.FillArea ( MenuFillPos_x, MenuFillPos_y, HeadFillWidth, HeadFillHeight, g_Vars.Menu.BoxSelectColor[0], 
							g_Vars.Menu.BoxSelectColor[1], g_Vars.Menu.BoxSelectColor[2], g_Vars.Menu.BoxSelectColor[3] );

						Renderer::g_Drawing.FillArea ( MenuFillPos_x, MenuFillPos_y, 2, HeadFillHeight,
							g_Vars.Menu.BoxSelectColor[0], g_Vars.Menu.BoxSelectColor[1], g_Vars.Menu.BoxSelectColor[2], 200 );
					}
					else
					{
						Renderer::g_Drawing.FillArea ( MenuFillPos_x, MenuFillPos_y, 2, HeadFillHeight, g_Vars.Menu.BoxSelectColor[0], 
							g_Vars.Menu.BoxSelectColor[1], g_Vars.Menu.BoxSelectColor[2], 200 );
					}
				}

				for ( BYTE a = 0; a < sizeof ( M_Entry::Name ); ++a )
				{
					MenuEntry[i].Name[a] ^= MENU_ENTRY_KEY;
				}

				Renderer::g_Verdana.Print ( MenuTextPos_x, MenuTextPos_y, MenuEntry[i].Color[0],
					MenuEntry[i].Color[1], MenuEntry[i].Color[2], 255, FL_OUTLINE, MenuEntry[i].Name );

				Pos_y += g_Vars.Menu.BoxHeight + 1;

				if ( MenuEntry[i].Space )
				{
					Pos_y += g_Vars.Menu.BoxHeight + 1;
				}
			}

			Pos_x += g_Vars.Menu.BoxWidth + 1;

			short HeadSubMenuFillPos_x = Pos_x + 1;
			short HeadSubMenuFillPos_y = Pos_y + 1;

			if ( SubMenu )
			{
				short SubMenuBoxPos_y = HeadPos_y + g_Vars.Menu.BoxHeight + 2;

				short SubMenuFillPos_x = Pos_x + 1;
				short SubMenuFillPos_y = SubMenuBoxPos_y + 1;

				short SubMenuTextPos_x = SubMenuFillPos_x + 6;
				short SubMenuTextPos_y = SubMenuFillPos_y + ( HeadFillHeight / 2 ) + 4;

				for ( BYTE i = 0; i < S_EntrySize; ++i )
				{
					Renderer::g_Drawing.Box ( Pos_x, SubMenuBoxPos_y, g_Vars.Menu.BoxWidth, g_Vars.Menu.BoxHeight, 1,
						g_Vars.Menu.BoxColor[0], g_Vars.Menu.BoxColor[1], g_Vars.Menu.BoxColor[2], g_Vars.Menu.BoxColor[3] );

					Renderer::g_Drawing.FillArea ( SubMenuFillPos_x, SubMenuFillPos_y, HeadFillWidth, HeadFillHeight, g_Vars.Menu.BoxFillColor[0], 
						g_Vars.Menu.BoxFillColor[1], g_Vars.Menu.BoxFillColor[2], g_Vars.Menu.BoxFillColor[3] );

					if ( i == S_EntryPos )
					{
						Renderer::g_Drawing.FillArea ( SubMenuFillPos_x, SubMenuFillPos_y, HeadFillWidth, HeadFillHeight, g_Vars.Menu.BoxSelectColor[0], 
							g_Vars.Menu.BoxSelectColor[1], g_Vars.Menu.BoxSelectColor[2], g_Vars.Menu.BoxSelectColor[3] );

						Renderer::g_Drawing.FillArea ( SubMenuFillPos_x, SubMenuFillPos_y, 2, HeadFillHeight,
							g_Vars.Menu.BoxSelectColor[0], g_Vars.Menu.BoxSelectColor[1], g_Vars.Menu.BoxSelectColor[2], 200 );
					}

					for ( BYTE a = 0; a < 32; ++a )
					{
						SubmEntry[i].Name[a] ^= SUBM_ENTRY_KEY;
					}

					Renderer::g_Verdana.Print ( SubMenuTextPos_x, SubMenuTextPos_y, g_Vars.Menu.TextColor[0], g_Vars.Menu.TextColor[1],
						g_Vars.Menu.TextColor[2], g_Vars.Menu.TextColor[3], FL_OUTLINE, SubmEntry[i].Name );

					if ( !SubmEntry[i].Min && SubmEntry[i].Max < 3 )
					{
						if ( SubmEntry[i].Max == 1 )
						{
							*SubmEntry[i].Value ?
								Renderer::g_Verdana.Print ( SubMenuTextPos_x + ( g_Vars.Menu.BoxWidth - 40 ),
									SubMenuTextPos_y, 80, 255, 80, 255, FL_OUTLINE, ON ) :

								Renderer::g_Verdana.Print ( SubMenuTextPos_x + ( g_Vars.Menu.BoxWidth - 40 ),
									SubMenuTextPos_y, 255, 80, 80, 255, FL_OUTLINE, OFF );
						}
						else if ( SubmEntry[i].Max == 2 )
						{
							*SubmEntry[i].Value ?
								Renderer::g_Verdana.Print ( SubMenuTextPos_x + ( g_Vars.Menu.BoxWidth - 40 ),
									SubMenuTextPos_y, 80, 255, 80, 255, FL_OUTLINE, "%d", ( int )*SubmEntry[i].Value ) :

								Renderer::g_Verdana.Print ( SubMenuTextPos_x + ( g_Vars.Menu.BoxWidth - 40 ),
									SubMenuTextPos_y, 255, 80, 80, 255, FL_OUTLINE, OFF );
						}
					}
					else if ( SubmEntry[i].Min == 1000 && SubmEntry[i].Max == 1001 )
					{
						if ( *SubmEntry[i].Value == 1000 )
						{
							Renderer::g_Verdana.Print ( SubMenuTextPos_x + ( g_Vars.Menu.BoxWidth - 40 ),
								SubMenuTextPos_y, 255, 255, 255, 255, FL_OUTLINE, DOWN );
						}
						else if ( *SubmEntry[i].Value == 1001 )
						{
							Renderer::g_Verdana.Print ( SubMenuTextPos_x + ( g_Vars.Menu.BoxWidth - 40 ),
								SubMenuTextPos_y, 255, 255, 255, 255, FL_OUTLINE, UP );
						}
					}
					else
					{
						if ( SubmEntry[i].Float )
						{
							Renderer::g_Verdana.Print ( SubMenuTextPos_x + ( g_Vars.Menu.BoxWidth - 40 ), SubMenuTextPos_y,
								255, 255, 255, 255, FL_OUTLINE, "%.1f", *SubmEntry[i].Value );
						}
						else
						{
							Renderer::g_Verdana.Print ( SubMenuTextPos_x + ( g_Vars.Menu.BoxWidth - 40 ), SubMenuTextPos_y, 255,
								255, 255, 255, FL_OUTLINE, "%d", ( int )*SubmEntry[i].Value );
						}
					}

					SubMenuBoxPos_y += g_Vars.Menu.BoxHeight + 1;
					SubMenuFillPos_y += g_Vars.Menu.BoxHeight + 1;
					SubMenuTextPos_y += g_Vars.Menu.BoxHeight + 1;

					if ( SubmEntry[i].Space )
					{
						SubMenuBoxPos_y += g_Vars.Menu.BoxHeight + 1;
						SubMenuFillPos_y += g_Vars.Menu.BoxHeight + 1;
						SubMenuTextPos_y += g_Vars.Menu.BoxHeight + 1;
					}
				}
			}
		}

		void Menu::Add ( char* Name, BYTE Red, BYTE Green, BYTE Blue, bool Space, bool Active )
		{
			g_Util.MemorySet ( MenuEntry[M_EntrySize].Name, sizeof ( M_Entry::Name ), 0 );

			lstrcpy ( MenuEntry[M_EntrySize].Name, Name );

			for ( BYTE i = 0; i < 32; ++i )
			{
				MenuEntry[M_EntrySize].Name[i] ^= MENU_ENTRY_KEY;
			}

			MenuEntry[M_EntrySize].Color[0] = Red;
			MenuEntry[M_EntrySize].Color[1] = Green;
			MenuEntry[M_EntrySize].Color[2] = Blue;

			MenuEntry[M_EntrySize].Space = Space;
			MenuEntry[M_EntrySize].Active = Active;

			++M_EntrySize;
		}

		void Menu::AddSub ( char* Name, float* Value, float Min, float Max, float Step, bool Float, bool Space )
		{
			g_Util.MemorySet ( SubmEntry[S_EntrySize].Name, sizeof ( S_Entry::Name ), 0 );

			lstrcpy ( SubmEntry[S_EntrySize].Name, Name );

			for ( BYTE i = 0; i < 32; ++i )
			{
				SubmEntry[S_EntrySize].Name[i] ^= SUBM_ENTRY_KEY;
			}

			SubmEntry[S_EntrySize].Value = Value;
			SubmEntry[S_EntrySize].Min = Min;
			SubmEntry[S_EntrySize].Max = Max;
			SubmEntry[S_EntrySize].Step = Step;
			SubmEntry[S_EntrySize].Float = Float;
			SubmEntry[S_EntrySize].Space = Space;

			++S_EntrySize;
		}

		void Menu::Clear ( )
		{
			for ( BYTE i = 0; i < M_EntrySize; ++i )
			{
				g_Util.MemorySet ( &MenuEntry[i].Name, sizeof ( M_Entry::Name ), 0 );
			}

			for ( BYTE i = 0; i < S_EntrySize; ++i )
			{
				g_Util.MemorySet ( &MenuEntry[i].Name, sizeof ( S_Entry::Name ), 0 );

				SubmEntry[i].Value = 0;
				SubmEntry[i].Min = 0;
				SubmEntry[i].Max = 0;
				SubmEntry[i].Step = 0;
				SubmEntry[i].Float = false;
			}

			M_EntrySize = 0;
			S_EntrySize = 0;
		}

		void _fastcall Menu::HUD_Key_Event ( int keynum )
		{
			if ( keynum == g_Vars.Menu.Key )
			{
				Visible = !Visible;
			}

			if ( !Visible )
			{
				return;
			}

			if ( ( keynum == K_ENTER || keynum == K_RIGHTARROW ) && !SubMenu )
			{
				switch ( M_EntryPos )
				{
				case LOAD_SETTINGS_MENU:
					if ( keynum != K_RIGHTARROW )
					{
						Initial::g_Init.ReloadSettings ( );

						if ( g_Vars.Main.Launguage )
						{
							g_Util.ConsolePrintColor ( 100, 255, 200, HPP );
							g_Util.ConsolePrintColor ( 200, 255, 200, SETTINGS_RELOADED_ENG );
						}
						else
						{
							g_Util.ConsolePrintColor ( 100, 255, 200, HPP );
							g_Util.ConsolePrintColor ( 200, 255, 200, SETTINGS_RELOADED_RUS );
						}

						Engine::g_Engine.pfnPlaySoundByName ( "vox/loading.wav", 1 );
					}

					break;

				case SAVE_SETTINGS_MENU:
					if ( keynum != K_RIGHTARROW )
					{
						Initial::g_Init.SaveSettings ( );

						if ( g_Vars.Main.Launguage )
						{
							g_Util.ConsolePrintColor ( 100, 255, 200, HPP );
							g_Util.ConsolePrintColor ( 200, 255, 200, SETTINGS_SAVED_ENG );
						}
						else
						{
							g_Util.ConsolePrintColor ( 100, 255, 200, HPP );
							g_Util.ConsolePrintColor ( 200, 255, 200, SETTINGS_SAVED_RUS );
						}

						Engine::g_Engine.pfnPlaySoundByName ( "vox/save.wav", 1 );
					}

					break;

				default:
					if ( MenuEntry[M_EntryPos].Active )
					{
						S_EntryPos = 0;

						SubMenu = true;
					}

					break;
				}
			}
			else if ( keynum == K_BACKSPACE && !SubMenu )
			{
				Visible = false;
			}
			else if ( keynum == K_BACKSPACE && SubMenu )
			{
				SubMenu = false;
			}
			else if ( keynum == K_UPARROW && !SubMenu )
			{
				if ( M_EntryPos > 0 )
				{
					--M_EntryPos;
				}
			}
			else if ( keynum == K_DOWNARROW && !SubMenu )
			{
				if ( M_EntryPos < ( M_EntrySize - 1 ) )
				{
					++M_EntryPos;
				}
			}
			else if ( keynum == K_UPARROW && SubMenu )
			{
				if ( S_EntryPos > 0 )
				{
					--S_EntryPos;
				}
				else
				{
					SubMenu = false;
				}
			}
			else if ( keynum == K_DOWNARROW && SubMenu )
			{
				if ( S_EntryPos < ( S_EntrySize - 1 ) )
				{
					++S_EntryPos;
				}
			}
			else if ( keynum == K_LEFTARROW && SubMenu )
			{
				*SubmEntry[S_EntryPos].Value -= SubmEntry[S_EntryPos].Step;

				if ( *SubmEntry[S_EntryPos].Value < SubmEntry[S_EntryPos].Min )
				{
					*SubmEntry[S_EntryPos].Value = SubmEntry[S_EntryPos].Min;
				}
			}
			else if ( keynum == K_RIGHTARROW && SubMenu )
			{
				*SubmEntry[S_EntryPos].Value += SubmEntry[S_EntryPos].Step;

				if ( *SubmEntry[S_EntryPos].Value > SubmEntry[S_EntryPos].Max )
				{
					*SubmEntry[S_EntryPos].Value = SubmEntry[S_EntryPos].Max;
				}
			}
		}

		Menu g_Menu;
	}
}