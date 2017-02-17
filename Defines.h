/*dll's*/
#define HW_DLL							"hw.dll"
#define SW_DLL							"sw.dll"
#define CLIENT_DLL						"client.dll"
#define GAMEUI_DLL						"GameUI.dll"
/*end*/

/*pattern's*/
#define CLIENT_PATTERN					"ScreenFade"
#define STUDIO_PATTERN					"Couldn't get client .dll studio model rendering interface."
#define CONSOLE_PATTERN					"GameConsole003"
#define USERMSG_PATTERN					"UserMsg: Not Present on Client %d"
#define SVC_MSG_PATTERN					"-------- Message Load ---------"
#define SVC_MESSAGES_PATTERN			"End of List."
/*end*/

/*error's*/
#define ERROR_HEADER					"Hpp Hack"

#define CLIENT_FIND_ERROR				"Error #0000. Couldn't find g_pClient pointer."
#define ENGINE_FIND_ERROR				"Error #0001. Couldn't find g_pEngine pointer."
#define STUDIO_FIND_ERROR				"Error #0002. Couldn't find g_pStudio pointer."
#define PPMOVE_PTR_ERROR				"Error #0003. Couldn't find g_pPlayerMove pointer."
#define USERMSG_BASE_FIND_ERROR			"Error #0004. Couldn't find g_pUserMsgBase pointer."
#define ENGINEMSG_BASE_FIND_ERROR		"Error #0005. Couldn't find g_pEngineMsgBase pointer."
#define CONSOLE_ERROR_1					"Error #0006. Couldn't find GameConsole pointer."
#define CONSOLE_ERROR_2					"Error #0007. Couldn't find GameConsole pointer."
#define CONSOLE_ERROR_3					"Error #0008. Couldn't find GameConsole pointer."
#define ABSOLUTE_ERROR					"Error #0009. Absolute Address Error."
#define GAMEINFO_ERROR					"Error #0010. Couldn't find GameInfo pointer."
#define SVC_MSG_ERROR_1					"Error #0011. Couldn't find SvcBase pointer."
#define SVC_MSG_ERROR_2					"Error #0012. Couldn't find SvcBase pointer."
#define ENGINEMSG_ERROR					"Error #0013. Couldn't find %s."
#define MSG_READ_CORD					"Error #0014. MSG_ReadCoord."
#define MSG_STR_READING					"Error #0015. MSG_StartBitReading.\nNote: If you inject Hpp Hack with another cheat, it is likely that they are not compatible."
#define MSG_END_READING					"Error #0016. MSG_EndBitReading.\nNote: If you inject Hpp Hack with another cheat, it is likely that they are not compatible."
#define EXEC_CONFIG_ERROR				"Error #0017. Couldn't find file \""
#define SPEEDPTR_ERROR					"Error #0018. Couldn't find SpeedPtr pointer."
/*end*/

#define FE_MAIN_CREATE					"File \"Main.ini\" automatically created.\n"

#define HPP								"[Hpp] "
#define SETTINGS_RELOADED_ENG			"Settings successfully reloaded.\n"
#define SETTINGS_RELOADED_RUS			"Настройки успешно перезагружены.\n"
#define SETTINGS_SAVED_ENG				"Settings successfully saved.\n"
#define SETTINGS_SAVED_RUS				"Настройки успешно сохранены.\n"
#define FILE_LOADED_ENG					"Config file successfully loaded.\n"
#define FILE_LOADED_RUS					"Файл конфигурации успешно загружен.\n"

#define BIND_ATTACH_CMD					"bind <key> [command] : attach a command to a key\n"
#define UNBIND_REMOVE_CMD				"unbind <key> : remove commands from a key\n"
#define IS_NOT_BOUND					" is not bound\n"

#define VERSION							"3.0 dev 11\n"
#define AUTHOR							"kilabeez\n"

#define COPYRIGHT_TEXT					"Hpp Hack v3.0 (dev version)"

#define LUCIDA_CONSOLE					"Lucida Console"
#define VERDANA							"Verdana"
#define CALIBRI							"Calibri"

#define MENU							"Menu"
#define MAIN							"Main"
#define FUNCTIONS						"Functions"
#define mESP							"ESP"
#define NOFLASH							"NoFlash"
#define mSCREENINFO						"ScreenInfo"
#define CAMERA							"Camera"
#define SPEED							"Speed"
#define BHOP							"BunnyHop"
#define GSTRAFE							"GroundStrafe"
#define JUMPBUG							"JumpBug"
#define EDGEBUG							"EdgeBug"
#define STRAFE_HELPER					"StrafeHelper"

#define SETTINGS_DIR_PATH				"\\Settings"
#define CONFIGS_DIR_PATH				"\\Configs"

#define MISC_PATH						"\\Settings\\Misc.ini"
#define MAIN_PATH						"\\Settings\\Main.ini"
#define VISUALS_PATH					"\\Settings\\Visuals.ini"
#define FUNCTIONS_PATH					"\\Settings\\Functions.ini"
#define AUTORUN_PATH					"\\Configs\\AutoRun.cfg"

#define MENU_POS_X						"|Menu.Pos.x"
#define MENU_POS_Y						"|Menu.Pos.y"
#define MENU_BOX_HEIGHT					"|Menu.Box.Height"
#define MENU_BOX_WIDTH					"|Menu.Box.Width"
#define MENU_BOX_COLOR					"|Menu.Box.Color"
#define MENU_BOXFILL_COLOR				"|Menu.BoxFill.Color"
#define MENU_BOXSELECT_COLOR			"|Menu.BoxSelect.Color"
#define MENU_TEXT_COLOR					"|Menu.Text.Color"
#define MENU_KEY						"|Menu.Key"

#define MAIN_LANGUAGE					"|Language"
#define MAIN_RELOAD_KEY					"|Reload.Key"
#define MAIN_PANIC_KEY					"|Panic.Key"
#define MAIN_PLAYER_VISIBLE_SCAN		"|Player.VisibleScan"
#define MAIN_PLAYER_VALID_CHECK			"|Player.ValidCheck"
#define MAIN_FONT_OUTLINE_QUALITY		"|Font.OutLine.Quality"
#define MAIN_ANTISCREEN_ENABLE			"|AntiScreen.Enable"
#define MAIN_ANTISCREEN_TIMER			"|AntiScreen.Timer"
#define MAIN_ANTISCREEN_STEAM_KEY		"|AntiScreen.Steam.Key"

