#include "Cmds.h"

namespace Engine
{
	bool Command::Return;

	enum FUNCTION_INDEX
	{
		PANIC, ESP_PANIC, RELOAD_SETTINGS, BUNNYHOP, BUNNYHOP_STANDUP, GROUNDSTRAFE,
		GROUNDSTRAFE_STANDUP, SPEEDBOOST, SPEEDSLOWMO, JB, EB, ANTISCREEN, STRAFEHELPER,
		STRAFEHELPER_SWITCH, THIRDPERSON_SWITCH, FREELOOK_SWITCH, SPECTATOR_SWITCH
	};

	uint8 Command::GetFunctionIndex ( char *CommandName )
	{
		PARSE_CMD2 ( CMD_PANIC, PANIC );
		PARSE_CMD2 ( CMD_ESP_PANIC, ESP_PANIC );
		PARSE_CMD2 ( CMD_SETTINGS_RELOAD, RELOAD_SETTINGS );
		PARSE_CMD ( CMD_BHOP, BUNNYHOP );
		PARSE_CMD ( CMD_BHOP_STANDUP, BUNNYHOP_STANDUP );
		PARSE_CMD ( CMD_GSTRAFE, GROUNDSTRAFE );
		PARSE_CMD ( CMD_GSTRAFE_STANDUP, GROUNDSTRAFE_STANDUP );
		PARSE_CMD ( CMD_SPEED_BOOST, SPEEDBOOST );
		PARSE_CMD ( CMD_SPEED_SLOWMO, SPEEDSLOWMO );
		PARSE_CMD ( CMD_JUMPBUG, JB );
		PARSE_CMD ( CMD_EDGEBUG, EB );
		PARSE_CMD2 ( CMD_ANTISCREEN, ANTISCREEN );
		PARSE_CMD ( CMD_STRAFE_HELPER, STRAFEHELPER );
		PARSE_CMD2 ( CMD_STRAFE_HELPER_SWITCH, STRAFEHELPER_SWITCH );
		PARSE_CMD2 ( CMD_THIRDPERSON_SWITCH, THIRDPERSON_SWITCH );
		PARSE_CMD2 ( CMD_FREELOOK_SWITCH, FREELOOK_SWITCH );
		PARSE_CMD2 ( CMD_SPECTATOR_SWITCH, SPECTATOR_SWITCH );

		return 0;
	}

