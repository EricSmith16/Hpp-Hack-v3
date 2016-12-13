#include "Menu.h"

#pragma warning (disable: 4244)
#pragma warning (disable: 4838)

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
			MENU_SETTINGS, MAIN_MENU, ESP_MENU, ESP_COLORS_MENU, NOFLASH_MENU,
			SCREENINFO_MENU, SPEED_MENU, BHOP_MENU, GSTRAFE_MENU, JUMPBUG_MENU,
			EDGEBUG_MENU, LOAD_SETTINGS_MENU, SAVE_SETTINGS_MENU
		};

		void Menu::Initialize ( )
		{
			Clear ( );

			Add ( MENU_MENU, 255, 255, 255, false, true );

			Add ( MENU_MAIN, 255, 255, 255, false, true );

			if ( g_Vars.function.esp )
			{
				Add ( MENU_ESP, 255, 255, 255, false, true );
				Add ( MENU_ESP_COLORS, 255, 255, 255, false, true );
			}
			else
			{
				Add ( MENU_ESP, 100, 100, 100, false, false );
				Add ( MENU_ESP_COLORS, 100, 100, 100, false, false );
			}

			if ( g_Vars.function.noflash )
			{
				Add ( MENU_NOFLASH, 255, 255, 255, false, true );
			}
			else
			{
				Add ( MENU_NOFLASH, 100, 100, 100, false, false );
			}

			if ( g_Vars.function.screeninfo )
			{
				Add ( MENU_SCREENINFO, 255, 255, 255, false, true );
			}
			else
			{
				Add ( MENU_SCREENINFO, 100, 100, 100, false, false );
			}

			if ( g_Vars.function.speed )
			{
				Add ( MENU_SPEED, 255, 255, 255, false, true );
			}
			else
			{
				Add ( MENU_SPEED, 100, 100, 100, false, false );
			}

			if ( g_Vars.function.bhop )
			{
				Add ( MENU_BHOP, 255, 255, 255, false, true );
			}
			else
			{
				Add ( MENU_BHOP, 100, 100, 100, false, false );
			}

			if ( g_Vars.function.gstrafe )
			{
				Add ( MENU_GSTRAFE, 255, 255, 255, false, true );
			}
			else
			{
				Add ( MENU_GSTRAFE, 100, 100, 100, false, false );
			}

			if ( g_Vars.function.jumpbug )
			{
				Add ( MENU_JUMPBUG, 255, 255, 255, false, true );
			}
			else
			{
				Add ( MENU_JUMPBUG, 100, 100, 100, false, false );
			}

			if ( g_Vars.function.edgebug )
			{
				Add ( MENU_EDGEBUG, 255, 255, 255, true, true );
			}
			else
			{
				Add ( MENU_EDGEBUG, 100, 100, 100, true, false );
			}

			Add ( MENU_LOAD_SETTINGS, 255, 255, 255, false, true );
			Add ( MENU_SAVE_SETTINGS, 255, 255, 255, false, true );

			if ( M_EntryPos == MENU_SETTINGS )
			{
				AddSub ( MENU_MENU_POS_X, &g_Vars.menu.pos_x, 1, Engine::g_Screen.iWidth, 1, 0, false, false );
				AddSub ( MENU_MENU_POS_Y, &g_Vars.menu.pos_y, 1, Engine::g_Screen.iHeight, 1, 0, false, true );

				AddSub ( MENU_MENU_BOX_HEIGHT, &g_Vars.menu.box_height, 13, 39, 1, 0, false, false );
				AddSub ( MENU_MENU_BOX_WIDTH, &g_Vars.menu.box_width, 170, 220, 1, 0, false, true );

				AddSub ( MENU_MENU_BOX_COLOR_R, &g_Vars.menu.box_color[0], 0, 255, 1, 0, false, false );
				AddSub ( MENU_MENU_BOX_COLOR_G, &g_Vars.menu.box_color[1], 0, 255, 1, 0, false, false );
				AddSub ( MENU_MENU_BOX_COLOR_B, &g_Vars.menu.box_color[2], 0, 255, 1, 0, false, false );
				AddSub ( MENU_MENU_BOX_COLOR_A, &g_Vars.menu.box_color[3], 0, 255, 1, 0, false, true );

				AddSub ( MENU_MENU_FILL_COLOR_R, &g_Vars.menu.fill_color[0], 0, 255, 1, 0, false, false );
				AddSub ( MENU_MENU_FILL_COLOR_G, &g_Vars.menu.fill_color[1], 0, 255, 1, 0, false, false );
				AddSub ( MENU_MENU_FILL_COLOR_B, &g_Vars.menu.fill_color[2], 0, 255, 1, 0, false, false );
				AddSub ( MENU_MENU_FILL_COLOR_A, &g_Vars.menu.fill_color[3], 0, 255, 1, 0, false, true );

				AddSub ( MENU_MENU_TEXT_COLOR_R, &g_Vars.menu.text_color[0], 0, 255, 1, 0, false, false );
				AddSub ( MENU_MENU_TEXT_COLOR_G, &g_Vars.menu.text_color[1], 0, 255, 1, 0, false, false );
				AddSub ( MENU_MENU_TEXT_COLOR_B, &g_Vars.menu.text_color[2], 0, 255, 1, 0, false, false );
				AddSub ( MENU_MENU_TEXT_COLOR_A, &g_Vars.menu.text_color[3], 0, 255, 1, 0, false, true );

				AddSub ( MENU_MENU_SELECT_COLOR_R, &g_Vars.menu.select_color[0], 0, 255, 1, 0, false, false );
				AddSub ( MENU_MENU_SELECT_COLOR_G, &g_Vars.menu.select_color[1], 0, 255, 1, 0, false, false );
				AddSub ( MENU_MENU_SELECT_COLOR_B, &g_Vars.menu.select_color[2], 0, 255, 1, 0, false, false );
				AddSub ( MENU_MENU_SELECT_COLOR_A, &g_Vars.menu.select_color[3], 0, 255, 1, 0, false, true );
			}

			if ( M_EntryPos == MAIN_MENU )
			{
				AddSub ( MENU_MAIN_SCAN_VISIBILITY, &g_Vars.main.player_scan_visibility, 1, 3, 1, 0, false, false );
				AddSub ( MENU_MAIN_VALID_CHECK, &g_Vars.main.player_valid_check, 1, 2, 1, 0, false, true );
				AddSub ( MENU_MAIN_OUTLINE_QUALITY, &g_Vars.main.font_outline_quality, 1, 3, 1, 0, false, false );
			}

			if ( M_EntryPos == ESP_MENU && g_Vars.function.esp )
			{
				AddSub ( MENU_ESP_ENABLE, &g_Vars.esp.enable, 0, 1, 1, 0, false, true );

				AddSub ( MENU_ESP_PLAYER, &g_Vars.esp.player, 0, 2, 1, 0, false, false );
				AddSub ( MENU_ESP_PLAYER_VISIBLECHECK, &g_Vars.esp.player_visible_check, 0, 1, 1, 0, false, false );
				AddSub ( MENU_ESP_PLAYER_VISIBLEONLY, &g_Vars.esp.player_visible_only, 0, 1, 1, 0, false, false );
				AddSub ( MENU_ESP_PLAYER_IGNOREDEATH, &g_Vars.esp.player_ignore_death, 0, 1, 1, 0, false, true );

				AddSub ( MENU_ESP_PLAYER_BOX, &g_Vars.esp.player_box, 0, 2, 1, 0, false, false );
				AddSub ( MENU_ESP_PLAYER_BOX_LW, &g_Vars.esp.player_box_linewidth, 1, 10, 1, 0, false, false );
				AddSub ( MENU_ESP_PLAYER_BOX_SIZE, &g_Vars.esp.player_box_size, 0.1f, 2, 0.1f, 0, true, true );

				AddSub ( MENU_ESP_PLAYER_NAME, &g_Vars.esp.player_name, 0, 1, 1, 0, false, false );
				AddSub ( MENU_ESP_PLAYER_WEAPON, &g_Vars.esp.player_weapon, 0, 1, 1, 0, false, false );
				AddSub ( MENU_ESP_PLAYER_DISTANCE, &g_Vars.esp.player_distance, 0, 2, 1, 0, false, false );
				AddSub ( MENU_ESP_PLAYER_BARREL, &g_Vars.esp.player_barrel, 0, 1, 1, 0, false, true );

				AddSub ( MENU_ESP_WORLD, &g_Vars.esp.world, 0, 1, 1, 0, false, false );
				AddSub ( MENU_ESP_WORLD_WEAPONS, &g_Vars.esp.world_weapons, 0, 1, 1, 0, false, false );
				AddSub ( MENU_ESP_WORLD_NADES, &g_Vars.esp.world_nades, 0, 1, 1, 0, false, true );

				AddSub ( MENU_ESP_C4TIMER, &g_Vars.esp.c4timer, 0, 2, 1, 0, false, false );
				AddSub ( MENU_ESP_C4TIMER_VALUE, &g_Vars.esp.c4timer_value, 1, 100, 1, 0, false, true );

				AddSub ( MENU_ESP_SOUND, &g_Vars.esp.sound, 0, 1, 1, 0, false, false );
				AddSub ( MENU_ESP_SOUND_LINEWIDTH, &g_Vars.esp.sound_linewidth, 1, 10, 1, 0, false, false );
				AddSub ( MENU_ESP_SOUND_FADE_TIME, &g_Vars.esp.sound_fade_time, 100, 5000, 100, 0, false, true );

				AddSub ( MENU_ESP_FONT_OUTLINE, &g_Vars.esp.font_outline, 0, 1, 1, 0, false, false );
			}

			if ( M_EntryPos == ESP_COLORS_MENU && g_Vars.function.esp )
			{
				AddSub ( MENU_ESP_COLOR_T_HIDE_R, &g_Vars.esp.color_t_hide[0], 0, 255, 1, 0, false, false );
				AddSub ( MENU_ESP_COLOR_T_HIDE_G, &g_Vars.esp.color_t_hide[1], 0, 255, 1, 0, false, false );
				AddSub ( MENU_ESP_COLOR_T_HIDE_B, &g_Vars.esp.color_t_hide[2], 0, 255, 1, 0, false, true );

				AddSub ( MENU_ESP_COLOR_T_VIS_R, &g_Vars.esp.color_t_vis[0], 0, 255, 1, 0, false, false );
				AddSub ( MENU_ESP_COLOR_T_VIS_G, &g_Vars.esp.color_t_vis[1], 0, 255, 1, 0, false, false );
				AddSub ( MENU_ESP_COLOR_T_VIS_B, &g_Vars.esp.color_t_vis[2], 0, 255, 1, 0, false, true );

				AddSub ( MENU_ESP_COLOR_CT_HIDE_R, &g_Vars.esp.color_ct_hide[0], 0, 255, 1, 0, false, false );
				AddSub ( MENU_ESP_COLOR_CT_HIDE_G, &g_Vars.esp.color_ct_hide[1], 0, 255, 1, 0, false, false );
				AddSub ( MENU_ESP_COLOR_CT_HIDE_B, &g_Vars.esp.color_ct_hide[2], 0, 255, 1, 0, false, true );

				AddSub ( MENU_ESP_COLOR_CT_VIS_R, &g_Vars.esp.color_ct_vis[0], 0, 255, 1, 0, false, false );
				AddSub ( MENU_ESP_COLOR_CT_VIS_G, &g_Vars.esp.color_ct_vis[1], 0, 255, 1, 0, false, false );
				AddSub ( MENU_ESP_COLOR_CT_VIS_B, &g_Vars.esp.color_ct_vis[2], 0, 255, 1, 0, false, true );

				AddSub ( MENU_ESP_SOUND_COLOR_R, &g_Vars.esp.sound_color[0], 0, 255, 1, 0, false, false );
				AddSub ( MENU_ESP_SOUND_COLOR_G, &g_Vars.esp.sound_color[1], 0, 255, 1, 0, false, false );
				AddSub ( MENU_ESP_SOUND_COLOR_B, &g_Vars.esp.sound_color[2], 0, 255, 1, 0, false, true );

				AddSub ( MENU_ESP_FONT_COLOR_R, &g_Vars.esp.font_color[0], 0, 255, 1, 0, false, false );
				AddSub ( MENU_ESP_FONT_COLOR_G, &g_Vars.esp.font_color[1], 0, 255, 1, 0, false, false );
				AddSub ( MENU_ESP_FONT_COLOR_B, &g_Vars.esp.font_color[2], 0, 255, 1, 0, false, false );
			}

			if ( M_EntryPos == NOFLASH_MENU && g_Vars.function.noflash )
			{
				AddSub ( MENU_NOFLASH_ENABLE, &g_Vars.noflash.enable, 0, 1, 1, 0, false, true );

				AddSub ( MENU_NOFLASH_FADELIMIT, &g_Vars.noflash.fade_limit, 0, 255, 1, 0, false, true );

				AddSub ( MENU_NOFLASH_FADECOLOR_R, &g_Vars.noflash.fade_color[0], 0, 255, 1, 0, false, false );
				AddSub ( MENU_NOFLASH_FADECOLOR_G, &g_Vars.noflash.fade_color[1], 0, 255, 1, 0, false, false );
				AddSub ( MENU_NOFLASH_FADECOLOR_B, &g_Vars.noflash.fade_color[2], 0, 255, 1, 0, false, false );
				AddSub ( MENU_NOFLASH_FADECOLORRANDOM, &g_Vars.noflash.fade_color_random, 0, 1, 1, 0, false, true );
				
				AddSub ( MENU_NOFLASH_SHOWPERCENTAGE, &g_Vars.noflash.show_percentage, 0, 2, 1, 0, false, true );

				AddSub ( MENU_NOFLASH_FONT_OUTLINE, &g_Vars.noflash.font_outline, 0, 1, 1, 0, false, false );
			}

			if ( M_EntryPos == SCREENINFO_MENU && g_Vars.function.screeninfo )
			{
				AddSub ( MENU_SCREENINFO_ENABLE, &g_Vars.screeninfo.enable, 0, 1, 1, 0, false, true );

				AddSub ( MENU_SCREENINFO_FPS, &g_Vars.screeninfo.fps, 0, 1, 1, 0, false, false );
				AddSub ( MENU_SCREENINFO_COPYRIGHT, &g_Vars.screeninfo.copyright, 0, 1, 1, 0, false, false );
				AddSub ( MENU_SCREENINFO_TIME, &g_Vars.screeninfo.time, 0, 1, 1, 0, false, false );
				AddSub ( MENU_SCREENINFO_SHOWKEYS, &g_Vars.screeninfo.showkeys, 0, 1, 1, 0, false, false );
				AddSub ( MENU_SCREENINFO_KREEDZ, &g_Vars.screeninfo.kreedz, 0, 1, 1, 0, false, true );

				AddSub ( MENU_SCREENINFO_COLOR_R, &g_Vars.screeninfo.color[0], 0, 255, 1, 0, false, false );
				AddSub ( MENU_SCREENINFO_COLOR_G, &g_Vars.screeninfo.color[1], 0, 255, 1, 0, false, false );
				AddSub ( MENU_SCREENINFO_COLOR_B, &g_Vars.screeninfo.color[2], 0, 255, 1, 0, false, false );
				AddSub ( MENU_SCREENINFO_FONT_OUTLINE, &g_Vars.screeninfo.font_outline, 0, 1, 1, 0, false, true );

				AddSub ( MENU_SCREENINFO_DEBUG, &g_Vars.screeninfo.debug, 0, 1, 1, 0, false, false );
			}

			if ( M_EntryPos == SPEED_MENU  && g_Vars.function.speed )
			{
				AddSub ( MENU_SPEED_VALUE, &g_Vars.speed.value, 0.1f, 1000, 0.1f, 0, true, false );
				AddSub ( MENU_SPEED_ENGINE_VALUE, &g_Vars.speed.engine_value, -255, 255, 1, 0, false, true );

				AddSub ( MENU_SPEED_TYPE, &g_Vars.speed.speed_type, 1, 2, 1, 0, false, true );

				if ( g_Vars.speed.speed_type == 1 )
				{
					if ( g_Vars.speed.boost < 1.1f )
					{
						g_Vars.speed.boost = 1.1f;
					}

					AddSub ( MENU_SPEED_BOOST, &g_Vars.speed.boost, 1.1f, 1000, 0.1f, 0, true, false );
				}
				else if ( g_Vars.speed.speed_type == 2 )
				{
					if ( g_Vars.speed.boost > 255 )
					{
						g_Vars.speed.boost = 255;
					}

					AddSub ( MENU_SPEED_BOOST, &g_Vars.speed.boost, 1, 255, 1, 0, false, false );
				}

				if ( g_Vars.speed.speed_type == 1 )
				{
					if ( g_Vars.speed.slowmo < 0 )
					{
						g_Vars.speed.slowmo = 0.1f;
					}

					AddSub ( MENU_SPEED_SLOWMO, &g_Vars.speed.slowmo, 0.1f, 0.9f, 0.1f, 0, true, false );
				}
				else if ( g_Vars.speed.speed_type == 2 )
				{
					if ( g_Vars.speed.slowmo >= 0 )
					{
						g_Vars.speed.slowmo = -1;
					}

					AddSub ( MENU_SPEED_SLOWMO, &g_Vars.speed.slowmo, -255, -1, 1, 0, false, false );
				}
			}

			if ( M_EntryPos == BHOP_MENU && g_Vars.function.bhop )
			{
				AddSub ( MENU_BHOP_MWHEEL_EMULATION, &g_Vars.bhop.mouse_wheel_emulation, 0, 1, 1, 0, false, false );
				AddSub ( MENU_BHOP_MWHEEL_DIRECTION, &g_Vars.bhop.mouse_wheel_direction, 1000, 1001, 1, 0, false, true );

				AddSub ( MENU_BHOP_DISTANCE_TYPE, &g_Vars.bhop.distance_type, 1, 2, 1, 0, false, false );

				if ( g_Vars.bhop.distance[0] > g_Vars.bhop.distance[1] )
				{
					g_Vars.bhop.distance[0] = g_Vars.bhop.distance[1];
				}

				if ( g_Vars.bhop.distance[1] < g_Vars.bhop.distance[0] )
				{
					g_Vars.bhop.distance[1] = g_Vars.bhop.distance[0];
				}

				
				AddSub ( MENU_BHOP_DISTANCE_MINIMAL, &g_Vars.bhop.distance[0], 0, 50, 0.1f, 0, true, false );
				AddSub ( MENU_BHOP_DISTANCE_MAXIMAL, &g_Vars.bhop.distance[1], 0, 50, 0.1f, 0, true, true );			

				AddSub ( MENU_BHOP_NOSLOWDOWN, &g_Vars.bhop.noslowdown, 0, 2, 1, 0, false, true );

				AddSub ( MENU_BHOP_INWATER, &g_Vars.bhop.in_water, 0, 1, 1, 0, false, false );
				AddSub ( MENU_BHOP_ONLADDER, &g_Vars.bhop.on_ladder, 0, 1, 1, 0, false, true );

				AddSub ( MENU_BHOP_STANDUP, &g_Vars.bhop.standup, 0, 1, 1, 0, false, false );
				AddSub ( MENU_BHOP_STANDUP_FALLVELOCITY, &g_Vars.bhop.standup_fallvelocity, 0, 250, 0.1f, 0, true, false );
				AddSub ( MENU_BHOP_STANDUP_GROUNDANGLE, &g_Vars.bhop.standup_groundangle, 0, 45, 0.1f, 0, true, false );
			}

			if ( M_EntryPos == GSTRAFE_MENU && g_Vars.function.gstrafe )
			{
				AddSub ( MENU_GSTRAFE_MWHEEL_EMULATION, &g_Vars.gstrafe.mouse_wheel_emulation, 0, 1, 1, 0, false, false );
				AddSub ( MENU_GSTRAFE_MWHEEL_DIRECTION, &g_Vars.gstrafe.mouse_wheel_direction, 1000, 1001, 1, 0, false, true );

				AddSub ( MENU_GSTRAFE_DISTANCE_TYPE, &g_Vars.gstrafe.distance_type, 1, 2, 1, 0, false, false );

				if ( g_Vars.gstrafe.distance[0] > g_Vars.gstrafe.distance[1] )
				{
					g_Vars.gstrafe.distance[0] = g_Vars.gstrafe.distance[1];
				}
				else if ( g_Vars.gstrafe.distance[1] < g_Vars.gstrafe.distance[0] )
				{
					g_Vars.gstrafe.distance[1] = g_Vars.gstrafe.distance[0];
				}

				AddSub ( MENU_GSTRAFE_DISTANCE_MINIMAL, &g_Vars.gstrafe.distance[0], 0, 50, 0.1f, 0, true, false );
				AddSub ( MENU_GSTRAFE_DISTANCE_MAXIMAL, &g_Vars.gstrafe.distance[1], 0, 50, 0.1f, 0, true, true );

				if ( g_Vars.gstrafe.count[0] > g_Vars.gstrafe.count[1] )
				{
					g_Vars.gstrafe.count[0] = g_Vars.gstrafe.count[1];
				}
				else if ( g_Vars.gstrafe.count[1] < g_Vars.gstrafe.count[0] )
				{
					g_Vars.gstrafe.count[1] = g_Vars.gstrafe.count[0];
				}

				AddSub ( MENU_GSTRAFE_COUNT_MINIMAL, &g_Vars.gstrafe.count[0], 1, 50, 1, 0, false, false );
				AddSub ( MENU_GSTRAFE_COUNT_MAXIMAL, &g_Vars.gstrafe.count[1], 1, 50, 1, 0, false, true );

				AddSub ( MENU_GSTARFE_FALLRUN, &g_Vars.gstrafe.fallrun, 0, 1, 1, 0, false, true );

				AddSub ( MENU_GSTARFE_SLOWDOWN_SCALE, &g_Vars.gstrafe.slowdown_scale, 0, 5, 0.1f, 0, true, false );
				AddSub ( MENU_GSTARFE_SLOWDOWN_ANGLE, &g_Vars.gstrafe.slowdown_groundangle, 0, 45, 0.1f, 0, true, true );

				AddSub ( MENU_GSTARFE_STANDUP_VELOCITY, &g_Vars.gstrafe.standup_fallvelocity, 0, 250, 0.1f, 0, true, false );
			}

			if ( M_EntryPos == JUMPBUG_MENU && g_Vars.function.jumpbug )
			{
				AddSub ( MENU_JUMPBUG_AUTO, &g_Vars.jumpbug.auto_enable, 0, 1, 1, 0, false, false );
				AddSub ( MENU_JUMPBUG_AUTO_DAMAGE, &g_Vars.jumpbug.auto_damage, 1, 100, 1, 0, false, false );
				AddSub ( MENU_JUMPBUG_AUTO_PERCENTAGE, &g_Vars.jumpbug.auto_percentage, 1, 100, 1, 0, false, true );

				AddSub ( MENU_JUMPBUG_SLOWDOWN, &g_Vars.jumpbug.slowdown, 0, 1, 1, 0, false, false );
				AddSub ( MENU_JUMPBUG_SLOWDOWN_DISTANCE, &g_Vars.jumpbug.slowdown_distance, 1, 10000, 1, 0, true, true );

				AddSub ( MENU_JUMPBUG_SLOWMOTION, &g_Vars.jumpbug.slowmotion, 0, 1, 1, 0, false, false );
			}

			if ( M_EntryPos == EDGEBUG_MENU && g_Vars.function.edgebug )
			{
				AddSub ( MENU_EDGEBUG_AUTO, &g_Vars.edgebug.auto_enable, 0, 1, 1, 0, false, false );
				AddSub ( MENU_EDGEBUG_AUTO_DAMAGE, &g_Vars.edgebug.auto_damage, 1, 100, 1, 0, false, true );

				AddSub ( MENU_EDGEBUG_SPEED, &g_Vars.edgebug.speed, 0, 255, 1, 0, false, true );

				AddSub ( MENU_EDGEBUG_DISTANCE, &g_Vars.edgebug.distance, 0.1f, 100, 0.1f, 0, true, false );
				AddSub ( MENU_EDGEBUG_DISTANCE_DYNAMIC, &g_Vars.edgebug.distance_auto, 0, 1, 1, 0, false, false );
			}
		}

		void Menu::Draw ( int x, int y )
		{
			if ( !Visible )
			{
				g_Util.MemorySet ( SubmEntry, sizeof ( SubmEntry ), 0 );
				g_Util.MemorySet ( MenuEntry, sizeof ( MenuEntry ), 0 );

				return;
			}

			Initialize ( );

			BYTE box_color[4], fill_color[4], text_color[4], select_color[4];

			for ( BYTE i = 0; i < 4; ++i )
			{
				box_color[i] = g_Vars.menu.box_color[i];
				fill_color[i] = g_Vars.menu.fill_color[i];
				text_color[i] = g_Vars.menu.text_color[i];
				select_color[i] = g_Vars.menu.select_color[i];
			}

			int HeadMenuBoxPos_x = x;
			int HeadMenuBoxPos_y = y;
			int HeadMenuBoxWidth = g_Vars.menu.box_width;
			int HeadMenuBoxHeight = g_Vars.menu.box_height;

			Renderer::g_Drawing.Box ( HeadMenuBoxPos_x, HeadMenuBoxPos_y, HeadMenuBoxWidth,
				HeadMenuBoxHeight, 1, box_color[0], box_color[1], box_color[2], box_color[3] );

			int HeadMenuFillPos_x = HeadMenuBoxPos_x + 1;
			int HeadMenuFillPos_y = HeadMenuBoxPos_y + 1;
			int HeadMenuFillWidth = HeadMenuBoxWidth - 2;
			int HeadMenuFillHeight = HeadMenuBoxHeight - 2;

			Renderer::g_Drawing.Fill ( HeadMenuFillPos_x, HeadMenuFillPos_y, HeadMenuFillWidth,
				HeadMenuFillHeight, fill_color[0], fill_color[1], fill_color[2], fill_color[3] );

			int HeadMenuTextPos_x = HeadMenuFillPos_x + ( HeadMenuFillWidth / 2 );
			int HeadMenuTextPos_y = HeadMenuFillPos_y + ( HeadMenuFillHeight / 2 ) + 4;

			Renderer::g_Verdana.Print ( HeadMenuTextPos_x, HeadMenuTextPos_y, text_color[0],
				text_color[1], text_color[2], text_color[3], FL_OUTLINE | FL_CENTER, HPP_MESSAGE );

			y += HeadMenuBoxHeight + 2;

			int MenuBoxPos_x = HeadMenuBoxPos_x;
			int MenuBoxPos_y;
			int MenuBoxWidth = HeadMenuBoxWidth;
			int MenuBoxHeight = HeadMenuBoxHeight;

			int MenuFillPos_x = MenuBoxPos_x + 1;
			int MenuFillPos_y;
			int MenuFillWidth = MenuBoxWidth - 2;
			int MenuFillHeight = MenuBoxHeight - 2;

			int MenuTextPos_x = MenuFillPos_x + 6;
			int MenuTextPos_y;

			for ( int i = 0; i < M_EntrySize; ++i )
			{
				MenuBoxPos_y = y;

				MenuFillPos_y = MenuBoxPos_y + 1;

				MenuTextPos_y = MenuFillPos_y + ( MenuFillHeight / 2 ) + 4;

				Renderer::g_Drawing.Box ( MenuBoxPos_x, MenuBoxPos_y, MenuBoxWidth, MenuBoxHeight,
					1, box_color[0], box_color[1], box_color[2], box_color[3] );

				Renderer::g_Drawing.Fill ( MenuFillPos_x, MenuFillPos_y, MenuFillWidth, MenuFillHeight,
					fill_color[0], fill_color[1], fill_color[2], fill_color[3] );

				if ( i == M_EntryPos )
				{
					if ( !SubMenu )
					{
						Renderer::g_Drawing.Fill ( MenuFillPos_x, MenuFillPos_y, MenuFillWidth, MenuFillHeight,
							select_color[0], select_color[1], select_color[2], select_color[3] );

						Renderer::g_Drawing.Fill ( MenuFillPos_x, MenuFillPos_y, 2, MenuFillHeight,
							select_color[0], select_color[1], select_color[2], 200 );
					}
				}

				for ( BYTE a = 0; a < sizeof ( m_entry::Name ); ++a )
				{
					MenuEntry[i].Name[a] ^= MENU_ENTRY_KEY;
				}

				Renderer::g_Verdana.Print ( MenuTextPos_x, MenuTextPos_y, MenuEntry[i].Color[0],
					MenuEntry[i].Color[1], MenuEntry[i].Color[2], 255, FL_OUTLINE, MenuEntry[i].Name );

				y += HeadMenuBoxHeight + 1;

				if ( MenuEntry[i].Space )
				{
					y += HeadMenuBoxHeight + 1;
				}
			}

			x += HeadMenuBoxWidth + 1;

			int HeadSubMenuBoxPos_x = x;
			int HeadSubMenuBoxPos_y = HeadMenuBoxPos_y;
			int HeadSubMenuBoxWidth = HeadMenuBoxWidth;
			int HeadSubMenuBoxHeight = HeadMenuBoxHeight;

			int HeadSubMenuFillPos_x = HeadSubMenuBoxPos_x + 1;
			int HeadSubMenuFillPos_y = HeadSubMenuBoxPos_y + 1;
			int HeadSubMenuFillWidth = HeadSubMenuBoxWidth - 2;
			int HeadSubMenuFillHeight = HeadSubMenuBoxHeight - 2;

			if ( SubMenu )
			{
				int SubMenuBoxPos_x = HeadSubMenuBoxPos_x;
				int SubMenuBoxPos_y = HeadSubMenuBoxPos_y + HeadSubMenuBoxHeight + 2;
				int SubMenuBoxWidth = HeadSubMenuBoxWidth;
				int SubMenuBoxHeight = HeadSubMenuBoxHeight;

				int SubMenuFillPos_x = SubMenuBoxPos_x + 1;
				int SubMenuFillPos_y = SubMenuBoxPos_y + 1;
				int SubMenuFillWidth = SubMenuBoxWidth - 2;
				int SubMenuFillHeight = SubMenuBoxHeight - 2;

				int SubMenuTextPos_x = SubMenuFillPos_x + 6;
				int SubMenuTextPos_y = SubMenuFillPos_y + ( SubMenuFillHeight / 2 ) + 4;

				for ( int i = 0; i < S_EntrySize; ++i )
				{
					char* on = "on";
					char* off = "off";
					char* up = "up";
					char* down = "down";

					Renderer::g_Drawing.Box ( SubMenuBoxPos_x, SubMenuBoxPos_y, SubMenuBoxWidth,
						SubMenuBoxHeight, 1, box_color[0], box_color[1], box_color[2], box_color[3] );

					Renderer::g_Drawing.Fill ( SubMenuFillPos_x, SubMenuFillPos_y, SubMenuFillWidth,
						SubMenuFillHeight, fill_color[0], fill_color[1], fill_color[2], fill_color[3] );

					if ( i == S_EntryPos )
					{
						Renderer::g_Drawing.Fill ( SubMenuFillPos_x, SubMenuFillPos_y, SubMenuFillWidth,
							SubMenuFillHeight, select_color[0], select_color[1], select_color[2], select_color[3] );

						Renderer::g_Drawing.Fill ( SubMenuFillPos_x, SubMenuFillPos_y, 2, SubMenuFillHeight,
							select_color[0], select_color[1], select_color[2], 200 );
					}

					for ( BYTE a = 0; a < 32; ++a )
					{
						SubmEntry[i].Name[a] ^= SUBM_ENTRY_KEY;
					}

					Renderer::g_Verdana.Print ( SubMenuTextPos_x, SubMenuTextPos_y, text_color[0],
						text_color[1], text_color[2], text_color[3], FL_OUTLINE, SubmEntry[i].Name );

					if ( SubmEntry[i].Min == 0 && SubmEntry[i].Max > 0 && SubmEntry[i].Max < 3 )
					{
						if ( SubmEntry[i].Max == 1 )
						{
							if ( *SubmEntry[i].Value == 0 )
							{
								Renderer::g_Verdana.Print ( SubMenuTextPos_x + ( HeadMenuBoxWidth - 30 ), 
									SubMenuTextPos_y, 255, 80, 80, 255, FL_OUTLINE, off );
							}
							else if ( *SubmEntry[i].Value == 1 )
							{
								Renderer::g_Verdana.Print ( SubMenuTextPos_x + ( HeadMenuBoxWidth - 30 ), 
									SubMenuTextPos_y, 80, 255, 80, 255, FL_OUTLINE, on );
							}
						}
						else if ( SubmEntry[i].Max == 2 )
						{
							if ( *SubmEntry[i].Value == 0 )
							{
								Renderer::g_Verdana.Print ( SubMenuTextPos_x + ( HeadMenuBoxWidth - 30), 
									SubMenuTextPos_y, 255, 80, 80, 255, FL_OUTLINE, off );
							}
							else
							{
								Renderer::g_Verdana.Print ( SubMenuTextPos_x + ( HeadMenuBoxWidth - 25 ), 
									SubMenuTextPos_y, 80, 255, 80, 255, FL_OUTLINE, "%d", ( int )*SubmEntry[i].Value );
							}
						}
					}
					else if ( SubmEntry[i].Min == 1000 && SubmEntry[i].Max == 1001 )
					{
						if ( *SubmEntry[i].Value == 1000 )
						{
							Renderer::g_Verdana.Print ( SubMenuTextPos_x + ( HeadMenuBoxWidth - 45 ),
								SubMenuTextPos_y, 255, 255, 255, 255, FL_OUTLINE, down );
						}
						else if ( *SubmEntry[i].Value == 1001 )
						{
							Renderer::g_Verdana.Print ( SubMenuTextPos_x + ( HeadMenuBoxWidth - 30 ),
								SubMenuTextPos_y, 255, 255, 255, 255, FL_OUTLINE, up );
						}
					}
					else
					{
						if ( SubmEntry[i].bFloat )
						{
							if ( *SubmEntry[i].Value >= 10 && *SubmEntry[i].Value < 100 )
							{
								Renderer::g_Verdana.Print ( SubMenuTextPos_x + ( HeadMenuBoxWidth - 38), SubMenuTextPos_y, 
									255, 255, 255, 255, FL_OUTLINE, "%.1f", *SubmEntry[i].Value );
							}
							else if ( *SubmEntry[i].Value >= 100 && *SubmEntry[i].Value < 1000 )
							{
								Renderer::g_Verdana.Print ( SubMenuTextPos_x + ( HeadMenuBoxWidth - 42), SubMenuTextPos_y, 
									255, 255, 255, 255, FL_OUTLINE, "%.1f", *SubmEntry[i].Value );
							}
							else if ( *SubmEntry[i].Value >= 1000 && *SubmEntry[i].Value < 10000 )
							{
								Renderer::g_Verdana.Print ( SubMenuTextPos_x + ( HeadMenuBoxWidth - 46), SubMenuTextPos_y, 
									255, 255, 255, 255, FL_OUTLINE, "%.1f", *SubmEntry[i].Value );
							}
							else if ( *SubmEntry[i].Value >= 10000 )
							{
								Renderer::g_Verdana.Print ( SubMenuTextPos_x + ( HeadMenuBoxWidth - 50), SubMenuTextPos_y, 
									255, 255, 255, 255, FL_OUTLINE, "%.1f", *SubmEntry[i].Value );
							}
							else
							{
								Renderer::g_Verdana.Print ( SubMenuTextPos_x + ( HeadMenuBoxWidth - 34), SubMenuTextPos_y, 
									255, 255, 255, 255, FL_OUTLINE, "%.1f", *SubmEntry[i].Value );
							}
						}
						else
						{
							if ( *SubmEntry[i].Value >= 10 && *SubmEntry[i].Value < 100 )
							{
								Renderer::g_Verdana.Print ( SubMenuTextPos_x + ( HeadMenuBoxWidth - 30), SubMenuTextPos_y, 255,
									255, 255, 255, FL_OUTLINE, "%d", ( int )*SubmEntry[i].Value );
							}
							else if ( *SubmEntry[i].Value >= 100 && *SubmEntry[i].Value < 1000 )
							{
								Renderer::g_Verdana.Print ( SubMenuTextPos_x + ( HeadMenuBoxWidth - 34 ), SubMenuTextPos_y, 255,
									255, 255, 255, FL_OUTLINE, "%d", ( int )*SubmEntry[i].Value );
							}
							else if ( *SubmEntry[i].Value >= 1000 && *SubmEntry[i].Value < 10000 )
							{
								Renderer::g_Verdana.Print ( SubMenuTextPos_x + ( HeadMenuBoxWidth - 38 ), SubMenuTextPos_y, 255,
									255, 255, 255, FL_OUTLINE, "%d", ( int )*SubmEntry[i].Value );
							}
							else if ( *SubmEntry[i].Value >= 10000 )
							{
								Renderer::g_Verdana.Print ( SubMenuTextPos_x + ( HeadMenuBoxWidth - 42 ), SubMenuTextPos_y, 255,
									255, 255, 255, FL_OUTLINE, "%d", ( int )*SubmEntry[i].Value );
							}
							else
							{
								Renderer::g_Verdana.Print ( SubMenuTextPos_x + ( HeadMenuBoxWidth - 25 ), SubMenuTextPos_y, 255,
									255, 255, 255, FL_OUTLINE, "%d", ( int )*SubmEntry[i].Value );
							}
						}
					}

					SubMenuBoxPos_y += SubMenuBoxHeight + 1;
					SubMenuFillPos_y += HeadSubMenuBoxHeight + 1;
					SubMenuTextPos_y += HeadSubMenuBoxHeight + 1;

					if ( SubmEntry[i].Space )
					{
						SubMenuBoxPos_y += SubMenuBoxHeight + 1;
						SubMenuFillPos_y += HeadSubMenuBoxHeight + 1;
						SubMenuTextPos_y += HeadSubMenuBoxHeight + 1;
					}
				}
			}
		}

		void Menu::Add ( char* Name, BYTE r, BYTE g, BYTE b, bool Space, bool Active )
		{
			g_Util.MemorySet ( MenuEntry[M_EntrySize].Name, sizeof ( m_entry::Name ), 0 );

			lstrcpy ( MenuEntry[M_EntrySize].Name, Name );

			for ( BYTE i = 0; i < 32; ++i )
			{
				MenuEntry[M_EntrySize].Name[i] ^= MENU_ENTRY_KEY;
			}

			MenuEntry[M_EntrySize].Color[0] = r;
			MenuEntry[M_EntrySize].Color[1] = g;
			MenuEntry[M_EntrySize].Color[2] = b;
			MenuEntry[M_EntrySize].Space = Space;
			MenuEntry[M_EntrySize].Active = Active;

			++M_EntrySize;
		}

		void Menu::AddSub ( char* Name, float* Value, float Min, float Max, float Step, char* Help, bool bFloat, bool Space )
		{
			g_Util.MemorySet ( SubmEntry[S_EntrySize].Name, sizeof ( s_entry::Name ), 0 );

			lstrcpy ( SubmEntry[S_EntrySize].Name, Name );

			for ( BYTE i = 0; i < 32; ++i )
			{
				SubmEntry[S_EntrySize].Name[i] ^= SUBM_ENTRY_KEY;
			}

			SubmEntry[S_EntrySize].Value = Value;
			SubmEntry[S_EntrySize].Min = Min;
			SubmEntry[S_EntrySize].Max = Max;
			SubmEntry[S_EntrySize].Step = Step;
			SubmEntry[S_EntrySize].Help = Help;
			SubmEntry[S_EntrySize].bFloat = bFloat;
			SubmEntry[S_EntrySize].Space = Space;

			++S_EntrySize;
		}

		void Menu::Clear ( )
		{
			for ( BYTE i = 0; i < M_EntrySize; ++i )
			{
				g_Util.MemorySet ( &MenuEntry[i].Name, sizeof ( m_entry::Name ), 0 );
			}

			for ( BYTE i = 0; i < S_EntrySize; ++i )
			{
				g_Util.MemorySet ( &MenuEntry[i].Name, sizeof ( s_entry::Name ), 0 );

				SubmEntry[i].Value = 0;
				SubmEntry[i].Min = 0;
				SubmEntry[i].Max = 0;
				SubmEntry[i].Step = 0;
				SubmEntry[i].Help = 0;
				SubmEntry[i].bFloat = false;
			}

			M_EntrySize = 0;
			S_EntrySize = 0;
		}

		void Menu::Menu_KeyEvent ( int keynum )
		{
			if ( keynum == g_Vars.menu.key )
			{
				Visible = !Visible;
			}

			ExitMenu = false;

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

						if ( g_Vars.main.language )
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

						if ( g_Vars.main.language )
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
				ExitMenu = true;
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
			else if ( keynum == K_LEFTARROW && Functions::Visuals::g_Menu.SubMenu )
			{
				*SubmEntry[S_EntryPos].Value -= SubmEntry[S_EntryPos].Step;

				if ( *SubmEntry[S_EntryPos].Value < SubmEntry[S_EntryPos].Min )
				{
					*SubmEntry[S_EntryPos].Value = SubmEntry[S_EntryPos].Min;
				}
			}
			else if ( keynum == K_RIGHTARROW && Functions::Visuals::g_Menu.SubMenu )
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