#define FUNCTIONS_MENU					"|Menu"
#define FUNCTIONS_ESP					"|ESP"
#define FUNCTIONS_NOFLASH				"|NoFlash"
#define FUNCTIONS_SCREEINFO				"|ScreenInfo"
#define FUNCTIONS_CAMERA				"|Camera"
#define FUNCTIONS_SPEED					"|Speed"
#define FUNCTIONS_BHOP					"|BunnyHop"
#define FUNCTIONS_GSTRAFE				"|GroundStrafe"
#define FUNCTIONS_JUMPBUG				"|JumpBug"
#define FUNCTIONS_EDGEBUG				"|EdgeBug"
#define FUNCTIONS_STRAFE_HELPER			"|StrafeHelper"
#define FUNCTIONS_CMDS					"|Console.Commands"
#define FUNCTIONS_CMDS_PREFIX			"|Console.Commands.Prefix"
#define FUNCTIONS_CMDS_BINDS			"|Console.Binds"

#define ESP_ENABLE						"|ESP.Enable"
#define ESP_PLAYER						"|ESP.Player"
#define ESP_PLAYER_VISIBLE_ONLY			"|ESP.Player.VisibleOnly"
#define ESP_PLAYER_BOX					"|ESP.Player.Box"
#define ESP_PLAYER_BOX_LINEWIDTH		"|ESP.Player.Box.LineWidth"
#define ESP_PLAYER_BOX_T_VIS			"|ESP.Player.Box.T.Vis"
#define ESP_PLAYER_BOX_T_HIDE			"|ESP.Player.Box.T.Hide"
#define ESP_PLAYER_BOX_CT_VIS			"|ESP.Player.Box.CT.Vis"
#define ESP_PLAYER_BOX_CT_HIDE			"|ESP.Player.Box.CT.Hide"
#define ESP_PLAYER_NAME					"|ESP.Player.Name"
#define ESP_PLAYER_WEAPON				"|ESP.Player.Weapon"
#define ESP_PLAYER_DISTANCE				"|ESP.Player.Distance"
#define ESP_PLAYER_BARREL				"|ESP.Player.Barrel"
#define ESP_WORLD_ITEMS					"|ESP.World.Items"
#define ESP_WORLD_NADES					"|ESP.World.Nades"
#define ESP_C4TIMER						"|ESP.C4Timer"
#define ESP_C4TIMER_VALUE				"|ESP.C4Timer.Value"
#define ESP_SOUND						"|ESP.Sound"
#define ESP_SOUND_LINEWIDTH				"|ESP.Sound.LineWidth"
#define ESP_SOUND_FADE_TIME				"|ESP.Sound.FadeTime"
#define ESP_SOUND_COLOR					"|ESP.Sound.Color"
#define ESP_FONT_OUTLINE				"|ESP.Font.OutLine"
#define ESP_FONT_COLOR					"|ESP.Font.Color"
#define ESP_PANIC_KEY					"|ESP.Panic.Key"

#define NOFLASH_ENABLE					"|NoFlash.Enable"
#define NOFLASH_FADELIMIT				"|NoFlash.Fade.Limit"
#define NOFLASH_FADECOLOR				"|NoFlash.Fade.Color"
#define NOFLASH_FADECOLORRANDOM			"|NoFlash.Fade.Color.Random"
#define NOFLASH_SHOWPERCENTAGE			"|NoFlash.ShowPercentage"
#define NOFLASH_FONT_OUTLINE			"|NoFlash.Font.OutLine"

#define SCREENINFO_ENABLE				"|ScreenInfo.Enable"
#define SCREENINFO_FPS					"|ScreenInfo.FPS"
#define SCREENINFO_COPYRIGHT			"|ScreenInfo.CopyRight"
#define SCREENINFO_TIME					"|ScreenInfo.Time"
#define SCREENINFO_SHOWKEYS				"|ScreenInfo.ShowKeys"
#define SCREENINFO_KREEDZ				"|ScreenInfo.Kreedz"
#define SCREENINFO_FONT_COLOR			"|ScreenInfo.Font.Color"
#define SCREENINFO_FONT_OUTLINE			"|ScreenInfo.Font.OutLine"

#define THIRDPERSON_ENABLE				"|ThirdPerson.Enable"
#define THIRDPERSON_SIDE				"|ThirdPerson.Side"
#define THIRDPERSON_UP					"|ThirdPerson.Up"
#define THIRDPERSON_BACK				"|ThirdPerson.Back"
#define THIRDPERSON_SWITCH_KEY			"|ThirdPerson.SwitchKey"

#define FREELOOK_ENABLE					"|FreeLook.Enable"
#define FREELOOK_SPEED					"|FreeLook.Speed"	
#define FREELOOK_SWITCH_KEY				"|FreeLook.SwitchKey"

#define SPECTATOR_ENABLE				"|Spectator.Enable"
#define SPECTATOR_ID					"|Spectator.ID"
#define SPECTATOR_SWITCH_KEY			"|Spectator.SwitchKey"

#define SPEED_VALUE						"|Speed"
#define SPEED_ENGINE_VALUE				"|Speed.Engine"
#define SPEED_TYPE						"|Speed.Type"
#define SPEED_BOOST						"|Speed.Boost"
#define SPEED_BOOST_KEY					"|Speed.Boost.Key"
#define SPEED_SLOWMOTION				"|Speed.SlowMotion"
#define SPEED_SLOWMOTION_KEY			"|Speed.SlowMotion.Key"

#define BHOP_SCROLL_EMULATION			"|BunnyHop.Scroll.Emulation"
#define BHOP_SCROLL_DIRECTION			"|BunnyHop.Scroll.Direction"
#define BHOP_DISTANCE					"|BunnyHop.Distance"
#define BHOP_NOSLOWDOWN					"|BunnyHop.NoSlowDown"
#define BHOP_ONLADDER					"|BunnyHop.OnLadder"
#define BHOP_STANDUP_AUTO				"|BunnyHop.StandUp.Auto"
#define BHOP_STANDUP_FALLVELOCITY		"|BunnyHop.StandUp.FallVelocity"
#define BHOP_STANDUP_KEY				"|BunnyHop.StandUp.Key"
#define BHOP_KEY						"|BunnyHop.Key"

#define GSTRAFE_SCROLL_EMULATION		"|GroundStrafe.Scroll.Emulation"
#define GSTRAFE_SCROLL_DIRECTION		"|GroundStrafe.Scroll.Direction"
#define GSTRAFE_DISTANCE				"|GroundStrafe.Distance"
#define GSTRAFE_COUNT					"|GroundStrafe.Count"
#define GSTRAFE_FALLRUN					"|GroundStrafe.FallRun"
#define GSTRAFE_SLOWDOWN_SCALE			"|GroundStrafe.SlowDown.Scale"
#define GSTRAFE_STANDUP_FALLVELOCITY	"|GroundStrafe.StandUp.FallVelocity"
#define GSTRAFE_STANDUP_KEY				"|GroundStrafe.StandUp.Key"
#define GSTRAFE_KEY						"|GroundStrafe.Key"

