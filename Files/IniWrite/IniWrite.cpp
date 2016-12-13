#include "IniWrite.h"

namespace Files
{
	void IniWrite::EdgeBug ( )
	{
		std::string Path = g_File.DirFile ( MISC_PATH ).c_str ( );

		WRITE_INT ( EDGEBUG, EDGEBUG_AUTO, g_Vars.edgebug.auto_enable );
		WRITE_INT ( EDGEBUG, EDGEBUG_AUTO_DAMAGE, g_Vars.edgebug.auto_damage );

		WRITE_INT ( EDGEBUG, EDGEBUG_SPEED, g_Vars.edgebug.speed );

		WRITE_FLOAT ( EDGEBUG, EDGEBUG_DIST, g_Vars.edgebug.distance );
		WRITE_INT ( EDGEBUG, EDGEBUG_DIST_DYNAMIC, g_Vars.edgebug.distance_auto );
	}

	void IniWrite::JumpBug ( )
	{
		std::string Path = g_File.DirFile ( MISC_PATH ).c_str ( );

		WRITE_INT ( JUMPBUG, JUMPBUG_AUTO, g_Vars.jumpbug.auto_enable );
		WRITE_INT ( JUMPBUG, JUMPBUG_AUTO_DAMAGE, g_Vars.jumpbug.auto_damage );
		WRITE_INT ( JUMPBUG, JUMPBUG_AUTO_PERCENTAGE, g_Vars.jumpbug.auto_percentage );

		WRITE_INT ( JUMPBUG, JUMPBUG_SLOWDOWN, g_Vars.jumpbug.slowdown );
		WRITE_FLOAT ( JUMPBUG, JUMPBUG_SLOWDOWN_DIST, g_Vars.jumpbug.slowdown_distance );

		WRITE_INT ( JUMPBUG, JUMPBUG_SLOWMOTION, g_Vars.jumpbug.slowmotion );
	}

	void IniWrite::Speed ( )
	{
		std::string Path = g_File.DirFile ( MISC_PATH ).c_str ( );

		WRITE_FLOAT ( SPEED, SPEED_VALUE, g_Vars.speed.value );
		WRITE_INT ( SPEED, SPEED_ENGINE_VALUE, g_Vars.speed.engine_value );

		WRITE_INT ( SPEED, SPEED_TYPE, g_Vars.speed.speed_type );

		if ( g_Vars.speed.speed_type == 1 )
		{
			WRITE_FLOAT ( SPEED, SPEED_BOOST, g_Vars.speed.boost );
		}
		else if ( g_Vars.speed.speed_type == 2 )
		{
			WRITE_INT ( SPEED, SPEED_BOOST, g_Vars.speed.boost );
		}

		if ( g_Vars.speed.speed_type == 1 )
		{
			WRITE_FLOAT ( SPEED, SPEED_SLOWMO, g_Vars.speed.slowmo );
		}
		else if ( g_Vars.speed.speed_type == 2 )
		{
			WRITE_INT ( SPEED, SPEED_SLOWMO, g_Vars.speed.slowmo );
		}
	}

	void IniWrite::GStrafe ( )
	{
		std::string Path = g_File.DirFile ( MISC_PATH ).c_str ( );

		WRITE_INT ( GSTRAFE, GSTRAFE_MWHEEL_EMU, g_Vars.gstrafe.mouse_wheel_emulation );
		WRITE_DIR ( GSTRAFE, GSTRAFE_MWHEEL_DIR, g_Vars.gstrafe.mouse_wheel_direction );

		WRITE_INT ( GSTRAFE, GSTRAFE_DISTANCE_TYPE, g_Vars.gstrafe.distance_type );
		WRITE_FLOAT_2 ( GSTRAFE, GSTRAFE_DISTANCE, g_Vars.gstrafe.distance[0], g_Vars.gstrafe.distance[1] );
		WRITE_INT_2 ( GSTRAFE, GSTRAFE_COUNT, g_Vars.gstrafe.count[0], g_Vars.gstrafe.count[1] );

		WRITE_INT ( GSTRAFE, GSTRAFE_FALLRUN, g_Vars.gstrafe.fallrun );

		WRITE_FLOAT ( GSTRAFE, GSTRAFE_SLOWDOWN_SCALE, g_Vars.gstrafe.slowdown_scale );

		WRITE_FLOAT ( GSTRAFE, GSTRAFE_STANDUP_VEL, g_Vars.gstrafe.standup_fallvelocity );
	}

