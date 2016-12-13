#include "Initial.h"

#pragma warning (disable: 4996)

namespace Initial
{
	void _fastcall Init::InitHack ( )
	{
		LoadSettings ( );

		//Engine::g_Engine.pfnRegisterVariable ( "gl_texture_1d", "1", 0 );

		Engine::g_Engine.pfnClientCmd ( "toggleconsole" );

		if ( g_Vars.main.language )
		{
			g_Util.ConsolePrintColor ( 80, 255, 80, "Hpp Hack successfully injected!\n\n" );

			g_Util.ConsolePrintColor ( 255, 240, 0, "Information about game:\n" );
			g_Util.ConsolePrintColor ( 0, 230, 230, "\t\tName: " );
			g_Util.ConsolePrintColor ( 255, 200, 0, Client::BuildInfo.GameName );
			g_Util.ConsolePrintColor ( 0, 230, 230, "\n\t\tVersion: " );
			g_Util.ConsolePrintColor ( 255, 200, 0, Client::BuildInfo.GameVersion );
			g_Util.ConsolePrintColor ( 0, 230, 230, "\n\t\tProtocol: " );
			g_Util.ConsolePrintColor ( 255, 200, 0, Client::BuildInfo.Protocol );
			g_Util.ConsolePrintColor ( 0, 230, 230, "\n\t\tBuild: " );
			g_Util.ConsolePrintColor ( 255, 200, 0, Client::BuildInfo.Build );
			g_Util.ConsolePrintColor ( 0, 230, 230, "\n\t\tRender: " );
			g_Util.ConsolePrintColor ( 255, 200, 0, g_Util.ConvertTypeToRenderString ( Engine::g_Offset.HLType ) );

			g_Util.ConsolePrintColor ( 255, 240, 0, "\n\nInformation about cheat:\n" );
			g_Util.ConsolePrintColor ( 0, 230, 230, "\t\tVersion: " );
			g_Util.ConsolePrintColor ( 255, 200, 0, VERSION );
			g_Util.ConsolePrintColor ( 0, 230, 230, "\t\tAuthor: " );
			g_Util.ConsolePrintColor ( 255, 200, 0, AUTHOR );
			g_Util.ConsolePrintColor ( 0, 230, 230, "\t\tPath: " );
			g_Util.ConsolePrintColor ( 255, 200, 0, Engine::BaseDir );
			g_Util.ConsolePrintColor ( 0, 0, 0, "\n\n" );
		}
		else
		{
			g_Util.ConsolePrintColor ( 80, 255, 80, "Hpp Hack успешно загружен!\n\n" );

			g_Util.ConsolePrintColor ( 255, 240, 0, "Информация о игре:\n" );
			g_Util.ConsolePrintColor ( 0, 230, 230, "\t\tНазвание:: " );
			g_Util.ConsolePrintColor ( 255, 200, 0, Client::BuildInfo.GameName );
			g_Util.ConsolePrintColor ( 0, 230, 230, "\n\t\tВерсия: " );
			g_Util.ConsolePrintColor ( 255, 200, 0, Client::BuildInfo.GameVersion );
			g_Util.ConsolePrintColor ( 0, 230, 230, "\n\t\tПротокол: " );
			g_Util.ConsolePrintColor ( 255, 200, 0, Client::BuildInfo.Protocol );
			g_Util.ConsolePrintColor ( 0, 230, 230, "\n\t\tПостроение: " );
			g_Util.ConsolePrintColor ( 255, 200, 0, Client::BuildInfo.Build );
			g_Util.ConsolePrintColor ( 0, 230, 230, "\n\t\tРендер: " );
			g_Util.ConsolePrintColor ( 255, 200, 0, g_Util.ConvertTypeToRenderString ( Engine::g_Offset.HLType ) );

			g_Util.ConsolePrintColor ( 255, 240, 0, "\n\nИнформация о чите:\n" );
			g_Util.ConsolePrintColor ( 0, 230, 230, "\t\tВерсия: " );
			g_Util.ConsolePrintColor ( 255, 200, 0, VERSION );
			g_Util.ConsolePrintColor ( 0, 230, 230, "\t\tАвтор�: " );
			g_Util.ConsolePrintColor ( 255, 200, 0, AUTHOR );
			g_Util.ConsolePrintColor ( 0, 230, 230, "\t\tПуть: " );
			g_Util.ConsolePrintColor ( 255, 200, 0, Engine::BaseDir );
			g_Util.ConsolePrintColor ( 0, 0, 0, "\n\n" );
		}
	}

