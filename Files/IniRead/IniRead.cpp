#include "IniRead.h"

#pragma warning (disable: 4244)
#pragma warning (disable: 4800)

namespace Files
{
	void IniRead::EdgeBug ( )
	{
		std::string Path = g_File.DirFile ( MISC_PATH ).c_str ( );

		INIREAD_INT ( g_Vars.edgebug.auto_enable, EDGEBUG, EDGEBUG_AUTO );
		INIREAD_INT ( g_Vars.edgebug.auto_damage, EDGEBUG, EDGEBUG_AUTO_DAMAGE );

		INIREAD_INT ( g_Vars.edgebug.speed, EDGEBUG, EDGEBUG_SPEED );

		INIREAD_FLOAT ( g_Vars.edgebug.distance, EDGEBUG, EDGEBUG_DIST );
		INIREAD_INT ( g_Vars.edgebug.distance_auto, EDGEBUG, EDGEBUG_DIST_DYNAMIC );

		INIREAD_STRING_CONVERT ( g_Vars.edgebug.key, EDGEBUG, EGDEBUG_KEY );
	}

	void IniRead::JumpBug ( )
	{
		std::string Path = g_File.DirFile ( MISC_PATH ).c_str ( );

		INIREAD_INT ( g_Vars.jumpbug.auto_enable, JUMPBUG, JUMPBUG_AUTO );
		INIREAD_INT ( g_Vars.jumpbug.auto_percentage, JUMPBUG, JUMPBUG_AUTO_PERCENTAGE );
		INIREAD_INT ( g_Vars.jumpbug.auto_damage, JUMPBUG, JUMPBUG_AUTO_DAMAGE );

		INIREAD_INT ( g_Vars.jumpbug.slowdown, JUMPBUG, JUMPBUG_SLOWDOWN );
		INIREAD_FLOAT ( g_Vars.jumpbug.slowdown_distance, JUMPBUG, JUMPBUG_SLOWDOWN_DIST );

		INIREAD_INT ( g_Vars.jumpbug.slowmotion, JUMPBUG, JUMPBUG_SLOWMOTION );

		INIREAD_STRING_CONVERT ( g_Vars.jumpbug.key, JUMPBUG, JUMPBUG_KEY );
	}

	void IniRead::Speed ( )
	{
		std::string Path = g_File.DirFile ( MISC_PATH ).c_str ( );

		INIREAD_FLOAT ( g_Vars.speed.value, SPEED, SPEED_VALUE );
		INIREAD_INT ( g_Vars.speed.engine_value, SPEED, SPEED_ENGINE_VALUE );

		INIREAD_FLOAT ( g_Vars.speed.speed_type, SPEED, SPEED_TYPE );
		INIREAD_STRING_CONVERT ( g_Vars.speed.boost_key, SPEED, SPEED_BOOST_KEY );

		INIREAD_FLOAT ( g_Vars.speed.slowmo, SPEED, SPEED_SLOWMO );
		INIREAD_STRING_CONVERT ( g_Vars.speed.slowmo_key, SPEED, SPEED_SLOWMO_KEY );
	}

	void IniRead::GStrafe ( )
	{
		std::string Path = g_File.DirFile ( MISC_PATH ).c_str ( );

		INIREAD_INT ( g_Vars.gstrafe.mouse_wheel_emulation, GSTRAFE, GSTRAFE_MWHEEL_EMU );
		INIREAD_STRING_CONVERT ( g_Vars.gstrafe.mouse_wheel_direction, GSTRAFE, GSTRAFE_MWHEEL_DIR );

		INIREAD_INT ( g_Vars.gstrafe.distance_type, GSTRAFE, GSTRAFE_DISTANCE_TYPE );
		INIREAD_STRING ( g_Vars.gstrafe.distance_string, GSTRAFE, GSTRAFE_DISTANCE );
		INIREAD_STRING ( g_Vars.gstrafe.count_string, GSTRAFE, GSTRAFE_COUNT );

		INIREAD_INT ( g_Vars.gstrafe.fallrun, GSTRAFE, GSTRAFE_FALLRUN );

		INIREAD_FLOAT ( g_Vars.gstrafe.slowdown_scale, GSTRAFE, GSTRAFE_SLOWDOWN_SCALE );
		INIREAD_FLOAT ( g_Vars.gstrafe.slowdown_groundangle, GSTRAFE, GSTRAFE_SLOWDOWN_ANGLE );

		INIREAD_FLOAT ( g_Vars.gstrafe.standup_fallvelocity, GSTRAFE, GSTRAFE_STANDUP_VEL );

		INIREAD_STRING_CONVERT ( g_Vars.gstrafe.standup_key, GSTRAFE, GSTRAFE_STANDUP_KEY );
		INIREAD_STRING_CONVERT ( g_Vars.gstrafe.key, GSTRAFE, GSTRAFE_KEY );

		g_Util.Parse ( 2, g_Vars.gstrafe.distance_string, g_Vars.gstrafe.distance );
		g_Util.Parse ( 2, g_Vars.gstrafe.count_string, g_Vars.gstrafe.count );
	}

