#include "IniRead.h"

#pragma warning (disable: 4800)

namespace Files
{
	void IniRead::NoFlash ( )
	{
		std::string noflash = g_File.DirFile ( VISUALS_PATH ).c_str ( );

		INIREAD_INT ( enable, noflash, NOFLASH, NOFLASH_ENABLE );
		INIREAD_INT ( fade_limit, noflash, NOFLASH, NOFLASH_FADELIMIT );
		INIREAD ( fade_color_string, noflash, NOFLASH, NOFLASH_FADECOLOR );
		INIREAD_INT ( fade_color_random, noflash, NOFLASH, NOFLASH_FADECOLORRANDOM );
		INIREAD_INT ( show_percentage, noflash, NOFLASH, NOFLASH_SHOWPERCENTAGE );

		g_Util.Parse ( 3, g_IniRead.noflash.fade_color_string, g_IniRead.noflash.fade_color );
	}

	void IniRead::ESP ( )
	{
		std::string esp = g_File.DirFile ( VISUALS_PATH ).c_str ( );

		INIREAD_INT ( enable, esp, mESP, ESP_ENABLE );

		INIREAD_INT ( player, esp, mESP, ESP_PLAYER );
		INIREAD_INT ( player_visible_only, esp, mESP, ESP_PLAYER_VISIBLE_ONLY );

		INIREAD_INT ( player_box, esp, mESP, ESP_PLAYER_BOX );

		INIREAD_INT ( player_name, esp, mESP, ESP_PLAYER_NAME );
		INIREAD_INT ( player_weapon, esp, mESP, ESP_PLAYER_WEAPON );
		INIREAD_INT ( player_distance, esp, mESP, ESP_PLAYER_DISTANCE );

		INIREAD_INT ( world, esp, mESP, ESP_WORLD );
		INIREAD_INT ( world_weapons, esp, mESP, ESP_WORLD_WEAPONS );
		INIREAD_INT ( world_sprites, esp, mESP, ESP_WORLD_SPRITES );
		INIREAD_INT ( world_nades, esp, mESP, ESP_WORLD_NADES );

		INIREAD_INT ( sound, esp, mESP, ESP_SOUND );
		INIREAD_INT ( sound_fade_time, esp, mESP, ESP_SOUND_FADE_TIME );

		INIREAD_STRING ( panic_key, esp, mESP, ESP_PANIC_KEY );
	}

	void IniRead::Main ( )
	{
		std::string main = g_File.DirFile ( MAIN_PATH ).c_str ( );

		INIREAD_STRING ( language, main, MAIN, MAIN_LANGUAGE );

		INIREAD_STRING ( reload_key, main, MAIN, MAIN_RELOAD_KEY );
		INIREAD_STRING ( panic_key, main, MAIN, MAIN_PANIC_KEY );

		INIREAD_INT ( scan_visibility, main, MAIN, MAIN_SCAN_VISIBILITY );
	}

	void IniRead::Functions ( )
	{
		std::string function = g_File.DirFile ( FUNCTIONS_PATH ).c_str ( );

		INIREAD_INT ( esp, function, FUNCTIONS, FUNCTIONS_ESP );
		INIREAD_INT ( noflash, function, FUNCTIONS, FUNCTIONS_NOFLASH );
		INIREAD_INT ( menu, function, FUNCTIONS, FUNCTIONS_MENU );
	}

	IniRead g_IniRead;
}