	void _fastcall Init::LoadSettings ( )
	{
		Renderer::g_Font.InitText ( LUCIDA_CONSOLE, 12, 8 );
		Renderer::g_Verdana.InitText ( VERDANA, 13, 0 );

		if ( Files::g_File.FileExists ( Files::g_File.DirFile ( FUNCTIONS_PATH ).c_str ( ) ) )
		{
			Files::g_IniRead.Functions ( );
		}
		else
		{
			CreateFileFunctions ( );

			Files::g_IniRead.Functions ( );
		}

		if ( Files::g_File.FileExists ( Files::g_File.DirFile ( MAIN_PATH ).c_str ( ) ) )
		{
			Files::g_IniRead.Main ( );
		}
		else
		{
			CreateFileMain ( );

			Files::g_IniRead.Main ( );
		}

		if ( Files::g_File.FileExists ( Files::g_File.DirFile ( VISUALS_PATH ).c_str ( ) ) )
		{
			if ( g_Vars.function.menu )
			{
				Files::g_IniRead.Menu ( );
			}

			if ( g_Vars.function.esp )
			{
				Files::g_IniRead.ESP ( );
			}

			if ( g_Vars.function.noflash )
			{
				Files::g_IniRead.NoFlash ( );
			}

			if ( g_Vars.function.screeninfo )
			{
				Files::g_IniRead.ScreenInfo ( );
			}
		}
		else
		{
			CreateFileVisuals ( );

			if ( g_Vars.function.menu )
			{
				Files::g_IniRead.Menu ( );
			}

			if ( g_Vars.function.esp )
			{
				Files::g_IniRead.ESP ( );
			}

			if ( g_Vars.function.noflash )
			{
				Files::g_IniRead.NoFlash ( );
			}

			if ( g_Vars.function.screeninfo )
			{
				Files::g_IniRead.ScreenInfo ( );
			}
		}

		if ( Files::g_File.FileExists ( Files::g_File.DirFile ( MISC_PATH ).c_str ( ) ) )
		{
			if ( g_Vars.function.bhop )
			{
				Files::g_IniRead.BHop ( );
			}

			if ( g_Vars.function.gstrafe )
			{
				Files::g_IniRead.GStrafe ( );
			}

			if ( g_Vars.function.speed )
			{
				Files::g_IniRead.Speed ( );
			}

			if ( g_Vars.function.jumpbug )
			{
				Files::g_IniRead.JumpBug ( );
			}

			if ( g_Vars.function.edgebug )
			{
				Files::g_IniRead.EdgeBug ( );
			}
		}
		else
		{
			CreateFileMisc ( );

			if ( g_Vars.function.bhop )
			{
				Files::g_IniRead.BHop ( );
			}

			if ( g_Vars.function.gstrafe )
			{
				Files::g_IniRead.GStrafe ( );
			}

			if ( g_Vars.function.speed )
			{
				Files::g_IniRead.Speed ( );
			}

			if ( g_Vars.function.jumpbug )
			{
				Files::g_IniRead.JumpBug ( );
			}

			if ( g_Vars.function.edgebug )
			{
				Files::g_IniRead.EdgeBug ( );
			}
		}

		if ( Files::g_File.FileExists ( Files::g_File.DirFile ( AUTORUN_PATH ).c_str ( ) ) )
		{
			RunScript ( "AutoRun.cfg" );
		}
		else
		{
			CreateFileAutoRun ( );

			RunScript ( "AutoRun.cfg" );
		}
	}

