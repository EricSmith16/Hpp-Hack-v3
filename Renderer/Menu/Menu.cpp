#include "Menu.h"

#pragma warning (disable: 4244)
#pragma warning (disable: 4458)

namespace Renderer
{
	enum FuncSettings { MENU_ESP, MENU_NOFLASH };

	Menu::Menu ( )
	{
		Heap = HeapCreate ( 0, INT_DIGITS, 0 );
		Value = ( PCHAR )HeapAlloc ( Heap, HEAP_ZERO_MEMORY, INT_DIGITS );

		Visible = false;
		SubMenu = false;

		M_EntryPos = 0;
		M_EntrySize = 0;

		S_EntryPos = 0;
		S_EntrySize = 0;

		LastSaveTime = 0;
		LastLoadTime = 0;

		Clear ( );

		DisableReload = false;
	}

	void Menu::Initialize ( )
	{
		Clear ( );

		if ( Files::g_IniRead.function.esp )
		{
			Add ( MENU_ESP_SETTINGS, 255, 255, 255 );
		}
		else
		{
			Add ( MENU_ESP_SETTINGS, 100, 100, 100 );
		}

		if ( Files::g_IniRead.function.noflash )
		{
			Add ( MENU_NOFLASH_SETTINGS, 255, 255, 255 );
		}
		else
		{
			Add ( MENU_NOFLASH_SETTINGS, 100, 100, 100 );
		}

		if ( Files::g_IniRead.function.esp && M_EntryPos == MENU_ESP )
		{
			AddSub ( MENU_ESP_ENABLE, &Files::g_IniRead.esp.enable, 0, 1, 1, MENU_ESP_ENABLE_HELP );

			AddSub ( MENU_ESP_PLAYER, &Files::g_IniRead.esp.player, 0, 2, 1, MENU_ESP_PLAYER_HELP );
			AddSub ( MENU_ESP_PLAYER_VISIBLE_ONLY, &Files::g_IniRead.esp.player_visible_only, 0, 1, 1, MENU_ESP_PLAYER_VISIBLE_ONLY_HELP );
			AddSub ( MENU_ESP_PLAYER_BOX, &Files::g_IniRead.esp.player_box, 0, 2, 1, MENU_ESP_PLAYER_BOX_HELP );
			AddSub ( MENU_ESP_PLAYER_NAME, &Files::g_IniRead.esp.player_name, 0, 1, 1, MENU_ESP_PLAYER_NAME_HELP );
			AddSub ( MENU_ESP_PLAYER_WEAPON, &Files::g_IniRead.esp.player_weapon, 0, 1, 1, MENU_ESP_PLAYER_WEAPON_HELP );
			AddSub ( MENU_ESP_PLAYER_DISTANCE, &Files::g_IniRead.esp.player_distance, 0, 2, 1, MENU_ESP_PLAYER_DISTANCE_HELP );

			AddSub ( MENU_ESP_WORLD, &Files::g_IniRead.esp.world, 0, 1, 1, MENU_ESP_WORLD_HELP );
			AddSub ( MENU_ESP_WORLD_WEAPONS, &Files::g_IniRead.esp.world_weapons, 0, 1, 1, MENU_ESP_WORLD_WEAPONS_HELP );
			AddSub ( MENU_ESP_WORLD_SPRITES, &Files::g_IniRead.esp.world_sprites, 0, 1, 1, MENU_ESP_WORLD_SPRITES_HELP );
			AddSub ( MENU_ESP_WORLD_NADES, &Files::g_IniRead.esp.world_nades, 0, 1, 1, MENU_ESP_WORLD_NADES_HELP );

			AddSub ( MENU_ESP_SOUND, &Files::g_IniRead.esp.sound, 0, 1, 1, MENU_ESP_SOUND_HELP );
			AddSub ( MENU_ESP_SOUND_FADE_TIME, &Files::g_IniRead.esp.sound_fade_time, 0, 5000, 100, MENU_ESP_SOUND_FADE_TIME_HELP );
		}

		if ( Files::g_IniRead.function.noflash && M_EntryPos == MENU_NOFLASH )
		{
			AddSub ( MENU_NOFLASH_ENABLE, &Files::g_IniRead.noflash.enable, 0, 1, 1, MENU_NOFLASH_ENABLE_HELP );

			AddSub ( MENU_NOFLASH_FADELIMIT, &Files::g_IniRead.noflash.fade_limit, 0, 255, 1, MENU_NOFLASH_FADELIMIT_HELP );
			AddSub ( MENU_NOFLASH_FADECOLOR_R, &Files::g_IniRead.noflash.fade_color[0], 0, 255, 1, MENU_NOFLASH_FADECOLOR_HELP );
			AddSub ( MENU_NOFLASH_FADECOLOR_G, &Files::g_IniRead.noflash.fade_color[1], 0, 255, 1, MENU_NOFLASH_FADECOLOR_HELP );
			AddSub ( MENU_NOFLASH_FADECOLOR_B, &Files::g_IniRead.noflash.fade_color[2], 0, 255, 1, MENU_NOFLASH_FADECOLOR_HELP );
			AddSub ( MENU_NOFLASH_FADECOLORRANDOM, &Files::g_IniRead.noflash.fade_color_random, 0, 1, 1, MENU_NOFLASH_FADECOLORRANDOM_HELP );

			AddSub ( MENU_NOFLASH_SHOWPERCENTAGE, &Files::g_IniRead.noflash.show_percentage, 0, 2, 1, MENU_NOFLASH_SHOWPERCENTAGE_HELP );
		}
	}