	void IniWrite::BHop ( )
	{
		std::string Path = g_File.DirFile ( MISC_PATH ).c_str ( );

		WRITE_INT ( BHOP, BHOP_MWHEEL_EMU, g_Vars.bhop.mouse_wheel_emulation );
		WRITE_DIR ( BHOP, BHOP_MWHEEL_DIR, g_Vars.bhop.mouse_wheel_direction );

		WRITE_FLOAT_2 ( BHOP, BHOP_DISTANCE, g_Vars.bhop.distance[0], g_Vars.bhop.distance[1] );
		WRITE_INT ( BHOP, BHOP_DISTANCE_TYPE, g_Vars.bhop.distance_type );

		WRITE_INT ( BHOP, BHOP_NOSLOWDOWN, g_Vars.bhop.noslowdown );
		WRITE_INT ( BHOP, BHOP_ONLADDER, g_Vars.bhop.on_ladder );

		WRITE_INT ( BHOP, BHOP_STANDUP, g_Vars.bhop.standup );
		WRITE_FLOAT ( BHOP, BHOP_STANDUP_VELOCITY, g_Vars.bhop.standup_fallvelocity );
		WRITE_FLOAT ( BHOP, BHOP_STANDUP_ANGLE, g_Vars.bhop.standup_groundangle );

		WRITE_INT ( BHOP, BHOP_INWATER, g_Vars.bhop.in_water );
	}

	void IniWrite::ScreenInfo ( )
	{
		std::string Path = g_File.DirFile ( VISUALS_PATH ).c_str ( );

		WRITE_INT ( mSCREENINFO, SCREENINFO_ENABLE, g_Vars.screeninfo.enable );

		WRITE_INT ( mSCREENINFO, SCREENINFO_FPS, g_Vars.screeninfo.fps );
		WRITE_INT ( mSCREENINFO, SCREENINFO_COPYRIGHT, g_Vars.screeninfo.copyright );
		WRITE_INT ( mSCREENINFO, SCREENINFO_TIME, g_Vars.screeninfo.time );
		WRITE_INT ( mSCREENINFO, SCREENINFO_SHOWKEYS, g_Vars.screeninfo.showkeys );
		WRITE_INT ( mSCREENINFO, SCREENINFO_KREEDZ, g_Vars.screeninfo.kreedz );

		WRITE_COLOR ( mSCREENINFO, SCREENINFO_COLOR, g_Vars.screeninfo.color[0], g_Vars.screeninfo.color[1], g_Vars.screeninfo.color[2] );
		WRITE_INT ( mSCREENINFO, SCREENINFO_FONT_OUTLINE, g_Vars.screeninfo.font_outline );

		WRITE_INT ( mSCREENINFO, SCREENINFO_DEBUG, g_Vars.screeninfo.debug );
	}

	void IniWrite::NoFlash ( )
	{
		std::string Path = g_File.DirFile ( VISUALS_PATH ).c_str ( );

		WRITE_INT ( NOFLASH, NOFLASH_ENABLE, g_Vars.noflash.enable );

		WRITE_INT ( NOFLASH, NOFLASH_FADELIMIT, g_Vars.noflash.fade_limit );

		WRITE_COLOR ( NOFLASH, NOFLASH_FADECOLOR, g_Vars.noflash.fade_color[0], g_Vars.noflash.fade_color[1], g_Vars.noflash.fade_color[2] );

		WRITE_INT ( NOFLASH, NOFLASH_FADECOLORRANDOM, g_Vars.noflash.fade_color_random );
		WRITE_INT ( NOFLASH, NOFLASH_SHOWPERCENTAGE, g_Vars.noflash.show_percentage );

		WRITE_INT ( NOFLASH, NOFLASH_FONT_OUTLINE, g_Vars.noflash.font_outline );
	}