	void _fastcall Init::ReloadSettings ( )
	{
		if ( Files::g_File.FileExists ( Files::g_File.DirFile ( MAIN_PATH ).c_str ( ) ) )
		{
			Files::g_IniRead.Main ( );
		}
		else
		{
			CreateFileMain ( );

			Files::g_IniRead.Main ( );
		}

		if ( Files::g_File.FileExists ( Files::g_File.DirFile ( VISUALS_PATH ).c_str ( ) ) )
		{
			if ( g_Vars.function.menu )
			{
				Files::g_IniRead.Menu ( );
			}

			if ( g_Vars.function.esp )
			{
				Files::g_IniRead.ESP ( );
			}

			if ( g_Vars.function.noflash )
			{
				Files::g_IniRead.NoFlash ( );
			}

			if ( g_Vars.function.screeninfo )
			{
				Files::g_IniRead.ScreenInfo ( );
			}
		}
		else
		{
			CreateFileVisuals ( );

			if ( g_Vars.function.menu )
			{
				Files::g_IniRead.Menu ( );
			}

			if ( g_Vars.function.esp )
			{
				Files::g_IniRead.ESP ( );
			}

			if ( g_Vars.function.noflash )
			{
				Files::g_IniRead.NoFlash ( );
			}

			if ( g_Vars.function.screeninfo )
			{
				Files::g_IniRead.ScreenInfo ( );
			}
		}

		if ( Files::g_File.FileExists ( Files::g_File.DirFile ( MISC_PATH ).c_str ( ) ) )
		{
			if ( g_Vars.function.bhop )
			{
				Files::g_IniRead.BHop ( );
			}

			if ( g_Vars.function.gstrafe )
			{
				Files::g_IniRead.GStrafe ( );
			}

			if ( g_Vars.function.speed )
			{
				Files::g_IniRead.Speed ( );
			}

			if ( g_Vars.function.jumpbug )
			{
				Files::g_IniRead.JumpBug ( );
			}

			if ( g_Vars.function.edgebug )
			{
				Files::g_IniRead.EdgeBug ( );
			}
		}
		else
		{
			CreateFileMisc ( );

			if ( g_Vars.function.bhop )
			{
				Files::g_IniRead.BHop ( );
			}

			if ( g_Vars.function.gstrafe )
			{
				Files::g_IniRead.GStrafe ( );
			}

			if ( g_Vars.function.speed )
			{
				Files::g_IniRead.Speed ( );
			}

			if ( g_Vars.function.jumpbug )
			{
				Files::g_IniRead.JumpBug ( );
			}

			if ( g_Vars.function.edgebug )
			{
				Files::g_IniRead.EdgeBug ( );
			}
		}
	}

	void _fastcall Init::SaveSettings ( )
	{
		if ( Files::g_File.FileExists ( Files::g_File.DirFile ( MAIN_PATH ).c_str ( ) ) )
		{
			Files::g_IniWrite.Main ( );
		}
		else
		{
			CreateFileMain ( );

			Files::g_IniWrite.Main ( );
		}

		if ( Files::g_File.FileExists ( Files::g_File.DirFile ( VISUALS_PATH ).c_str ( ) ) )
		{
			if ( g_Vars.function.menu )
			{
				Files::g_IniWrite.Menu ( );
			}

			if ( g_Vars.function.esp )
			{
				Files::g_IniWrite.ESP ( );
			}

			if ( g_Vars.function.noflash )
			{
				Files::g_IniWrite.NoFlash ( );
			}

			if ( g_Vars.function.screeninfo )
			{
				Files::g_IniWrite.ScreenInfo ( );
			}
		}
		else
		{
			CreateFileVisuals ( );

			if ( g_Vars.function.menu )
			{
				Files::g_IniWrite.Menu ( );
			}

			if ( g_Vars.function.esp )
			{
				Files::g_IniWrite.ESP ( );
			}

			if ( g_Vars.function.noflash )
			{
				Files::g_IniWrite.NoFlash ( );
			}

			if ( g_Vars.function.screeninfo )
			{
				Files::g_IniWrite.ScreenInfo ( );
			}
		}

		if ( Files::g_File.FileExists ( Files::g_File.DirFile ( MISC_PATH ).c_str ( ) ) )
		{
			if ( g_Vars.function.bhop )
			{
				Files::g_IniWrite.BHop ( );
			}

			if ( g_Vars.function.gstrafe )
			{
				Files::g_IniWrite.GStrafe ( );
			}

			if ( g_Vars.function.speed )
			{
				Files::g_IniWrite.Speed ( );
			}

			if ( g_Vars.function.jumpbug )
			{
				Files::g_IniWrite.JumpBug ( );
			}

			if ( g_Vars.function.edgebug )
			{
				Files::g_IniWrite.EdgeBug ( );
			}
		}
		else
		{
			CreateFileMisc ( );

			if ( g_Vars.function.bhop )
			{
				Files::g_IniWrite.BHop ( );
			}

			if ( g_Vars.function.gstrafe )
			{
				Files::g_IniWrite.GStrafe ( );
			}

			if ( g_Vars.function.speed )
			{
				Files::g_IniWrite.Speed ( );
			}

			if ( g_Vars.function.jumpbug )
			{
				Files::g_IniWrite.JumpBug ( );
			}

			if ( g_Vars.function.edgebug )
			{
				Files::g_IniWrite.EdgeBug ( );
			}
		}
	}

