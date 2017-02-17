#include "Client.h"

Vars g_Vars;

namespace Client
{
	Snapshot_t SnapShot_s = nullptr;
	Screenshot_t ScreenShot_s = nullptr;

	xcommand_t xJumpPressed, xJumpReleased;
	xcommand_t xDuckPressed, xDuckReleased;

	float Hpp::LastScrollTime[2];

	int Hpp::UpdateCurrent, Hpp::UpdateLast;
	int Hpp::ScreenTimer;

	int Hpp::ScrollCounter[2];

	bool Hpp::GameActive, Hpp::FirstFrame, Hpp::PanicEnabled;
	bool Hpp::bSnapShot, Hpp::bScreenShot;
	bool Hpp::JumpPressed, Hpp::ScrollJump;
	bool Hpp::DuckPressed, Hpp::ScrollDuck;

	void Hpp::HookedJumpPressed ( )
	{
		JumpPressed = true;

		_asm CALL xJumpPressed
	}

	void Hpp::HookedJumpReleased ( )
	{
		if ( JumpPressed )
		{
			ScrollJump = true;
		}

		_asm CALL xJumpReleased
	}

	void Hpp::HookedDuckPressed ( )
	{
		DuckPressed = true;

		_asm CALL xDuckPressed
	}

	void Hpp::HookedDuckReleased ( )
	{
		if ( DuckPressed )
		{
			ScrollDuck = true;
		}

		_asm CALL xDuckReleased
	}

	void Hpp::AntiSnapShot ( )
	{
		if ( g_Vars.Main.AntiScreenEnable )
		{
			bSnapShot = true;

			ResetFadeColor ( );
		}
		else
		{
			SnapShot_s ( );
		}
	}

	void Hpp::AntiScreenShot ( )
	{
		if ( g_Vars.Main.AntiScreenEnable )
		{
			bScreenShot = true;

			if ( g_Vars.Function.NoFlash && g_Vars.NoFlash.Enable )
			{
				ResetFadeColor ( );
			}
		}
		else
		{
			ScreenShot_s ( );
		}
	}

	void Hpp::ResetFadeColor ( )
	{
		Engine::g_pScreenFade->fader = 255;
		Engine::g_pScreenFade->fadeg = 255;
		Engine::g_pScreenFade->fadeb = 255;
	}

	int Hpp::CL_IsThirdPerson ( )
	{
		if ( g_Vars.Function.Camera )
		{
			if ( g_Vars.Camera.ThirdPersonEnable || g_Vars.Camera.FreeLookEnable )
			{
				return 1;
			}

			if ( g_Vars.Camera.SpectatorEnable && g_Vars.Camera.SpectatorID != Info::g_Local.Player.Index &&
				Info::g_Player[int ( g_Vars.Camera.SpectatorID )].Valid && Info::g_Local.Player.isAlive )
			{
				return 1;
			}
		}

		return Engine::g_Client.CL_IsThirdPerson ( );
	}