	void IniRead::BHop ( )
	{
		std::string Path = g_File.DirFile ( MISC_PATH ).c_str ( );

		INIREAD_INT ( g_Vars.bhop.mouse_wheel_emulation, BHOP, BHOP_MWHEEL_EMU );
		INIREAD_STRING_CONVERT ( g_Vars.bhop.mouse_wheel_direction, BHOP, BHOP_MWHEEL_DIR );

		INIREAD_STRING ( g_Vars.bhop.distance_string, BHOP, BHOP_DISTANCE );
		INIREAD_INT ( g_Vars.bhop.distance_type, BHOP, BHOP_DISTANCE_TYPE );

		INIREAD_INT ( g_Vars.bhop.noslowdown, BHOP, BHOP_NOSLOWDOWN );

		INIREAD_INT ( g_Vars.bhop.in_water, BHOP, BHOP_INWATER );
		INIREAD_INT ( g_Vars.bhop.on_ladder, BHOP, BHOP_ONLADDER );

		INIREAD_INT ( g_Vars.bhop.standup, BHOP, BHOP_STANDUP );
		INIREAD_FLOAT ( g_Vars.bhop.standup_fallvelocity, BHOP, BHOP_STANDUP_VELOCITY );
		INIREAD_FLOAT ( g_Vars.bhop.standup_groundangle, BHOP, BHOP_STANDUP_ANGLE );

		INIREAD_STRING_CONVERT ( g_Vars.bhop.standup_key, BHOP, BHOP_STANDUP_KEY );
		INIREAD_STRING_CONVERT ( g_Vars.bhop.key, BHOP, BHOP_KEY );

		g_Util.Parse ( 2, g_Vars.bhop.distance_string, g_Vars.bhop.distance );
	}

	void IniRead::ScreenInfo ( )
	{
		std::string Path = g_File.DirFile ( VISUALS_PATH ).c_str ( );

		INIREAD_INT ( g_Vars.screeninfo.enable, mSCREENINFO, SCREENINFO_ENABLE );

		INIREAD_INT ( g_Vars.screeninfo.fps, mSCREENINFO, SCREENINFO_FPS );
		INIREAD_INT ( g_Vars.screeninfo.copyright, mSCREENINFO, SCREENINFO_COPYRIGHT );
		INIREAD_INT ( g_Vars.screeninfo.time, mSCREENINFO, SCREENINFO_TIME );
		INIREAD_INT ( g_Vars.screeninfo.showkeys, mSCREENINFO, SCREENINFO_SHOWKEYS );
		INIREAD_INT ( g_Vars.screeninfo.kreedz, mSCREENINFO, SCREENINFO_KREEDZ );

		INIREAD_STRING ( g_Vars.screeninfo.color_string, mSCREENINFO, SCREENINFO_COLOR );
		INIREAD_INT ( g_Vars.screeninfo.font_outline, mSCREENINFO, SCREENINFO_FONT_OUTLINE );

		INIREAD_INT ( g_Vars.screeninfo.debug, mSCREENINFO, SCREENINFO_DEBUG );

		g_Util.Parse ( 3, g_Vars.screeninfo.color_string, g_Vars.screeninfo.color );
	}

	void IniRead::NoFlash ( )
	{
		std::string Path = g_File.DirFile ( VISUALS_PATH ).c_str ( );

		INIREAD_INT ( g_Vars.noflash.enable, NOFLASH, NOFLASH_ENABLE );

		INIREAD_INT ( g_Vars.noflash.fade_limit, NOFLASH, NOFLASH_FADELIMIT );

		INIREAD_STRING ( g_Vars.noflash.fade_color_string, NOFLASH, NOFLASH_FADECOLOR );

		INIREAD_INT ( g_Vars.noflash.fade_color_random, NOFLASH, NOFLASH_FADECOLORRANDOM );
		INIREAD_INT ( g_Vars.noflash.show_percentage, NOFLASH, NOFLASH_SHOWPERCENTAGE );

		INIREAD_INT ( g_Vars.noflash.font_outline, NOFLASH, NOFLASH_FONT_OUTLINE );

		g_Util.Parse ( 3, g_Vars.noflash.fade_color_string, g_Vars.noflash.fade_color );
	}