	void Init::RunScript ( char *ScriptName )
	{
		char *o = new char[256];

		strcpy ( o, "" );
		strcat ( o, "Configs/" );
		strcat ( o, ScriptName );

		FILE *File = fopen ( Files::g_File.DirFile ( o ).c_str ( ), "r" );

		if ( File != 0 )
		{
			char Script[1024];

			while ( fgets ( Script, sizeof ( Script ), File ) != 0 )
			{
				g_Util.StrReplace ( Script, "%prefix%", g_Util.Prefix );
				Engine::g_Engine.pfnClientCmd ( Script );
			}

			fclose ( File );

			if ( !lstrcmpi ( o, "AutoRun.cfg" ) )
			{
				if ( g_Vars.main.language )
				{
					g_Util.ConsolePrintColor ( 100, 255, 200, HPP );
					g_Util.ConsolePrintColor ( 200, 255, 200, FILE_LOADED_ENG );
				}
				else
				{
					g_Util.ConsolePrintColor ( 100, 255, 200, HPP );
					g_Util.ConsolePrintColor ( 200, 255, 200, FILE_LOADED_RUS );
				}
			}
		}
		else
		{
			g_Util.ConsolePrintColor ( 100, 255, 200, HPP );
			g_Util.ConsolePrintColor ( 255, 80, 80, EXEC_CONFIG_ERROR );
			g_Util.ConsolePrintColor ( 255, 80, 80, o );
			g_Util.ConsolePrintColor ( 255, 80, 80, "\".\n" );
		}
	}

	void Init::CreateFileFunctions ( )
	{
		std::ofstream FileFunctions;

		char* FileSettingsPath = new char[256];

		lstrcpy ( FileSettingsPath, Engine::BaseDir );
		lstrcat ( FileSettingsPath, SETTINGS_DIR_PATH );

		CreateDirectory ( FileSettingsPath, 0 );

		char* FileFunctionsPath = new char[256];

		lstrcpy ( FileFunctionsPath, Engine::BaseDir );
		lstrcat ( FileFunctionsPath, FUNCTIONS_PATH );

		FileFunctions.open ( FileFunctionsPath, std::ios::app );

		FileFunctions << "[Functions]" << std::endl;
		FileFunctions << "|Menu = 1" << std::endl;
		FileFunctions << "|ESP = 1" << std::endl;
		FileFunctions << "|NoFlash = 1" << std::endl;
		FileFunctions << "|ScreenInfo = 1" << std::endl;
		FileFunctions << "|Speed = 1" << std::endl;
		FileFunctions << "|BunnyHop = 1" << std::endl;
		FileFunctions << "|GroundStrafe = 1" << std::endl;	
		FileFunctions << "|JumpBug = 1" << std::endl;
		FileFunctions << "|EdgeBug = 1" << std::endl << std::endl;
		FileFunctions << "|Commands = 0" << std::endl;
		FileFunctions << "|Commands.Prefix = hpp_" << std::endl;
		FileFunctions << "|Commands.Binds = 1";

		FileFunctions.close ( );
	}

