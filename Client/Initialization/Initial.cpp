#include "Initial.h"

namespace Initial
{
	void Init::FilesCheck ( )
	{
		if ( !Files::g_File.FileExists ( Files::g_File.DirFile ( FUNCTIONS_PATH ).c_str ( ) ) )
		{
			CreateFileFunctions ( );
		}

		if ( !Files::g_File.FileExists ( Files::g_File.DirFile ( MAIN_PATH ).c_str ( ) ) )
		{
			CreateFileMain ( );
		}

		if ( !Files::g_File.FileExists ( Files::g_File.DirFile ( VISUALS_PATH ).c_str ( ) ) )
		{
			CreateFileVisuals ( );
		}

		if ( !Files::g_File.FileExists ( Files::g_File.DirFile ( MISC_PATH ).c_str ( ) ) )
		{
			CreateFileMisc ( );
		}

		if ( !Files::g_File.FileExists ( Files::g_File.DirFile ( AUTORUN_PATH ).c_str ( ) ) )
		{
			CreateFileAutoRun ( );
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
		FileFunctions << "|Camera = 1" << std::endl;
		FileFunctions << "|Speed = 1" << std::endl;
		FileFunctions << "|BunnyHop = 1" << std::endl;
		FileFunctions << "|GroundStrafe = 1" << std::endl;
		FileFunctions << "|JumpBug = 1" << std::endl;
		FileFunctions << "|EdgeBug = 1" << std::endl;
		FileFunctions << "|StrafeHelper = 1" << std::endl << std::endl;
		FileFunctions << "|Console.Commands = 1" << std::endl;
		FileFunctions << "|Console.Commands.Prefix = hpp^" << std::endl;
		FileFunctions << "|Console.Binds = 1";

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
		FileMain << "|Reload.Key = F5" << std::endl;
		FileMain << "|Panic.Key = F6" << std::endl << std::endl;
		FileMain << "|Player.VisibleScan = 1" << std::endl;
		FileMain << "|Player.ValidCheck = 1" << std::endl << std::endl;
		FileMain << "|Font.OutLine.Quality = 1" << std::endl << std::endl;
		FileMain << "|AntiScreen.Enable = 1" << std::endl;
		FileMain << "|AntiScreen.Timer = 6" << std::endl;;
		FileMain << "|AntiScreen.Steam.Key = F12";

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
		FileVisuals << "|Menu.Box.Height = 20" << std::endl;
		FileVisuals << "|Menu.Box.Width = 190" << std::endl;
		FileVisuals << "|Menu.Box.Color = 20, 20, 20, 40" << std::endl;
		FileVisuals << "|Menu.BoxFill.Color = 20, 20, 50, 130" << std::endl;
		FileVisuals << "|Menu.BoxSelect.Color = 0, 0, 255, 100" << std::endl;
		FileVisuals << "|Menu.Text.Color = 255, 255, 255, 255" << std::endl;
		FileVisuals << "|Menu.Key = insert" << std::endl << std::endl;
		FileVisuals << "[ESP]" << std::endl;
		FileVisuals << "|ESP.Enable = 1" << std::endl;
		FileVisuals << "|ESP.Player = 2" << std::endl;
		FileVisuals << "|ESP.Player.VisibleOnly = 0" << std::endl;
		FileVisuals << "|ESP.Player.Box = 1" << std::endl;
		FileVisuals << "|ESP.Player.Box.LineWidth = 1" << std::endl;
		FileVisuals << "|ESP.Player.Box.T.Vis = 255, 255, 0" << std::endl;
		FileVisuals << "|ESP.Player.Box.T.Hide = 255, 0, 0" << std::endl;
		FileVisuals << "|ESP.Player.Box.CT.Vis = 0, 255, 255" << std::endl;
		FileVisuals << "|ESP.Player.Box.CT.Hide = 0, 0, 255" << std::endl;
		FileVisuals << "|ESP.Player.Name = 1" << std::endl;
		FileVisuals << "|ESP.Player.Weapon = 1" << std::endl;
		FileVisuals << "|ESP.Player.Distance = 0" << std::endl;
		FileVisuals << "|ESP.Player.Barrel = 0" << std::endl;
		FileVisuals << "|ESP.World.Items = 1" << std::endl;
		FileVisuals << "|ESP.World.Nades = 1" << std::endl;
		FileVisuals << "|ESP.C4Timer = 2" << std::endl;
		FileVisuals << "|ESP.C4Timer.Value = 35" << std::endl;
		FileVisuals << "|ESP.Sound = 1" << std::endl;
		FileVisuals << "|ESP.Sound.LineWidth = 1" << std::endl;
		FileVisuals << "|ESP.Sound.FadeTime = 1000" << std::endl;
		FileVisuals << "|ESP.Sound.Color = 255, 255, 255" << std::endl;
		FileVisuals << "|ESP.Font.OutLine = 1" << std::endl;
		FileVisuals << "|ESP.Font.Color = 255, 255, 255" << std::endl;
		FileVisuals << "|ESP.Panic.Key = F7" << std::endl << std::endl;
		FileVisuals << "[NoFlash]" << std::endl;
		FileVisuals << "|NoFlash.Enable = 1" << std::endl;
		FileVisuals << "|NoFlash.Fade.Limit = 60" << std::endl;
		FileVisuals << "|NoFlash.Fade.Color = 255, 255, 255" << std::endl;
		FileVisuals << "|NoFlash.Fade.Color.Random = 1" << std::endl;
		FileVisuals << "|NoFlash.ShowPercentage = 1" << std::endl;
		FileVisuals << "|NoFlash.Font.OutLine = 0" << std::endl << std::endl;
		FileVisuals << "[ScreenInfo]" << std::endl;
		FileVisuals << "|ScreenInfo.Enable = 1" << std::endl;
		FileVisuals << "|ScreenInfo.FPS = 1" << std::endl;
		FileVisuals << "|ScreenInfo.CopyRight = 1" << std::endl;
		FileVisuals << "|ScreenInfo.Time = 1" << std::endl;
		FileVisuals << "|ScreenInfo.ShowKeys = 0" << std::endl;
		FileVisuals << "|ScreenInfo.Kreedz = 1" << std::endl;
		FileVisuals << "|ScreenInfo.Font.Color = 0, 0, 255" << std::endl;
		FileVisuals << "|ScreenInfo.Font.OutLine = 0" << std::endl << std::endl;
		FileVisuals << "[Camera]" << std::endl;
		FileVisuals << "|ThirdPerson.Enable = 0" << std::endl;
		FileVisuals << "|ThirdPerson.Side = 0" << std::endl;
		FileVisuals << "|ThirdPerson.Up = 15" << std::endl;
		FileVisuals << "|ThirdPerson.Back = 150" << std::endl;
		FileVisuals << "|ThirdPerson.SwitchKey = none" << std::endl << std::endl;
		FileVisuals << "|FreeLook.Enable = 0" << std::endl;
		FileVisuals << "|FreeLook.Speed = 500" << std::endl;
		FileVisuals << "|FreeLook.SwitchKey = none" << std::endl << std::endl;
		FileVisuals << "|Spectator.Enable = 0" << std::endl;
		FileVisuals << "|Spectator.ID = 0" << std::endl;
		FileVisuals << "|Spectator.SwitchKey = none";

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
		FileMisc << "|BunnyHop.Scroll.Emulation = 1" << std::endl;
		FileMisc << "|BunnyHop.Scroll.Direction = up" << std::endl;
		FileMisc << "|BunnyHop.Distance = 0, 10" << std::endl;
		FileMisc << "|BunnyHop.NoSlowDown = 1" << std::endl;
		FileMisc << "|BunnyHop.OnLadder = 1" << std::endl;
		FileMisc << "|BunnyHop.StandUp.Auto = 0" << std::endl;
		FileMisc << "|BunnyHop.StandUp.FallVelocity = 200.0" << std::endl;
		FileMisc << "|BunnyHop.StandUp.Key = none" << std::endl;
		FileMisc << "|BunnyHop.Key = none" << std::endl << std::endl;
		FileMisc << "[GroundStrafe]" << std::endl;
		FileMisc << "|GroundStrafe.Scroll.Emulation = 0" << std::endl;
		FileMisc << "|GroundStrafe.Scroll.Direction = down" << std::endl;
		FileMisc << "|GroundStrafe.Distance = 0, 5" << std::endl;
		FileMisc << "|GroundStrafe.Count = 1, 3" << std::endl;
		FileMisc << "|GroundStrafe.FallRun = 1" << std::endl;
		FileMisc << "|GroundStrafe.SlowDown.Scale = 1.0" << std::endl;
		FileMisc << "|GroundStrafe.StandUp.FallVelocity = 80.0" << std::endl;
		FileMisc << "|GroundStrafe.StandUp.Key = none" << std::endl;
		FileMisc << "|GroundStrafe.Key = none" << std::endl << std::endl;
		FileMisc << "[JumpBug]" << std::endl;
		FileMisc << "|JumpBug.Auto = 0" << std::endl;
		FileMisc << "|JumpBug.Auto.Damage = 1" << std::endl;
		FileMisc << "|JumpBug.Auto.Percentage = 100" << std::endl;
		FileMisc << "|JumpBug.SlowDown = 0" << std::endl;
		FileMisc << "|JumpBug.SlowMotion = 1" << std::endl;
		FileMisc << "|JumpBug.Key = none" << std::endl << std::endl;
		FileMisc << "[EdgeBug]" << std::endl;
		FileMisc << "|EdgeBug.Auto = 1" << std::endl;
		FileMisc << "|EdgeBug.Auto.Damage = 20" << std::endl;
		FileMisc << "|EdgeBug.Speed = 75" << std::endl;
		FileMisc << "|EdgeBug.Speed.Final = -2" << std::endl;
		FileMisc << "|EdgeBug.Speed.Offset = -1" << std::endl;
		FileMisc << "|EdgeBug.Key = none" << std::endl << std::endl;
		FileMisc << "[StrafeHelper]" << std::endl;
		FileMisc << "|StrafeHelper.Active = 0" << std::endl;
		FileMisc << "|StrafeHelper.Mode = 5" << std::endl;
		FileMisc << "|StrafeHelper.Type = 2" << std::endl;
		FileMisc << "|StrafeHelper.Correct.Speed = 0.0" << std::endl;
		FileMisc << "|StrafeHelper.Correct.Limit = 0.0" << std::endl;
		FileMisc << "|StrafeHelper.Correct.Limit.Smooth = 0.0" << std::endl;
		FileMisc << "|StrafeHelper.KeyEmulation = 0" << std::endl;
		FileMisc << "|StrafeHelper.Boost = 0.0" << std::endl;
		FileMisc << "|StrafeHelper.MinimalSpeed = 0" << std::endl;
		FileMisc << "|StrafeHelper.Direction = 1" << std::endl;
		FileMisc << "|StrafeHelper.Direction.Auto = 1" << std::endl;
		FileMisc << "|StrafeHelper.StrafeLimit = 0" << std::endl;
		FileMisc << "|StrafeHelper.SwitchKey = none" << std::endl;
		FileMisc << "|StrafeHelper.Key = none";

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
		FileAutoRun << "unbind \"enter\"" << std::endl;
		FileAutoRun << "echo \"AutoRun.cfg loaded\"";

		FileAutoRun.close ( );
	}

	void Init::LoadFileFunctions ( )
	{
		if ( Files::g_File.FileExists ( Files::g_File.DirFile ( FUNCTIONS_PATH ).c_str ( ) ) )
		{
			Files::g_IniRead.Functions ( );
		}
	}

	void Init::LoadFileMain ( )
	{
		if ( Files::g_File.FileExists ( Files::g_File.DirFile ( MAIN_PATH ).c_str ( ) ) )
		{
			Files::g_IniRead.Main ( );
		}
	}

	void Init::LoadFileVisuals ( )
	{
		if ( Files::g_File.FileExists ( Files::g_File.DirFile ( VISUALS_PATH ).c_str ( ) ) )
		{
			if ( g_Vars.Function.Menu )
			{
				Files::g_IniRead.Menu ( );
			}

			if ( g_Vars.Function.ESP )
			{
				Files::g_IniRead.ESP ( );
			}

			if ( g_Vars.Function.NoFlash )
			{
				Files::g_IniRead.NoFlash ( );
			}

			if ( g_Vars.Function.ScreenInfo )
			{
				Files::g_IniRead.ScreenInfo ( );
			}

			if ( g_Vars.Function.Camera )
			{
				Files::g_IniRead.Camera ( );
			}
		}
	}

	void Init::LoadFileMisc ( )
	{
		if ( Files::g_File.FileExists ( Files::g_File.DirFile ( MISC_PATH ).c_str ( ) ) )
		{
			if ( g_Vars.Function.BunnyHop )
			{
				Files::g_IniRead.BunnyHop ( );
			}

			if ( g_Vars.Function.GroundStrafe )
			{
				Files::g_IniRead.GStrafe ( );
			}

			if ( g_Vars.Function.Speed )
			{
				Files::g_IniRead.Speed ( );
			}

			if ( g_Vars.Function.JumpBug )
			{
				Files::g_IniRead.JumpBug ( );
			}

			if ( g_Vars.Function.EdgeBug )
			{
				Files::g_IniRead.EdgeBug ( );
			}

			if ( g_Vars.Function.StrafeHelper )
			{
				Files::g_IniRead.StrafeHelper ( );
			}
		}
	}

	void Init::LoadFileAutoRun ( )
	{
		if ( Files::g_File.FileExists ( Files::g_File.DirFile ( AUTORUN_PATH ).c_str ( ) ) )
		{
			g_Util.RunScript ( "AutoRun.cfg" );
		}
	}

	void Init::SaveFileMain ( )
	{
		if ( Files::g_File.FileExists ( Files::g_File.DirFile ( MAIN_PATH ).c_str ( ) ) )
		{
			Files::g_IniWrite.Main ( );
		}
	}

	void Init::SaveFileVisuals ( )
	{
		if ( Files::g_File.FileExists ( Files::g_File.DirFile ( VISUALS_PATH ).c_str ( ) ) )
		{
			if ( g_Vars.Function.Menu )
			{
				Files::g_IniWrite.Menu ( );
			}

			if ( g_Vars.Function.ESP )
			{
				Files::g_IniWrite.ESP ( );
			}

			if ( g_Vars.Function.NoFlash )
			{
				Files::g_IniWrite.NoFlash ( );
			}

			if ( g_Vars.Function.ScreenInfo )
			{
				Files::g_IniWrite.ScreenInfo ( );
			}

			if ( g_Vars.Function.Camera )
			{
				Files::g_IniWrite.Camera ( );
			}
		}
	}

	void Init::SaveFileMisc ( )
	{
		if ( Files::g_File.FileExists ( Files::g_File.DirFile ( MISC_PATH ).c_str ( ) ) )
		{
			if ( g_Vars.Function.BunnyHop )
			{
				Files::g_IniWrite.BunnyHop ( );
			}

			if ( g_Vars.Function.GroundStrafe )
			{
				Files::g_IniWrite.GStrafe ( );
			}

			if ( g_Vars.Function.Speed )
			{
				Files::g_IniWrite.Speed ( );
			}

			if ( g_Vars.Function.JumpBug )
			{
				Files::g_IniWrite.JumpBug ( );
			}

			if ( g_Vars.Function.EdgeBug )
			{
				Files::g_IniWrite.EdgeBug ( );
			}

			if ( g_Vars.Function.StrafeHelper )
			{
				Files::g_IniWrite.StrafeHelper ( );
			}
		}
	}

	void _fastcall Init::InitHack ( )
	{
		LoadSettings ( );

		//Engine::g_Engine.pfnRegisterVariable ( "gl_texture_1d", "1", 0 );

		Engine::g_Engine.pfnClientCmd ( "toggleconsole" );

		g_Util.ConsolePrintColor ( 80, 255, 80, g_Vars.Main.Launguage ? "Hpp Hack successfully injected!\n\n" : "Hpp Hack успешно загружен!\n\n" );
		g_Util.ConsolePrintColor ( 255, 240, 0, g_Vars.Main.Launguage ? "Information about game:\n" : "Информация о игре:\n" );
		g_Util.ConsolePrintColor ( 0, 230, 230, g_Vars.Main.Launguage ? "\t\tName: " : "\t\tНазвание:: " );
		g_Util.ConsolePrintColor ( 255, 200, 0, Client::BuildInfo.GameName );
		g_Util.ConsolePrintColor ( 0, 230, 230, g_Vars.Main.Launguage ? "\n\t\tVersion: " : "\n\t\tВерсия: " );
		g_Util.ConsolePrintColor ( 255, 200, 0, Client::BuildInfo.GameVersion );
		g_Util.ConsolePrintColor ( 0, 230, 230, g_Vars.Main.Launguage ? "\n\t\tProtocol: " : "\n\t\tПротокол: " );
		g_Util.ConsolePrintColor ( 255, 200, 0, Client::BuildInfo.Protocol );
		g_Util.ConsolePrintColor ( 0, 230, 230, g_Vars.Main.Launguage ? "\n\t\tBuild: " : "\n\t\tПостроение: " );
		g_Util.ConsolePrintColor ( 255, 200, 0, Client::BuildInfo.Build );
		g_Util.ConsolePrintColor ( 0, 230, 230, g_Vars.Main.Launguage ? "\n\t\tRender: " : "\n\t\tРендер: " );
		g_Util.ConsolePrintColor ( 255, 200, 0, g_Util.ConvertTypeToRenderString ( Engine::g_Offset.HLType ) );
		g_Util.ConsolePrintColor ( 255, 240, 0, g_Vars.Main.Launguage ? "\n\nInformation about cheat:\n" : "\n\nИнформация о чите:\n" );
		g_Util.ConsolePrintColor ( 0, 230, 230, g_Vars.Main.Launguage ? "\t\tVersion: " : "\t\tВерсия: " );
		g_Util.ConsolePrintColor ( 255, 200, 0, VERSION );
		g_Util.ConsolePrintColor ( 0, 230, 230, g_Vars.Main.Launguage ? "\t\tAuthor: " : "\t\tАвтор�: " );
		g_Util.ConsolePrintColor ( 255, 200, 0, AUTHOR );
		g_Util.ConsolePrintColor ( 0, 230, 230, g_Vars.Main.Launguage ? "\t\tPath: " : "\t\tПуть: " );
		g_Util.ConsolePrintColor ( 255, 200, 0, Engine::BaseDir );
		g_Util.ConsolePrintColor ( 0, 0, 0, "\n\n" );
	}

	void _fastcall Init::LoadSettings ( )
	{
		Renderer::g_Font.InitText ( LUCIDA_CONSOLE, 12, 8 );
		Renderer::g_Verdana.InitText ( VERDANA, 13, 0 );

		FilesCheck ( );

		LoadFileFunctions ( );
		LoadFileMain ( );
		LoadFileVisuals ( );
		LoadFileMisc ( );
		LoadFileAutoRun ( );
	}

	void _fastcall Init::SaveSettings ( )
	{
		FilesCheck ( );

		SaveFileMain ( );
		SaveFileVisuals ( );
		SaveFileMisc ( );
	}

	void _fastcall Init::ReloadSettings ( )
	{
		FilesCheck ( );

		LoadFileMain ( );
		LoadFileVisuals ( );
		LoadFileMisc ( );
	}

	Init g_Init;
}