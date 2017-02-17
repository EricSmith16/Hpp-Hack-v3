#include "Cmds.h"

namespace Engine
{
	void _fastcall Command::ConsoleCommands ( )
	{
		if ( g_Vars.Function.StrafeHelper )
		{
			rcmd ( "strafe_helper", StrafeHelperOn, StrafeHelperOff );
			acmd ( "strafe_helper_switch", StrafeHelperSwitch );
			acmd ( "strafe_helper_strafe_limit", StrafeHelperStrafeLimit );
			acmd ( "strafe_helper_direction_auto", StrafeHelperDirectionAuto );
			acmd ( "strafe_helper_direction", StrafeHelperDirection );
			acmd ( "strafe_helper_minimal_speed", StrafeHelperMinimalSpeed );
			acmd ( "strafe_helper_boost", StrafeHelperBoost );
			acmd ( "strafe_helper_key_emulation", StrafeHelperKeyEmulation );
			acmd ( "strafe_helper_correct_limit_smooth", StrafeHelperCorrectLimitSmooth );
			acmd ( "strafe_helper_correct_limit", StrafeHelperCorrectLimit );
			acmd ( "strafe_helper_correct_speed", StrafeHelperCorrectSpeed );
			acmd ( "strafe_helper_type", StrafeHelperType );
			acmd ( "strafe_helper_mode", StrafeHelperMode );
			acmd ( "strafe_helper_active", StrafeHelperActive );
		}

		if ( g_Vars.Function.EdgeBug )
		{
			rcmd ( "edgebug", EdgeBugOn, EdgeBugOff );
			acmd ( "edgebug_speed_offset", EdgeBugSpeedOffset );
			acmd ( "edgebug_speed_final", EdgeBugSpeedFinal );
			acmd ( "edgebug_speed", EdgeBugSpeed );
			acmd ( "edgebug_auto_damage", EdgeBugAutoDamage );
			acmd ( "edgebug_auto", EdgeBugAuto );
		}

		if ( g_Vars.Function.JumpBug )
		{
			rcmd ( "jumpbug", JumpBugOn, JumpBugOff );
			acmd ( "jumpbug_slowmotion", JumpBugSlowMotion );
			acmd ( "jumpbug_slowdown", JumpBugSlowDown );
			acmd ( "jumpbug_auto_percentage", JumpBugAutoPercentage );
			acmd ( "jumpbug_auto_damage", JumpBugAutoDamage );
			acmd ( "jumpbug_auto", JumpBugAuto );
		}

		if ( g_Vars.Function.GroundStrafe )
		{
			rcmd ( "gstrafe", GroundStrafeOn, GroundStrafeOff );
			rcmd ( "gstrafe_standup", GroundStrafeStandUpOn, GroundStrafeStandUpOff );
			acmd ( "gstrafe_standup_fallvelocity", GroundStrafeStandUpFallVelocity );
			acmd ( "gstrafe_slowdown_scale", GroundStrafeSlowDownScale );
			acmd ( "gstrafe_fallrun", GroundStrafeFallRun );
			acmd ( "gstrafe_count", GroundStrafeCount );
			acmd ( "gstrafe_distance", GroundStrafeDistance );
			acmd ( "gstrafe_scroll_direction", GroundStrafeScrollDirection );
			acmd ( "gstrafe_scroll_emulation", GroundStrafeScrollEmulation );
		}

		if ( g_Vars.Function.BunnyHop )
		{
			rcmd ( "bhop", BunnyHopOn, BunnyHopOff );
			rcmd ( "bhop_standup", BunnyHopStandUpOn, BunnyHopStandUpOff );
			acmd ( "bhop_standup_fallvelocity", BunnyHopStandUpFallVelocity );
			acmd ( "bhop_standup_auto", BunnyHopStandUpAuto );
			acmd ( "bhop_on_ladder", BunnyHopOnLadder );
			acmd ( "bhop_noslowdown", BunnyHopNoSlowDown );
			acmd ( "bhop_distance", BunnyHopDistance );
			acmd ( "bhop_scroll_direction", BunnyHopScrollDirection );
			acmd ( "bhop_scroll_emulation", BunnyHopScrollEmulation );
		}

		if ( g_Vars.Function.Speed )
		{
			rcmd ( "speed_slowmo", SpeedSlowMoOn, SpeedSlowMoOff );
			rcmd ( "speed_boost", SpeedBoostOn, SpeedBoostOff );
			acmd ( "speed_slowmo", SpeedSlowMo );
			acmd ( "speed_boost", SpeedBoost );
			acmd ( "speed_type", SpeedType );
			acmd ( "speed_engine", SpeedEngine );
			acmd ( "speed", Speed );
		}

		if ( g_Vars.Function.Camera )
		{
			acmd ( "spectator_switch", SpectatorSwitch );
			acmd ( "spectator_id", SpectatorID );
			acmd ( "spectator_enable", SpectatorEnable );

			acmd ( "freelook_switch", FreeLookSwitch );
			acmd ( "freelook_speed", FreeLookSpeed );
			acmd ( "freelook_enable", FreeLookEnable );

			acmd ( "thirdperson_switch", ThirdPersonSwitch );
			acmd ( "thirdperson_back", ThirdPersonPositionBack );
			acmd ( "thirdperson_up", ThirdPersonPositionUp );
			acmd ( "thirdperson_side", ThirdPersonPositionSide );
			acmd ( "thirdperson_enable", ThirdPersonEnable );
		}

		if ( g_Vars.Function.ScreenInfo )
		{
			acmd ( "screeninfo_font_outline", ScreenInfoFontOutLine );
			acmd ( "screeninfo_font_color", ScreenInfoFontColor );
			acmd ( "screeninfo_kreedz", ScreenInfoKreedz );
			acmd ( "screeninfo_showkeys", ScreenInfoShowKeys );
			acmd ( "screeninfo_time", ScreenInfoTime );
			acmd ( "screeninfo_copyright", ScreenInfoCopyRight );
			acmd ( "screeninfo_fps", ScreenInfoFPS );
			acmd ( "screeninfo_enable", ScreenInfoEnable );
		}

		if ( g_Vars.Function.NoFlash )
		{
			acmd ( "noflash_font_outline", NoFlashFontOutLine );
			acmd ( "noflash_show_percentage", NoFlashShowPercentage );
			acmd ( "noflash_fade_color_random", NoFlashFadeColorRandom );
			acmd ( "noflash_fade_color", NoFlashFadeColor );
			acmd ( "noflash_fade_limit", NoFlashFadeLimit );
			acmd ( "noflash_enable", NoFlashEnable );
		}

		if ( g_Vars.Function.ESP )
		{
			acmd ( "esp_panic", ESPPanic );
			acmd ( "esp_font_color", ESPFontColor );
			acmd ( "esp_font_outline", ESPFontOutLine );
			acmd ( "esp_sound_color", ESPSoundColor );
			acmd ( "esp_sound_fade_time", ESPSoundFadeTime );
			acmd ( "esp_sound_linewidth", ESPSoundLineWidth );
			acmd ( "esp_sound", ESPSound );
			acmd ( "esp_c4timer_value", ESPC4TimerValue );
			acmd ( "esp_c4timer", ESPC4Timer );
			acmd ( "esp_world_nades", ESPWorldNades );
			acmd ( "esp_world_items", ESPWorldItems );
			acmd ( "esp_player_barrel", ESPPlayerBarrel );
			acmd ( "esp_player_distance", ESPPlayerDistance );
			acmd ( "esp_player_weapon", ESPPlayerWeapon );
			acmd ( "esp_player_name", ESPPlayerName );
			acmd ( "esp_player_box_ct_hide", ESPPlayerBoxCTHide );
			acmd ( "esp_player_box_ct_vis", ESPPlayerBoxCTVis );
			acmd ( "esp_player_box_t_hide", ESPPlayerBoxTHide );
			acmd ( "esp_player_box_t_vis", ESPPlayerBoxTVis );
			acmd ( "esp_player_box_linewidth", ESPPlayerBoxLineWidth );
			acmd ( "esp_player_box", ESPPlayerBox );
			acmd ( "esp_player_visible_only", ESPPlayerVisibleOnly );
			acmd ( "esp_player", ESPPlayer );
			acmd ( "esp_enable", ESPEnable );
		}

		if ( g_Vars.Function.Menu )
		{
			acmd ( "menu_text_color", MenuTextColor );
			acmd ( "menu_boxselect_color", MenuBoxSelectColor );			
			acmd ( "menu_boxfill_color", MenuBoxFillColor );
			acmd ( "menu_box_color", MenuBoxColor );
			acmd ( "menu_box_width", MenuBoxWidth );
			acmd ( "menu_box_height", MenuBoxHeight );
			acmd ( "menu_pos_y", MenuPos_y );
			acmd ( "menu_pos_x", MenuPos_x );
			acmd ( "menu", Menu );
		}

		acmd ( "antiscreen_timer", AntiScreenTimer );
		acmd ( "antiscreen_enable", AntiScreenEnable );
		acmd ( "antiscreen", AntiScreen );

		acmd ( "font_outline_quality", FontOutLineQuality );

		acmd ( "player_valid_check", PlayerValidCheck );
		acmd ( "player_visible_scan", PlayerVisibleScan );

		acmd ( "panic", Panic );

		acmd ( "settings_save", Save );
		acmd ( "settings_reload", Reload );

		acmd ( "exec", ExecConfig );

		if ( g_Vars.Function.CommandsBinds )
		{
			acmd ( "bind", Bind );
			acmd ( "unbindall", UnbindAll );
			acmd ( "unbind", Unbind );
		}
	}

