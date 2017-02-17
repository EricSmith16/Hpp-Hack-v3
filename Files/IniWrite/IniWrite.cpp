#include "IniWrite.h"

namespace Files
{
	void _fastcall IniWrite::Camera ( )
	{
		std::string Path = g_File.DirFile ( VISUALS_PATH ).c_str ( );

		WRITE_INT ( CAMERA, THIRDPERSON_ENABLE, g_Vars.Camera.ThirdPersonEnable );
		WRITE_INT ( CAMERA, THIRDPERSON_SIDE, g_Vars.Camera.ThirdPersonSide );
		WRITE_INT ( CAMERA, THIRDPERSON_UP, g_Vars.Camera.ThirdPersonUp );
		WRITE_INT ( CAMERA, THIRDPERSON_BACK, g_Vars.Camera.ThirdPersonBack );

		WRITE_INT ( CAMERA, FREELOOK_ENABLE, g_Vars.Camera.FreeLookEnable );
		WRITE_INT ( CAMERA, FREELOOK_SPEED, g_Vars.Camera.FreeLookSpeed );

		WRITE_INT ( CAMERA, SPECTATOR_ENABLE, g_Vars.Camera.SpectatorEnable );
		WRITE_INT ( CAMERA, SPECTATOR_ID, g_Vars.Camera.SpectatorID );
	}

	void _fastcall IniWrite::StrafeHelper ( )
	{
		std::string Path = g_File.DirFile ( MISC_PATH ).c_str ( );

		WRITE_INT ( STRAFE_HELPER, STRAFE_HELPER_ACTIVE, g_Vars.StrafeHelper.Active );

		WRITE_INT ( STRAFE_HELPER, STRAFE_HELPER_MODE, g_Vars.StrafeHelper.Mode );
		WRITE_INT ( STRAFE_HELPER, STRAFE_HELPER_TYPE, g_Vars.StrafeHelper.Type );

		WRITE_FLOAT ( STRAFE_HELPER, STRAFE_HELPER_CORRECT_SPEED, g_Vars.StrafeHelper.CorrectSpeed );
		WRITE_FLOAT ( STRAFE_HELPER, STRAFE_HELPER_CORRECT_LIMIT, g_Vars.StrafeHelper.CorrectLimit );
		WRITE_FLOAT ( STRAFE_HELPER, STRAFE_HELPER_CORRECT_SMOOTH, g_Vars.StrafeHelper.CorrectLimitSmooth );

		WRITE_INT ( STRAFE_HELPER, STRAFE_HELPER_KEY_EMULATION, g_Vars.StrafeHelper.KeyEmulation );

		WRITE_FLOAT ( STRAFE_HELPER, STRAFE_HELPER_BOOST, g_Vars.StrafeHelper.Boost );

		WRITE_INT ( STRAFE_HELPER, STRAFE_HELPER_MINIMAL_SPEED, g_Vars.StrafeHelper.MinimalSpeed );

		WRITE_INT ( STRAFE_HELPER, STRAFE_HELPER_DIRECTION, g_Vars.StrafeHelper.Direction );
		WRITE_INT ( STRAFE_HELPER, STRAFE_HELPER_DIRECTION_AUTO, g_Vars.StrafeHelper.DirectionAuto );

		WRITE_INT ( STRAFE_HELPER, STRAFE_HELPER_STRAFE_LIMIT, g_Vars.StrafeHelper.StrafeLimit );
	}

	void _fastcall IniWrite::EdgeBug ( )
	{
		std::string Path = g_File.DirFile ( MISC_PATH ).c_str ( );

		WRITE_INT ( EDGEBUG, EDGEBUG_AUTO, g_Vars.EdgeBug.AutoEnable );
		WRITE_INT ( EDGEBUG, EDGEBUG_AUTO_DAMAGE, g_Vars.EdgeBug.AutoDamage );

		WRITE_INT ( EDGEBUG, EDGEBUG_SPEED, g_Vars.EdgeBug.Speed );
		WRITE_INT ( EDGEBUG, EDGEBUG_SPEED_FINAL, g_Vars.EdgeBug.SpeedFinal );
		WRITE_INT ( EDGEBUG, EDGEBUG_SPEED_OFFSET, g_Vars.EdgeBug.SpeedOffset );
	}