	uint8 Command::SetKeyCommand ( )
	{
		return Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) );
	}

	void Command::BindIs ( BYTE Key, char *act, char *CommandName )
	{
		if ( !Return )
		{
			if ( Key == Files::g_File.StringToKey ( g_Engine.Cmd_Argv ( 1 ) ) )
			{
				g_Util.ConsolePrintColor ( 200, 255, 200, " = \"" );
				g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.PrefHack ( act, g_Util.Prefix, CommandName ) );
				g_Util.ConsolePrintColor ( 200, 255, 200, "\"\n" );

				Return = true;
			}
			else
			{
				Return = false;
			}
		}
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

			BindIs ( g_Vars.Main.PanicKey, "", CMD_PANIC );
			BindIs ( g_Vars.ESP.PanicKey, "", CMD_ESP_PANIC );
			BindIs ( g_Vars.Main.ReloadKey, "", CMD_SETTINGS_RELOAD );
			BindIs ( g_Vars.BHop.Key, "+", CMD_BHOP );
			BindIs ( g_Vars.BHop.StandUpKey, "+", CMD_BHOP_STANDUP );
			BindIs ( g_Vars.GStrafe.Key, "+", CMD_GSTRAFE );
			BindIs ( g_Vars.GStrafe.StandUpKey, "+", CMD_GSTRAFE_STANDUP );
			BindIs ( g_Vars.Speed.BoostKey, "+", CMD_SPEED_BOOST );
			BindIs ( g_Vars.Speed.SlowMotionKey, "+", CMD_SPEED_SLOWMO );
			BindIs ( g_Vars.JumpBug.Key, "+", CMD_JUMPBUG );
			BindIs ( g_Vars.EdgeBug.Key, "+", CMD_EDGEBUG );
			BindIs ( g_Vars.Main.AntiScreenKey, "", CMD_ANTISCREEN );
			BindIs ( g_Vars.StrafeHelper.Key, "+", CMD_STRAFE_HELPER );
			BindIs ( g_Vars.StrafeHelper.SwitchKey, "", CMD_STRAFE_HELPER_SWITCH );
			BindIs ( g_Vars.Camera.ThirdPersonSwitchKey, "", CMD_THIRDPERSON_SWITCH );
			BindIs ( g_Vars.Camera.FreeLookSwitchKey, "", CMD_FREELOOK_SWITCH );
			BindIs ( g_Vars.Camera.SpectatorSwitchKey, "", CMD_SPECTATOR_SWITCH );

			if ( Return )
			{
				Return = false;

				return;
			}
			else
			{
				g_Util.ConsolePrintColor ( 200, 255, 200, IS_NOT_BOUND );
			}
		}
		else
		{
			uint8 FunctionIndex = GetFunctionIndex ( g_Engine.Cmd_Argv ( 2 ) );

			switch ( FunctionIndex )
			{
			case PANIC:
				g_Vars.Main.PanicKey = SetKeyCommand ( );

				break;

			case ESP_PANIC:
				g_Vars.ESP.PanicKey = SetKeyCommand ( );

				break;

			case RELOAD_SETTINGS:
				g_Vars.Main.ReloadKey = SetKeyCommand ( );

				break;

			case BUNNYHOP:
				g_Vars.BHop.Key = SetKeyCommand ( );

				break;

			case BUNNYHOP_STANDUP:
				g_Vars.BHop.StandUpKey = SetKeyCommand ( );

				break;

			case GROUNDSTRAFE:
				g_Vars.GStrafe.Key = SetKeyCommand ( );

				break;

			case GROUNDSTRAFE_STANDUP:
				g_Vars.GStrafe.StandUpKey = SetKeyCommand ( );

				break;

			case SPEEDBOOST:
				g_Vars.Speed.BoostKey = SetKeyCommand ( );

				break;

			case SPEEDSLOWMO:
				g_Vars.Speed.SlowMotionKey = SetKeyCommand ( );

				break;

			case JB:
				g_Vars.JumpBug.Key = SetKeyCommand ( );

				break;

			case EB:
				g_Vars.EdgeBug.Key = SetKeyCommand ( );

				break;

			case ANTISCREEN:
				g_Vars.Main.AntiScreenKey = SetKeyCommand ( );

				break;

			case STRAFEHELPER:
				g_Vars.StrafeHelper.Key = SetKeyCommand ( );

				break;

			case STRAFEHELPER_SWITCH:
				g_Vars.StrafeHelper.SwitchKey = SetKeyCommand ( );

				break;

			case THIRDPERSON_SWITCH:
				g_Vars.Camera.ThirdPersonSwitchKey = SetKeyCommand ( );

				break;

			case FREELOOK_SWITCH:
				g_Vars.Camera.FreeLookSwitchKey = SetKeyCommand ( );

				break;

			case SPECTATOR_SWITCH:
				g_Vars.Camera.SpectatorSwitchKey = SetKeyCommand ( );

				break;
			}
		}
	}

	void Command::Unbind ( )
	{
		if ( g_Engine.Cmd_Argc ( ) < 2 )
		{
			g_Util.ConsolePrintColor ( 100, 255, 200, HPP );
			g_Util.ConsolePrintColor ( 200, 255, 200, g_Util.Prefix );
			g_Util.ConsolePrintColor ( 200, 255, 200, UNBIND_REMOVE_CMD );
		}
		else
		{
			uint8 KeyCommand = SetKeyCommand ( );

			DELETE_KEY_CMD ( g_Vars.Main.PanicKey );
			DELETE_KEY_CMD ( g_Vars.Main.ReloadKey );
			DELETE_KEY_CMD ( g_Vars.BHop.Key );
			DELETE_KEY_CMD ( g_Vars.BHop.StandUpKey );
			DELETE_KEY_CMD ( g_Vars.GStrafe.Key );
			DELETE_KEY_CMD ( g_Vars.GStrafe.StandUpKey );
			DELETE_KEY_CMD ( g_Vars.Speed.BoostKey );
			DELETE_KEY_CMD ( g_Vars.Speed.SlowMotionKey );
			DELETE_KEY_CMD ( g_Vars.JumpBug.Key );
			DELETE_KEY_CMD ( g_Vars.EdgeBug.Key );
			DELETE_KEY_CMD ( g_Vars.Main.AntiScreenKey );
			DELETE_KEY_CMD ( g_Vars.StrafeHelper.Key );
			DELETE_KEY_CMD ( g_Vars.StrafeHelper.SwitchKey );
			DELETE_KEY_CMD ( g_Vars.Camera.ThirdPersonSwitchKey );
			DELETE_KEY_CMD ( g_Vars.Camera.FreeLookSwitchKey );
			DELETE_KEY_CMD ( g_Vars.Camera.SpectatorSwitchKey );
		}
	}

	void Command::UnbindAll ( )
	{
		g_Vars.ESP.PanicKey = 0;

		g_Vars.BHop.Key = 0;
		g_Vars.BHop.StandUpKey = 0;

		g_Vars.GStrafe.Key = 0;
		g_Vars.GStrafe.StandUpKey = 0;

		g_Vars.Speed.BoostKey = 0;
		g_Vars.Speed.SlowMotionKey = 0;

		g_Vars.JumpBug.Key = 0;

		g_Vars.EdgeBug.Key = 0;

		g_Vars.Main.ReloadKey = 0;
		g_Vars.Main.AntiScreenKey = 0;

		g_Vars.StrafeHelper.Key = 0;
		g_Vars.StrafeHelper.SwitchKey = 0;

		g_Vars.Camera.ThirdPersonSwitchKey = 0;
		g_Vars.Camera.FreeLookSwitchKey = 0;
		g_Vars.Camera.SpectatorSwitchKey = 0;
	}
}