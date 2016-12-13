#include "ConsoleCmds.h"

namespace Engine
{
	void Command::ConsoleCommands ( )
	{
		if ( g_Vars.function.edgebug )
		{
			rcmd ( "edgebug", EdgeBugOn, EdgeBugOff );
			acmd ( "edgebug_distance_auto", EdgeBugDistanceAuto );
			acmd ( "edgebug_distance", EdgeBugDistance );
			acmd ( "edgebug_speed", EdgeBugSpeed );
			acmd ( "edgebug_auto_damage", EdgeBugAutoDamage );
			acmd ( "edgebug_auto", EdgeBugAuto );
		}

		if ( g_Vars.function.jumpbug )
		{
			rcmd ( "jumpbug", JumpBugOn, JumpBugOff );
			acmd ( "jumpbug_slowmotion", JumpBugSlowMotion );
			acmd ( "jumpbug_slowdown_distance", JumpBugSlowDownDistance );
			acmd ( "jumpbug_slowdown", JumpBugSlowDown );
			acmd ( "jumpbug_auto_percentage", JumpBugAutoPercentage );
			acmd ( "jumpbug_auto_damage", JumpBugAutoDamage );
			acmd ( "jumpbug_auto", JumpBugAuto );
		}

		if ( g_Vars.function.gstrafe )
		{
			rcmd ( "groundstrafe", GroundStrafeOn, GroundStrafeOff );
			rcmd ( "groundstrafe_standup", GroundStrafeStandUpOn, GroundStrafeStandUpOff );
			acmd ( "groundstrafe_standup_fallvelocity", GroundStrafeStandUpFallVelocity );
			acmd ( "groundstrafe_slowdown_groundangle", GroundStrafeSlowDownGroundAngle );
			acmd ( "groundstrafe_slowdown_scale", GroundStrafeSlowDownScale );
			acmd ( "groundstrafe_fallrun", GroundStrafeFallRun );
			acmd ( "groundstrafe_count", GroundStrafeCount );
			acmd ( "groundstrafe_distance", GroundStrafeDistance );
			acmd ( "groundstrafe_distance_type", GroundStrafeDistanceType );
			acmd ( "groundstrafe_mousewheel_direction", GroundStrafeMouseWheelDirection );
			acmd ( "groundstrafe_mousewheel_emulation", GroundStrafeMouseWheelEmulation );
		}

		if ( g_Vars.function.bhop )
		{
			rcmd ( "bunnyhop", BunnyHopOn, BunnyHopOff );
			rcmd ( "bunnyhop_standup", BunnyHopStandUpOn, BunnyHopStandUpOff );
			acmd ( "bunnyhop_standup_groundangle", BunnyHopStandUpGroundAngle );
			acmd ( "bunnyhop_standup_fallvelocity", BunnyHopStandUpFallVelocity );
			acmd ( "bunnyhop_standup", BunnyHopStandUp );
			acmd ( "bunnyhop_on_ladder", BunnyHopOnLadder );
			acmd ( "bunnyhop_in_water", BunnyHopInWater );
			acmd ( "bunnyhop_noslowdown", BunnyHopNoSlowDown );		
			acmd ( "bunnyhop_distance", BunnyHopDistance );
			acmd ( "bunnyhop_distance_type", BunnyHopDistanceType );
			acmd ( "bunnyhop_mousewheel_direction", BunnyHopMouseWheelDirection );
			acmd ( "bunnyhop_mousewheel_emulation", BunnyHopMouseWheelEmulation );
		}

		if ( g_Vars.function.speed )
		{
			rcmd ( "speed_slowmo", SpeedSlowMoOn, SpeedSlowMoOff );
			rcmd ( "speed_boost", SpeedBoostOn, SpeedBoostOff );
			acmd ( "speed_slowmo", SpeedSlowMo );
			acmd ( "speed_boost", SpeedBoost );
			acmd ( "speed_type", SpeedType );
			acmd ( "speed_engine", SpeedEngine );
			acmd ( "speed", Speed );
		}

		if ( g_Vars.function.screeninfo )
		{
			acmd ( "screeninfo_font_out_line", ScreenInfoFontOutLine );
			acmd ( "screeninfo_color", ScreenInfoColor );
			acmd ( "screeninfo_kreedz", ScreenInfoKreedz );
			acmd ( "screeninfo_showkeys", ScreenInfoShowKeys );
			acmd ( "screeninfo_time", ScreenInfoTime );
			acmd ( "screeninfo_copyright", ScreenInfoCopyRight );
			acmd ( "screeninfo_fps", ScreenInfoFPS );
			acmd ( "screeninfo_enable", ScreenInfoEnable );
		}

		if ( g_Vars.function.noflash )
		{
			acmd ( "noflash_font_outline", NoFlashFontOutLine );
			acmd ( "noflash_show_percentage", NoFlashShowPercentage );
			acmd ( "noflash_fade_color_random", NoFlashFadeColorRandom );
			acmd ( "noflash_fade_color", NoFlashFadeColor );
			acmd ( "noflash_fade_limit", NoFlashFadeLimit );
			acmd ( "noflash_enable", NoFlashEnable );
		}

		if ( g_Vars.function.esp )
		{
			acmd ( "esp_panic", ESPPanic );
			acmd ( "esp_font_color", ESPFontColor );
			acmd ( "esp_font_out_line", ESPFontOutLine );
			acmd ( "esp_sound_color", ESPSoundColor );
			acmd ( "esp_sound_fade_time", ESPSoundFadeTime );
			acmd ( "esp_sound_line_width", ESPSoundLineWidth );
			acmd ( "esp_sound", ESPSound );
			acmd ( "esp_c4timer_value", ESPC4TimerValue );
			acmd ( "esp_c4timer", ESPC4Timer );
			acmd ( "esp_world_nades", ESPWorldNades );
			acmd ( "esp_world_weapons", ESPWorldWeapons );
			acmd ( "esp_world", ESPWorld );
			acmd ( "esp_player_barrel", ESPPlayerBarrel );
			acmd ( "esp_player_distance", ESPPlayerDistance );
			acmd ( "esp_player_weapon", ESPPlayerWeapon );
			acmd ( "esp_player_name", ESPPlayerName );
			acmd ( "esp_player_box_ct_hide", ESPPlayerBoxCTHide );
			acmd ( "esp_player_box_ct_vis", ESPPlayerBoxCTVis );
			acmd ( "esp_player_box_t_hide", ESPPlayerBoxTHide );
			acmd ( "esp_player_box_t_vis", ESPPlayerBoxTVis );
			acmd ( "esp_player_box_size", ESPPlayerBoxSize );
			acmd ( "esp_player_box_line_width", ESPPlayerBoxLineWidth );
			acmd ( "esp_player_box", ESPPlayerBox );
			acmd ( "esp_player_ignore_death", ESPPlayerIgnoreDeath );
			acmd ( "esp_player_visible_only", ESPPlayerVisibleOnly );
			acmd ( "esp_player_visible_check", ESPPlayerVisibleCheck );
			acmd ( "esp_player", ESPPlayer );
			acmd ( "esp_enable", ESPEnable );
		}

		if ( g_Vars.function.menu )
		{
			acmd ( "menu_select_color", MenuSelectColor );
			acmd ( "menu_text_color", MenuTextColor );
			acmd ( "menu_fill_color", MenuFillColor );
			acmd ( "menu_box_color", MenuBoxColor );
			acmd ( "menu_box_height", MenuBoxHeight );
			acmd ( "menu_pos_y", MenuPos_y );
			acmd ( "menu_pos_x", MenuPos_x );
		}

		acmd ( "font_outline_quality", FontOutLineQuality );
		acmd ( "player_valid_check", PlayerValidCheck );
		acmd ( "player_scan_visibility", PlayerScanVisibility );
		acmd ( "panic", Panic );
		acmd ( "reload_settings", ReloadSettings );
		acmd ( "exec", ExecConfig );

		if ( g_Vars.function.commands_binds )
		{
			acmd ( "bind", Bind );
			acmd ( "unbindall", UnBindAll );
			acmd ( "unbind", UnBind );
		}
	}

