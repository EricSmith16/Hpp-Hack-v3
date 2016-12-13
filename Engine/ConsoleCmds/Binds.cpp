#include "ConsoleCmds.h"

namespace Engine
{
	enum FUNC_NAME
	{
		PANIC, RELOAD_SETTINGS, BUNNYHOP, BUNNYHOP_STANDUP, GROUNDSTRAFE,
		GROUNDSTRAFE_STANDUP, SPEEDBOOST, SPEEDSLOWMO, JB, EB
	};

	int Command::Function ( char *Command )
	{
		PARSE_CMD ( "panic", PANIC );
		PARSE_CMD ( "reload_settings", RELOAD_SETTINGS );
		PARSE_CMD ( "bunnyhop", BUNNYHOP );
		PARSE_CMD ( "bunnyhop_standup", BUNNYHOP_STANDUP );
		PARSE_CMD ( "groundstrafe", GROUNDSTRAFE );
		PARSE_CMD ( "groundstrafe_standup", GROUNDSTRAFE_STANDUP );
		PARSE_CMD ( "speed_boost", SPEEDBOOST );
		PARSE_CMD ( "speed_slowmo", SPEEDSLOWMO );
		PARSE_CMD ( "jumpbug", JB );
		PARSE_CMD ( "edgebug", EB );

		return 0;
	}

