#include "IniRead.h"

#pragma warning ( disable: 4244 )
#pragma warning ( disable: 4800 )

namespace Files
{
	void _fastcall IniRead::Camera ( )
	{
		std::string Path = g_File.DirFile ( VISUALS_PATH ).c_str ( );

		INIREAD_INT ( g_Vars.Camera.ThirdPersonEnable, CAMERA, THIRDPERSON_ENABLE );
		INIREAD_INT ( g_Vars.Camera.ThirdPersonSide, CAMERA, THIRDPERSON_SIDE );
		INIREAD_INT ( g_Vars.Camera.ThirdPersonUp, CAMERA, THIRDPERSON_UP );
		INIREAD_INT ( g_Vars.Camera.ThirdPersonBack, CAMERA, THIRDPERSON_BACK );

		INIREAD_STRING_CONVERT ( g_Vars.Camera.ThirdPersonSwitchKey, CAMERA, THIRDPERSON_SWITCH_KEY );

		INIREAD_INT ( g_Vars.Camera.FreeLookEnable, CAMERA, FREELOOK_ENABLE );
		INIREAD_INT ( g_Vars.Camera.FreeLookSpeed, CAMERA, FREELOOK_SPEED );

		INIREAD_STRING_CONVERT ( g_Vars.Camera.FreeLookSwitchKey, CAMERA, FREELOOK_SWITCH_KEY );

		INIREAD_INT ( g_Vars.Camera.SpectatorEnable, CAMERA, SPECTATOR_ENABLE );
		INIREAD_INT ( g_Vars.Camera.SpectatorID, CAMERA, SPECTATOR_ID );

		INIREAD_STRING_CONVERT ( g_Vars.Camera.SpectatorSwitchKey, CAMERA, SPECTATOR_SWITCH_KEY );
	}

	void _fastcall IniRead::StrafeHelper ( )
	{
		std::string Path = g_File.DirFile ( MISC_PATH ).c_str ( );

		INIREAD_INT ( g_Vars.StrafeHelper.Active, STRAFE_HELPER, STRAFE_HELPER_ACTIVE );

		INIREAD_INT ( g_Vars.StrafeHelper.Mode, STRAFE_HELPER, STRAFE_HELPER_MODE );
		INIREAD_INT ( g_Vars.StrafeHelper.Type, STRAFE_HELPER, STRAFE_HELPER_TYPE );

		INIREAD_FLOAT ( g_Vars.StrafeHelper.CorrectSpeed, STRAFE_HELPER, STRAFE_HELPER_CORRECT_SPEED );
		INIREAD_FLOAT ( g_Vars.StrafeHelper.CorrectLimit, STRAFE_HELPER, STRAFE_HELPER_CORRECT_LIMIT );
		INIREAD_FLOAT ( g_Vars.StrafeHelper.CorrectLimitSmooth, STRAFE_HELPER, STRAFE_HELPER_CORRECT_SMOOTH );

		INIREAD_INT ( g_Vars.StrafeHelper.KeyEmulation, STRAFE_HELPER, STRAFE_HELPER_KEY_EMULATION );

		INIREAD_FLOAT ( g_Vars.StrafeHelper.Boost, STRAFE_HELPER, STRAFE_HELPER_BOOST );

		INIREAD_INT ( g_Vars.StrafeHelper.MinimalSpeed, STRAFE_HELPER, STRAFE_HELPER_MINIMAL_SPEED );

		INIREAD_INT ( g_Vars.StrafeHelper.Direction, STRAFE_HELPER, STRAFE_HELPER_DIRECTION );
		INIREAD_INT ( g_Vars.StrafeHelper.DirectionAuto, STRAFE_HELPER, STRAFE_HELPER_DIRECTION_AUTO );

		INIREAD_INT ( g_Vars.StrafeHelper.StrafeLimit, STRAFE_HELPER, STRAFE_HELPER_STRAFE_LIMIT );

		INIREAD_STRING_CONVERT ( g_Vars.StrafeHelper.SwitchKey, STRAFE_HELPER, STRAFE_HELPER_SWITCH_KEY );
		INIREAD_STRING_CONVERT ( g_Vars.StrafeHelper.Key, STRAFE_HELPER, STRAFE_HELPER_KEY );
	}