	void Menu::Draw ( int x, int y )
	{
		if ( !Visible )
		{
			LastSaveTime = 0;
			LastLoadTime = 0;

			g_Util.MemorySet ( subm_entry, sizeof ( subm_entry ), 0 );
			g_Util.MemorySet ( menu_entry, sizeof ( menu_entry ), 0 );

			return;
		}

		Initialize ( );

		BYTE text_r = 255, text_g = 255, text_b = 255;
		BYTE on_r = 64, on_g = 255, on_b = 64;
		BYTE off_r = 255, off_g = 64, off_b = 64;

		int MenuHeadWidth = SUBM_ENTRY_WIDTH + MENU_ENTRY_WIDTH + SUBM_PADDING_LEFT;

		g_Drawing.Box ( x, y, MenuHeadWidth, ENTRY_HEIGHT, 1, 0, 0, 0, 255 );
		g_Drawing.Fill ( x + 1, y + 1, MenuHeadWidth - 2, ENTRY_HEIGHT - 2, 20, 20, 20, 200 );

		if ( !LastSaveTime && !LastLoadTime )
		{
			g_Verdana.Print ( x + ( MenuHeadWidth / 2 ), y + 10, text_r, text_g, text_b, 255, FL_CENTER | FL_OUTLINE, HPP_MESSAGE );
		}

		y += ENTRY_HEIGHT + MENU_PADDING_TOP;

		g_Drawing.Box ( x, y, MENU_ENTRY_WIDTH, ENTRY_HEIGHT * M_EntrySize + 2, 1, 0, 0, 0, 255 );
		g_Drawing.Fill ( x + 1, y + 1, MENU_ENTRY_WIDTH - 2, ENTRY_HEIGHT * M_EntrySize, 20, 20, 20, 200 );

		for ( int i = 0; i < M_EntrySize; ++i )
		{
			if ( i == M_EntryPos )
			{
				if ( !SubMenu )
				{
					g_Drawing.Fill ( x + 1, y + 1 + ENTRY_HEIGHT * i, MENU_ENTRY_WIDTH - 2, ENTRY_HEIGHT, 100, 100, 100, 120 );
				}
			}

			for ( BYTE a = 0; a < sizeof ( m_entry::Name ); ++a )
			{
				menu_entry[i].Name[a] ^= MENU_ENTRY_KEY;
			}

			g_Verdana.Print ( x + TEXT_PADDING_LEFT, y + 11 + 13 * i, menu_entry[i].Color[0],
				menu_entry[i].Color[1], menu_entry[i].Color[2], 255, FL_OUTLINE, menu_entry[i].Name );

			for ( BYTE a = 0; a < sizeof ( m_entry::Name ); ++a )
			{
				menu_entry[i].Name[a] ^= MENU_ENTRY_KEY;
			}
		}

		int subm_x = x + MENU_ENTRY_WIDTH + SUBM_PADDING_LEFT;
		int help_x = x + ( MENU_ENTRY_WIDTH + SUBM_PADDING_LEFT ) * 2.67f;

		g_Drawing.Box ( subm_x, y, SUBM_ENTRY_WIDTH, ENTRY_HEIGHT * S_EntrySize + 2, 1, 0, 0, 0, 255 );
		g_Drawing.Fill ( subm_x + 1, y + 1, SUBM_ENTRY_WIDTH - 2, ENTRY_HEIGHT * S_EntrySize, 20, 20, 20, 200 );

		if ( S_EntryPos > ( S_EntrySize - 1 ) )
		{
			S_EntryPos = ( S_EntrySize - 1 );
		}

		for ( int i = 0; i < S_EntrySize; ++i )
		{
			char* on = "on";
			char* off = "off";

			if ( i == S_EntryPos )
			{
				if ( SubMenu )
				{
					g_Drawing.Fill ( subm_x + 1, y + 1 + ENTRY_HEIGHT * i, SUBM_ENTRY_WIDTH - 2, ENTRY_HEIGHT, 130, 130, 130, 150 );

					g_Drawing.Box ( help_x, y + ENTRY_HEIGHT * i, SUBM_ENTRY_WIDTH + 120, ENTRY_HEIGHT + 1, 1, 0, 0, 0, 255 );
					g_Drawing.Fill ( help_x + 1, y + 1 + ENTRY_HEIGHT * i, SUBM_ENTRY_WIDTH + 118, ENTRY_HEIGHT - 1, 20, 20, 20, 200 );

					g_Verdana.Print ( help_x + TEXT_PADDING_LEFT, y + 11 + 13 * i, text_r, text_g, text_b, 255, FL_OUTLINE, subm_entry[i].Help );
				}
			}

			for ( BYTE a = 0; a < 32; ++a )
			{
				subm_entry[i].Name[a] ^= SUBM_ENTRY_KEY;
			}

			if ( subm_entry[i].Min == 0 && subm_entry[i].Max > 0 && subm_entry[i].Max < 3 )
			{
				g_Verdana.Print ( subm_x + TEXT_PADDING_LEFT, y + 11 + 13 * i, text_r, text_g, text_b, 255, FL_OUTLINE, subm_entry[i].Name );

				if ( subm_entry[i].Max == 1 )
				{
					if ( *subm_entry[i].Value == 0 )
					{
						g_Verdana.Print ( subm_x + SUBM_ENTRY_WIDTH - SUBM_VALUE_PADDING, y + 11 + 13 * i, off_r, off_g, off_b, 255, FL_OUTLINE, off );
					}
					else
					{
						g_Verdana.Print ( subm_x + SUBM_ENTRY_WIDTH - SUBM_VALUE_PADDING, y + 11 + 13 * i, on_r, on_g, on_b, 255, FL_OUTLINE, on );
					}
				}
				else if ( subm_entry[i].Max == 2 )
				{
					Value = g_Util.itoa ( *subm_entry[i].Value );

					if ( *subm_entry[i].Value == 0 )
					{
						g_Verdana.Print ( subm_x + SUBM_ENTRY_WIDTH - SUBM_VALUE_PADDING, y + 11 + 13 * i, off_r, off_g, off_b, 255, FL_OUTLINE, off );
					}
					else
					{
						g_Verdana.Print ( subm_x + SUBM_ENTRY_WIDTH - SUBM_VALUE_PADDING, y + 11 + 13 * i, on_r, on_g, on_b, 255, FL_OUTLINE, Value );
					}
				}
			}
			else
			{
				g_Verdana.Print ( subm_x + TEXT_PADDING_LEFT, y + 11 + 13 * i, text_r, text_g, text_b, 255, FL_OUTLINE, subm_entry[i].Name );

				if ( *subm_entry[i].Value == 0 )
				{
					g_Verdana.Print ( subm_x + SUBM_ENTRY_WIDTH - SUBM_VALUE_PADDING, y + 11 + 13 * i, text_r, text_g, text_b, 255, FL_OUTLINE, Value );
				}
				else
				{
					Value = g_Util.itoa ( *subm_entry[i].Value );

					g_Verdana.Print ( subm_x + SUBM_ENTRY_WIDTH - SUBM_VALUE_PADDING, y + 11 + 13 * i, text_r, text_g, text_b, 255, FL_OUTLINE, Value );
				}
			}

			for ( BYTE a = 0; a < 32; ++a )
			{
				subm_entry[i].Name[a] ^= SUBM_ENTRY_KEY;
			}
		}
	}