	void Command::Bind ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			g_Util.ConsolePrintColor ( 100, 255, 200, HPP );
			g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.Prefix );
			g_Util.ConsolePrintColor ( 200, 255, 200, BIND_ATTACH_CMD );
		}
		else if ( g_Engine.Cmd_Argc ( ) < 3 )
		{
			g_Util.ConsolePrintColor ( 100, 255, 200, HPP );
			g_Util.ConsolePrintColor ( 200, 255, 200, "\"" );
			g_Util.ConsolePrintColor ( 200, 255, 200, g_Engine.Cmd_Argv ( 1 ) );
			g_Util.ConsolePrintColor ( 200, 255, 200, "\"" );

			if ( g_Vars.main.panic_key == Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) ) )
			{
				g_Util.ConsolePrintColor ( 200, 255, 200, " = \"" );
				g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.PrefHack ( "+", g_Util.Prefix, "panic" ) );
				g_Util.ConsolePrintColor ( 200, 255, 200, "\"\n" );
			}
			else if ( g_Vars.main.reload_key == Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) ) )
			{
				g_Util.ConsolePrintColor ( 200, 255, 200, " = \"" );
				g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.PrefHack ( "+", g_Util.Prefix, "reload_settings" ) );
				g_Util.ConsolePrintColor ( 200, 255, 200, "\"\n" );
			}
			else if ( g_Vars.bhop.key == Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) ) )
			{
				g_Util.ConsolePrintColor ( 200, 255, 200, " = \"" );
				g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.PrefHack ( "+", g_Util.Prefix, "bunnyhop" ) );
				g_Util.ConsolePrintColor ( 200, 255, 200, "\"\n" );
			}
			else if ( g_Vars.bhop.standup_key == Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) ) )
			{
				g_Util.ConsolePrintColor ( 200, 255, 200, " = \"" );
				g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.PrefHack ( "+", g_Util.Prefix, "bunnyhop_standup" ) );
				g_Util.ConsolePrintColor ( 200, 255, 200, "\"\n" );
			}
			else if ( g_Vars.gstrafe.key == Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) ) )
			{
				g_Util.ConsolePrintColor ( 200, 255, 200, " = \"" );
				g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.PrefHack ( "+", g_Util.Prefix, "groundstrafe" ) );
				g_Util.ConsolePrintColor ( 200, 255, 200, "\"\n" );
			}
			else if ( g_Vars.gstrafe.standup_key == Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) ) )
			{
				g_Util.ConsolePrintColor ( 200, 255, 200, " = \"" );
				g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.PrefHack ( "+", g_Util.Prefix, "groundstrafe_standup" ) );
				g_Util.ConsolePrintColor ( 200, 255, 200, "\"\n" );
			}
			else if ( g_Vars.speed.boost_key == Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) ) )
			{
				g_Util.ConsolePrintColor ( 200, 255, 200, " = \"" );
				g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.PrefHack ( "+", g_Util.Prefix, "speed_boost" ) );
				g_Util.ConsolePrintColor ( 200, 255, 200, "\"\n" );
			}
			else if ( g_Vars.speed.slowmo_key == Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) ) )
			{
				g_Util.ConsolePrintColor ( 200, 255, 200, " = \"" );
				g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.PrefHack ( "+", g_Util.Prefix, "speed_slowmo" ) );
				g_Util.ConsolePrintColor ( 200, 255, 200, "\"\n" );
			}
			else if ( g_Vars.jumpbug.key == Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) ) )
			{
				g_Util.ConsolePrintColor ( 200, 255, 200, " = \"" );
				g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.PrefHack ( "+", g_Util.Prefix, "jumpbug" ) );
				g_Util.ConsolePrintColor ( 200, 255, 200, "\"\n" );
			}
			else if ( g_Vars.edgebug.key == Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) ) )
			{
				g_Util.ConsolePrintColor ( 200, 255, 200, " = \"" );
				g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.PrefHack ( "+", g_Util.Prefix, "edgebug" ) );
				g_Util.ConsolePrintColor ( 200, 255, 200, "\"\n" );
			}
			else
			{
				g_Util.ConsolePrintColor ( 200, 255, 200, IS_NOT_BOUND );
			}
		}
		else
		{
			int function = Function ( g_Engine.Cmd_Argv ( 2 ) );

			if ( function == PANIC )
			{
				g_Vars.main.panic_key = Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) );
			}

			if ( function == RELOAD_SETTINGS )
			{
				g_Vars.main.reload_key = Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) );
			}

			if ( function == BUNNYHOP )
			{
				g_Vars.bhop.key = Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) );
			}

			if ( function == BUNNYHOP_STANDUP )
			{
				g_Vars.bhop.standup_key = Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) );
			}

			if ( function == GROUNDSTRAFE )
			{
				g_Vars.gstrafe.key = Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) );
			}

			if ( function == GROUNDSTRAFE_STANDUP )
			{
				g_Vars.gstrafe.standup_key = Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) );
			}

			if ( function == SPEEDBOOST )
			{
				g_Vars.speed.boost_key = Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) );
			}

			if ( function == SPEEDSLOWMO )
			{
				g_Vars.speed.slowmo_key = Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) );
			}

			if ( function == JB )
			{
				g_Vars.jumpbug.key = Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) );
			}

			if ( function == EB )
			{
				g_Vars.edgebug.key = Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) );
			}
		}
	}

	void Command::UnBind ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			g_Util.ConsolePrintColor ( 100, 255, 200, HPP );
			g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.Prefix );
			g_Util.ConsolePrintColor ( 200, 255, 200, UNBIND_REMOVE_CMD );
		}
		else
		{
			if ( g_Vars.main.panic_key == Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) ) )
			{
				g_Vars.main.panic_key = 0;
			}

			if ( g_Vars.main.reload_key == Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) ) )
			{
				g_Vars.main.reload_key = 0;
			}

			if ( g_Vars.bhop.key == Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) ) )
			{
				g_Vars.bhop.key = 0;
			}

			if ( g_Vars.bhop.standup_key == Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) ) )
			{
				g_Vars.bhop.standup_key = 0;
			}

			if ( g_Vars.gstrafe.key == Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) ) )
			{
				g_Vars.gstrafe.key = 0;
			}

			if ( g_Vars.gstrafe.standup_key == Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) ) )
			{
				g_Vars.gstrafe.standup_key = 0;
			}

			if ( g_Vars.speed.boost_key == Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) ) )
			{
				g_Vars.speed.boost_key = 0;
			}

			if ( g_Vars.speed.slowmo_key == Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) ) )
			{
				g_Vars.speed.slowmo_key = 0;
			}

			if ( g_Vars.jumpbug.key == Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) ) )
			{
				g_Vars.jumpbug.key = 0;
			}

			if ( g_Vars.edgebug.key == Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) ) )
			{
				g_Vars.edgebug.key = 0;
			}
		}
	}

	void Command::UnBindAll ( )
	{
		g_Vars.bhop.key = 0;
		g_Vars.bhop.standup_key = 0;
		g_Vars.gstrafe.key = 0;
		g_Vars.gstrafe.standup_key = 0;
		g_Vars.speed.boost_key = 0;
		g_Vars.speed.slowmo_key = 0;
		g_Vars.jumpbug.key = 0;
		g_Vars.edgebug.key = 0;
	}
}