	void _fastcall IniRead::EdgeBug ( )
	{
		std::string Path = g_File.DirFile ( MISC_PATH ).c_str ( );

		INIREAD_INT ( g_Vars.EdgeBug.AutoEnable, EDGEBUG, EDGEBUG_AUTO );
		INIREAD_INT ( g_Vars.EdgeBug.AutoDamage, EDGEBUG, EDGEBUG_AUTO_DAMAGE );

		INIREAD_INT ( g_Vars.EdgeBug.Speed, EDGEBUG, EDGEBUG_SPEED );
		INIREAD_INT ( g_Vars.EdgeBug.SpeedFinal, EDGEBUG, EDGEBUG_SPEED_FINAL );
		INIREAD_INT ( g_Vars.EdgeBug.SpeedOffset, EDGEBUG, EDGEBUG_SPEED_OFFSET );

		INIREAD_STRING_CONVERT ( g_Vars.EdgeBug.Key, EDGEBUG, EGDEBUG_KEY );
	}

	void _fastcall IniRead::JumpBug ( )
	{
		std::string Path = g_File.DirFile ( MISC_PATH ).c_str ( );

		INIREAD_INT ( g_Vars.JumpBug.AutoEnable, JUMPBUG, JUMPBUG_AUTO );
		INIREAD_INT ( g_Vars.JumpBug.AutoPercentage, JUMPBUG, JUMPBUG_AUTO_PERCENTAGE );
		INIREAD_INT ( g_Vars.JumpBug.AutoDamage, JUMPBUG, JUMPBUG_AUTO_DAMAGE );

		INIREAD_INT ( g_Vars.JumpBug.SlowDown, JUMPBUG, JUMPBUG_SLOWDOWN );

		INIREAD_INT ( g_Vars.JumpBug.SlowMotion, JUMPBUG, JUMPBUG_SLOWMOTION );

		INIREAD_STRING_CONVERT ( g_Vars.JumpBug.Key, JUMPBUG, JUMPBUG_KEY );
	}

	void _fastcall IniRead::Speed ( )
	{
		std::string Path = g_File.DirFile ( MISC_PATH ).c_str ( );

		INIREAD_FLOAT ( g_Vars.Speed.Value, SPEED, SPEED_VALUE );
		INIREAD_INT ( g_Vars.Speed.EngineValue, SPEED, SPEED_ENGINE_VALUE );

		INIREAD_INT ( g_Vars.Speed.SpeedType, SPEED, SPEED_TYPE );

		INIREAD_FLOAT ( g_Vars.Speed.Boost, SPEED, SPEED_BOOST );
		INIREAD_STRING_CONVERT ( g_Vars.Speed.BoostKey, SPEED, SPEED_BOOST_KEY );

		INIREAD_FLOAT ( g_Vars.Speed.SlowMotion, SPEED, SPEED_SLOWMOTION );
		INIREAD_STRING_CONVERT ( g_Vars.Speed.SlowMotionKey, SPEED, SPEED_SLOWMOTION_KEY );
	}

	void _fastcall IniRead::GStrafe ( )
	{
		std::string Path = g_File.DirFile ( MISC_PATH ).c_str ( );

		INIREAD_INT ( g_Vars.GStrafe.ScrollEmulation, GSTRAFE, GSTRAFE_SCROLL_EMULATION );
		INIREAD_STRING_CONVERT ( g_Vars.GStrafe.ScrollDirection, GSTRAFE, GSTRAFE_SCROLL_DIRECTION );

		INIREAD_STRING ( g_Vars.GStrafe.DistanceString, GSTRAFE, GSTRAFE_DISTANCE );
		INIREAD_STRING ( g_Vars.GStrafe.CountString, GSTRAFE, GSTRAFE_COUNT );

		INIREAD_INT ( g_Vars.GStrafe.FallRun, GSTRAFE, GSTRAFE_FALLRUN );

		INIREAD_FLOAT ( g_Vars.GStrafe.SlowDownScale, GSTRAFE, GSTRAFE_SLOWDOWN_SCALE );

		INIREAD_FLOAT ( g_Vars.GStrafe.StandUpFallVelocity, GSTRAFE, GSTRAFE_STANDUP_FALLVELOCITY );

		INIREAD_STRING_CONVERT ( g_Vars.GStrafe.StandUpKey, GSTRAFE, GSTRAFE_STANDUP_KEY );
		INIREAD_STRING_CONVERT ( g_Vars.GStrafe.Key, GSTRAFE, GSTRAFE_KEY );

		g_Util.Parse ( 2, g_Vars.GStrafe.DistanceString, g_Vars.GStrafe.Distance );
		g_Util.Parse ( 2, g_Vars.GStrafe.CountString, g_Vars.GStrafe.Count );
	}