	void Menu::KeyEvent ( int keynum )
	{
		if ( keynum == K_INS )
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
			S_EntryPos = 0;
			SubMenu = true;
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
		else if ( keynum == K_LEFTARROW && SubMenu )
		{
			*subm_entry[S_EntryPos].Value -= subm_entry[S_EntryPos].Step;

			if ( *subm_entry[S_EntryPos].Value < subm_entry[S_EntryPos].Min )
			{
				*subm_entry[S_EntryPos].Value = subm_entry[S_EntryPos].Min;
			}
		}
		else if ( keynum == K_RIGHTARROW && SubMenu )
		{
			*subm_entry[S_EntryPos].Value += subm_entry[S_EntryPos].Step;

			if ( *subm_entry[S_EntryPos].Value > subm_entry[S_EntryPos].Max )
			{
				*subm_entry[S_EntryPos].Value = subm_entry[S_EntryPos].Max;
			}
		}
	}

	void Menu::Add ( char* Name, BYTE r, BYTE g, BYTE b )
	{
		g_Util.MemorySet ( menu_entry[M_EntrySize].Name, sizeof ( m_entry::Name ), 0 );
		lstrcpy ( menu_entry[M_EntrySize].Name, Name );

		for ( BYTE i = 0; i < 32; ++i )
		{
			menu_entry[M_EntrySize].Name[i] ^= MENU_ENTRY_KEY;
		}

		menu_entry[M_EntrySize].Color[0] = r;
		menu_entry[M_EntrySize].Color[1] = g;
		menu_entry[M_EntrySize].Color[2] = b;

		++M_EntrySize;
	}