	void Command::ExecConfig ( )
	{
		Initial::g_Init.RunScript ( g_Engine.Cmd_Argv ( 1 ) );
	}

	void Command::ReloadSettings ( )
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

	void Command::Panic ( )
	{
		Client::g_Hpp.PanicEnabled = !Client::g_Hpp.PanicEnabled;

		Engine::g_Engine.pfnPlaySoundByName ( Client::g_Hpp.PanicEnabled ? "vox/of.wav" : "vox/on.wav", 1 );
	}

	void Command::PlayerScanVisibility ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "player_scan_visibility", g_Vars.main.player_scan_visibility )
		}
		else
		{
			PRINT_ATOI ( "player_scan_visibility", g_Vars.main.player_scan_visibility )
		}
	}

	void Command::PlayerValidCheck ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "player_valid_check", g_Vars.main.player_valid_check )
		}
		else
		{
			PRINT_ATOI ( "player_valid_check", g_Vars.main.player_valid_check )
		}
	}

	void Command::FontOutLineQuality ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "font_outline_quality", g_Vars.main.font_outline_quality )
		}
		else
		{
			PRINT_ATOI ( "font_outline_quality", g_Vars.main.font_outline_quality )
		}
	}

	void Command::MenuPos_x ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "menu_pos_x", g_Vars.menu.pos_x )
		}
		else
		{
			PRINT_ATOI ( "menu_pos_x", g_Vars.menu.pos_x )
		}
	}

	void Command::MenuPos_y ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "menu_pos_y", g_Vars.menu.pos_y )
		}
		else
		{
			PRINT_ATOI ( "menu_pos_y", g_Vars.menu.pos_y )
		}
	}

	void Command::MenuBoxHeight ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "menu_box_height", g_Vars.menu.box_height )
		}
		else
		{
			PRINT_ATOI ( "menu_box_height", g_Vars.menu.box_height )
		}
	}

	void Command::MenuBoxColor ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 5 )
		{
			PRINT_COLOR_IS_4 ( "menu_box_color", g_Vars.menu.box_color[0],
				g_Vars.menu.box_color[1], g_Vars.menu.box_color[2], g_Vars.menu.box_color[3] )
		}
		else
		{
			PRINT_COLOR_ATOI_4 ( "menu_box_color", g_Vars.menu.box_color[0],
				g_Vars.menu.box_color[1], g_Vars.menu.box_color[2], g_Vars.menu.box_color[3] );
		}
	}

	void Command::MenuFillColor ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 5 )
		{
			PRINT_COLOR_IS_4 ( "menu_fill_color", g_Vars.menu.fill_color[0],
				g_Vars.menu.fill_color[1], g_Vars.menu.fill_color[2], g_Vars.menu.fill_color[3] )
		}
		else
		{
			PRINT_COLOR_ATOI_4 ( "menu_fill_color", g_Vars.menu.fill_color[0],
				g_Vars.menu.fill_color[1], g_Vars.menu.fill_color[2], g_Vars.menu.fill_color[3] );
		}
	}

	void Command::MenuTextColor ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 5 )
		{
			PRINT_COLOR_IS_4 ( "menu_text_color", g_Vars.menu.text_color[0],
				g_Vars.menu.text_color[1], g_Vars.menu.text_color[2], g_Vars.menu.text_color[3] )
		}
		else
		{
			PRINT_COLOR_ATOI_4 ( "menu_text_color", g_Vars.menu.text_color[0],
				g_Vars.menu.text_color[1], g_Vars.menu.text_color[2], g_Vars.menu.text_color[3] );
		}
	}

	void Command::MenuSelectColor ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 5 )
		{
			PRINT_COLOR_IS_4 ( "menu_select_color", g_Vars.menu.select_color[0],
				g_Vars.menu.select_color[1], g_Vars.menu.select_color[2], g_Vars.menu.select_color[3] )
		}
		else
		{
			PRINT_COLOR_ATOI_4 ( "menu_select_color", g_Vars.menu.select_color[0],
				g_Vars.menu.select_color[1], g_Vars.menu.select_color[2], g_Vars.menu.select_color[3] );
		}
	}

	void Command::ESPEnable ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_enable", g_Vars.esp.enable )
		}
		else
		{
			PRINT_ATOI ( "esp_enable", g_Vars.esp.enable )
		}
	}

	void Command::ESPPlayer ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_player", g_Vars.esp.player )
		}
		else
		{
			PRINT_ATOI ( "esp_player", g_Vars.esp.player )
		}
	}

	void Command::ESPPlayerVisibleCheck ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_player_visible_check", g_Vars.esp.player_visible_check )
		}
		else
		{
			PRINT_ATOI ( "esp_player_visible_check", g_Vars.esp.player_visible_check )
		}
	}

	void Command::ESPPlayerVisibleOnly ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_player_visible_only", g_Vars.esp.player_visible_only )
		}
		else
		{
			PRINT_ATOI ( "esp_player_visible_only", g_Vars.esp.player_visible_only )
		}
	}

	void Command::ESPPlayerIgnoreDeath ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_player_ignore_death", g_Vars.esp.player_ignore_death )
		}
		else
		{
			PRINT_ATOI ( "esp_player_ignore_death", g_Vars.esp.player_ignore_death )
		}
	}

	void Command::ESPPlayerBox ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_player_box", g_Vars.esp.player_box )
		}
		else
		{
			PRINT_ATOI ( "esp_player_box", g_Vars.esp.player_box )
		}
	}

	void Command::ESPPlayerBoxLineWidth ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_player_box_line_width", g_Vars.esp.player_box_linewidth )
		}
		else
		{
			PRINT_ATOI ( "esp_player_box_line_width", g_Vars.esp.player_box_linewidth )
		}
	}

	void Command::ESPPlayerBoxSize ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS_FLOAT ( "esp_player_box_size", g_Vars.esp.player_box_size )
		}
		else
		{
			PRINT_ATOF ( "esp_player_box_size", g_Vars.esp.player_box_size )
		}
	}

	void Command::ESPPlayerBoxTVis ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 4 )
		{
			PRINT_COLOR_IS_3 ( "esp_player_box_t_vis", g_Vars.esp.color_t_vis[0],
				g_Vars.esp.color_t_vis[1], g_Vars.esp.color_t_vis[2] )
		}
		else
		{
			PRINT_COLOR_ATOI_3 ( "esp_player_box_t_vis", g_Vars.esp.color_t_vis[0],
				g_Vars.esp.color_t_vis[1], g_Vars.esp.color_t_vis[2] );
		}
	}

	void Command::ESPPlayerBoxTHide ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 4 )
		{
			PRINT_COLOR_IS_3 ( "esp_player_box_t_hide", g_Vars.esp.color_t_hide[0],
				g_Vars.esp.color_t_hide[1], g_Vars.esp.color_t_hide[2] )
		}
		else
		{
			PRINT_COLOR_ATOI_3 ( "esp_player_box_t_hide", g_Vars.esp.color_t_hide[0],
				g_Vars.esp.color_t_hide[1], g_Vars.esp.color_t_hide[2] );
		}
	}

	void Command::ESPPlayerBoxCTVis ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 4 )
		{
			PRINT_COLOR_IS_3 ( "esp_player_box_ct_vis", g_Vars.esp.color_ct_vis[0],
				g_Vars.esp.color_ct_vis[1], g_Vars.esp.color_ct_vis[2] )
		}
		else
		{
			PRINT_COLOR_ATOI_3 ( "esp_player_box_ct_vis", g_Vars.esp.color_ct_vis[0],
				g_Vars.esp.color_ct_vis[1], g_Vars.esp.color_ct_vis[2] );
		}
	}

	void Command::ESPPlayerBoxCTHide ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 4 )
		{
			PRINT_COLOR_IS_3 ( "esp_player_box_ct_hide", g_Vars.esp.color_ct_hide[0],
				g_Vars.esp.color_ct_hide[1], g_Vars.esp.color_ct_hide[2] )
		}
		else
		{
			PRINT_COLOR_ATOI_3 ( "esp_player_box_ct_hide", g_Vars.esp.color_ct_hide[0],
				g_Vars.esp.color_ct_hide[1], g_Vars.esp.color_ct_hide[2] );
		}
	}

	void Command::ESPPlayerName ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_player_name", g_Vars.esp.player_name )
		}
		else
		{
			PRINT_ATOI ( "esp_player_name", g_Vars.esp.player_name )
		}
	}

	void Command::ESPPlayerWeapon ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_player_weapon", g_Vars.esp.player_weapon )
		}
		else
		{
			PRINT_ATOI ( "esp_player_weapon", g_Vars.esp.player_weapon )
		}
	}

	void Command::ESPPlayerDistance ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_player_distance", g_Vars.esp.player_distance )
		}
		else
		{
			PRINT_ATOI ( "esp_player_distance", g_Vars.esp.player_distance )
		}
	}

	void Command::ESPPlayerBarrel ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_player_barrel", g_Vars.esp.player_barrel )
		}
		else
		{
			PRINT_ATOI ( "esp_player_barrel", g_Vars.esp.player_barrel )
		}
	}

	void Command::ESPWorld ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_world", g_Vars.esp.world )
		}
		else
		{
			PRINT_ATOI ( "esp_world", g_Vars.esp.world )
		}
	}

	void Command::ESPWorldWeapons ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_world_weapons", g_Vars.esp.world_weapons )
		}
		else
		{
			PRINT_ATOI ( "esp_world_weapons", g_Vars.esp.world_weapons )
		}
	}

	void Command::ESPWorldNades ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_world_nades", g_Vars.esp.world_nades )
		}
		else
		{
			PRINT_ATOI ( "esp_world_nades", g_Vars.esp.world_nades )
		}
	}

	void Command::ESPC4Timer ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_c4timer", g_Vars.esp.c4timer )
		}
		else
		{
			PRINT_ATOI ( "esp_c4timer", g_Vars.esp.c4timer )
		}
	}

	void Command::ESPC4TimerValue ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_c4timer_value", g_Vars.esp.c4timer_value )
		}
		else
		{
			PRINT_ATOI ( "esp_c4timer_value", g_Vars.esp.c4timer_value )
		}
	}

	void Command::ESPSound ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_sound", g_Vars.esp.sound )
		}
		else
		{
			PRINT_ATOI ( "esp_sound", g_Vars.esp.sound )
		}
	}

	void Command::ESPSoundLineWidth ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_sound_line_width", g_Vars.esp.sound_linewidth )
		}
		else
		{
			PRINT_ATOI ( "esp_sound_line_width", g_Vars.esp.sound_linewidth )
		}
	}

	void Command::ESPSoundFadeTime ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_sound_fade_time", g_Vars.esp.sound_fade_time )
		}
		else
		{
			PRINT_ATOI ( "esp_sound_fade_time", g_Vars.esp.sound_fade_time )
		}
	}

	void Command::ESPSoundColor ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 4 )
		{
			PRINT_COLOR_IS_3 ( "esp_sound_color", g_Vars.esp.sound_color[0],
				g_Vars.esp.sound_color[1], g_Vars.esp.sound_color[2] )
		}
		else
		{
			PRINT_COLOR_ATOI_3 ( "esp_sound_color", g_Vars.esp.sound_color[0],
				g_Vars.esp.sound_color[1], g_Vars.esp.sound_color[2] );
		}
	}

	void Command::ESPFontOutLine ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_font_out_line", g_Vars.esp.font_outline )
		}
		else
		{
			PRINT_ATOI ( "esp_font_out_line", g_Vars.esp.font_outline )
		}
	}

	void Command::ESPFontColor ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 4 )
		{
			PRINT_COLOR_IS_3 ( "esp_font_color", g_Vars.esp.font_color[0],
				g_Vars.esp.font_color[1], g_Vars.esp.font_color[2] )
		}
		else
		{
			PRINT_COLOR_ATOI_3 ( "esp_font_color", g_Vars.esp.font_color[0],
				g_Vars.esp.font_color[1], g_Vars.esp.font_color[2] );
		}
	}

	void Command::ESPPanic ( )
	{
		Functions::Visuals::g_ESP.PanicEnabled = !Functions::Visuals::g_ESP.PanicEnabled;

		Engine::g_Engine.pfnPlaySoundByName ( Functions::Visuals::g_ESP.PanicEnabled ? "vox/of.wav" : "vox/on.wav", 1 );
	}

	void Command::NoFlashEnable ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "noflash_enable", g_Vars.noflash.enable )
		}
		else
		{
			PRINT_ATOI ( "noflash_enable", g_Vars.noflash.enable )
		}
	}

	void Command::NoFlashFadeLimit ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "noflash_fade_limit", g_Vars.noflash.fade_limit )
		}
		else
		{
			PRINT_ATOI ( "noflash_fade_limit", g_Vars.noflash.fade_limit )
		}
	}

	void Command::NoFlashFadeColor ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 4 )
		{
			PRINT_COLOR_IS_3 ( "noflash_fade_color", g_Vars.noflash.fade_color[0],
				g_Vars.noflash.fade_color[1], g_Vars.noflash.fade_color[2] )
		}
		else
		{
			PRINT_COLOR_ATOI_3 ( "noflash_fade_color", g_Vars.noflash.fade_color[0],
				g_Vars.noflash.fade_color[1], g_Vars.noflash.fade_color[2] );
		}
	}

	void Command::NoFlashFadeColorRandom ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "noflash_fade_color_random", g_Vars.noflash.fade_color_random )
		}
		else
		{
			PRINT_ATOI ( "noflash_fade_color_random", g_Vars.noflash.fade_color_random )
		}
	}

	void Command::NoFlashShowPercentage ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "noflash_show_percentage", g_Vars.noflash.show_percentage )
		}
		else
		{
			PRINT_ATOI ( "noflash_show_percentage", g_Vars.noflash.show_percentage )
		}
	}

	void Command::NoFlashFontOutLine ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "noflash_font_outline", g_Vars.noflash.font_outline )
		}
		else
		{
			PRINT_ATOI ( "noflash_font_outline", g_Vars.noflash.font_outline )
		}
	}

	void Command::ScreenInfoEnable ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "screeninfo_enable", g_Vars.screeninfo.enable )
		}
		else
		{
			PRINT_ATOI ( "screeninfo_enable", g_Vars.screeninfo.enable )
		}
	}

	void Command::ScreenInfoFPS ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "screeninfo_fps", g_Vars.screeninfo.fps )
		}
		else
		{
			PRINT_ATOI ( "screeninfo_fps", g_Vars.screeninfo.fps )
		}
	}

	void Command::ScreenInfoCopyRight ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "screeninfo_copyright", g_Vars.screeninfo.copyright )
		}
		else
		{
			PRINT_ATOI ( "screeninfo_copyright", g_Vars.screeninfo.copyright )
		}
	}

	void Command::ScreenInfoTime ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "screeninfo_time", g_Vars.screeninfo.time )
		}
		else
		{
			PRINT_ATOI ( "screeninfo_time", g_Vars.screeninfo.time )
		}
	}

	void Command::ScreenInfoShowKeys ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "screeninfo_showkeys", g_Vars.screeninfo.showkeys )
		}
		else
		{
			PRINT_ATOI ( "screeninfo_showkeys", g_Vars.screeninfo.showkeys )
		}
	}

	void Command::ScreenInfoKreedz ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "screeninfo_kreedz", g_Vars.screeninfo.kreedz )
		}
		else
		{
			PRINT_ATOI ( "screeninfo_kreedz", g_Vars.screeninfo.kreedz )
		}
	}

	void Command::ScreenInfoColor ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 4 )
		{
			PRINT_COLOR_IS_3 ( "screeninfo_color", g_Vars.screeninfo.color[0],
				g_Vars.screeninfo.color[1], g_Vars.screeninfo.color[2] )
		}
		else
		{
			PRINT_COLOR_ATOI_3 ( "screeninfo_color", g_Vars.screeninfo.color[0],
				g_Vars.screeninfo.color[1], g_Vars.screeninfo.color[2] );
		}
	}

	void Command::ScreenInfoFontOutLine ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "screeninfo_font_out_line", g_Vars.screeninfo.font_outline )
		}
		else
		{
			PRINT_ATOI ( "screeninfo_font_out_line", g_Vars.screeninfo.font_outline )
		}
	}

	void Command::BunnyHopMouseWheelEmulation ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "bunnyhop_mousewheel_emulation", g_Vars.bhop.mouse_wheel_emulation )
		}
		else
		{
			PRINT_ATOI ( "bunnyhop_mousewheel_emulation", g_Vars.bhop.mouse_wheel_emulation )
		}
	}

	void Command::BunnyHopMouseWheelDirection ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "bunnyhop_mousewheel_direction", g_Vars.bhop.mouse_wheel_direction )
		}
		else
		{
			PRINT_ATOI ( "bunnyhop_mousewheel_direction", g_Vars.bhop.mouse_wheel_direction )
		}
	}

	void Command::BunnyHopDistanceType ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "bunnyhop_distance_type", g_Vars.bhop.distance_type )
		}
		else
		{
			PRINT_ATOI ( "bunnyhop_distance_type", g_Vars.bhop.distance_type )
		}
	}

	void Command::BunnyHopDistance ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 3 )
		{
			PRINT_IS_FLOAT_2 ( "bunnyhop_distance", g_Vars.bhop.distance[0], g_Vars.bhop.distance[1] )
		}
		else
		{
			PRINT_ATOF_2 ( "bunnyhop_distance", g_Vars.bhop.distance[0], g_Vars.bhop.distance[1] )
		}
	}
	
	void Command::BunnyHopNoSlowDown ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "bunnyhop_noslowdown", g_Vars.bhop.noslowdown )
		}
		else
		{
			PRINT_ATOI ( "bunnyhop_noslowdown", g_Vars.bhop.noslowdown )
		}
	}

	void Command::BunnyHopInWater ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "bunnyhop_in_water", g_Vars.bhop.in_water )
		}
		else
		{
			PRINT_ATOI ( "bunnyhop_in_water", g_Vars.bhop.in_water )
		}
	}

	void Command::BunnyHopOnLadder ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "bunnyhop_on_ladder", g_Vars.bhop.on_ladder )
		}
		else
		{
			PRINT_ATOI ( "bunnyhop_on_ladder", g_Vars.bhop.on_ladder )
		}
	}

	void Command::BunnyHopStandUp ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "bunnyhop_standup", g_Vars.bhop.standup )
		}
		else
		{
			PRINT_ATOI ( "bunnyhop_standup", g_Vars.bhop.standup )
		}
	}

	void Command::BunnyHopStandUpFallVelocity ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS_FLOAT ( "bunnyhop_standup_fallvelocity", g_Vars.bhop.standup_fallvelocity )
		}
		else
		{
			PRINT_ATOF ( "bunnyhop_standup_fallvelocity", g_Vars.bhop.standup_fallvelocity )
		}
	}

	void Command::BunnyHopStandUpGroundAngle ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS_FLOAT ( "bunnyhop_standup_groundangle", g_Vars.bhop.standup_groundangle )
		}
		else
		{
			PRINT_ATOF ( "bunnyhop_standup_groundangle", g_Vars.bhop.standup_groundangle )
		}
	}

	void Command::BunnyHopStandUpOn ( )
	{
		Functions::Misc::g_BHop.StandUpActive = true;
	}

	void Command::BunnyHopStandUpOff ( )
	{
		Functions::Misc::g_BHop.StandUpActive = false;
	}

	void Command::BunnyHopOn ( )
	{
		Functions::Misc::g_BHop.BunnyHopActive = true;
	}

	void Command::BunnyHopOff ( )
	{
		Functions::Misc::g_BHop.BunnyHopActive = false;
	}

	void Command::GroundStrafeMouseWheelEmulation ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "groundstrafe_mousewheel_emulation", g_Vars.gstrafe.mouse_wheel_emulation )
		}
		else
		{
			PRINT_ATOI ( "groundstrafe_mousewheel_emulation", g_Vars.gstrafe.mouse_wheel_emulation )
		}
	}

	void Command::GroundStrafeMouseWheelDirection ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "groundstrafe_mousewheel_direction", g_Vars.gstrafe.mouse_wheel_direction )
		}
		else
		{
			PRINT_ATOI ( "groundstrafe_mousewheel_direction", g_Vars.gstrafe.mouse_wheel_direction )
		}
	}

	void Command::GroundStrafeDistanceType ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "groundstrafe_distance_type", g_Vars.gstrafe.distance_type )
		}
		else
		{
			PRINT_ATOI ( "groundstrafe_distance_type", g_Vars.gstrafe.distance_type )
		}
	}

	void Command::GroundStrafeDistance ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 3 )
		{
			PRINT_IS_FLOAT_2 ( "groundstrafe_distance", g_Vars.gstrafe.distance[0], g_Vars.gstrafe.distance[1] )
		}
		else
		{
			PRINT_ATOF_2 ( "groundstrafe_distance", g_Vars.gstrafe.distance[0], g_Vars.gstrafe.distance[1] )
		}
	}

	void Command::GroundStrafeCount ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 3 )
		{
			PRINT_IS_2 ( "groundstrafe_count", g_Vars.gstrafe.count[0], g_Vars.gstrafe.count[1] )
		}
		else
		{
			PRINT_ATOI_2 ( "groundstrafe_count", g_Vars.gstrafe.count[0], g_Vars.gstrafe.count[1] )
		}
	}

	void Command::GroundStrafeFallRun ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "groundstrafe_fallrun", g_Vars.gstrafe.fallrun )
		}
		else
		{
			PRINT_ATOI ( "groundstrafe_fallrun", g_Vars.gstrafe.fallrun )
		}
	}

	void Command::GroundStrafeSlowDownScale ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS_FLOAT ( "groundstrafe_slowdown_scale", g_Vars.gstrafe.slowdown_scale )
		}
		else
		{
			PRINT_ATOF ( "groundstrafe_slowdown_scale", g_Vars.gstrafe.slowdown_scale )
		}
	}

	void Command::GroundStrafeSlowDownGroundAngle ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS_FLOAT ( "groundstrafe_slowdown_groundangle", g_Vars.gstrafe.slowdown_groundangle )
		}
		else
		{
			PRINT_ATOF ( "groundstrafe_slowdown_groundangle", g_Vars.gstrafe.slowdown_groundangle )
		}
	}

	void Command::GroundStrafeStandUpFallVelocity ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS_FLOAT ( "groundstrafe_standup_fallvelocity", g_Vars.gstrafe.standup_fallvelocity )
		}
		else
		{
			PRINT_ATOF ( "groundstrafe_standup_fallvelocity", g_Vars.gstrafe.standup_fallvelocity )
		}
	}

	void Command::GroundStrafeStandUpOn ( )
	{
		Functions::Misc::g_GStrafe.StandUpActive = true;
	}

	void Command::GroundStrafeStandUpOff ( )
	{
		Functions::Misc::g_GStrafe.StandUpActive = false;
	}

	void Command::GroundStrafeOn ( )
	{
		Functions::Misc::g_GStrafe.GroundStrafeActive = true;
	}

	void Command::GroundStrafeOff ( )
	{
		Functions::Misc::g_GStrafe.GroundStrafeActive = false;
	}

	void Command::Speed ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS_FLOAT ( "speed", g_Vars.speed.value )
		}
		else
		{
			PRINT_ATOF ( "speed", g_Vars.speed.value )
		}
	}

	void Command::SpeedEngine ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "speed_engine", g_Vars.speed.engine_value )
		}
		else
		{
			PRINT_ATOI ( "speed_engine", g_Vars.speed.engine_value )
		}
	}

	void Command::SpeedType ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "speed_type", g_Vars.speed.speed_type )
		}
		else
		{
			PRINT_ATOI ( "speed_type", g_Vars.speed.speed_type )
		}
	}

	void Command::SpeedBoost ( )
	{
		if ( g_Vars.speed.speed_type == 1 )
		{
			if ( g_Engine.Cmd_Argc ( ) < 2 )
			{
				PRINT_IS_FLOAT ( "speed_boost", g_Vars.speed.boost )
			}
			else
			{
				PRINT_ATOF ( "speed_boost", g_Vars.speed.boost )
			}
		}
		else if ( g_Vars.speed.speed_type == 1 )
		{
			if ( g_Engine.Cmd_Argc ( ) < 2 )
			{
				PRINT_IS ( "speed_boost", g_Vars.speed.boost )
			}
			else
			{
				PRINT_ATOI ( "speed_boost", g_Vars.speed.boost )
			}
		}
	}

	void Command::SpeedBoostOn ( )
	{
		Functions::Misc::g_Speed.SpeedBoost = true;
	}

	void Command::SpeedBoostOff ( )
	{
		Functions::Misc::g_Speed.SpeedBoost = false;
	}

	void Command::SpeedSlowMo ( )
	{
		if ( g_Vars.speed.speed_type == 1 )
		{
			if ( g_Engine.Cmd_Argc ( ) < 2 )
			{
				PRINT_IS_FLOAT ( "speed_slowmo", g_Vars.speed.slowmo )
			}
			else
			{
				PRINT_ATOF ( "speed_slowmo", g_Vars.speed.slowmo )
			}
		}
		else if ( g_Vars.speed.speed_type == 2 )
		{
			if ( g_Engine.Cmd_Argc ( ) < 2 )
			{
				PRINT_IS ( "speed_slowmo", g_Vars.speed.slowmo )
			}
			else
			{
				PRINT_ATOI ( "speed_slowmo", g_Vars.speed.slowmo )
			}
		}
	}

	void Command::SpeedSlowMoOn ( )
	{
		Functions::Misc::g_Speed.SpeedSlowMo = true;
	}

	void Command::SpeedSlowMoOff ( )
	{
		Functions::Misc::g_Speed.SpeedSlowMo = false;
	}

	void Command::JumpBugAuto ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "jumpbug_auto", g_Vars.jumpbug.auto_enable )
		}
		else
		{
			PRINT_ATOI ( "jumpbug_auto", g_Vars.jumpbug.auto_enable )
		}
	}

	void Command::JumpBugAutoDamage ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "jumpbug_auto_damage", g_Vars.jumpbug.auto_damage )
		}
		else
		{
			PRINT_ATOI ( "jumpbug_auto_damage", g_Vars.jumpbug.auto_damage )
		}
	}

	void Command::JumpBugAutoPercentage ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "jumpbug_auto_percentage", g_Vars.jumpbug.auto_percentage )
		}
		else
		{
			PRINT_ATOI ( "jumpbug_auto_percentage", g_Vars.jumpbug.auto_percentage )
		}
	}

	void Command::JumpBugSlowDown ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "jumpbug_slowdown", g_Vars.jumpbug.slowdown )
		}
		else
		{
			PRINT_ATOI ( "jumpbug_slowdown", g_Vars.jumpbug.slowdown )
		}
	}

	void Command::JumpBugSlowDownDistance ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS_FLOAT ( "jumpbug_slowdown_distance", g_Vars.jumpbug.slowdown_distance )
		}
		else
		{
			PRINT_ATOF ( "jumpbug_slowdown_distance", g_Vars.jumpbug.slowdown_distance )
		}
	}

	void Command::JumpBugSlowMotion ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "jumpbug_slowmotion", g_Vars.jumpbug.slowmotion )
		}
		else
		{
			PRINT_ATOI ( "jumpbug_slowmotion", g_Vars.jumpbug.slowmotion )
		}
	}

	void Command::JumpBugOn ( )
	{
		Functions::Misc::g_JumpBug.JumpBugActive = true;
	}

	void Command::JumpBugOff ( )
	{
		Functions::Misc::g_JumpBug.JumpBugActive = false;
	}

	void Command::EdgeBugAuto ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "edgebug_auto", g_Vars.edgebug.auto_enable )
		}
		else
		{
			PRINT_ATOI ( "edgebug_auto", g_Vars.edgebug.auto_enable )
		}
	}

	void Command::EdgeBugAutoDamage ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "edgebug_auto_damage", g_Vars.edgebug.auto_damage )
		}
		else
		{
			PRINT_ATOI ( "edgebug_auto_damage", g_Vars.edgebug.auto_damage )
		}
	}

	void Command::EdgeBugSpeed ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "edgebug_speed", g_Vars.edgebug.speed )
		}
		else
		{
			PRINT_ATOI ( "edgebug_speed", g_Vars.edgebug.speed )
		}
	}

	void Command::EdgeBugDistance ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS_FLOAT ( "edgebug_distance", g_Vars.edgebug.distance )
		}
		else
		{
			PRINT_ATOF ( "edgebug_distance", g_Vars.edgebug.distance )
		}
	}

	void Command::EdgeBugDistanceAuto ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "edgebug_distance_auto", g_Vars.edgebug.distance_auto )
		}
		else
		{
			PRINT_ATOI ( "edgebug_distance_auto", g_Vars.edgebug.distance_auto )
		}
	}

	void Command::EdgeBugOn ( )
	{
		Functions::Misc::g_EdgeBug.EdgeBugActive = true;
	}

	void Command::EdgeBugOff ( )
	{
		Functions::Misc::g_EdgeBug.EdgeBugActive = false;
	}

	Command g_Command;
}