	void Command::ExecConfig ( )
	{
		g_Util.RunScript ( g_Engine.Cmd_Argv ( 1 ) );
	}

	void Command::Reload ( )
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

	void Command::Save ( )
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

	void Command::Panic ( )
	{
		Client::g_Hpp.PanicEnabled = !Client::g_Hpp.PanicEnabled;

		Engine::g_Engine.pfnPlaySoundByName ( Client::g_Hpp.PanicEnabled ? "vox/of.wav" : "vox/on.wav", 1 );
	}

	void Command::PlayerVisibleScan ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "player_visible_scan", g_Vars.Main.PlayerVisibleScan )
		}
		else
		{
			PRINT_ATOI ( "player_visible_scan", g_Vars.Main.PlayerVisibleScan )
		}
	}

	void Command::PlayerValidCheck ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "player_valid_check", g_Vars.Main.PlayerValidCheck )
		}
		else
		{
			PRINT_ATOI ( "player_valid_check", g_Vars.Main.PlayerValidCheck )
		}
	}

	void Command::FontOutLineQuality ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "font_outline_quality", g_Vars.Main.FontOutLineQuality )
		}
		else
		{
			PRINT_ATOI ( "font_outline_quality", g_Vars.Main.FontOutLineQuality )
		}
	}

	void Command::AntiScreen ( )
	{
		Client::g_Hpp.bSnapShot = true;
	}

	void Command::AntiScreenEnable ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "antiscreen_enable", g_Vars.Main.AntiScreenEnable )
		}
		else
		{
			PRINT_ATOI ( "antiscreen_enable", g_Vars.Main.AntiScreenEnable )
		}
	}

	void Command::AntiScreenTimer ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "antiscreen_timer", g_Vars.Main.AntiScreenTimer )
		}
		else
		{
			PRINT_ATOI ( "antiscreen_timer", g_Vars.Main.AntiScreenTimer )
		}
	}

	void Command::Menu ( )
	{
		Functions::Visuals::g_Menu.Visible = !Functions::Visuals::g_Menu.Visible;
	}

	void Command::MenuPos_x ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "menu_pos_x", g_Vars.Menu.Pos_x )
		}
		else
		{
			PRINT_ATOI ( "menu_pos_x", g_Vars.Menu.Pos_x )
		}
	}

	void Command::MenuPos_y ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "menu_pos_y", g_Vars.Menu.Pos_y )
		}
		else
		{
			PRINT_ATOI ( "menu_pos_y", g_Vars.Menu.Pos_y )
		}
	}

	void Command::MenuBoxHeight ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "menu_box_height", g_Vars.Menu.BoxHeight )
		}
		else
		{
			PRINT_ATOI ( "menu_box_height", g_Vars.Menu.BoxHeight )
		}
	}

	void Command::MenuBoxWidth ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "menu_box_width", g_Vars.Menu.BoxWidth )
		}
		else
		{
			PRINT_ATOI ( "menu_box_width", g_Vars.Menu.BoxWidth )
		}
	}

	void Command::MenuBoxColor ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 5 )
		{
			PRINT_COLOR_IS_4 ( "menu_box_color", g_Vars.Menu.BoxColor[0],
				g_Vars.Menu.BoxColor[1], g_Vars.Menu.BoxColor[2], g_Vars.Menu.BoxColor[3] )
		}
		else
		{
			PRINT_COLOR_ATOI_4 ( "menu_box_color", g_Vars.Menu.BoxColor[0],
				g_Vars.Menu.BoxColor[1], g_Vars.Menu.BoxColor[2], g_Vars.Menu.BoxColor[3] );
		}
	}

	void Command::MenuBoxFillColor ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 5 )
		{
			PRINT_COLOR_IS_4 ( "menu_boxfill_color", g_Vars.Menu.BoxFillColor[0],
				g_Vars.Menu.BoxFillColor[1], g_Vars.Menu.BoxFillColor[2], g_Vars.Menu.BoxFillColor[3] )
		}
		else
		{
			PRINT_COLOR_ATOI_4 ( "menu_boxfill_color", g_Vars.Menu.BoxFillColor[0],
				g_Vars.Menu.BoxFillColor[1], g_Vars.Menu.BoxFillColor[2], g_Vars.Menu.BoxFillColor[3] );
		}
	}

	void Command::MenuBoxSelectColor ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 5 )
		{
			PRINT_COLOR_IS_4 ( "menu_boxselect_color", g_Vars.Menu.BoxSelectColor[0],
				g_Vars.Menu.BoxSelectColor[1], g_Vars.Menu.BoxSelectColor[2], g_Vars.Menu.BoxSelectColor[3] )
		}
		else
		{
			PRINT_COLOR_ATOI_4 ( "menu_boxselect_color", g_Vars.Menu.BoxSelectColor[0],
				g_Vars.Menu.BoxSelectColor[1], g_Vars.Menu.BoxSelectColor[2], g_Vars.Menu.BoxSelectColor[3] );
		}
	}

	void Command::MenuTextColor ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 5 )
		{
			PRINT_COLOR_IS_4 ( "menu_text_color", g_Vars.Menu.TextColor[0],
				g_Vars.Menu.TextColor[1], g_Vars.Menu.TextColor[2], g_Vars.Menu.TextColor[3] )
		}
		else
		{
			PRINT_COLOR_ATOI_4 ( "menu_text_color", g_Vars.Menu.TextColor[0],
				g_Vars.Menu.TextColor[1], g_Vars.Menu.TextColor[2], g_Vars.Menu.TextColor[3] );
		}
	}

	void Command::ESPEnable ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_enable", g_Vars.ESP.Enable )
		}
		else
		{
			PRINT_ATOI ( "esp_enable", g_Vars.ESP.Enable )
		}
	}

	void Command::ESPPlayer ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_player", g_Vars.ESP.Player )
		}
		else
		{
			PRINT_ATOI ( "esp_player", g_Vars.ESP.Player )
		}
	}

	void Command::ESPPlayerVisibleOnly ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_player_visible_only", g_Vars.ESP.PlayerVisibleOnly )
		}
		else
		{
			PRINT_ATOI ( "esp_player_visible_only", g_Vars.ESP.PlayerVisibleOnly )
		}
	}

	void Command::ESPPlayerBox ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_player_box", g_Vars.ESP.PlayerBox )
		}
		else
		{
			PRINT_ATOI ( "esp_player_box", g_Vars.ESP.PlayerBox )
		}
	}

	void Command::ESPPlayerBoxLineWidth ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_player_box_linewidth", g_Vars.ESP.PlayerBoxLineWidth )
		}
		else
		{
			PRINT_ATOI ( "esp_player_box_linewidth", g_Vars.ESP.PlayerBoxLineWidth )
		}
	}

	void Command::ESPPlayerBoxTVis ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 4 )
		{
			PRINT_COLOR_IS_3 ( "esp_player_box_t_vis", g_Vars.ESP.ColorTVis[0],
				g_Vars.ESP.ColorTVis[1], g_Vars.ESP.ColorTVis[2] )
		}
		else
		{
			PRINT_COLOR_ATOI_3 ( "esp_player_box_t_vis", g_Vars.ESP.ColorTVis[0],
				g_Vars.ESP.ColorTVis[1], g_Vars.ESP.ColorTVis[2] );
		}
	}

	void Command::ESPPlayerBoxTHide ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 4 )
		{
			PRINT_COLOR_IS_3 ( "esp_player_box_t_hide", g_Vars.ESP.ColorTHide[0],
				g_Vars.ESP.ColorTHide[1], g_Vars.ESP.ColorTHide[2] )
		}
		else
		{
			PRINT_COLOR_ATOI_3 ( "esp_player_box_t_hide", g_Vars.ESP.ColorTHide[0],
				g_Vars.ESP.ColorTHide[1], g_Vars.ESP.ColorTHide[2] );
		}
	}

	void Command::ESPPlayerBoxCTVis ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 4 )
		{
			PRINT_COLOR_IS_3 ( "esp_player_box_ct_vis", g_Vars.ESP.ColorCTVis[0],
				g_Vars.ESP.ColorCTVis[1], g_Vars.ESP.ColorCTVis[2] )
		}
		else
		{
			PRINT_COLOR_ATOI_3 ( "esp_player_box_ct_vis", g_Vars.ESP.ColorCTVis[0],
				g_Vars.ESP.ColorCTVis[1], g_Vars.ESP.ColorCTVis[2] );
		}
	}

	void Command::ESPPlayerBoxCTHide ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 4 )
		{
			PRINT_COLOR_IS_3 ( "esp_player_box_ct_hide", g_Vars.ESP.ColorCTHide[0],
				g_Vars.ESP.ColorCTHide[1], g_Vars.ESP.ColorCTHide[2] )
		}
		else
		{
			PRINT_COLOR_ATOI_3 ( "esp_player_box_ct_hide", g_Vars.ESP.ColorCTHide[0],
				g_Vars.ESP.ColorCTHide[1], g_Vars.ESP.ColorCTHide[2] );
		}
	}

	void Command::ESPPlayerName ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_player_name", g_Vars.ESP.PlayerName )
		}
		else
		{
			PRINT_ATOI ( "esp_player_name", g_Vars.ESP.PlayerName )
		}
	}

	void Command::ESPPlayerWeapon ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_player_weapon", g_Vars.ESP.PlayerWeapon )
		}
		else
		{
			PRINT_ATOI ( "esp_player_weapon", g_Vars.ESP.PlayerWeapon )
		}
	}

	void Command::ESPPlayerDistance ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_player_distance", g_Vars.ESP.PlayerDistance )
		}
		else
		{
			PRINT_ATOI ( "esp_player_distance", g_Vars.ESP.PlayerDistance )
		}
	}

	void Command::ESPPlayerBarrel ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_player_barrel", g_Vars.ESP.PlayerBarrel )
		}
		else
		{
			PRINT_ATOI ( "esp_player_barrel", g_Vars.ESP.PlayerBarrel )
		}
	}

	void Command::ESPWorldItems ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_world_items", g_Vars.ESP.WorldItems )
		}
		else
		{
			PRINT_ATOI ( "esp_world_items", g_Vars.ESP.WorldItems )
		}
	}

	void Command::ESPWorldNades ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_world_nades", g_Vars.ESP.WorldNades )
		}
		else
		{
			PRINT_ATOI ( "esp_world_nades", g_Vars.ESP.WorldNades )
		}
	}

	void Command::ESPC4Timer ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_c4timer", g_Vars.ESP.C4Timer )
		}
		else
		{
			PRINT_ATOI ( "esp_c4timer", g_Vars.ESP.C4Timer )
		}
	}

	void Command::ESPC4TimerValue ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_c4timer_value", g_Vars.ESP.C4TimerValue )
		}
		else
		{
			PRINT_ATOI ( "esp_c4timer_value", g_Vars.ESP.C4TimerValue )
		}
	}

	void Command::ESPSound ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_sound", g_Vars.ESP.Sound )
		}
		else
		{
			PRINT_ATOI ( "esp_sound", g_Vars.ESP.Sound )
		}
	}

	void Command::ESPSoundLineWidth ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_sound_linewidth", g_Vars.ESP.SoundLineWidth )
		}
		else
		{
			PRINT_ATOI ( "esp_sound_linewidth", g_Vars.ESP.SoundLineWidth )
		}
	}

	void Command::ESPSoundFadeTime ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_sound_fade_time", g_Vars.ESP.SoundFadeTime )
		}
		else
		{
			PRINT_ATOI ( "esp_sound_fade_time", g_Vars.ESP.SoundFadeTime )
		}
	}

	void Command::ESPSoundColor ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 4 )
		{
			PRINT_COLOR_IS_3 ( "esp_sound_color", g_Vars.ESP.SoundColor[0],
				g_Vars.ESP.SoundColor[1], g_Vars.ESP.SoundColor[2] )
		}
		else
		{
			PRINT_COLOR_ATOI_3 ( "esp_sound_color", g_Vars.ESP.SoundColor[0],
				g_Vars.ESP.SoundColor[1], g_Vars.ESP.SoundColor[2] );
		}
	}

	void Command::ESPFontOutLine ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "esp_font_outline", g_Vars.ESP.FontOutLine )
		}
		else
		{
			PRINT_ATOI ( "esp_font_outline", g_Vars.ESP.FontOutLine )
		}
	}

	void Command::ESPFontColor ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 4 )
		{
			PRINT_COLOR_IS_3 ( "esp_font_color", g_Vars.ESP.FontColor[0],
				g_Vars.ESP.FontColor[1], g_Vars.ESP.FontColor[2] )
		}
		else
		{
			PRINT_COLOR_ATOI_3 ( "esp_font_color", g_Vars.ESP.FontColor[0],
				g_Vars.ESP.FontColor[1], g_Vars.ESP.FontColor[2] );
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
			PRINT_IS ( "noflash_enable", g_Vars.NoFlash.Enable )
		}
		else
		{
			PRINT_ATOI ( "noflash_enable", g_Vars.NoFlash.Enable )
		}
	}

	void Command::NoFlashFadeLimit ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "noflash_fade_limit", g_Vars.NoFlash.FadeLimit )
		}
		else
		{
			PRINT_ATOI ( "noflash_fade_limit", g_Vars.NoFlash.FadeLimit )
		}
	}

	void Command::NoFlashFadeColor ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 4 )
		{
			PRINT_COLOR_IS_3 ( "noflash_fade_color", g_Vars.NoFlash.FadeColor[0],
				g_Vars.NoFlash.FadeColor[1], g_Vars.NoFlash.FadeColor[2] )
		}
		else
		{
			PRINT_COLOR_ATOI_3 ( "noflash_fade_color", g_Vars.NoFlash.FadeColor[0],
				g_Vars.NoFlash.FadeColor[1], g_Vars.NoFlash.FadeColor[2] );
		}
	}

	void Command::NoFlashFadeColorRandom ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "noflash_fade_color_random", g_Vars.NoFlash.FadeColorRandom )
		}
		else
		{
			PRINT_ATOI ( "noflash_fade_color_random", g_Vars.NoFlash.FadeColorRandom )
		}
	}

	void Command::NoFlashShowPercentage ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "noflash_show_percentage", g_Vars.NoFlash.ShowPercentage )
		}
		else
		{
			PRINT_ATOI ( "noflash_show_percentage", g_Vars.NoFlash.ShowPercentage )
		}
	}

	void Command::NoFlashFontOutLine ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "noflash_font_outline", g_Vars.NoFlash.FontOutLine )
		}
		else
		{
			PRINT_ATOI ( "noflash_font_outline", g_Vars.NoFlash.FontOutLine )
		}
	}

	void Command::ScreenInfoEnable ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "screeninfo_enable", g_Vars.ScreenInfo.Enable )
		}
		else
		{
			PRINT_ATOI ( "screeninfo_enable", g_Vars.ScreenInfo.Enable )
		}
	}

	void Command::ScreenInfoFPS ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "screeninfo_fps", g_Vars.ScreenInfo.FPS )
		}
		else
		{
			PRINT_ATOI ( "screeninfo_fps", g_Vars.ScreenInfo.FPS )
		}
	}

	void Command::ScreenInfoCopyRight ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "screeninfo_copyright", g_Vars.ScreenInfo.CopyRight )
		}
		else
		{
			PRINT_ATOI ( "screeninfo_copyright", g_Vars.ScreenInfo.CopyRight )
		}
	}

	void Command::ScreenInfoTime ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "screeninfo_time", g_Vars.ScreenInfo.Time )
		}
		else
		{
			PRINT_ATOI ( "screeninfo_time", g_Vars.ScreenInfo.Time )
		}
	}

	void Command::ScreenInfoShowKeys ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "screeninfo_showkeys", g_Vars.ScreenInfo.ShowKeys )
		}
		else
		{
			PRINT_ATOI ( "screeninfo_showkeys", g_Vars.ScreenInfo.ShowKeys )
		}
	}

	void Command::ScreenInfoKreedz ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "screeninfo_kreedz", g_Vars.ScreenInfo.Kreedz )
		}
		else
		{
			PRINT_ATOI ( "screeninfo_kreedz", g_Vars.ScreenInfo.Kreedz )
		}
	}

	void Command::ScreenInfoFontColor ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 4 )
		{
			PRINT_COLOR_IS_3 ( "screeninfo_font_color", g_Vars.ScreenInfo.FontColor[0],
				g_Vars.ScreenInfo.FontColor[1], g_Vars.ScreenInfo.FontColor[2] )
		}
		else
		{
			PRINT_COLOR_ATOI_3 ( "screeninfo_font_color", g_Vars.ScreenInfo.FontColor[0],
				g_Vars.ScreenInfo.FontColor[1], g_Vars.ScreenInfo.FontColor[2] );
		}
	}

	void Command::ScreenInfoFontOutLine ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "screeninfo_font_outline", g_Vars.ScreenInfo.FontOutLine )
		}
		else
		{
			PRINT_ATOI ( "screeninfo_font_outline", g_Vars.ScreenInfo.FontOutLine )
		}
	}

	void Command::BunnyHopScrollEmulation ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "bhop_scroll_emulation", g_Vars.BHop.ScrollEmulation )
		}
		else
		{
			PRINT_ATOI ( "bhop_scroll_emulation", g_Vars.BHop.ScrollEmulation )
		}
	}

	void Command::BunnyHopScrollDirection ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS_MWHEEL ( "bhop_scroll_direction", g_Vars.BHop.ScrollDirection );
		}
		else
		{
			PRINT_ATOI_MWHEEL ( "bhop_scroll_direction", g_Vars.BHop.ScrollDirection );
		}
	}

	void Command::BunnyHopDistance ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 3 )
		{
			PRINT_IS_FLOAT_2 ( "bhop_distance", g_Vars.BHop.Distance[0], g_Vars.BHop.Distance[1] )
		}
		else
		{
			PRINT_ATOF_2 ( "bhop_distance", g_Vars.BHop.Distance[0], g_Vars.BHop.Distance[1] )
		}
	}

	void Command::BunnyHopNoSlowDown ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "bhop_noslowdown", g_Vars.BHop.NoSlowDown )
		}
		else
		{
			PRINT_ATOI ( "bhop_noslowdown", g_Vars.BHop.NoSlowDown )
		}
	}

	void Command::BunnyHopOnLadder ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "bhop_on_ladder", g_Vars.BHop.OnLadder )
		}
		else
		{
			PRINT_ATOI ( "bhop_on_ladder", g_Vars.BHop.OnLadder )
		}
	}

	void Command::BunnyHopStandUpAuto ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "bhop_standup_auto", g_Vars.BHop.StandUpAuto )
		}
		else
		{
			PRINT_ATOI ( "bhop_standup_auto", g_Vars.BHop.StandUpAuto )
		}
	}

	void Command::BunnyHopStandUpFallVelocity ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS_FLOAT ( "bhop_standup_fallvelocity", g_Vars.BHop.StandUpFallVelocity )
		}
		else
		{
			PRINT_ATOF ( "bhop_standup_fallvelocity", g_Vars.BHop.StandUpFallVelocity )
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

	void Command::GroundStrafeScrollEmulation ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "gstrafe_scroll_emulation", g_Vars.GStrafe.ScrollEmulation )
		}
		else
		{
			PRINT_ATOI ( "gstrafe_scroll_emulation", g_Vars.GStrafe.ScrollEmulation )
		}
	}

	void Command::GroundStrafeScrollDirection ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS_MWHEEL ( "gstrafe_scroll_direction", g_Vars.GStrafe.ScrollDirection )
		}
		else
		{
			PRINT_ATOI_MWHEEL ( "gstrafe_scroll_direction", g_Vars.GStrafe.ScrollDirection )
		}
	}

	void Command::GroundStrafeDistance ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 3 )
		{
			PRINT_IS_FLOAT_2 ( "gstrafe_distance", g_Vars.GStrafe.Distance[0], g_Vars.GStrafe.Distance[1] )
		}
		else
		{
			PRINT_ATOF_2 ( "gstrafe_distance", g_Vars.GStrafe.Distance[0], g_Vars.GStrafe.Distance[1] )
		}
	}

	void Command::GroundStrafeCount ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 3 )
		{
			PRINT_IS_2 ( "gstrafe_count", g_Vars.GStrafe.Count[0], g_Vars.GStrafe.Count[1] )
		}
		else
		{
			PRINT_ATOI_2 ( "gstrafe_count", g_Vars.GStrafe.Count[0], g_Vars.GStrafe.Count[1] )
		}
	}

	void Command::GroundStrafeFallRun ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "gstrafe_fallrun", g_Vars.GStrafe.FallRun )
		}
		else
		{
			PRINT_ATOI ( "gstrafe_fallrun", g_Vars.GStrafe.FallRun )
		}
	}

	void Command::GroundStrafeSlowDownScale ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS_FLOAT ( "gstrafe_slowdown_scale", g_Vars.GStrafe.SlowDownScale )
		}
		else
		{
			PRINT_ATOF ( "gstrafe_slowdown_scale", g_Vars.GStrafe.SlowDownScale )
		}
	}

	void Command::GroundStrafeStandUpFallVelocity ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS_FLOAT ( "gstrafe_standup_fallvelocity", g_Vars.GStrafe.StandUpFallVelocity )
		}
		else
		{
			PRINT_ATOF ( "gstrafe_standup_fallvelocity", g_Vars.GStrafe.StandUpFallVelocity )
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
			PRINT_IS_FLOAT ( "speed", g_Vars.Speed.Value )
		}
		else
		{
			PRINT_ATOF ( "speed", g_Vars.Speed.Value )
		}
	}

	void Command::SpeedEngine ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "speed_engine", g_Vars.Speed.EngineValue )
		}
		else
		{
			PRINT_ATOI ( "speed_engine", g_Vars.Speed.EngineValue )
		}
	}

	void Command::SpeedType ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "speed_type", g_Vars.Speed.SpeedType )
		}
		else
		{
			PRINT_ATOI ( "speed_type", g_Vars.Speed.SpeedType )
		}
	}

	void Command::SpeedBoost ( )
	{
		if ( g_Vars.Speed.SpeedType == 1 )
		{
			if ( g_Engine.Cmd_Argc ( ) < 2 )
			{
				PRINT_IS_FLOAT ( "speed_boost", g_Vars.Speed.Boost )
			}
			else
			{
				PRINT_ATOF ( "speed_boost", g_Vars.Speed.Boost )
			}
		}
		else if ( g_Vars.Speed.SpeedType == 2 )
		{
			if ( g_Engine.Cmd_Argc ( ) < 2 )
			{
				PRINT_IS ( "speed_boost", g_Vars.Speed.Boost )
			}
			else
			{
				PRINT_ATOI ( "speed_boost", g_Vars.Speed.Boost )
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
		if ( g_Vars.Speed.SpeedType == 1 )
		{
			if ( g_Engine.Cmd_Argc ( ) < 2 )
			{
				PRINT_IS_FLOAT ( "speed_slowmo", g_Vars.Speed.SlowMotion )
			}
			else
			{
				PRINT_ATOF ( "speed_slowmo", g_Vars.Speed.SlowMotion )
			}
		}
		else if ( g_Vars.Speed.SpeedType == 2 )
		{
			if ( g_Engine.Cmd_Argc ( ) < 2 )
			{
				PRINT_IS ( "speed_slowmo", g_Vars.Speed.SlowMotion )
			}
			else
			{
				PRINT_ATOI ( "speed_slowmo", g_Vars.Speed.SlowMotion )
			}
		}
	}

	void Command::SpeedSlowMoOn ( )
	{
		Functions::Misc::g_Speed.SpeedSlowMotion = true;
	}

	void Command::SpeedSlowMoOff ( )
	{
		Functions::Misc::g_Speed.SpeedSlowMotion = false;
	}

	void Command::JumpBugAuto ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "jumpbug_auto", g_Vars.JumpBug.AutoEnable )
		}
		else
		{
			PRINT_ATOI ( "jumpbug_auto", g_Vars.JumpBug.AutoEnable )
		}
	}

	void Command::JumpBugAutoDamage ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "jumpbug_auto_damage", g_Vars.JumpBug.AutoDamage )
		}
		else
		{
			PRINT_ATOI ( "jumpbug_auto_damage", g_Vars.JumpBug.AutoDamage )
		}
	}

	void Command::JumpBugAutoPercentage ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "jumpbug_auto_percentage", g_Vars.JumpBug.AutoPercentage )
		}
		else
		{
			PRINT_ATOI ( "jumpbug_auto_percentage", g_Vars.JumpBug.AutoPercentage )
		}
	}

	void Command::JumpBugSlowDown ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "jumpbug_slowdown", g_Vars.JumpBug.SlowDown )
		}
		else
		{
			PRINT_ATOI ( "jumpbug_slowdown", g_Vars.JumpBug.SlowDown )
		}
	}

	void Command::JumpBugSlowMotion ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "jumpbug_slowmotion", g_Vars.JumpBug.SlowMotion )
		}
		else
		{
			PRINT_ATOI ( "jumpbug_slowmotion", g_Vars.JumpBug.SlowMotion )
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
			PRINT_IS ( "edgebug_auto", g_Vars.EdgeBug.AutoEnable )
		}
		else
		{
			PRINT_ATOI ( "edgebug_auto", g_Vars.EdgeBug.AutoEnable )
		}
	}

	void Command::EdgeBugAutoDamage ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "edgebug_auto_damage", g_Vars.EdgeBug.AutoDamage )
		}
		else
		{
			PRINT_ATOI ( "edgebug_auto_damage", g_Vars.EdgeBug.AutoDamage )
		}
	}

	void Command::EdgeBugSpeed ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "edgebug_speed", g_Vars.EdgeBug.Speed )
		}
		else
		{
			PRINT_ATOI ( "edgebug_speed", g_Vars.EdgeBug.Speed )
		}
	}

	void Command::EdgeBugSpeedFinal ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "edgebug_speed_final", g_Vars.EdgeBug.SpeedFinal )
		}
		else
		{
			PRINT_ATOI ( "edgebug_speed_final", g_Vars.EdgeBug.SpeedFinal )
		}
	}

	void Command::EdgeBugSpeedOffset ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "edgebug_speed_offset", g_Vars.EdgeBug.SpeedOffset )
		}
		else
		{
			PRINT_ATOI ( "edgebug_speed_offset", g_Vars.EdgeBug.SpeedOffset )
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

	void Command::StrafeHelperActive ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "strafe_helper_active", g_Vars.StrafeHelper.Active )
		}
		else
		{
			PRINT_ATOI ( "strafe_helper_active", g_Vars.StrafeHelper.Active )
		}
	}

	void Command::StrafeHelperMode ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "strafe_helper_mode", g_Vars.StrafeHelper.Mode )
		}
		else
		{
			PRINT_ATOI ( "strafe_helper_mode", g_Vars.StrafeHelper.Mode )
		}
	}

	void Command::StrafeHelperType ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "strafe_helper_type", g_Vars.StrafeHelper.Type )
		}
		else
		{
			PRINT_ATOI ( "strafe_helper_type", g_Vars.StrafeHelper.Type )
		}
	}

	void Command::StrafeHelperCorrectSpeed ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS_FLOAT ( "strafe_helper_correct_speed", g_Vars.StrafeHelper.CorrectSpeed )
		}
		else
		{
			PRINT_ATOF ( "strafe_helper_correct_speed", g_Vars.StrafeHelper.CorrectSpeed )
		}
	}

	void Command::StrafeHelperCorrectLimit ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS_FLOAT ( "strafe_helper_correct_limit", g_Vars.StrafeHelper.CorrectLimit )
		}
		else
		{
			PRINT_ATOF ( "strafe_helper_correct_limit", g_Vars.StrafeHelper.CorrectLimit )
		}
	}

	void Command::StrafeHelperCorrectLimitSmooth ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS_FLOAT ( "strafe_helper_correct_limit_smooth", g_Vars.StrafeHelper.CorrectLimitSmooth )
		}
		else
		{
			PRINT_ATOF ( "strafe_helper_correct_limit_smooth", g_Vars.StrafeHelper.CorrectLimitSmooth )
		}
	}

	void Command::StrafeHelperKeyEmulation ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "strafe_helper_key_emulation", g_Vars.StrafeHelper.KeyEmulation )
		}
		else
		{
			PRINT_ATOI ( "strafe_helper_key_emulation", g_Vars.StrafeHelper.KeyEmulation )
		}
	}

	void Command::StrafeHelperBoost ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS_FLOAT ( "strafe_helper_boost", g_Vars.StrafeHelper.Boost )
		}
		else
		{
			PRINT_ATOF ( "strafe_helper_boost", g_Vars.StrafeHelper.Boost )
		}
	}

	void Command::StrafeHelperMinimalSpeed ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "strafe_helper_minimal_speed", g_Vars.StrafeHelper.MinimalSpeed )
		}
		else
		{
			PRINT_ATOI ( "strafe_helper_minimal_speed", g_Vars.StrafeHelper.MinimalSpeed )
		}
	}

	void Command::StrafeHelperDirection ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "strafe_helper_direction", g_Vars.StrafeHelper.Direction )
		}
		else
		{
			PRINT_ATOI ( "strafe_helper_direction", g_Vars.StrafeHelper.Direction )
		}
	}

	void Command::StrafeHelperDirectionAuto ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "strafe_helper_direction_auto", g_Vars.StrafeHelper.DirectionAuto )
		}
		else
		{
			PRINT_ATOI ( "strafe_helper_direction_auto", g_Vars.StrafeHelper.DirectionAuto )
		}
	}

	void Command::StrafeHelperStrafeLimit ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "strafe_helper_strafe_limit", g_Vars.StrafeHelper.StrafeLimit )
		}
		else
		{
			PRINT_ATOI ( "strafe_helper_strafe_limit", g_Vars.StrafeHelper.StrafeLimit )
		}
	}

	void Command::StrafeHelperSwitch ( )
	{
		g_Vars.StrafeHelper.Active = !g_Vars.StrafeHelper.Active;

		Engine::g_Engine.pfnPlaySoundByName ( g_Vars.StrafeHelper.Active ? "vox/on.wav" : "vox/of.wav", 1 );
	}

	void Command::StrafeHelperOn ( )
	{
		Functions::Misc::g_StrafeHelper.StrafeHelperActive = true;

		g_Vars.StrafeHelper.Active = 1;
	}

	void Command::StrafeHelperOff ( )
	{
		Functions::Misc::g_StrafeHelper.StrafeHelperActive = false;

		g_Vars.StrafeHelper.Active = 0;
	}

	void Command::ThirdPersonEnable ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "thirdperson_enable", g_Vars.Camera.ThirdPersonEnable )
		}
		else
		{
			PRINT_ATOI ( "thirdperson_enable", g_Vars.Camera.ThirdPersonEnable )
		}
	}

	void Command::ThirdPersonPositionSide ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "thirdperson_side", g_Vars.Camera.ThirdPersonSide )
		}
		else
		{
			PRINT_ATOI ( "thirdperson_side", g_Vars.Camera.ThirdPersonSide )
		}
	}

	void Command::ThirdPersonPositionUp ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "thirdperson_up", g_Vars.Camera.ThirdPersonUp )
		}
		else
		{
			PRINT_ATOI ( "thirdperson_up", g_Vars.Camera.ThirdPersonUp )
		}
	}

	void Command::ThirdPersonPositionBack ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "thirdperson_back", g_Vars.Camera.ThirdPersonBack )
		}
		else
		{
			PRINT_ATOI ( "thirdperson_back", g_Vars.Camera.ThirdPersonBack )
		}
	}

	void Command::ThirdPersonSwitch ( )
	{
		g_Vars.Camera.ThirdPersonEnable = !g_Vars.Camera.ThirdPersonEnable;

		Engine::g_Engine.pfnPlaySoundByName ( g_Vars.Camera.ThirdPersonEnable ? "vox/on.wav" : "vox/of.wav", 1 );
	}

	void Command::FreeLookEnable ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "freelook_enable", g_Vars.Camera.FreeLookEnable )
		}
		else
		{
			PRINT_ATOI ( "freelook_enable", g_Vars.Camera.FreeLookEnable )
		}
	}

	void Command::FreeLookSpeed ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "freelook_speed", g_Vars.Camera.FreeLookSpeed )
		}
		else
		{
			PRINT_ATOI ( "freelook_speed", g_Vars.Camera.FreeLookSpeed )
		}
	}

	void Command::FreeLookSwitch ( )
	{
		g_Vars.Camera.FreeLookEnable = !g_Vars.Camera.FreeLookEnable;

		Engine::g_Engine.pfnPlaySoundByName ( g_Vars.Camera.FreeLookEnable ? "vox/on.wav" : "vox/of.wav", 1 );
	}

	void Command::SpectatorEnable ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "spectator_enable", g_Vars.Camera.SpectatorEnable )
		}
		else
		{
			PRINT_ATOI ( "spectator_enable", g_Vars.Camera.SpectatorEnable )
		}
	}

	void Command::SpectatorID ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			PRINT_IS ( "spectator_id", g_Vars.Camera.SpectatorID )
		}
		else
		{
			PRINT_ATOI ( "spectator_id", g_Vars.Camera.SpectatorID )
		}
	}

	void Command::SpectatorSwitch ( )
	{
		g_Vars.Camera.SpectatorEnable = !g_Vars.Camera.SpectatorEnable;

		Engine::g_Engine.pfnPlaySoundByName ( g_Vars.Camera.SpectatorEnable ? "vox/on.wav" : "vox/of.wav", 1 );
	}

	Command g_Command;
}