	void _fastcall IniWrite::JumpBug ( )
	{
		std::string Path = g_File.DirFile ( MISC_PATH ).c_str ( );

		WRITE_INT ( JUMPBUG, JUMPBUG_AUTO, g_Vars.JumpBug.AutoEnable );
		WRITE_INT ( JUMPBUG, JUMPBUG_AUTO_DAMAGE, g_Vars.JumpBug.AutoDamage );
		WRITE_INT ( JUMPBUG, JUMPBUG_AUTO_PERCENTAGE, g_Vars.JumpBug.AutoPercentage );

		WRITE_INT ( JUMPBUG, JUMPBUG_SLOWDOWN, g_Vars.JumpBug.SlowDown );

		WRITE_INT ( JUMPBUG, JUMPBUG_SLOWMOTION, g_Vars.JumpBug.SlowMotion );
	}

	void _fastcall IniWrite::Speed ( )
	{
		std::string Path = g_File.DirFile ( MISC_PATH ).c_str ( );

		WRITE_FLOAT ( SPEED, SPEED_VALUE, g_Vars.Speed.Value );
		WRITE_INT ( SPEED, SPEED_ENGINE_VALUE, g_Vars.Speed.EngineValue );

		WRITE_INT ( SPEED, SPEED_TYPE, g_Vars.Speed.SpeedType );

		if ( g_Vars.Speed.SpeedType == 1 )
		{
			WRITE_FLOAT ( SPEED, SPEED_BOOST, g_Vars.Speed.Boost );
		}
		else if ( g_Vars.Speed.SpeedType == 2 )
		{
			WRITE_INT ( SPEED, SPEED_BOOST, g_Vars.Speed.Boost );
		}

		if ( g_Vars.Speed.SpeedType == 1 )
		{
			WRITE_FLOAT ( SPEED, SPEED_SLOWMOTION, g_Vars.Speed.SlowMotion );
		}
		else if ( g_Vars.Speed.SpeedType == 2 )
		{
			WRITE_INT ( SPEED, SPEED_SLOWMOTION, g_Vars.Speed.SlowMotion );
		}
	}

	void _fastcall IniWrite::GStrafe ( )
	{
		std::string Path = g_File.DirFile ( MISC_PATH ).c_str ( );

		WRITE_INT ( GSTRAFE, GSTRAFE_SCROLL_EMULATION, g_Vars.GStrafe.ScrollEmulation );
		WRITE_DIR ( GSTRAFE, GSTRAFE_SCROLL_DIRECTION, g_Vars.GStrafe.ScrollDirection );

		WRITE_FLOAT_2 ( GSTRAFE, GSTRAFE_DISTANCE, g_Vars.GStrafe.Distance[0], g_Vars.GStrafe.Distance[1] );
		WRITE_INT_2 ( GSTRAFE, GSTRAFE_COUNT, g_Vars.GStrafe.Count[0], g_Vars.GStrafe.Count[1] );

		WRITE_INT ( GSTRAFE, GSTRAFE_FALLRUN, g_Vars.GStrafe.FallRun );

		WRITE_FLOAT ( GSTRAFE, GSTRAFE_SLOWDOWN_SCALE, g_Vars.GStrafe.SlowDownScale );

		WRITE_FLOAT ( GSTRAFE, GSTRAFE_STANDUP_FALLVELOCITY, g_Vars.GStrafe.StandUpFallVelocity );
	}

	void _fastcall IniWrite::BunnyHop ( )
	{
		std::string Path = g_File.DirFile ( MISC_PATH ).c_str ( );

		WRITE_INT ( BHOP, BHOP_SCROLL_EMULATION, g_Vars.BHop.ScrollEmulation );
		WRITE_DIR ( BHOP, BHOP_SCROLL_DIRECTION, g_Vars.BHop.ScrollDirection );

		WRITE_FLOAT_2 ( BHOP, BHOP_DISTANCE, g_Vars.BHop.Distance[0], g_Vars.BHop.Distance[1] );

		WRITE_INT ( BHOP, BHOP_NOSLOWDOWN, g_Vars.BHop.NoSlowDown );

		WRITE_INT ( BHOP, BHOP_ONLADDER, g_Vars.BHop.OnLadder );

		WRITE_INT ( BHOP, BHOP_STANDUP_AUTO, g_Vars.BHop.StandUpAuto );
		WRITE_FLOAT ( BHOP, BHOP_STANDUP_FALLVELOCITY, g_Vars.BHop.StandUpFallVelocity );
	}

