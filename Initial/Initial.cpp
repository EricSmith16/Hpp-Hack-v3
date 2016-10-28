#include "Initial.h"

namespace Initial
{
	bool Init::PanicEnabled = false;

	void Init::InitHack ( )
	{
		LoadSettings ( );

		Engine::g_Engine.pfnClientCmd ( "toggleconsole" );

		if ( Files::g_IniRead.main.language )
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
			g_Util.ConsolePrintColor ( 0, 0, 0, "\n" );
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
			g_Util.ConsolePrintColor ( 0, 0, 0, "\n" );
		}

		if ( !Files::g_File.FileExists ( Files::g_File.DirFile ( FUNCTIONS_PATH ).c_str ( ) ) )
		{
			g_Util.ConsolePrintColor ( 0, 0, 0, "\n" );
			g_Util.ConsolePrintColor ( 100, 255, 200, HPP );
			g_Util.ConsolePrintColor ( 255, 120, 120, FE_FUNCTIONS_ERROR );
		}

		if ( !Files::g_File.FileExists ( Files::g_File.DirFile ( MAIN_PATH ).c_str ( ) ) )
		{
			g_Util.ConsolePrintColor ( 0, 0, 0, "\n" );
			g_Util.ConsolePrintColor ( 100, 255, 200, HPP );
			g_Util.ConsolePrintColor ( 255, 120, 120, FE_MAIN_ERROR );
		}

		if ( !Files::g_File.FileExists ( Files::g_File.DirFile ( VISUALS_PATH ).c_str ( ) ) )
		{
			g_Util.ConsolePrintColor ( 0, 0, 0, "\n" );
			g_Util.ConsolePrintColor ( 100, 255, 200, HPP );
			g_Util.ConsolePrintColor ( 255, 120, 120, FE_VISUALS_ERROR );
		}
	}

	void Init::LoadSettings ( )
	{
		Renderer::g_Font.InitText ( LUCIDA_CONSOLE, 12, 9 );

		Renderer::g_Verdana.InitText ( VERDANA, 13, 6 );

		if ( Files::g_File.FileExists ( Files::g_File.DirFile ( FUNCTIONS_PATH ).c_str ( ) ) )
		{
			Files::g_IniRead.Functions ( );
		}
		else
		{
			Files::g_IniRead.function.esp = true;
			Files::g_IniRead.function.noflash = true;
		}

		if ( Files::g_File.FileExists ( Files::g_File.DirFile ( MAIN_PATH ).c_str ( ) ) )
		{
			Files::g_IniRead.Main ( );
		}
		else
		{
			Files::g_IniRead.main.language = 1;
		}

		if ( Files::g_File.FileExists ( Files::g_File.DirFile ( VISUALS_PATH ).c_str ( ) ) )
		{
			if ( Files::g_IniRead.function.esp )
			{
				Files::g_IniRead.ESP ( );
			}

			if ( Files::g_IniRead.function.noflash )
			{
				Files::g_IniRead.NoFlash ( );
			}
		}
	}

	void Init::ReloadSettings ( )
	{
		if ( Files::g_File.FileExists ( Files::g_File.DirFile ( MAIN_PATH ).c_str ( ) ) )
		{
			if ( Files::g_IniRead.function.esp )
			{
				Files::g_IniRead.ESP ( );
			}

			if ( Files::g_IniRead.function.noflash )
			{
				Files::g_IniRead.NoFlash ( );
			}
		}

		if ( Files::g_File.FileExists ( Files::g_File.DirFile ( VISUALS_PATH ).c_str ( ) ) )
		{
			Files::g_IniRead.Main ( );
		}
	}

	void Init::Panic ( bool enabled )
	{
		if ( enabled )
		{
			if ( Files::g_IniRead.function.esp )
			{
				Files::g_IniRead.esp.enable = 0;
				Files::g_IniRead.esp.panic_key = 0;

				Functions::g_ESP.PanicEnabled = false;
			}

			if ( Files::g_IniRead.function.noflash )
			{
				Files::g_IniRead.noflash.enable = false;
			}
		}
		else
		{
			ReloadSettings ( );
		}
	}

	void Init::ReloadKey ( int keynum )
	{
		if ( keynum == Files::g_IniRead.main.reload_key )
		{
			ReloadSettings ( );

			PanicEnabled = false;

			Functions::g_ESP.PanicEnabled = false;

			if ( Files::g_IniRead.main.language )
			{
				g_Util.ConsolePrintColor ( 100, 255, 200, HPP );
				g_Util.ConsolePrintColor ( 200, 255, 200, SETTINGS_RELOADED_ENG );
			}
			else
			{
				g_Util.ConsolePrintColor ( 100, 255, 200, HPP );
				g_Util.ConsolePrintColor ( 200, 255, 200, SETTINGS_RELOADED_RUS );
			}

			Engine::g_Engine.pfnPlaySoundByName ( "vox/ok.wav", 1 );
		}
	}

	void Init::PanicKey ( int keynum )
	{
		if ( keynum == Files::g_IniRead.main.panic_key )
		{
			PanicEnabled = !PanicEnabled;

			Panic ( PanicEnabled );

			Engine::g_Engine.pfnPlaySoundByName ( PanicEnabled ? "vox/of.wav" : "vox/on.wav", 1 );
		}
	}

	Init g_Init;
}