#define JUMPBUG_AUTO					"|JumpBug.Auto"
#define JUMPBUG_AUTO_DAMAGE				"|JumpBug.Auto.Damage"
#define JUMPBUG_AUTO_PERCENTAGE			"|JumpBug.Auto.Percentage"
#define JUMPBUG_SLOWDOWN				"|JumpBug.SlowDown"
#define JUMPBUG_SLOWMOTION				"|JumpBug.SlowMotion"
#define JUMPBUG_KEY						"|JumpBug.Key"

#define EDGEBUG_AUTO					"|EdgeBug.Auto"
#define EDGEBUG_AUTO_DAMAGE				"|EdgeBug.Auto.Damage"
#define EDGEBUG_SPEED					"|EdgeBug.Speed"
#define EDGEBUG_SPEED_FINAL				"|EdgeBug.Speed.Final"
#define EDGEBUG_SPEED_OFFSET			"|EdgeBug.Speed.Offset"
#define EGDEBUG_KEY						"|EdgeBug.Key"

#define STRAFE_HELPER_ACTIVE			"|StrafeHelper.Active"
#define STRAFE_HELPER_MODE				"|StrafeHelper.Mode"
#define STRAFE_HELPER_TYPE				"|StrafeHelper.Type"
#define STRAFE_HELPER_CORRECT_SPEED		"|StrafeHelper.Correct.Speed"
#define STRAFE_HELPER_CORRECT_LIMIT		"|StrafeHelper.Correct.Limit"
#define STRAFE_HELPER_CORRECT_SMOOTH	"|StrafeHelper.Correct.Limit.Smooth"
#define STRAFE_HELPER_KEY_EMULATION		"|StrafeHelper.KeyEmulation"
#define STRAFE_HELPER_BOOST				"|StrafeHelper.Boost"
#define STRAFE_HELPER_MINIMAL_SPEED		"|StrafeHelper.MinimalSpeed"
#define STRAFE_HELPER_DIRECTION			"|StrafeHelper.Direction"
#define STRAFE_HELPER_DIRECTION_AUTO	"|StrafeHelper.Direction.Auto"
#define STRAFE_HELPER_STRAFE_LIMIT		"|StrafeHelper.StrafeLimit"
#define STRAFE_HELPER_SWITCH_KEY		"|StrafeHelper.SwitchKey"
#define STRAFE_HELPER_KEY				"|StrafeHelper.Key"

#define TERRORIST_UMSG					"TERRORIST"
#define CT_UMSG							"CT"

#define RESET_HUD						"ResetHUD"
#define SET_FOV							"SetFOV"
#define TEAM_INFO						"TeamInfo"
#define CUR_WEAPON						"CurWeapon"
#define DEATH_MSG						"DeathMsg"
#define TEXT_MSG						"TextMsg"

#define FLASHED							"Flashed: %d"
#define DONTSEE							"You are don't see."

#define SEQUENCE_RELOADING				"reloading"
#define SEQUENCE_PLANTING				"planting c4"

#define HEGREN							"hegrenade"
#define FLASH							"flash"
#define SMOKE							"smoke"
#define USP								"usp"
#define GLOCK18							"glock18"
#define DEAGLE							"deagle"
#define P228							"p228"
#define ELITE							"elite"
#define FIVESEVEN						"fiveseven"
#define M3								"m3"
#define XM1014							"xm1014"
#define MP5								"mp5"
#define TMP								"tmp"
#define P90								"p90"
#define MAC10							"mac10"
#define UMP45							"ump45"
#define FAMAS							"famas"
#define SG552							"sg552"
#define AK47							"ak47"
#define M4A1							"m4a1"
#define AUG								"aug"
#define SCOUT							"scout"
#define AWP								"awp"
#define G3SG1							"g3sg1"
#define SG550							"sg550"
#define GALIL							"galil"
#define M249							"m249"
#define SHIELD							"shield"
#define BACKPACK						"backpack"
#define THIGHPACK						"thighpack"
#define C4								"c4"
#define C4_PLANTED						"bomb"

#define SOUND							"svc_sound"
#define SPAWN_STATIC_SOUND				"svc_spawnstaticsound"
#define STUFF_TEXT						"svc_stufftext"
#define NEW_USER_MSG					"svc_newusermsg"
#define UPDATE_USER_INFO				"svc_updateuserinfo"
#define SEND_CVAR_VALUE					"svc_sendcvarvalue"
#define SEND_CVAR_VALUE2				"svc_sendcvarvalue2"
#define DIRECTOR						"svc_director"

#define HPP_MESSAGE						"Hpp Hack v3.0 (dev version)"

#define MENU_MENU						"Menu Settings"
#define MENU_MAIN						"Main"
#define MENU_ESP						"ESP Settings"
#define MENU_ESP_COLORS					"ESP Colors"
#define MENU_NOFLASH					"NoFlash"
#define MENU_SCREENINFO					"ScreenInfo"
#define MENU_CAMERA						"Camera"
#define MENU_SPEED						"Speed"
#define MENU_BHOP						"BunnyHop"
#define MENU_GSTRAFE					"GroundStrafe"
#define MENU_JUMPBUG					"JumpBug"
#define MENU_EDGEBUG					"EdgeBug"
#define MENU_STRAFE_HELPER				"Strafe Helper"
#define MENU_LOAD_SETTINGS				"Load Settings"
#define MENU_SAVE_SETTINGS				"Save Settings"

#define MENU_MENU_POS_X					"Pos.x"
#define MENU_MENU_POS_Y					"Pos.y"
#define MENU_MENU_BOX_HEIGHT			"Box.Height"
#define MENU_MENU_BOX_WIDTH				"Box.Width"
#define MENU_MENU_BOX_COLOR_R			"Box.Color.R"
#define MENU_MENU_BOX_COLOR_G			"Box.Color.G"
#define MENU_MENU_BOX_COLOR_B			"Box.Color.B"
#define MENU_MENU_BOX_COLOR_A			"Box.Color.A"
#define MENU_MENU_BOXFILL_COLOR_R		"BoxFill.Color.R"
#define MENU_MENU_BOXFILL_COLOR_G		"BoxFill.Color.G"
#define MENU_MENU_BOXFILL_COLOR_B		"BoxFill.Color.B"
#define MENU_MENU_BOXFILL_COLOR_A		"BoxFill.Color.A"
#define MENU_MENU_BOXSELECT_COLOR_R		"BoxSelect.Color.R"
#define MENU_MENU_BOXSELECT_COLOR_G		"BoxSelect.Color.G"
#define MENU_MENU_BOXSELECT_COLOR_B		"BoxSelect.Color.B"
#define MENU_MENU_BOXSELECT_COLOR_A		"BoxSelect.Color.A"
#define MENU_MENU_TEXT_COLOR_R			"Text.Color.R"
#define MENU_MENU_TEXT_COLOR_G			"Text.Color.G"
#define MENU_MENU_TEXT_COLOR_B			"Text.Color.B"
#define MENU_MENU_TEXT_COLOR_A			"Text.Color.A"