	void _fastcall IniWrite::ScreenInfo ( )
	{
		std::string Path = g_File.DirFile ( VISUALS_PATH ).c_str ( );

		WRITE_INT ( mSCREENINFO, SCREENINFO_ENABLE, g_Vars.ScreenInfo.Enable );

		WRITE_INT ( mSCREENINFO, SCREENINFO_FPS, g_Vars.ScreenInfo.FPS );
		WRITE_INT ( mSCREENINFO, SCREENINFO_COPYRIGHT, g_Vars.ScreenInfo.CopyRight );
		WRITE_INT ( mSCREENINFO, SCREENINFO_TIME, g_Vars.ScreenInfo.Time );
		WRITE_INT ( mSCREENINFO, SCREENINFO_SHOWKEYS, g_Vars.ScreenInfo.ShowKeys );
		WRITE_INT ( mSCREENINFO, SCREENINFO_KREEDZ, g_Vars.ScreenInfo.Kreedz );

		WRITE_COLOR ( mSCREENINFO, SCREENINFO_FONT_COLOR, g_Vars.ScreenInfo.FontColor[0], g_Vars.ScreenInfo.FontColor[1], g_Vars.ScreenInfo.FontColor[2] );
		WRITE_INT ( mSCREENINFO, SCREENINFO_FONT_OUTLINE, g_Vars.ScreenInfo.FontOutLine );
	}

	void _fastcall IniWrite::NoFlash ( )
	{
		std::string Path = g_File.DirFile ( VISUALS_PATH ).c_str ( );

		WRITE_INT ( NOFLASH, NOFLASH_ENABLE, g_Vars.NoFlash.Enable );

		WRITE_INT ( NOFLASH, NOFLASH_FADELIMIT, g_Vars.NoFlash.FadeLimit );

		WRITE_COLOR ( NOFLASH, NOFLASH_FADECOLOR, g_Vars.NoFlash.FadeColor[0], g_Vars.NoFlash.FadeColor[1], g_Vars.NoFlash.FadeColor[2] );
		WRITE_INT ( NOFLASH, NOFLASH_FADECOLORRANDOM, g_Vars.NoFlash.FadeColorRandom );

		WRITE_INT ( NOFLASH, NOFLASH_SHOWPERCENTAGE, g_Vars.NoFlash.ShowPercentage );

		WRITE_INT ( NOFLASH, NOFLASH_FONT_OUTLINE, g_Vars.NoFlash.FontOutLine );
	}

	void _fastcall IniWrite::ESP ( )
	{
		std::string Path = g_File.DirFile ( VISUALS_PATH ).c_str ( );

		WRITE_INT ( mESP, ESP_ENABLE, g_Vars.ESP.Enable );

		WRITE_INT ( mESP, ESP_PLAYER, g_Vars.ESP.Player );
		WRITE_INT ( mESP, ESP_PLAYER_VISIBLE_ONLY, g_Vars.ESP.PlayerVisibleOnly );

		WRITE_INT ( mESP, ESP_PLAYER_BOX, g_Vars.ESP.PlayerBox );
		WRITE_INT ( mESP, ESP_PLAYER_BOX_LINEWIDTH, g_Vars.ESP.PlayerBoxLineWidth );

		WRITE_COLOR ( mESP, ESP_PLAYER_BOX_T_VIS, g_Vars.ESP.ColorTVis[0], g_Vars.ESP.ColorTVis[1], g_Vars.ESP.ColorTVis[2] );
		WRITE_COLOR ( mESP, ESP_PLAYER_BOX_T_HIDE, g_Vars.ESP.ColorTHide[0], g_Vars.ESP.ColorTHide[1], g_Vars.ESP.ColorTHide[2] );
		WRITE_COLOR ( mESP, ESP_PLAYER_BOX_CT_VIS, g_Vars.ESP.ColorCTVis[0], g_Vars.ESP.ColorCTVis[1], g_Vars.ESP.ColorCTVis[2] );
		WRITE_COLOR ( mESP, ESP_PLAYER_BOX_CT_HIDE, g_Vars.ESP.ColorCTHide[0], g_Vars.ESP.ColorCTHide[1], g_Vars.ESP.ColorCTHide[2] );

		WRITE_INT ( mESP, ESP_PLAYER_NAME, g_Vars.ESP.PlayerName );
		WRITE_INT ( mESP, ESP_PLAYER_WEAPON, g_Vars.ESP.PlayerWeapon );
		WRITE_INT ( mESP, ESP_PLAYER_DISTANCE, g_Vars.ESP.PlayerDistance );
		WRITE_INT ( mESP, ESP_PLAYER_BARREL, g_Vars.ESP.PlayerBarrel );

		WRITE_INT ( mESP, ESP_WORLD_ITEMS, g_Vars.ESP.WorldItems );
		WRITE_INT ( mESP, ESP_WORLD_NADES, g_Vars.ESP.WorldNades );

		WRITE_INT ( mESP, ESP_C4TIMER, g_Vars.ESP.C4Timer );
		WRITE_INT ( mESP, ESP_C4TIMER_VALUE, g_Vars.ESP.C4TimerValue );

		WRITE_INT ( mESP, ESP_SOUND, g_Vars.ESP.Sound );
		WRITE_INT ( mESP, ESP_SOUND_LINEWIDTH, g_Vars.ESP.SoundLineWidth );
		WRITE_INT ( mESP, ESP_SOUND_FADE_TIME, g_Vars.ESP.SoundFadeTime );

		WRITE_COLOR ( mESP, ESP_SOUND_COLOR, g_Vars.ESP.SoundColor[0], g_Vars.ESP.SoundColor[1], g_Vars.ESP.SoundColor[2] );

		WRITE_INT ( mESP, ESP_FONT_OUTLINE, g_Vars.ESP.FontOutLine );

		WRITE_COLOR ( mESP, ESP_FONT_COLOR, g_Vars.ESP.FontColor[0], g_Vars.ESP.FontColor[1], g_Vars.ESP.FontColor[2] );
	}