	void IniRead::ESP ( )
	{
		std::string Path = g_File.DirFile ( VISUALS_PATH ).c_str ( );

		INIREAD_INT ( g_Vars.esp.enable, mESP, ESP_ENABLE );

		INIREAD_INT ( g_Vars.esp.player, mESP, ESP_PLAYER );
		INIREAD_INT ( g_Vars.esp.player_visible_check, mESP, ESP_PLAYER_VISIBLECHECK );
		INIREAD_INT ( g_Vars.esp.player_visible_only, mESP, ESP_PLAYER_VISIBLEONLY );
		INIREAD_INT ( g_Vars.esp.player_ignore_death, mESP, ESP_PLAYER_IGNORE_DEATH );

		INIREAD_INT ( g_Vars.esp.player_box, mESP, ESP_PLAYER_BOX );
		INIREAD_INT ( g_Vars.esp.player_box_linewidth, mESP, ESP_PLAYER_BOX_LW );
		INIREAD_INT ( g_Vars.esp.player_box_size, mESP, ESP_PLAYER_BOX_SIZE );

		INIREAD_STRING ( g_Vars.esp.color_t_vis_string, mESP, ESP_PLAYER_BOX_T_VIS );
		INIREAD_STRING ( g_Vars.esp.color_t_hide_string, mESP, ESP_PLAYER_BOX_T_HIDE );
		INIREAD_STRING ( g_Vars.esp.color_ct_vis_string, mESP, ESP_PLAYER_BOX_CT_VIS );
		INIREAD_STRING ( g_Vars.esp.color_ct_hide_string, mESP, ESP_PLAYER_BOX_CT_HIDE );

		INIREAD_INT ( g_Vars.esp.player_name, mESP, ESP_PLAYER_NAME );
		INIREAD_INT ( g_Vars.esp.player_weapon, mESP, ESP_PLAYER_WEAPON );
		INIREAD_INT ( g_Vars.esp.player_distance, mESP, ESP_PLAYER_DISTANCE );
		INIREAD_INT ( g_Vars.esp.player_barrel, mESP, ESP_PLAYER_BARREL );

		INIREAD_INT ( g_Vars.esp.world, mESP, ESP_WORLD );
		INIREAD_INT ( g_Vars.esp.world_weapons, mESP, ESP_WORLD_WEAPONS );
		INIREAD_INT ( g_Vars.esp.world_nades, mESP, ESP_WORLD_NADES );

		INIREAD_INT ( g_Vars.esp.c4timer, mESP, ESP_C4TIMER );
		INIREAD_INT ( g_Vars.esp.c4timer_value, mESP, ESP_C4TIMER_VALUE );

		INIREAD_INT ( g_Vars.esp.sound, mESP, ESP_SOUND );
		INIREAD_INT ( g_Vars.esp.sound_linewidth, mESP, ESP_SOUND_LINEWIDTH );
		INIREAD_INT ( g_Vars.esp.sound_fade_time, mESP, ESP_SOUND_FADE_TIME );
		INIREAD_STRING ( g_Vars.esp.sound_color_string, mESP, ESP_SOUND_COLOR );

		INIREAD_INT ( g_Vars.esp.font_outline, mESP, ESP_FONT_OUTLINE );
		INIREAD_STRING ( g_Vars.esp.font_color_string, mESP, ESP_FONT_COLOR );

		INIREAD_STRING_CONVERT ( g_Vars.esp.panic_key, mESP, ESP_PANIC_KEY );

		g_Util.Parse ( 3, g_Vars.esp.color_t_hide_string, g_Vars.esp.color_t_hide );
		g_Util.Parse ( 3, g_Vars.esp.color_t_vis_string, g_Vars.esp.color_t_vis );
		g_Util.Parse ( 3, g_Vars.esp.color_ct_hide_string, g_Vars.esp.color_ct_hide );
		g_Util.Parse ( 3, g_Vars.esp.color_ct_vis_string, g_Vars.esp.color_ct_vis );
		g_Util.Parse ( 3, g_Vars.esp.sound_color_string, g_Vars.esp.sound_color );
		g_Util.Parse ( 3, g_Vars.esp.font_color_string, g_Vars.esp.font_color );
	}