#define MENU_MAIN_PLAYER_VISIBLE_SCAN	"Player.VisibleScan"
#define MENU_MAIN_PLAYER_VALID_CHECK	"Player.ValidCheck"
#define MENU_MAIN_FONT_OUTLINE_QUALITY	"Font.OutLine.Quality"
#define MENU_MAIN_ANTISCREEN_ENABLE		"AntiScreen.Enable"
#define MENU_MAIN_ANTISCREEN_TIME		"AntiScreen.Timer"

#define MENU_ESP_ENABLE					"Enable"
#define MENU_ESP_PLAYER					"Player"
#define MENU_ESP_PLAYER_VISIBLE_ONLY	"Player.VisibleOnly"
#define MENU_ESP_PLAYER_BOX				"Player.Box"
#define MENU_ESP_PLAYER_BOX_LINEWIDTH	"Player.Box.LineWidth"
#define MENU_ESP_PLAYER_NAME			"Player.Name"
#define MENU_ESP_PLAYER_WEAPON			"Player.Weapon"
#define MENU_ESP_PLAYER_DISTANCE		"Player.Distance"
#define MENU_ESP_PLAYER_BARREL			"Player.Barrel"
#define MENU_ESP_WORLD_ITEMS			"World.Items"
#define MENU_ESP_WORLD_NADES			"World.Nades"
#define MENU_ESP_C4TIMER				"C4Timer"
#define MENU_ESP_C4TIMER_VALUE			"C4Timer.Value"
#define MENU_ESP_SOUND					"Sound"
#define MENU_ESP_SOUND_LINEWIDTH		"Sound.LineWidth"
#define MENU_ESP_SOUND_FADE_TIME		"Sound.FadeTime"
#define MENU_ESP_FONT_OUTLINE			"Font.OutLine"

#define MENU_ESP_COLOR_T_HIDE_R			"Box.T.Hide.R"
#define MENU_ESP_COLOR_T_HIDE_G			"Box.T.Hide.G"
#define MENU_ESP_COLOR_T_HIDE_B			"Box.T.Hide.B"
#define MENU_ESP_COLOR_T_VIS_R			"Box.T.Vis.R"
#define MENU_ESP_COLOR_T_VIS_G			"Box.T.Vis.G"
#define MENU_ESP_COLOR_T_VIS_B			"Box.T.Vis.B"
#define MENU_ESP_COLOR_CT_HIDE_R		"Box.CT.Hide.R"
#define MENU_ESP_COLOR_CT_HIDE_G		"Box.CT.Hide.G"
#define MENU_ESP_COLOR_CT_HIDE_B		"Box.CT.Hide.B"
#define MENU_ESP_COLOR_CT_VIS_R			"Box.CT.Vis.R"
#define MENU_ESP_COLOR_CT_VIS_G			"Box.CT.Vis.G"
#define MENU_ESP_COLOR_CT_VIS_B			"Box.CT.Vis.B"
#define MENU_ESP_SOUND_COLOR_R			"Sound.Color.R"
#define MENU_ESP_SOUND_COLOR_G			"Sound.Color.G"
#define MENU_ESP_SOUND_COLOR_B			"Sound.Color.B"
#define MENU_ESP_FONT_COLOR_R			"Font.Color.R"
#define MENU_ESP_FONT_COLOR_G			"Font.Color.G"
#define MENU_ESP_FONT_COLOR_B			"Font.Color.B"

#define MENU_NOFLASH_ENABLE				"Enable"
#define MENU_NOFLASH_FADE_LIMIT			"Fade.Limit"
#define MENU_NOFLASH_FADE_COLOR_R		"Fade.Color.R"
#define MENU_NOFLASH_FADE_COLOR_G		"Fade.Color.G"
#define MENU_NOFLASH_FADE_COLOR_B		"Fade.Color.B"
#define MENU_NOFLASH_FADE_COLOR_RANDOM	"Fade.Color.Random"
#define MENU_NOFLASH_SHOWPERCENTAGE		"ShowPercentage"
#define MENU_NOFLASH_FONT_OUTLINE		"Font.OutLine"

#define MENU_SCREENINFO_ENABLE			"Enable"
#define MENU_SCREENINFO_FPS				"FPS"
#define MENU_SCREENINFO_COPYRIGHT		"CopyRight"
#define MENU_SCREENINFO_TIME			"Time"
#define MENU_SCREENINFO_SHOWKEYS		"ShowKeys"
#define MENU_SCREENINFO_KREEDZ			"Kreedz"
#define MENU_SCREENINFO_FONT_COLOR_R	"Font.Color.R"
#define MENU_SCREENINFO_FONT_COLOR_G	"Font.Color.G"
#define MENU_SCREENINFO_FONT_COLOR_B	"Font.Color.B"
#define MENU_SCREENINFO_FONT_OUTLINE	"Font.OutLine"

#define MENU_THIRDPERSON_ENABLE			"ThirdPerson.Enable"
#define MENU_THIRDPERSON_SIDE			"ThirdPerson.Side"
#define MENU_THIRDPERSON_UP				"ThirdPerson.Up"
#define MENU_THIRDPERSON_BACK			"ThirdPerson.Back"

#define MENU_FREELOOK_ENABLE			"FreeLook.Enable"
#define MENU_FREELOOK_SPEED				"FreeLook.Speed"

#define MENU_SPECTATOR_ENABLE			"Spectator.Enable"
#define MENU_SPECTATOR_ID				"Spectator.ID"

#define MENU_SPEED_VALUE				"Speed"
#define MENU_SPEED_ENGINE_VALUE			"Speed.Engine"
#define MENU_SPEED_TYPE					"Speed.Type"
#define MENU_SPEED_BOOST				"Speed.Boost"
#define MENU_SPEED_SLOWMO				"Speed.SlowMotion"

#define MENU_BHOP_SCROLL_EMULATION		"Scroll.Emulation"
#define MENU_BHOP_SCROLL_DIRECTION		"Scroll.Direction"
#define MENU_BHOP_DISTANCE_MIN			"Distance.Min"
#define MENU_BHOP_DISTANCE_MAX			"Distance.Max"
#define MENU_BHOP_COUNT_MIN				"Count.Min"
#define MENU_BHOP_COUNT_MAX				"Count.Max"
#define MENU_BHOP_NOSLOWDOWN			"NoSlowDown"
#define MENU_BHOP_ONLADDER				"OnLadder"
#define MENU_BHOP_STANDUP_AUTO			"StandUp.Auto"
#define MENU_BHOP_STANDUP_FALLVELOCITY	"StandUp.FallVelocity"

