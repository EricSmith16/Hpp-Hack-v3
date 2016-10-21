#include "IniRead.h"

#pragma warning (disable: 4800)
#pragma warning (disable: 4458)

namespace Files
{
	void IniRead::NoFlash ( )
	{
		std::string noflash = g_File.DirFile ( VISUALS_PATH ).c_str ( );

		INIREAD_INT ( enable, noflash, NOFLASH, NOFLASH_ENABLE );
		INIREAD_INT ( fade_limit, noflash, NOFLASH, NOFLASH_FADELIMIT );
		INIREAD_INT ( show_percentage, noflash, NOFLASH, NOFLASH_SHOWPERCENTAGE );
		INIREAD_INT ( font_outline, noflash, NOFLASH, NOFLASH_FONT_OUTLINE );
	}

	void IniRead::ESP ( )
	{
		std::string esp = g_File.DirFile ( VISUALS_PATH ).c_str ( );

		INIREAD_INT ( enable, esp, mESP, ESP_ENABLE );

		INIREAD_INT ( player, esp, mESP, ESP_PLAYER );
		INIREAD_INT ( player_visible_only, esp, mESP, ESP_PLAYER_VISIBLE_ONLY );

		INIREAD_INT ( player_box, esp, mESP, ESP_PLAYER_BOX );
		INIREAD_INT ( player_box_outline, esp, mESP, ESP_PLAYER_BOX_OUTLINE );
		INIREAD_INT ( player_box_linewidth, esp, mESP, ESP_PLAYER_BOX_LW );
		INIREAD ( t_vis_color_string, esp, mESP, ESP_PLAYER_BOX_T_VIS );
		INIREAD ( t_hide_color_string, esp, mESP, ESP_PLAYER_BOX_T_HIDE );
		INIREAD ( ct_vis_color_string, esp, mESP, ESP_PLAYER_BOX_CT_VIS );
		INIREAD ( ct_hide_color_string, esp, mESP, ESP_PLAYER_BOX_CT_HIDE );

		INIREAD_INT ( player_name, esp, mESP, ESP_PLAYER_NAME );
		INIREAD_INT ( player_weapon, esp, mESP, ESP_PLAYER_WEAPON );
		INIREAD_INT ( player_distance, esp, mESP, ESP_PLAYER_DISTANCE );

		INIREAD_INT ( world, esp, mESP, ESP_WORLD );
		INIREAD_INT ( world_weapons, esp, mESP, ESP_WORLD_WEAPONS );
		INIREAD_INT ( world_sprites, esp, mESP, ESP_WORLD_SPRITES );
		INIREAD_INT ( world_nades, esp, mESP, ESP_WORLD_NADES );

		INIREAD_INT ( font_outline, esp, mESP, ESP_FONT_OUTLINE );
		INIREAD ( font_color_string, esp, mESP, ESP_FONT_COLOR );

		INIREAD_INT ( sound, esp, mESP, ESP_SOUND );
		INIREAD_INT ( sound_fade_time, esp, mESP, ESP_SOUND_FADE_TIME );
		INIREAD ( sound_color_string, esp, mESP, ESP_SOUND_COLOR );

		g_Util.Parse ( 3, g_IniRead.esp.t_vis_color_string, g_IniRead.esp.t_vis_color );
		g_Util.Parse ( 3, g_IniRead.esp.t_hide_color_string, g_IniRead.esp.t_hide_color );
		g_Util.Parse ( 3, g_IniRead.esp.ct_vis_color_string, g_IniRead.esp.ct_vis_color );
		g_Util.Parse ( 3, g_IniRead.esp.ct_hide_color_string, g_IniRead.esp.ct_hide_color );
		g_Util.Parse ( 3, g_IniRead.esp.font_color_string, g_IniRead.esp.font_color );
		g_Util.Parse ( 3, g_IniRead.esp.sound_color_string, g_IniRead.esp.sound_color );
	}

	void IniRead::Main ( )
	{
		std::string main = g_File.DirFile ( MAIN_PATH ).c_str ( );

		INIREAD_STRING ( language, main, MAIN, MAIN_LANGUAGE );

		INIREAD_STRING ( reload_key, main, MAIN, MAIN_RELOAD_KEY );
	}

	void IniRead::Functions ( )
	{
		std::string function = g_File.DirFile ( FUNCTIONS_PATH ).c_str ( );

		INIREAD_INT ( esp, function, FUNCTIONS, FUNCTIONS_ESP );
		INIREAD_INT ( noflash, function, FUNCTIONS, FUNCTIONS_NOFLASH );
	}

	IniRead g_IniRead;
}