	void _fastcall IniWrite::Main ( )
	{
		std::string Path = g_File.DirFile ( MAIN_PATH ).c_str ( );

		WRITE_INT ( MAIN, MAIN_PLAYER_VISIBLE_SCAN, g_Vars.Main.PlayerVisibleScan );
		WRITE_INT ( MAIN, MAIN_PLAYER_VALID_CHECK, g_Vars.Main.PlayerValidCheck );

		WRITE_INT ( MAIN, MAIN_FONT_OUTLINE_QUALITY, g_Vars.Main.FontOutLineQuality );

		WRITE_INT ( MAIN, MAIN_ANTISCREEN_ENABLE, g_Vars.Main.AntiScreenEnable );
		WRITE_INT ( MAIN, MAIN_ANTISCREEN_TIMER, g_Vars.Main.AntiScreenTimer );
	}

	void _fastcall IniWrite::Menu ( )
	{
		std::string Path = g_File.DirFile ( VISUALS_PATH ).c_str ( );

		WRITE_INT ( MENU, MENU_POS_X, g_Vars.Menu.Pos_x );
		WRITE_INT ( MENU, MENU_POS_Y, g_Vars.Menu.Pos_y );

		WRITE_INT ( MENU, MENU_BOX_HEIGHT, g_Vars.Menu.BoxHeight );
		WRITE_INT ( MENU, MENU_BOX_WIDTH, g_Vars.Menu.BoxWidth );

		WRITE_COLOR_4 ( MENU, MENU_BOX_COLOR, g_Vars.Menu.BoxColor[0],
			g_Vars.Menu.BoxColor[1], g_Vars.Menu.BoxColor[2], g_Vars.Menu.BoxColor[3] );

		WRITE_COLOR_4 ( MENU, MENU_BOXFILL_COLOR, g_Vars.Menu.BoxFillColor[0], g_Vars.Menu.BoxFillColor[1], 
			g_Vars.Menu.BoxFillColor[2], g_Vars.Menu.BoxFillColor[3] );

		WRITE_COLOR_4 ( MENU, MENU_BOXSELECT_COLOR, g_Vars.Menu.BoxSelectColor[0], g_Vars.Menu.BoxSelectColor[1], 
			g_Vars.Menu.BoxSelectColor[2], g_Vars.Menu.BoxSelectColor[3] );

		WRITE_COLOR_4 ( MENU, MENU_TEXT_COLOR, g_Vars.Menu.TextColor[0], g_Vars.Menu.TextColor[1], 
			g_Vars.Menu.TextColor[2], g_Vars.Menu.TextColor[3] );
	}

	IniWrite g_IniWrite;
}