#define MENU_GSTRAFE_SCROLL_EMULATION	"Scroll.Emulation"
#define MENU_GSTRAFE_SCROLL_DIRECTION	"Scroll.Direction"
#define MENU_GSTRAFE_DISTANCE_MIN		"Distance.Min"
#define MENU_GSTRAFE_DISTANCE_MAX		"Distance.Max"
#define MENU_GSTRAFE_COUNT_MIN			"Count.Min"
#define MENU_GSTRAFE_COUNT_MAX			"Count.Max"
#define MENU_GSTARFE_FALLRUN			"FallRun"
#define MENU_GSTARFE_SLOWDOWN_SCALE		"SlowDown.Scale"
#define MENU_GSTARFE_STANDUP_VELOCITY	"StandUp.FallVelocity"

#define MENU_JUMPBUG_AUTO				"Auto"
#define MENU_JUMPBUG_AUTO_DAMAGE		"Auto.Damage"
#define MENU_JUMPBUG_AUTO_PERCENTAGE	"Auto.Percentage"
#define MENU_JUMPBUG_SLOWDOWN			"SlowDown"
#define MENU_JUMPBUG_SLOWDOWN_DISTANCE	"SlowDown.Distance"
#define MENU_JUMPBUG_SLOWMOTION			"SlowMotion"

#define MENU_EDGEBUG_AUTO				"Auto"
#define MENU_EDGEBUG_AUTO_DAMAGE		"Auto.Damage"
#define MENU_EDGEBUG_SPEED				"Speed"
#define MENU_EDGEBUG_SPEED_FINAL		"Speed.Final"
#define MENU_EDGEBUG_SPEED_OFFSET		"Speed.Offset"

#define MENU_STRAFEHELPER_ACTIVE		"Active"
#define MENU_STRAFEHELPER_MODE			"Mode"
#define MENU_STRAFEHELPER_TYPE			"Type"
#define MENU_STRAFEHELPER_CORRECT_SPEED	"Correct.Speed"
#define MENU_STRAFEHELPER_CORRECT_LIMIT	"Correct.Limit"
#define MENU_STRAFEHELPER_CORRECT_SMOTH	"Correct.Limit.Smooth"
#define MENU_STRAFEHELPER_KEY_EMULATION	"KeyEmulation"
#define MENU_STRAFEHELPER_BOOST			"Boost"
#define MENU_STRAFEHELPER_MIN_SPEED		"MinimalSpeed"
#define MENU_STRAFEHELPER_DIRECTION		"Direction"
#define MENU_STRAFEHELPER_DIR_AUTO		"Direction.Auto"
#define MENU_STRAFEHELPER_STRAFE_LIMIT	"StrafeLimit"

#define CMD_PANIC						"panic"
#define CMD_ESP_PANIC					"esp_panic"
#define CMD_SETTINGS_RELOAD				"settings_reload"
#define CMD_BHOP						"bhop"
#define CMD_BHOP_STANDUP				"bhop_standup"
#define CMD_GSTRAFE						"gstrafe"
#define CMD_GSTRAFE_STANDUP				"gstrafe_standup"
#define CMD_SPEED_BOOST					"speed_boost"
#define CMD_SPEED_SLOWMO				"speed_slowmo"
#define CMD_JUMPBUG						"jumpbug"
#define CMD_EDGEBUG						"edgebug"
#define CMD_ANTISCREEN					"antiscreen"
#define CMD_STRAFE_HELPER				"strafe_helper"
#define CMD_STRAFE_HELPER_SWITCH		"strafe_helper_switch"
#define CMD_THIRDPERSON_SWITCH			"thirdperson_switch"
#define CMD_FREELOOK_SWITCH				"freelook_switch"
#define CMD_SPECTATOR_SWITCH			"spectator_switch"

#define OFF								"off"
#define ON								"on"

#define DOWN							"down"
#define UP								"up"

#define CompareMemory(Buff1, Buff2, Size) __comparemem((const UCHAR *)Buff1, (const UCHAR *)Buff2, (UINT)Size)
#define FindMemoryClone(Start, End, Clone, Size) __findmemoryclone((const ULONG)Start, (const ULONG)End, (const ULONG)Clone, (UINT)Size)
#define FindReference(Start, End, Address)  __findreference((const ULONG)Start, (const ULONG)End, (const ULONG)Address)

#define POW(x) ((x)*(x))

#define VectorLength(a) sqrt(POW((a)[0])+POW((a)[1])+POW((a)[2]))
#define VectorLengthSquared(v) ((v)[0]*(v)[0]+(v)[1]*(v)[1]+(v)[2]*(v)[2])
#define VectorTransform(a,b,c){(c)[0]=DotProduct((a),(b)[0])+(b)[0][3];(c)[1]=DotProduct((a),(b)[1])+(b)[1][3];(c)[2]=DotProduct((a),(b)[2])+(b)[2][3];}
#define VectorDistance(a,b) sqrt(POW((a)[0]-(b)[0])+POW((a)[1]-(b)[1])+POW((a)[2]-(b)[2]))

#define STRAFE_MOVE_KOEF		1.4142135007461927831067196676929

#define FIND_COUNTER_VALUE		100

#define MAX_MENU_COUNT			25
#define MAX_SUB_MENU_COUNT		25

#define INT_DIGITS				19

#define MENU_ENTRY_KEY			0x5B15E
#define SUBM_ENTRY_KEY			0x1DC42

#define SUBM_ENTRY_WIDTH		185
#define SUBM_PADDING_LEFT		2
#define SUBM_VALUE_PADDING		35

#define MENU_ENTRY_WIDTH		110
#define MENU_PADDING_TOP		2

#define TEXT_PADDING_LEFT		3

#define ENTRY_HEIGHT			13