	void Menu::AddSub ( char* Name, int* Value, int Min, int Max, int Step, char* Help )
	{
		g_Util.MemorySet ( subm_entry[S_EntrySize].Name, sizeof ( s_entry::Name ), 0 );
		lstrcpy ( subm_entry[S_EntrySize].Name, Name );

		for ( BYTE i = 0; i < 32; ++i )
		{
			subm_entry[S_EntrySize].Name[i] ^= SUBM_ENTRY_KEY;
		}

		subm_entry[S_EntrySize].Value = Value;
		subm_entry[S_EntrySize].Min = Min;
		subm_entry[S_EntrySize].Max = Max;
		subm_entry[S_EntrySize].Step = Step;
		subm_entry[S_EntrySize].Help = Help;

		++S_EntrySize;
	}

	void Menu::Clear ( )
	{
		for ( BYTE i = 0; i < M_EntrySize; ++i )
		{
			g_Util.MemorySet ( &menu_entry[i].Name, sizeof ( m_entry::Name ), 0 );
		}

		for ( BYTE i = 0; i < S_EntrySize; ++i )
		{
			g_Util.MemorySet ( &subm_entry[i].Name, sizeof ( s_entry::Name ), 0 );

			subm_entry[i].Value = 0;
			subm_entry[i].Min = 0;
			subm_entry[i].Max = 0;
			subm_entry[i].Step = 0;
		}

		M_EntrySize = 0;
		S_EntrySize = 0;
	}

	Menu g_Menu;
}