	void Init::CreateFileMain ( )
	{
		std::ofstream FileMain;

		char* FileSettingsPath = new char[256];

		lstrcpy ( FileSettingsPath, Engine::BaseDir );
		lstrcat ( FileSettingsPath, SETTINGS_DIR_PATH );

		CreateDirectory ( FileSettingsPath, 0 );

		char* FileMainPath = new char[256];

		lstrcpy ( FileMainPath, Engine::BaseDir );
		lstrcat ( FileMainPath, MAIN_PATH );

		FileMain.open ( FileMainPath, std::ios::app );

		FileMain << "[Main]" << std::endl;
		FileMain << "|Language = english" << std::endl << std::endl;
		FileMain << "|ReloadSettings.Key = F5" << std::endl;
		FileMain << "|Panic.Key = F6" << std::endl << std::endl;
		FileMain << "|Player.Scan.Visibility = 2" << std::endl;
		FileMain << "|Player.Valid.Check = 1" << std::endl << std::endl;
		FileMain << "|Font.OutLine.Quality = 1";

		FileMain.close ( );
	}

	void Init::CreateFileVisuals ( )
	{
		std::ofstream FileVisuals;

		char* FileSettingsPath = new char[256];

		lstrcpy ( FileSettingsPath, Engine::BaseDir );
		lstrcat ( FileSettingsPath, SETTINGS_DIR_PATH );

		CreateDirectory ( FileSettingsPath, 0 );

		char* FileVisualsPath = new char[256];

		lstrcpy ( FileVisualsPath, Engine::BaseDir );
		lstrcat ( FileVisualsPath, VISUALS_PATH );

		FileVisuals.open ( FileVisualsPath, std::ios::app );

		FileVisuals << "[Menu]" << std::endl;
		FileVisuals << "|Menu.Pos.x = 200" << std::endl;
		FileVisuals << "|Menu.Pos.y = 138" << std::endl;
		FileVisuals << "|Menu.Box.Height = 22" << std::endl;
		FileVisuals << "|Menu.Box.Width = 200" << std::endl;
		FileVisuals << "|Menu.Box.Color = 20, 20, 20, 130" << std::endl;
		FileVisuals << "|Menu.Fill.Color = 20, 20, 20, 130" << std::endl;
		FileVisuals << "|Menu.Text.Color = 255, 255, 255, 255" << std::endl;
		FileVisuals << "|Menu.Select.Color = 0, 100, 255, 110" << std::endl;
		FileVisuals << "|Menu.Key = insert" << std::endl << std::endl;
		FileVisuals << "[ESP]" << std::endl;
		FileVisuals << "|ESP.Enable = 1" << std::endl;
		FileVisuals << "|ESP.Player = 2" << std::endl;
		FileVisuals << "|ESP.Player.VisibleCheck = 1" << std::endl;
		FileVisuals << "|ESP.Player.VisibleOnly = 0" << std::endl;
		FileVisuals << "|ESP.Player.IgnoreDeath = 1" << std::endl;
		FileVisuals << "|ESP.Player.Box = 1" << std::endl;
		FileVisuals << "|ESP.Player.Box.LineWidth = 1" << std::endl;
		FileVisuals << "|ESP.Player.Box.Size = 1.0" << std::endl;
		FileVisuals << "|ESP.Player.Box.T.Vis = 255, 255, 0" << std::endl;
		FileVisuals << "|ESP.Player.Box.T.Hide = 255, 0, 0" << std::endl;
		FileVisuals << "|ESP.Player.Box.CT.Vis = 0, 255, 255" << std::endl;
		FileVisuals << "|ESP.Player.Box.CT.Hide = 0, 0, 255" << std::endl;
		FileVisuals << "|ESP.Player.Name = 0" << std::endl;
		FileVisuals << "|ESP.Player.Weapon = 0" << std::endl;
		FileVisuals << "|ESP.Player.Distance = 0" << std::endl;
		FileVisuals << "|ESP.Player.Barrel = 0" << std::endl;
		FileVisuals << "|ESP.World = 1" << std::endl;
		FileVisuals << "|ESP.World.Weapons = 0" << std::endl;
		FileVisuals << "|ESP.World.Nades = 0" << std::endl;
		FileVisuals << "|ESP.C4Timer = 2" << std::endl;
		FileVisuals << "|ESP.C4Timer.Value = 35" << std::endl;
		FileVisuals << "|ESP.Sound = 0" << std::endl;
		FileVisuals << "|ESP.Sound.LineWidth = 1" << std::endl;
		FileVisuals << "|ESP.Sound.FadeTime = 1000" << std::endl;
		FileVisuals << "|ESP.Sound.Color = 255, 255, 255" << std::endl;
		FileVisuals << "|ESP.Font.OutLine = 1" << std::endl;
		FileVisuals << "|ESP.Font.Color = 255, 255, 255" << std::endl;
		FileVisuals << "|ESP.Panic.Key = F7" << std::endl << std::endl;
		FileVisuals << "[NoFlash]" << std::endl;
		FileVisuals << "|NoFlash.Enable = 1" << std::endl;
		FileVisuals << "|NoFlash.Fade.Limit = 100" << std::endl;
		FileVisuals << "|NoFlash.Fade.Color = 255, 255, 255" << std::endl;
		FileVisuals << "|NoFlash.Fade.Color.Random = 0" << std::endl;
		FileVisuals << "|NoFlash.ShowPercentage = 1" << std::endl << std::endl;
		FileVisuals << "[ScreenInfo]" << std::endl;
		FileVisuals << "|ScreenInfo.Enable = 1" << std::endl;
		FileVisuals << "|ScreenInfo.FPS = 1" << std::endl;
		FileVisuals << "|ScreenInfo.CopyRight = 1" << std::endl;
		FileVisuals << "|ScreenInfo.Time = 1" << std::endl;
		FileVisuals << "|ScreenInfo.ShowKeys = 0" << std::endl;
		FileVisuals << "|ScreenInfo.Kreedz = 0" << std::endl;
		FileVisuals << "|ScreenInfo.Font.Color = 0, 0, 255" << std::endl;
		FileVisuals << "|ScreenInfo.Font.OutLine = 0" << std::endl;
		FileVisuals << "|ScreenInfo.Debug = 0";

		FileVisuals.close ( );
	}