#define	SVC_BAD					0
#define	SVC_NOP                 1
#define	SVC_DISCONNECT          2
#define	SVC_EVENT               3
#define	SVC_VERSION             4
#define	SVC_SETVIEW             5
#define	SVC_SOUND               6
#define	SVC_TIME                7
#define	SVC_PRINT               8
#define	SVC_STUFFTEXT           9
#define	SVC_SETANGLE            10
#define	SVC_SERVERINFO          11
#define	SVC_LIGHTSTYLE          12
#define	SVC_UPDATEUSERINFO      13
#define	SVC_DELTADESCRIPTION    14
#define	SVC_CLIENTDATA          15
#define	SVC_STOPSOUND           16
#define	SVC_PINGS               17
#define	SVC_PARTICLE            18
#define	SVC_DAMAGE              19
#define	SVC_SPAWNSTATIC         20
#define	SVC_EVENT_RELIABLE      21
#define	SVC_SPAWNBASELINE       22
#define	SVC_TEMPENTITY          23
#define	SVC_SETPAUSE            24
#define	SVC_SIGNONNUM           25
#define	SVC_CENTERPRINT         26
#define	SVC_KILLEDMONSTER		27
#define	SVC_FOUNDSECRET         28
#define	SVC_SPAWNSTATICSOUND    29
#define	SVC_INTERMISSION        30
#define	SVC_FINALE              31
#define	SVC_CDTRACK             32
#define	SVC_RESTORE             33
#define	SVC_CUTSCENE            34
#define	SVC_WEAPONANIM          35
#define	SVC_DECALNAME           36
#define	SVC_ROOMTYPE            37
#define	SVC_ADDANGLE			38
#define	SVC_NEWUSERMSG          39
#define	SVC_PACKETENTITIES      40
#define	SVC_DELTAPACKETENTITIES 41
#define	SVC_CHOKE               42
#define	SVC_RESOURCELIST        43
#define	SVC_NEWMOVEVARS         44
#define	SVC_RESOURCEREQUEST     45
#define	SVC_CUSTOMIZATION       46
#define	SVC_CROSSHAIRANGLE      47
#define	SVC_SOUNDFADE           48
#define	SVC_FILETXFERFAILED     49
#define	SVC_HLTV                50
#define	SVC_DIRECTOR            51
#define	SVC_VOICEINIT           52
#define	SVC_VOICEDATA           53
#define	SVC_SENDEXTRAINFO       54
#define	SVC_TIMESCALE           55
#define	SVC_RESOURCELOCATION    56
#define	SVC_SENDCVARVALUE       57
#define	SVC_SENDCVARVALUE2      58

#define DEFAULT_SOUND_PACKET_VOLUME			255
#define DEFAULT_SOUND_PACKET_ATTENUATION	1.0f
#define DEFAULT_SOUND_PACKET_PITCH			100

#define BIT(n) (1<<(n))

#define SND_FL_VOLUME			BIT(0)
#define SND_FL_ATTENUATION		BIT(1)
#define SND_FL_LARGE_INDEX		BIT(2)
#define SND_FL_PITCH			BIT(3)
#define SND_FL_SENTENCE			BIT(4)
#define SND_FL_STOP				BIT(5)
#define SND_FL_CHANGE_VOL		BIT(6)
#define SND_FL_CHANGE_PITCH		BIT(7)
#define SND_FL_SPAWNING			BIT(8)

#define MAX_ENTITY				1024
#define MAX_SOUNDS				1024

#define TERRORIST				1
#define CT						2
#define SPECTATOR				0

#define FL_NONE					0
#define FL_OUTLINE				1
#define FL_CENTER				2

#define RUSSIAN					0
#define ENGLISH					1

#define	K_POINT					46
#define K_COMMA					44
#define K_0						48
#define K_1						49
#define K_2						50
#define K_3						51
#define K_4						52
#define K_5						53
#define K_6						54
#define K_7						55
#define K_8						56
#define K_9						57
#define K_BRACKET_LEFT			91
#define K_BRACKET_RIGHT			93
#define K_A						97
#define K_B						98
#define K_C						99
#define K_D						100
#define K_E						101
#define K_F						102
#define K_G						103
#define K_H						104
#define K_I						105
#define K_J						106
#define K_K						107
#define K_L						108
#define K_M						109
#define K_N						110
#define K_O						111
#define K_P						112
#define K_Q						113
#define K_R						114
#define K_S						115
#define K_T						116
#define K_U						117
#define K_V						118
#define K_W						119
#define K_X						120
#define K_Y						121
#define K_Z						122

#define M_PI					3.14159265358979323846

#define PLAYER_FATAL_FALL_SPEED		980
#define PLAYER_MAX_SAFE_FALL_SPEED	504.8

#define PARS_STRING( key_1, key_2, convert ) {\
	if ( !lstrcmpi ( Key, key_1 ) || !lstrcmpi ( Key, key_2 ) )\
	{\
		return convert;\
	}\
}

#define TraceEdge(x,y){\
	Vector Start = g_Local.Entity->origin;\
	Vector AirTemp = Start;\
	AirTemp[2] = -4096;\
	pmtrace_t *Trace = Engine::g_Engine.PM_TraceLine ( Start, AirTemp, 1.0f, ( Engine::g_pPlayerMove->flags & FL_DUCKING ) ? 1 : 0, -1 );\
	Vector Dis = ( AirTemp - g_Local.Entity->origin ) * Trace->fraction;\
	Start[2] -= 0.1f;\
	Start[2] -= -Dis[2];\
	Vector End = Start;\
	End[1] += x * mind;\
	End[0] += y * mind;\
	pmtrace_s* Trace_s = Engine::g_Engine.PM_TraceLine(End, Start, 1.0f, ( Engine::g_pPlayerMove->flags & FL_DUCKING ) ? 1 : 0, -1);\
	if ( !( Trace_s->startsolid ) )\
	{\
		mind = ( Trace_s->endpos - Start ).Length2D ( );\
	}\
}

#define DAMAGE_FOR_FALL_SPEED	(float) 100 / ( PLAYER_FATAL_FALL_SPEED - PLAYER_MAX_SAFE_FALL_SPEED )

#define WEAPON_PARS(name) {\
	Renderer::g_Drawing.Box ( int ( EntityScreen[0] - 2 ), int ( EntityScreen[1] ), 6, 6, 1, 0, 0, 0, 255 );\
	Renderer::g_Drawing.FillArea ( int ( EntityScreen[0] - 1 ), int ( EntityScreen[1] + 1 ), 4, 4, 255, 120, 50, 255 );\
	Renderer::g_Verdana.Print ( int ( EntityScreen[0] ), int ( EntityScreen[1] + 15 ), g_Vars.ESP.FontColor[0], g_Vars.ESP.FontColor[1], g_Vars.ESP.FontColor[2], 255, g_Vars.ESP.FontOutLine ?  FL_CENTER | FL_OUTLINE : FL_CENTER, name );\
}