	void IniWrite::ESP ( )
	{
		std::string Path = g_File.DirFile ( VISUALS_PATH ).c_str ( );

		WRITE_INT ( mESP, ESP_ENABLE, g_Vars.esp.enable );

		WRITE_INT ( mESP, ESP_PLAYER, g_Vars.esp.player );
		WRITE_INT ( mESP, ESP_PLAYER_VISIBLECHECK, g_Vars.esp.player_visible_check );
		WRITE_INT ( mESP, ESP_PLAYER_VISIBLEONLY, g_Vars.esp.player_visible_only );
		WRITE_INT ( mESP, ESP_PLAYER_IGNORE_DEATH, g_Vars.esp.player_ignore_death );

		WRITE_INT ( mESP, ESP_PLAYER_BOX, g_Vars.esp.player_box );
		WRITE_INT ( mESP, ESP_PLAYER_BOX_LW, g_Vars.esp.player_box_linewidth );
		WRITE_FLOAT ( mESP, ESP_PLAYER_BOX_SIZE, g_Vars.esp.player_box_size );

		WRITE_COLOR ( mESP, ESP_PLAYER_BOX_T_VIS, g_Vars.esp.color_t_vis[0], g_Vars.esp.color_t_vis[1], g_Vars.esp.color_t_vis[2] );
		WRITE_COLOR ( mESP, ESP_PLAYER_BOX_T_HIDE, g_Vars.esp.color_t_hide[0], g_Vars.esp.color_t_hide[1], g_Vars.esp.color_t_hide[2] );
		WRITE_COLOR ( mESP, ESP_PLAYER_BOX_CT_VIS, g_Vars.esp.color_ct_vis[0], g_Vars.esp.color_ct_vis[1], g_Vars.esp.color_ct_vis[2] );
		WRITE_COLOR ( mESP, ESP_PLAYER_BOX_CT_HIDE, g_Vars.esp.color_ct_hide[0], g_Vars.esp.color_ct_hide[1], g_Vars.esp.color_ct_hide[2] );

		WRITE_INT ( mESP, ESP_PLAYER_NAME, g_Vars.esp.player_name );
		WRITE_INT ( mESP, ESP_PLAYER_WEAPON, g_Vars.esp.player_weapon );
		WRITE_INT ( mESP, ESP_PLAYER_DISTANCE, g_Vars.esp.player_distance );
		WRITE_INT ( mESP, ESP_PLAYER_BARREL, g_Vars.esp.player_barrel );

		WRITE_INT ( mESP, ESP_WORLD, g_Vars.esp.world );
		WRITE_INT ( mESP, ESP_WORLD_WEAPONS, g_Vars.esp.world_weapons );
		WRITE_INT ( mESP, ESP_WORLD_NADES, g_Vars.esp.world_nades );

		WRITE_INT ( mESP, ESP_C4TIMER, g_Vars.esp.c4timer );
		WRITE_INT ( mESP, ESP_C4TIMER_VALUE, g_Vars.esp.c4timer_value );

		WRITE_INT ( mESP, ESP_SOUND, g_Vars.esp.sound );
		WRITE_INT ( mESP, ESP_SOUND_LINEWIDTH, g_Vars.esp.sound_linewidth );
		WRITE_INT ( mESP, ESP_SOUND_FADE_TIME, g_Vars.esp.sound_fade_time );

		WRITE_COLOR ( mESP, ESP_SOUND_COLOR, g_Vars.esp.sound_color[0], g_Vars.esp.sound_color[1], g_Vars.esp.sound_color[2] );

		WRITE_INT ( mESP, ESP_FONT_OUTLINE, g_Vars.esp.font_outline );

		WRITE_COLOR ( mESP, ESP_FONT_COLOR, g_Vars.esp.font_color[0], g_Vars.esp.font_color[1], g_Vars.esp.font_color[2] );
	}

	void IniWrite::Main ( )
	{
		std::string Path = g_File.DirFile ( MAIN_PATH ).c_str ( );

		WRITE_INT ( MAIN, MAIN_SCAN_VISIBILITY, g_Vars.main.player_scan_visibility );
		WRITE_INT ( MAIN, MAIN_VALID_CHECK, g_Vars.main.player_valid_check );

		WRITE_INT ( MAIN, MAIN_OUTLINE_QUALITY, g_Vars.main.font_outline_quality );
	}

	void IniWrite::Menu ( )
	{
		std::string Path = g_File.DirFile ( VISUALS_PATH ).c_str ( );

		WRITE_INT ( MENU, MENU_POS_X, g_Vars.menu.pos_x );
		WRITE_INT ( MENU, MENU_POS_Y, g_Vars.menu.pos_y );

		WRITE_INT ( MENU, MENU_BOX_HEIGHT, g_Vars.menu.box_height );
		WRITE_INT ( MENU, MENU_BOX_WIDTH, g_Vars.menu.box_width );

		WRITE_COLOR_4 ( MENU, MENU_BOX_COLOR, g_Vars.menu.box_color[0],
			g_Vars.menu.box_color[1], g_Vars.menu.box_color[2], g_Vars.menu.box_color[3] );

		WRITE_COLOR_4 ( MENU, MENU_FILL_COLOR, g_Vars.menu.fill_color[0],
			g_Vars.menu.fill_color[1], g_Vars.menu.fill_color[2], g_Vars.menu.fill_color[3] );

		WRITE_COLOR_4 ( MENU, MENU_TEXT_COLOR, g_Vars.menu.text_color[0],
			g_Vars.menu.text_color[1], g_Vars.menu.text_color[2], g_Vars.menu.text_color[3] );

		WRITE_COLOR_4 ( MENU, MENU_SELECT_COLOR, g_Vars.menu.select_color[0],
			g_Vars.menu.select_color[1], g_Vars.menu.select_color[2], g_Vars.menu.select_color[3] );
	}

	IniWrite g_IniWrite;
}