	void Init::CreateFileMisc ( )
	{
		std::ofstream FileMisc;

		char* FileSettingsPath = new char[256];

		lstrcpy ( FileSettingsPath, Engine::BaseDir );
		lstrcat ( FileSettingsPath, SETTINGS_DIR_PATH );

		CreateDirectory ( FileSettingsPath, 0 );

		char* FileMiscPath = new char[256];

		lstrcpy ( FileMiscPath, Engine::BaseDir );
		lstrcat ( FileMiscPath, MISC_PATH );

		FileMisc.open ( FileMiscPath, std::ios::app );

		FileMisc << "[Speed]" << std::endl;
		FileMisc << "|Speed = 1" << std::endl;
		FileMisc << "|Speed.Engine = 0" << std::endl;
		FileMisc << "|Speed.Type = 1" << std::endl;
		FileMisc << "|Speed.Boost = 30" << std::endl;
		FileMisc << "|Speed.Boost.Key = none" << std::endl;
		FileMisc << "|Speed.SlowMotion = 0.3" << std::endl;
		FileMisc << "|Speed.SlowMotion.Key = none" << std::endl << std::endl;
		FileMisc << "[BunnyHop]" << std::endl;
		FileMisc << "|BunnyHop.MouseWheel.Emulation = 0" << std::endl;
		FileMisc << "|BunnyHop.MouseWheel.Direction = up" << std::endl;
		FileMisc << "|BunnyHop.Distance.Type = 1" << std::endl;
		FileMisc << "|BunnyHop.Distance = 6, 12" << std::endl;		
		FileMisc << "|BunnyHop.NoSlowDown = 1" << std::endl;
		FileMisc << "|BunnyHop.InWater = 1" << std::endl;
		FileMisc << "|BunnyHop.OnLadder = 1" << std::endl;
		FileMisc << "|BunnyHop.StandUp = 0" << std::endl;
		FileMisc << "|BunnyHop.StandUp.FallVelocity = 200.0" << std::endl;
		FileMisc << "|BunnyHop.StandUp.GroundAngle = 28.0" << std::endl;
		FileMisc << "|BunnyHop.StandUp.Key = none" << std::endl;
		FileMisc << "|BunnyHop.Key = space" << std::endl << std::endl;
		FileMisc << "[GroundStrafe]" << std::endl;
		FileMisc << "|GroundStrafe.MouseWheel.Emulation = 0" << std::endl;
		FileMisc << "|GroundStrafe.MouseWheel.Direction = down" << std::endl;
		FileMisc << "|GroundStrafe.Distance.Type = 1" << std::endl;
		FileMisc << "|GroundStrafe.Distance = 2, 4" << std::endl;
		FileMisc << "|GroundStrafe.Count = 1, 2" << std::endl;
		FileMisc << "|GroundStrafe.FallRun = 0" << std::endl;
		FileMisc << "|GroundStrafe.SlowDown.Scale = 1.0" << std::endl;
		FileMisc << "|GroundStrafe.SlowDown.GroundAngle = 5.0" << std::endl;
		FileMisc << "|GroundStrafe.StandUp.FallVelocity = 100.0" << std::endl;
		FileMisc << "|GroundStrafe.StandUp.Key = none" << std::endl;
		FileMisc << "|GroundStrafe.Key = alt" << std::endl << std::endl;	
		FileMisc << "[JumpBug]" << std::endl;
		FileMisc << "|JumpBug.Auto = 0" << std::endl;
		FileMisc << "|JumpBug.Auto.Damage = 1" << std::endl;
		FileMisc << "|JumpBug.Auto.Percentage = 100" << std::endl;
		FileMisc << "|JumpBug.SlowDown = 0" << std::endl;
		FileMisc << "|JumpBug.SlowDown.Distance = 100" << std::endl;
		FileMisc << "|JumpBug.SlowMotion = 1" << std::endl;	
		FileMisc << "|JumpBug.Key = none" << std::endl << std::endl;
		FileMisc << "[EdgeBug]" << std::endl;
		FileMisc << "|EdgeBug.Auto = 0" << std::endl;
		FileMisc << "|EdgeBug.Auto.Damage = 1" << std::endl;
		FileMisc << "|EdgeBug.Speed = 40" << std::endl;
		FileMisc << "|EdgeBug.Distance = 50" << std::endl;
		FileMisc << "|EdgeBug.Distance.Auto = 0" << std::endl;
		FileMisc << "|EdgeBug.Key = none";

		FileMisc.close ( );
	}

	void Init::CreateFileAutoRun ( )
	{
		std::ofstream FileAutoRun;

		char* FileConfigsPath = new char[256];

		lstrcpy ( FileConfigsPath, Engine::BaseDir );
		lstrcat ( FileConfigsPath, CONFIGS_DIR_PATH );

		CreateDirectory ( FileConfigsPath, 0 );

		char* FileAutoRunPath = new char[256];

		lstrcpy ( FileAutoRunPath, Engine::BaseDir );
		lstrcat ( FileAutoRunPath, AUTORUN_PATH );

		FileAutoRun.open ( FileAutoRunPath, std::ios::app );

		FileAutoRun << "unbind \"rightarrow\"" << std::endl;
		FileAutoRun << "unbind \"leftarrow\"" << std::endl;
		FileAutoRun << "unbind \"uparrow\"" << std::endl;
		FileAutoRun << "unbind \"downarrow\"" << std::endl;
		FileAutoRun << "unbind \"ins\"" << std::endl;
		FileAutoRun << "echo \"AutoRun.cfg loaded\"";

		FileAutoRun.close ( );
	}

	Init g_Init;
}