#define WEAPON_PARS_C4_PLANTED(name) {\
	Renderer::g_Drawing.Box ( int ( EntityScreen[0] - 2 ), int ( EntityScreen[1] ), 6, 6, 1, 0, 0, 0, 255 );\
	Renderer::g_Drawing.FillArea ( int ( EntityScreen[0] - 1 ), int ( EntityScreen[1] + 1 ), 4, 4, 255, 0, 0, 255 );\
	Renderer::g_Verdana.Print ( int ( EntityScreen[0] ), int ( EntityScreen[1] + 15 ), g_Vars.ESP.FontColor[0], g_Vars.ESP.FontColor[1], g_Vars.ESP.FontColor[2], 255, g_Vars.ESP.FontOutLine ?  FL_CENTER | FL_OUTLINE : FL_CENTER, name );\
	if ( g_Vars.ESP.C4Timer && Info::g_Local.Bomb.isPlanted ) {\
	Renderer::g_Verdana.Print ( int ( EntityScreen[0] ), int ( EntityScreen[1] + 15 ) + 12, g_Vars.ESP.FontColor[0], g_Vars.ESP.FontColor[1], g_Vars.ESP.FontColor[2], 255, g_Vars.ESP.FontOutLine ?  FL_CENTER | FL_OUTLINE : FL_CENTER, "time: %.2f", Info::g_Local.Bomb.C4Timer );}\
}

#define WEAPON_PARS_C4(name) {\
	Renderer::g_Drawing.Box ( int ( EntityScreen[0] - 2 ), int ( EntityScreen[1] ), 6, 6, 1, 0, 0, 0, 255 );\
	Renderer::g_Drawing.FillArea ( int ( EntityScreen[0] - 1 ), int ( EntityScreen[1] + 1 ), 4, 4, 255, 0, 0, 255 );\
	Renderer::g_Verdana.Print ( int ( EntityScreen[0] ), int ( EntityScreen[1] + 15 ), g_Vars.ESP.FontColor[0], g_Vars.ESP.FontColor[1], g_Vars.ESP.FontColor[2], 255, g_Vars.ESP.FontOutLine ?  FL_CENTER | FL_OUTLINE : FL_CENTER, name );\
}

#define INIREAD_INT( var, section, key ) var = g_File.ReadInt ( ( char* )Path.c_str ( ), section, key, "0" )
#define INIREAD_FLOAT( var,  section, key ) var = g_File.ReadFloat ( ( char* )Path.c_str ( ), section, key, "0" )
#define INIREAD_STRING_CONVERT( var, section, key ) var = g_File.ReadStringConvert ( ( char* )Path.c_str ( ), section, key, "0" )
#define INIREAD_STRING( var, section, key ) var = g_File.ReadString ( ( char* )Path.c_str ( ), section, key, "0" )

#define WRITE_COLOR( section, key, value1, value2, value3 ) {\
	char String[100];\
	sprintf_s ( String, " %d, %d, %d", ( int )value1,  ( int )value2, ( int )value3 );\
	g_File.WriteString ( ( char* )Path.c_str ( ), section, key, String );\
}

#define WRITE_COLOR_4( section, key, value1, value2, value3, value4 ) {\
	char String[100];\
	sprintf_s ( String, " %d, %d, %d, %d", ( int )value1,  ( int )value2, ( int )value3, ( int )value4 );\
	g_File.WriteString ( ( char* )Path.c_str ( ), section, key, String );\
}

#define WRITE_DIR( section, key, value ) {\
	if ( value > 1000 ) {\
		g_File.WriteString ( ( char* )Path.c_str ( ), section, key, " up" ); }\
	else {\
		g_File.WriteString ( ( char* )Path.c_str ( ), section, key, " down" ); }\
}

#define WRITE_INT( section, key, value ) {\
	char String[100];\
	sprintf_s ( String, " %d", ( int )value );\
	g_File.WriteString ( ( char* )Path.c_str ( ), section, key, String );\
}

#define WRITE_FLOAT( section, key, value ) {\
	char String[100];\
	sprintf_s ( String, " %.1f", value );\
	g_File.WriteString ( ( char* )Path.c_str ( ), section, key, String );\
}

#define WRITE_FLOAT_2( section, key, value1, value2 ) {\
	char String[100];\
	sprintf_s ( String, " %.1f, %.1f", value1, value2 );\
	g_File.WriteString ( ( char* )Path.c_str ( ), section, key, String );\
}

#define WRITE_INT_2( section, key, value1, value2 ) {\
	char String[100];\
	sprintf_s ( String, " %d, %d", ( int )value1, ( int )value2 );\
	g_File.WriteString ( ( char* )Path.c_str ( ), section, key, String );\
}

#define rcmd( cmd_name, one, two ) {\
	g_Engine.pfnAddCommand ( g_Util.PrefHack ( "+", g_Util.Prefix, cmd_name ), one );\
	g_Engine.pfnAddCommand ( g_Util.PrefHack ( "-", g_Util.Prefix, cmd_name ), two );\
}

#define acmd( cvar_name, cmd ) g_Engine.pfnAddCommand ( g_Util.PrefHack ( "", g_Util.Prefix, cvar_name ), cmd )

#define DELETE_KEY_CMD( key ){\
	if ( KeyCommand == key )\
	{\
		key = 0;\
	}\
}

#define PRINT_IS( cmd_name, var ){\
	g_Util.ConsolePrintColor ( 100, 255, 200, "[Hpp] " );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.Prefix );\
	g_Util.ConsolePrintColor ( 200, 255, 200, cmd_name );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" is \"" );\
	g_Util.ConsolePrintColor_int ( 200, 255, 200, var );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"\n" );\
}

#define PRINT_IS_FLOAT( cmd_name, var ){\
	g_Util.ConsolePrintColor ( 100, 255, 200, "[Hpp] " );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.Prefix );\
	g_Util.ConsolePrintColor ( 200, 255, 200, cmd_name );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" is \"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, var );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"\n" );\
}

#define PRINT_ATOI( cmd_name, var ){\
	var = atoi ( g_Engine.Cmd_Argv ( 1 ) );\
	g_Util.ConsolePrintColor ( 100, 255, 200, "[Hpp] " );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.Prefix );\
	g_Util.ConsolePrintColor ( 200, 255, 200, cmd_name );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" changed to \"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Engine.Cmd_Argv ( 1 ) );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"\n" );\
}

#define PRINT_ATOF_2( cmd_name, var1, var2 ){\
	var1 = atof ( g_Engine.Cmd_Argv ( 1 ) );\
	var2 = atof ( g_Engine.Cmd_Argv ( 2 ) );\
	g_Util.ConsolePrintColor ( 100, 255, 200, "[Hpp] " );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.Prefix );\
	g_Util.ConsolePrintColor ( 200, 255, 200, cmd_name );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" changed to \"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Engine.Cmd_Argv ( 1 ) );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" \"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Engine.Cmd_Argv ( 2 ) );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"\n" );\
}