	void Hpp::HUD_Frame ( double time )
	{
		if ( !FirstFrame )
		{
			Engine::g_Screen.iSize = sizeof ( SCREENINFO );

			Engine::g_Offset.HLType = Engine::g_Studio.IsHardware ( ) + 1;

			Engine::g_Offset.ConsoleColorInitalize ( );
			Engine::g_Offset.GetGameInfo ( &BuildInfo );

			Engine::g_pScreenFade = *( screenfade_t** )( ( DWORD )Engine::g_Engine.pfnSetScreenFade + 0x17 );

			if ( IsBadReadPtr ( Engine::g_pScreenFade, sizeof ( screenfade_t ) ) )
			{
				Engine::g_pScreenFade = *( screenfade_t** )( ( DWORD )Engine::g_Engine.pfnSetScreenFade + 0x18 );
			}

			Engine::g_Offset.SpeedPtr = ( DWORD )Engine::g_Offset.SpeedHackPtr ( );

			if ( BuildInfo.Build > 4554 )
			{
				Info::g_Local.g_Net = ( double* )*( PDWORD )( ( DWORD )Engine::g_Engine.pNetAPI->SendRequest + 0x49 );
			}
			else
			{
				Info::g_Local.g_Net = ( double* )*( PDWORD )( ( DWORD )Engine::g_Engine.pNetAPI->SendRequest + 0x51 );

				if ( IsBadReadPtr ( Info::g_Local.g_Net, sizeof ( double ) ) )
				{
					Info::g_Local.g_Net = ( double* )*( PDWORD )( ( DWORD )Engine::g_Engine.pNetAPI->SendRequest + 0x49 );
				}
			}

			HookUserMessages ( );
			HookEngineMessages ( );

			Initial::g_Init.InitHack ( );

			if ( g_Vars.Function.Commands )
			{
				Engine::g_Command.ConsoleCommands ( );
			}

			pcmd_t SnapShot = CommandByName ( "snapshot" );
			pcmd_t ScreenShot = CommandByName ( "screenshot" );

			SnapShot_s = ( Snapshot_t )SnapShot->function;
			ScreenShot_s = ( Snapshot_t )ScreenShot->function;

			SnapShot->function = ( xcommand_t )AntiSnapShot;
			ScreenShot->function = ( xcommand_t )AntiScreenShot;

			g_Util.HookCommand ( "+jump", &xJumpPressed, HookedJumpPressed );
			g_Util.HookCommand ( "-jump", &xJumpReleased, HookedJumpReleased );

			g_Util.HookCommand ( "+duck", &xDuckPressed, HookedDuckPressed );
			g_Util.HookCommand ( "-duck", &xDuckReleased, HookedDuckReleased );

			FirstFrame = true;
		}

		Engine::g_Engine.pfnGetScreenInfo ( &Engine::g_Screen );

		UpdateCurrent = GetTickCount ( );

		if ( UpdateCurrent - UpdateLast >= 300 )
		{
			GameActive = false;
		}

		Engine::g_Client.HUD_Frame ( time );
	}

	void Hpp::HUD_Redraw ( float time, int intermission )
	{
		Engine::g_Client.HUD_Redraw ( time, intermission );

		GameActive = true;

		UpdateLast = GetTickCount ( );

		if ( !PanicEnabled && ( !bSnapShot && !bScreenShot ) )
		{
			Info::g_PlayerInfo.HUD_Redraw ( );

			if ( g_Vars.Function.ESP && g_Vars.ESP.Enable && !Functions::Visuals::g_ESP.PanicEnabled )
			{
				Functions::Visuals::g_ESP.HUD_Redraw ( );
			}

			if ( g_Vars.Function.NoFlash && g_Vars.NoFlash.Enable )
			{
				Functions::Visuals::g_NoFlash.HUD_Redraw ( );
			}

			if ( g_Vars.Function.ScreenInfo && g_Vars.ScreenInfo.Enable )
			{
				Functions::Visuals::g_ScreenInfo.HUD_Redraw ( );
			}

			if ( g_Vars.Function.Menu )
			{
				Functions::Visuals::g_Menu.Draw ( g_Vars.Menu.Pos_x, g_Vars.Menu.Pos_y );
			}

			if ( g_Vars.Function.ESP && g_Vars.ESP.Enable && g_Vars.ESP.C4Timer && !Info::g_Local.Bomb.isPlanted )
			{
				if ( g_Vars.ESP.C4Timer == 1 )
				{
					Info::g_Local.Bomb.C4Timer = 0;
				}
				else if ( g_Vars.ESP.C4Timer == 2 )
				{
					Info::g_Local.Bomb.C4Timer = g_Vars.ESP.C4TimerValue;
				}
			}
		}

		if ( bSnapShot || bScreenShot )
		{
			--ScreenTimer;

			if ( ScreenTimer <= 0 )
			{
				if ( bSnapShot )
				{
					SnapShot_s ( );

					bSnapShot = false;
				}
				else if ( bScreenShot )
				{
					ScreenShot_s ( );

					bScreenShot = false;
				}

				ScreenTimer = g_Vars.Main.AntiScreenTimer;
			}
		}
	}

	void Hpp::StudioEntityLight ( alight_s *plight )
	{
		if ( !PanicEnabled )
		{
			Info::g_PlayerInfo.StudioEntityLight ( );
		}

		Engine::g_Studio.StudioEntityLight ( plight );
	}

	int Hpp::HUD_AddEntity ( int type, cl_entity_s *ent, const char *modelname )
	{
		if ( !PanicEnabled && ( !bSnapShot && !bScreenShot ) )
		{
			if ( g_Vars.Function.ESP && g_Vars.ESP.Enable )
			{
				Functions::Visuals::g_ESP.HUD_AddEntity ( ent );
			}
		}

		return Engine::g_Client.HUD_AddEntity ( type, ent, modelname );
	}