	void IniRead::Main ( )
	{
		std::string Path = g_File.DirFile ( MAIN_PATH ).c_str ( );

		INIREAD_STRING_CONVERT ( g_Vars.main.language, MAIN, MAIN_LANGUAGE );

		INIREAD_STRING_CONVERT ( g_Vars.main.reload_key, MAIN, MAIN_RELOAD_KEY );
		INIREAD_STRING_CONVERT ( g_Vars.main.panic_key, MAIN, MAIN_PANIC_KEY );

		INIREAD_INT ( g_Vars.main.player_scan_visibility, MAIN, MAIN_SCAN_VISIBILITY );
		INIREAD_INT ( g_Vars.main.player_valid_check, MAIN, MAIN_VALID_CHECK );
		INIREAD_INT ( g_Vars.main.font_outline_quality, MAIN, MAIN_OUTLINE_QUALITY );
	}

	void IniRead::Menu ( )
	{
		std::string Path = g_File.DirFile ( VISUALS_PATH ).c_str ( );

		INIREAD_INT ( g_Vars.menu.pos_x, MENU, MENU_POS_X );
		INIREAD_INT ( g_Vars.menu.pos_y, MENU, MENU_POS_Y );

		INIREAD_INT ( g_Vars.menu.box_height, MENU, MENU_BOX_HEIGHT );
		INIREAD_INT ( g_Vars.menu.box_width, MENU, MENU_BOX_WIDTH );

		INIREAD_STRING ( g_Vars.menu.box_color_string, MENU, MENU_BOX_COLOR );
		INIREAD_STRING ( g_Vars.menu.fill_color_string, MENU, MENU_FILL_COLOR );
		INIREAD_STRING ( g_Vars.menu.text_color_string, MENU, MENU_TEXT_COLOR );
		INIREAD_STRING ( g_Vars.menu.select_color_string, MENU, MENU_SELECT_COLOR );

		INIREAD_STRING_CONVERT ( g_Vars.menu.key, MENU, MENU_KEY );

		g_Util.Parse ( 4, g_Vars.menu.box_color_string, g_Vars.menu.box_color );
		g_Util.Parse ( 4, g_Vars.menu.fill_color_string, g_Vars.menu.fill_color );
		g_Util.Parse ( 4, g_Vars.menu.text_color_string, g_Vars.menu.text_color );
		g_Util.Parse ( 4, g_Vars.menu.select_color_string, g_Vars.menu.select_color );
	}

	void IniRead::Functions ( )
	{
		std::string Path = g_File.DirFile ( FUNCTIONS_PATH ).c_str ( );

		INIREAD_INT ( g_Vars.function.esp, FUNCTIONS, FUNCTIONS_ESP );
		INIREAD_INT ( g_Vars.function.noflash, FUNCTIONS, FUNCTIONS_NOFLASH );
		INIREAD_INT ( g_Vars.function.screeninfo, FUNCTIONS, FUNCTIONS_SCREEINFO );
		INIREAD_INT ( g_Vars.function.speed, FUNCTIONS, FUNCTIONS_SPEED );
		INIREAD_INT ( g_Vars.function.bhop, FUNCTIONS, FUNCTIONS_BHOP );
		INIREAD_INT ( g_Vars.function.gstrafe, FUNCTIONS, FUNCTIONS_GSTRAFE );
		INIREAD_INT ( g_Vars.function.jumpbug, FUNCTIONS, FUNCTIONS_JUMPBUG );
		INIREAD_INT ( g_Vars.function.edgebug, FUNCTIONS, FUNCTIONS_EDGEBUG );
		INIREAD_INT ( g_Vars.function.menu, FUNCTIONS, FUNCTIONS_MENU );

		INIREAD_INT ( g_Vars.function.commands, FUNCTIONS, FUNCTIONS_CMDS );
		INIREAD_STRING ( g_Util.Prefix, FUNCTIONS, FUNCTIONS_CMDS_PREFIX );
		INIREAD_INT ( g_Vars.function.commands_binds, FUNCTIONS, FUNCTIONS_CMDS_BINDS );
	}

	IniRead g_IniRead;
}