#define PRINT_ATOI_2( cmd_name, var1, var2 ){\
	var1 = atoi ( g_Engine.Cmd_Argv ( 1 ) );\
	var2 = atoi ( g_Engine.Cmd_Argv ( 2 ) );\
	g_Util.ConsolePrintColor ( 100, 255, 200, "[Hpp] " );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.Prefix );\
	g_Util.ConsolePrintColor ( 200, 255, 200, cmd_name );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" changed to \"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Engine.Cmd_Argv ( 1 ) );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" \"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Engine.Cmd_Argv ( 2 ) );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"\n" );\
}

#define PRINT_ATOF( cmd_name, var ){\
	var = atof ( g_Engine.Cmd_Argv ( 1 ) );\
	g_Util.ConsolePrintColor ( 100, 255, 200, "[Hpp] " );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.Prefix );\
	g_Util.ConsolePrintColor ( 200, 255, 200, cmd_name );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" changed to \"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Engine.Cmd_Argv ( 1 ) );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"\n" );\
}

#define PRINT_COLOR_IS_3( cmd_name, var1, var2, var3 ){\
	g_Util.ConsolePrintColor ( 100, 255, 200, "[Hpp] " );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.Prefix );\
	g_Util.ConsolePrintColor ( 200, 255, 200, cmd_name );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" is \"" );\
	g_Util.ConsolePrintColor_int ( 200, 255, 200, var1 );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" \"" );\
	g_Util.ConsolePrintColor_int ( 200, 255, 200, var2 );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" \"" );\
	g_Util.ConsolePrintColor_int ( 200, 255, 200, var3 );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"\n" );\
}

#define PRINT_COLOR_IS_4( cmd_name, var1, var2, var3, var4 ){\
	g_Util.ConsolePrintColor ( 100, 255, 200, "[Hpp] " );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.Prefix );\
	g_Util.ConsolePrintColor ( 200, 255, 200, cmd_name );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" is \"" );\
	g_Util.ConsolePrintColor_int ( 200, 255, 200, var1 );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" \"" );\
	g_Util.ConsolePrintColor_int ( 200, 255, 200, var2 );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" \"" );\
	g_Util.ConsolePrintColor_int ( 200, 255, 200, var3 );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" \"" );\
	g_Util.ConsolePrintColor_int ( 200, 255, 200, var4 );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"\n" );\
}

#define PRINT_COLOR_ATOI_3( cmd_name, var1, var2, var3 ){\
	var1 = atoi ( g_Engine.Cmd_Argv ( 1 ) );\
	var2 = atoi ( g_Engine.Cmd_Argv ( 2 ) );\
	var3 = atoi ( g_Engine.Cmd_Argv ( 3 ) );\
	g_Util.ConsolePrintColor ( 100, 255, 200, "[Hpp] " );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.Prefix );\
	g_Util.ConsolePrintColor ( 200, 255, 200, cmd_name );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" changed to \"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Engine.Cmd_Argv ( 1 ) );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" \"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Engine.Cmd_Argv ( 2 ) );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" \"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Engine.Cmd_Argv ( 3 ) );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"\n" );\
}

#define PRINT_COLOR_ATOI_4( cmd_name, var1, var2, var3, var4 ){\
	var1 = atoi ( g_Engine.Cmd_Argv ( 1 ) );\
	var2 = atoi ( g_Engine.Cmd_Argv ( 2 ) );\
	var3 = atoi ( g_Engine.Cmd_Argv ( 3 ) );\
	var4 = atoi ( g_Engine.Cmd_Argv ( 4 ) );\
	g_Util.ConsolePrintColor ( 100, 255, 200, "[Hpp] " );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.Prefix );\
	g_Util.ConsolePrintColor ( 200, 255, 200, cmd_name );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" changed to \"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Engine.Cmd_Argv ( 1 ) );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" \"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Engine.Cmd_Argv ( 2 ) );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" \"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Engine.Cmd_Argv ( 3 ) );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" \"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Engine.Cmd_Argv ( 4 ) );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"\n" );\
}

#define PRINT_IS_FLOAT_2( cmd_name, var1, var2 ){\
	g_Util.ConsolePrintColor ( 100, 255, 200, "[Hpp] " );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.Prefix );\
	g_Util.ConsolePrintColor ( 200, 255, 200, cmd_name );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" is \"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, var1 );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" \"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, var2 );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"\n" );\
}

#define PRINT_IS_MWHEEL( cmd_name, var ){\
	g_Util.ConsolePrintColor ( 100, 255, 200, "[Hpp] " );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.Prefix );\
	g_Util.ConsolePrintColor ( 200, 255, 200, cmd_name );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" is \"" );\
	if ( var != 1000 )\
	{\
		g_Util.ConsolePrintColor ( 200, 255, 200, "up\"\n" );\
	}\
	else if ( var != 1001 )\
	{\
		g_Util.ConsolePrintColor ( 200, 255, 200, "down\"\n" );\
	}\
}

#define PRINT_ATOI_MWHEEL( cmd_name, var ){\
	var = Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) ); \
	g_Util.ConsolePrintColor ( 100, 255, 200, "[Hpp] " ); \
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"" ); \
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.Prefix ); \
	g_Util.ConsolePrintColor ( 200, 255, 200, cmd_name ); \
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" changed to \"" ); \
	if ( var != 1000 )\
	{\
		g_Util.ConsolePrintColor ( 200, 255, 200, "up\"\n" ); \
	}\
	else if ( var != 1001 )\
	{\
		g_Util.ConsolePrintColor ( 200, 255, 200, "down\"\n" ); \
	}\
}

#define PRINT_IS_2( cmd_name, var1, var2 ){\
	g_Util.ConsolePrintColor ( 100, 255, 200, "[Hpp] " );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"" );\
	g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.Prefix );\
	g_Util.ConsolePrintColor ( 200, 255, 200, cmd_name );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" is \"" );\
	g_Util.ConsolePrintColor_int ( 200, 255, 200, var1 );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\" \"" );\
	g_Util.ConsolePrintColor_int ( 200, 255, 200, var2 );\
	g_Util.ConsolePrintColor ( 200, 255, 200, "\"\n" );\
}

#define PARSE_CMD( cmd_name, ret ){\
	if ( !lstrcmpi ( CommandName, g_Util.PrefHack ( "+", g_Util.Prefix, cmd_name ) ) ) {\
	return ret;}\
}

#define PARSE_CMD2( cmd_name, ret ){\
	if ( !lstrcmpi ( CommandName, g_Util.PrefHack ( "", g_Util.Prefix, cmd_name ) ) ) {\
	return ret;}\
}

#define VectorMul( vec, num, res ){\
	( res )[0] = ( vec )[0] * ( num );\
	( res )[1] = ( vec )[1] * ( num );\
	( res )[2] = ( vec )[2] * ( num );\
}