	void Hpp::SetViewAngles ( float *Angles )
	{
		if ( g_Vars.Function.StrafeHelper && g_Vars.StrafeHelper.Active )
		{		
			Functions::Misc::g_StrafeHelper.SetViewAngles ( Angles );
		}

		Engine::g_Engine.SetViewAngles ( Angles );
	}

	int Hpp::HUD_Key_Event ( int down, int keynum, const char *pszCurrentBinding )
	{
		if ( keynum == g_Vars.Main.ReloadKey )
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

			return 0;
		}

		if ( keynum == g_Vars.Main.PanicKey )
		{
			PanicEnabled = !PanicEnabled;

			Engine::g_Engine.pfnPlaySoundByName ( PanicEnabled ? "vox/of.wav" : "vox/on.wav", 1 );

			return 0;
		}

		if ( !PanicEnabled )
		{
			if ( g_Vars.Main.AntiScreenEnable )
			{
				if ( keynum == g_Vars.Main.AntiScreenKey )
				{
					bSnapShot = true;

					ResetFadeColor ( );

					return 0;
				}
			}

			if ( g_Vars.Function.BunnyHop )
			{
				if ( keynum == g_Vars.BHop.Key )
				{
					if ( !Info::g_Local.Player.isAlive )
					{
						Functions::Misc::g_BHop.BunnyHopActive = false;
					}
					else
					{
						Functions::Misc::g_BHop.BunnyHopActive = !!down;

						return 0;
					}
				}

				if ( keynum == g_Vars.BHop.StandUpKey )
				{
					if ( !Info::g_Local.Player.isAlive )
					{
						Functions::Misc::g_BHop.StandUpActive = false;
					}
					else
					{
						Functions::Misc::g_BHop.StandUpActive = !!down;

						return 0;
					}
				}
			}

			if ( g_Vars.Function.GroundStrafe )
			{
				if ( keynum == g_Vars.GStrafe.Key )
				{
					if ( !Info::g_Local.Player.isAlive )
					{
						Functions::Misc::g_GStrafe.GroundStrafeActive = false;
					}
					else
					{
						Functions::Misc::g_GStrafe.GroundStrafeActive = !!down;

						return 0;
					}
				}

				if ( keynum == g_Vars.GStrafe.StandUpKey )
				{
					if ( !Info::g_Local.Player.isAlive )
					{
						Functions::Misc::g_GStrafe.StandUpActive = false;
					}
					else
					{
						Functions::Misc::g_GStrafe.StandUpActive = !!down;

						return 0;
					}
				}
			}

			if ( g_Vars.Function.Speed )
			{
				if ( keynum == g_Vars.Speed.BoostKey )
				{
					if ( !Info::g_Local.Player.isAlive )
					{
						Functions::Misc::g_Speed.SpeedBoost = false;
					}
					else
					{
						Functions::Misc::g_Speed.SpeedBoost = !!down;

						return 0;
					}
				}

				if ( keynum == g_Vars.Speed.SlowMotionKey )
				{
					if ( !Info::g_Local.Player.isAlive )
					{
						Functions::Misc::g_Speed.SpeedSlowMotion = false;
					}
					else
					{
						Functions::Misc::g_Speed.SpeedSlowMotion = !!down;

						return 0;
					}
				}
			}

			if ( g_Vars.Function.JumpBug )
			{
				if ( keynum == g_Vars.JumpBug.Key )
				{
					if ( !Info::g_Local.Player.isAlive )
					{
						Functions::Misc::g_JumpBug.JumpBugActive = false;
					}
					else
					{
						Functions::Misc::g_JumpBug.JumpBugActive = !!down;

						return 0;
					}
				}
			}

			if ( g_Vars.Function.EdgeBug )
			{
				if ( keynum == g_Vars.EdgeBug.Key )
				{
					if ( !Info::g_Local.Player.isAlive )
					{
						Functions::Misc::g_EdgeBug.EdgeBugActive = false;
					}
					else
					{
						Functions::Misc::g_EdgeBug.EdgeBugActive = !!down;

						return 0;
					}
				}
			}

			if ( g_Vars.Function.StrafeHelper )
			{
				if ( keynum == g_Vars.StrafeHelper.Key )
				{
					if ( !Info::g_Local.Player.isAlive )
					{
						Functions::Misc::g_StrafeHelper.StrafeHelperActive = false;
					}
					else
					{
						Functions::Misc::g_StrafeHelper.StrafeHelperActive = !!down;

						if ( Functions::Misc::g_StrafeHelper.StrafeHelperActive )
						{
							g_Vars.StrafeHelper.Active = 1;
						}
						else
						{
							g_Vars.StrafeHelper.Active = 0;
						}

						return 0;
					}
				}

				if ( keynum == g_Vars.StrafeHelper.SwitchKey )
				{
					g_Vars.StrafeHelper.Active = !g_Vars.StrafeHelper.Active;

					Engine::g_Engine.pfnPlaySoundByName ( g_Vars.StrafeHelper.Active ? "vox/on.wav" : "vox/of.wav", 1 );
				}
			}

			if ( keynum == g_Vars.Camera.ThirdPersonSwitchKey )
			{
				g_Vars.Camera.ThirdPersonEnable = !g_Vars.Camera.ThirdPersonEnable;

				Engine::g_Engine.pfnPlaySoundByName ( g_Vars.Camera.ThirdPersonEnable ? "vox/on.wav" : "vox/of.wav", 1 );
			}

			if ( keynum == g_Vars.Camera.FreeLookSwitchKey )
			{
				g_Vars.Camera.FreeLookEnable = !g_Vars.Camera.FreeLookEnable;

				Engine::g_Engine.pfnPlaySoundByName ( g_Vars.Camera.FreeLookEnable ? "vox/on.wav" : "vox/of.wav", 1 );
			}

			if ( keynum == g_Vars.Camera.SpectatorSwitchKey )
			{
				g_Vars.Camera.SpectatorEnable = !g_Vars.Camera.SpectatorEnable;

				Engine::g_Engine.pfnPlaySoundByName ( g_Vars.Camera.SpectatorEnable ? "vox/on.wav" : "vox/of.wav", 1 );
			}

			if ( g_Vars.Function.Menu )
			{
				Functions::Visuals::g_Menu.HUD_Key_Event ( keynum );
			}

			if ( g_Vars.Function.ESP && g_Vars.ESP.Enable )
			{
				Functions::Visuals::g_ESP.PanicKey ( keynum );
			}
		}