	void _fastcall IniRead::BunnyHop ( )
	{
		std::string Path = g_File.DirFile ( MISC_PATH ).c_str ( );

		INIREAD_INT ( g_Vars.BHop.ScrollEmulation, BHOP, BHOP_SCROLL_EMULATION );
		INIREAD_STRING_CONVERT ( g_Vars.BHop.ScrollDirection, BHOP, BHOP_SCROLL_DIRECTION );

		INIREAD_STRING ( g_Vars.BHop.DistanceString, BHOP, BHOP_DISTANCE );

		INIREAD_INT ( g_Vars.BHop.NoSlowDown, BHOP, BHOP_NOSLOWDOWN );

		INIREAD_INT ( g_Vars.BHop.OnLadder, BHOP, BHOP_ONLADDER );

		INIREAD_INT ( g_Vars.BHop.StandUpAuto, BHOP, BHOP_STANDUP_AUTO );
		INIREAD_FLOAT ( g_Vars.BHop.StandUpFallVelocity, BHOP, BHOP_STANDUP_FALLVELOCITY );

		INIREAD_STRING_CONVERT ( g_Vars.BHop.StandUpKey, BHOP, BHOP_STANDUP_KEY );
		INIREAD_STRING_CONVERT ( g_Vars.BHop.Key, BHOP, BHOP_KEY );

		g_Util.Parse ( 2, g_Vars.BHop.DistanceString, g_Vars.BHop.Distance );
	}

	void _fastcall IniRead::ScreenInfo ( )
	{
		std::string Path = g_File.DirFile ( VISUALS_PATH ).c_str ( );

		INIREAD_INT ( g_Vars.ScreenInfo.Enable, mSCREENINFO, SCREENINFO_ENABLE );

		INIREAD_INT ( g_Vars.ScreenInfo.FPS, mSCREENINFO, SCREENINFO_FPS );
		INIREAD_INT ( g_Vars.ScreenInfo.CopyRight, mSCREENINFO, SCREENINFO_COPYRIGHT );
		INIREAD_INT ( g_Vars.ScreenInfo.Time, mSCREENINFO, SCREENINFO_TIME );
		INIREAD_INT ( g_Vars.ScreenInfo.ShowKeys, mSCREENINFO, SCREENINFO_SHOWKEYS );
		INIREAD_INT ( g_Vars.ScreenInfo.Kreedz, mSCREENINFO, SCREENINFO_KREEDZ );

		INIREAD_STRING ( g_Vars.ScreenInfo.FontColorString, mSCREENINFO, SCREENINFO_FONT_COLOR );
		INIREAD_INT ( g_Vars.ScreenInfo.FontOutLine, mSCREENINFO, SCREENINFO_FONT_OUTLINE );

		g_Util.Parse ( 3, g_Vars.ScreenInfo.FontColorString, g_Vars.ScreenInfo.FontColor );
	}

	void _fastcall IniRead::NoFlash ( )
	{
		std::string Path = g_File.DirFile ( VISUALS_PATH ).c_str ( );

		INIREAD_INT ( g_Vars.NoFlash.Enable, NOFLASH, NOFLASH_ENABLE );

		INIREAD_INT ( g_Vars.NoFlash.FadeLimit, NOFLASH, NOFLASH_FADELIMIT );

		INIREAD_STRING ( g_Vars.NoFlash.FadeColorString, NOFLASH, NOFLASH_FADECOLOR );
		INIREAD_INT ( g_Vars.NoFlash.FadeColorRandom, NOFLASH, NOFLASH_FADECOLORRANDOM );

		INIREAD_INT ( g_Vars.NoFlash.ShowPercentage, NOFLASH, NOFLASH_SHOWPERCENTAGE );

		INIREAD_INT ( g_Vars.NoFlash.FontOutLine, NOFLASH, NOFLASH_FONT_OUTLINE );

		g_Util.Parse ( 3, g_Vars.NoFlash.FadeColorString, g_Vars.NoFlash.FadeColor );
	}

	void _fastcall IniRead::ESP ( )
	{
		std::string Path = g_File.DirFile ( VISUALS_PATH ).c_str ( );

		INIREAD_INT ( g_Vars.ESP.Enable, mESP, ESP_ENABLE );

		INIREAD_INT ( g_Vars.ESP.Player, mESP, ESP_PLAYER );
		INIREAD_INT ( g_Vars.ESP.PlayerVisibleOnly, mESP, ESP_PLAYER_VISIBLE_ONLY );

		INIREAD_INT ( g_Vars.ESP.PlayerBox, mESP, ESP_PLAYER_BOX );
		INIREAD_INT ( g_Vars.ESP.PlayerBoxLineWidth, mESP, ESP_PLAYER_BOX_LINEWIDTH );

		INIREAD_STRING ( g_Vars.ESP.ColorTVisString, mESP, ESP_PLAYER_BOX_T_VIS );
		INIREAD_STRING ( g_Vars.ESP.ColorTHideString, mESP, ESP_PLAYER_BOX_T_HIDE );
		INIREAD_STRING ( g_Vars.ESP.ColorCTVisString, mESP, ESP_PLAYER_BOX_CT_VIS );
		INIREAD_STRING ( g_Vars.ESP.ColorCTHideString, mESP, ESP_PLAYER_BOX_CT_HIDE );

		INIREAD_INT ( g_Vars.ESP.PlayerName, mESP, ESP_PLAYER_NAME );
		INIREAD_INT ( g_Vars.ESP.PlayerWeapon, mESP, ESP_PLAYER_WEAPON );
		INIREAD_INT ( g_Vars.ESP.PlayerDistance, mESP, ESP_PLAYER_DISTANCE );
		INIREAD_INT ( g_Vars.ESP.PlayerBarrel, mESP, ESP_PLAYER_BARREL );

		INIREAD_INT ( g_Vars.ESP.WorldItems, mESP, ESP_WORLD_ITEMS );
		INIREAD_INT ( g_Vars.ESP.WorldNades, mESP, ESP_WORLD_NADES );

		INIREAD_INT ( g_Vars.ESP.C4Timer, mESP, ESP_C4TIMER );
		INIREAD_INT ( g_Vars.ESP.C4TimerValue, mESP, ESP_C4TIMER_VALUE );

		INIREAD_INT ( g_Vars.ESP.Sound, mESP, ESP_SOUND );
		INIREAD_INT ( g_Vars.ESP.SoundLineWidth, mESP, ESP_SOUND_LINEWIDTH );
		INIREAD_INT ( g_Vars.ESP.SoundFadeTime, mESP, ESP_SOUND_FADE_TIME );
		INIREAD_STRING ( g_Vars.ESP.SoundColorString, mESP, ESP_SOUND_COLOR );

		INIREAD_INT ( g_Vars.ESP.FontOutLine, mESP, ESP_FONT_OUTLINE );
		INIREAD_STRING ( g_Vars.ESP.FontColorString, mESP, ESP_FONT_COLOR );

		INIREAD_STRING_CONVERT ( g_Vars.ESP.PanicKey, mESP, ESP_PANIC_KEY );

		g_Util.Parse ( 3, g_Vars.ESP.ColorTHideString, g_Vars.ESP.ColorTHide );
		g_Util.Parse ( 3, g_Vars.ESP.ColorTVisString, g_Vars.ESP.ColorTVis );
		g_Util.Parse ( 3, g_Vars.ESP.ColorCTHideString, g_Vars.ESP.ColorCTHide );
		g_Util.Parse ( 3, g_Vars.ESP.ColorCTVisString, g_Vars.ESP.ColorCTVis );
		g_Util.Parse ( 3, g_Vars.ESP.SoundColorString, g_Vars.ESP.SoundColor );
		g_Util.Parse ( 3, g_Vars.ESP.FontColorString, g_Vars.ESP.FontColor );
	}

	void _fastcall IniRead::Main ( )
	{
		std::string Path = g_File.DirFile ( MAIN_PATH ).c_str ( );

		INIREAD_STRING_CONVERT ( g_Vars.Main.Launguage, MAIN, MAIN_LANGUAGE );

		INIREAD_STRING_CONVERT ( g_Vars.Main.ReloadKey, MAIN, MAIN_RELOAD_KEY );
		INIREAD_STRING_CONVERT ( g_Vars.Main.PanicKey, MAIN, MAIN_PANIC_KEY );

		INIREAD_INT ( g_Vars.Main.PlayerVisibleScan, MAIN, MAIN_PLAYER_VISIBLE_SCAN );
		INIREAD_INT ( g_Vars.Main.PlayerValidCheck, MAIN, MAIN_PLAYER_VALID_CHECK );

		INIREAD_INT ( g_Vars.Main.FontOutLineQuality, MAIN, MAIN_FONT_OUTLINE_QUALITY );

		INIREAD_INT ( g_Vars.Main.AntiScreenEnable, MAIN, MAIN_ANTISCREEN_ENABLE );
		INIREAD_INT ( g_Vars.Main.AntiScreenTimer, MAIN, MAIN_ANTISCREEN_TIMER );
		INIREAD_STRING_CONVERT ( g_Vars.Main.AntiScreenKey, MAIN, MAIN_ANTISCREEN_STEAM_KEY );
	}