		return Engine::g_Client.HUD_Key_Event ( down, keynum, pszCurrentBinding );
	}

	void Hpp::CL_CreateMove ( float frametime, usercmd_s *cmd, int active )
	{
		POINT CurrentPosition;
		GetCursorPos ( &CurrentPosition );

		short check, MousePos_x;
		short OldMousePos_x = 0;

		MousePos_x = CurrentPosition.x - Engine::g_Engine.GetWindowCenterX ( );
		check = MousePos_x - OldMousePos_x;

		Engine::g_Client.CL_CreateMove ( frametime, cmd, active );

		if ( !PanicEnabled )
		{
			Info::g_Local.FrameTime = frametime;

			if ( g_Vars.Function.ESP && g_Vars.ESP.Enable && g_Vars.ESP.C4Timer && Info::g_Local.Bomb.isPlanted )
			{
				if ( g_Vars.ESP.C4Timer == 1 )
				{
					Info::g_Local.Bomb.C4Timer += frametime;
				}
				else if ( g_Vars.ESP.C4Timer == 2 )
				{
					Info::g_Local.Bomb.C4Timer -= frametime;

					if ( Info::g_Local.Bomb.C4Timer < 0 )
					{
						Info::g_Local.Bomb.C4Timer = 0;
					}
				}
			}

			if ( GameActive )
			{
				Functions::Misc::g_Speed.CL_CreateMove ( );

				if ( Info::g_Local.Player.isAlive )
				{
					if ( g_Vars.Function.BunnyHop )
					{
						Functions::Misc::g_BHop.CL_CreateMove ( frametime, cmd );
					}

					if ( g_Vars.Function.GroundStrafe )
					{
						Functions::Misc::g_GStrafe.CL_CreateMove ( frametime, cmd );
					}

					if ( g_Vars.Function.JumpBug )
					{
						Functions::Misc::g_JumpBug.CL_CreateMove ( frametime, cmd );
					}

					if ( g_Vars.Function.EdgeBug )
					{
						Functions::Misc::g_EdgeBug.CL_CreateMove ( frametime );
					}

					if ( g_Vars.Function.StrafeHelper )
					{
						Functions::Misc::g_StrafeHelper.CL_CreateMove ( frametime, cmd, check );
					}

					if ( g_Vars.Function.Camera )
					{
						Functions::Visuals::g_Camera.CL_CreateMove ( frametime, cmd );
					}

					if ( g_Vars.Function.ScreenInfo && g_Vars.ScreenInfo.Enable && g_Vars.ScreenInfo.ShowKeys )
					{
						Functions::Visuals::g_ScreenInfo.CL_CreateMove ( cmd );
					}
				}
			}
		}

		OldMousePos_x = MousePos_x;
	}

	void Hpp::V_CalcRefdef ( ref_params_s *pparams )
	{
		VectorCopy ( pparams->forward, Info::g_Local.Forward );
		VectorCopy ( pparams->right, Info::g_Local.Right );
		VectorCopy ( pparams->up, Info::g_Local.Up );

		Engine::g_Client.V_CalcRefdef ( pparams );

		Functions::Visuals::g_Camera.V_CalcRefdef ( pparams );
	}

	void _fastcall Hpp::HookStudio ( )
	{
		Engine::g_pStudio->StudioEntityLight = StudioEntityLight;
	}

	void _fastcall Hpp::HookFunction ( )
	{
		Engine::g_pClient->HUD_Frame = HUD_Frame;
		Engine::g_pClient->HUD_Redraw = HUD_Redraw;
		Engine::g_pClient->HUD_Key_Event = HUD_Key_Event;
		Engine::g_pClient->HUD_AddEntity = HUD_AddEntity;

		Engine::g_pClient->CL_IsThirdPerson = CL_IsThirdPerson;
		Engine::g_pClient->CL_CreateMove = CL_CreateMove;

		Engine::g_pClient->V_CalcRefdef = V_CalcRefdef;

		Engine::g_pEngine->SetViewAngles = SetViewAngles;
	}

	void Hpp::HookUserMessages ( )
	{
		Engine::pResetHUD = HookUserMsg ( RESET_HUD, Engine::g_UserMsg.ResetHUD );
		Engine::pSetFOV = HookUserMsg ( SET_FOV, Engine::g_UserMsg.SetFOV );
		Engine::pTextMsg = HookUserMsg ( TEXT_MSG, Engine::g_UserMsg.TextMsg );
		Engine::pTeamInfo = HookUserMsg ( TEAM_INFO, Engine::g_UserMsg.TeamInfo );
		Engine::pCurWeapon = HookUserMsg ( CUR_WEAPON, Engine::g_UserMsg.CurWeapon );
		Engine::pDeathMsg = HookUserMsg ( DEATH_MSG, Engine::g_UserMsg.DeathMsg );
	}

	void Hpp::HookEngineMessages ( )
	{
		Engine::pSVC_sound = HookEngineMsg ( SOUND, Engine::g_EngineMsg.SVC_Sound );
		Engine::pSVC_SpawnStaticSound = HookEngineMsg ( SPAWN_STATIC_SOUND, Engine::g_EngineMsg.SVC_SpawnStaticSound );
		Engine::pSVC_StuffText = HookEngineMsg ( STUFF_TEXT, Engine::g_EngineMsg.SVC_StuffText );
		Engine::pSVC_NewUserMsg = HookEngineMsg ( NEW_USER_MSG, Engine::g_EngineMsg.SVC_NewUserMsg );
		Engine::pSVC_UpdateUserInfo = HookEngineMsg ( UPDATE_USER_INFO, Engine::g_EngineMsg.SVC_UpdateUserInfo );
		Engine::pSVC_SendCvarValue = HookEngineMsg ( SEND_CVAR_VALUE, Engine::g_EngineMsg.SVC_SendCvarValue );
		Engine::pSVC_SendCvarValue2 = HookEngineMsg ( SEND_CVAR_VALUE2, Engine::g_EngineMsg.SVC_SendCvarValue2 );
		Engine::pSVC_Director = HookEngineMsg ( DIRECTOR, Engine::g_EngineMsg.SVC_Director );
	}

	Hpp g_Hpp;

	GameInfo_t BuildInfo;
}