	void _fastcall IniRead::Menu ( )
	{
		std::string Path = g_File.DirFile ( VISUALS_PATH ).c_str ( );

		INIREAD_INT ( g_Vars.Menu.Pos_x, MENU, MENU_POS_X );
		INIREAD_INT ( g_Vars.Menu.Pos_y, MENU, MENU_POS_Y );

		INIREAD_INT ( g_Vars.Menu.BoxHeight, MENU, MENU_BOX_HEIGHT );
		INIREAD_INT ( g_Vars.Menu.BoxWidth, MENU, MENU_BOX_WIDTH );

		INIREAD_STRING ( g_Vars.Menu.BoxColorString, MENU, MENU_BOX_COLOR );
		INIREAD_STRING ( g_Vars.Menu.BoxFillColorString, MENU, MENU_BOXFILL_COLOR );
		INIREAD_STRING ( g_Vars.Menu.BoxSelectColorString, MENU, MENU_BOXSELECT_COLOR );
		INIREAD_STRING ( g_Vars.Menu.TextColorString, MENU, MENU_TEXT_COLOR );

		INIREAD_STRING_CONVERT ( g_Vars.Menu.Key, MENU, MENU_KEY );

		g_Util.Parse ( 4, g_Vars.Menu.BoxColorString, g_Vars.Menu.BoxColor );
		g_Util.Parse ( 4, g_Vars.Menu.BoxFillColorString, g_Vars.Menu.BoxFillColor );
		g_Util.Parse ( 4, g_Vars.Menu.BoxSelectColorString, g_Vars.Menu.BoxSelectColor );
		g_Util.Parse ( 4, g_Vars.Menu.TextColorString, g_Vars.Menu.TextColor );
	}

	void _fastcall IniRead::Functions ( )
	{
		std::string Path = g_File.DirFile ( FUNCTIONS_PATH ).c_str ( );

		INIREAD_INT ( g_Vars.Function.Menu, FUNCTIONS, FUNCTIONS_MENU );
		INIREAD_INT ( g_Vars.Function.ESP, FUNCTIONS, FUNCTIONS_ESP );
		INIREAD_INT ( g_Vars.Function.NoFlash, FUNCTIONS, FUNCTIONS_NOFLASH );
		INIREAD_INT ( g_Vars.Function.ScreenInfo, FUNCTIONS, FUNCTIONS_SCREEINFO );
		INIREAD_INT ( g_Vars.Function.Camera, FUNCTIONS, FUNCTIONS_CAMERA );
		INIREAD_INT ( g_Vars.Function.Speed, FUNCTIONS, FUNCTIONS_SPEED );
		INIREAD_INT ( g_Vars.Function.BunnyHop, FUNCTIONS, FUNCTIONS_BHOP );
		INIREAD_INT ( g_Vars.Function.GroundStrafe, FUNCTIONS, FUNCTIONS_GSTRAFE );
		INIREAD_INT ( g_Vars.Function.JumpBug, FUNCTIONS, FUNCTIONS_JUMPBUG );
		INIREAD_INT ( g_Vars.Function.EdgeBug, FUNCTIONS, FUNCTIONS_EDGEBUG );
		INIREAD_INT ( g_Vars.Function.StrafeHelper, FUNCTIONS, FUNCTIONS_STRAFE_HELPER );

		INIREAD_INT ( g_Vars.Function.Commands, FUNCTIONS, FUNCTIONS_CMDS );
		INIREAD_STRING ( g_Util.Prefix, FUNCTIONS, FUNCTIONS_CMDS_PREFIX );
		INIREAD_INT ( g_Vars.Function.CommandsBinds, FUNCTIONS, FUNCTIONS_CMDS_BINDS );
	}

	IniRead g_IniRead;
}