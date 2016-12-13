#include "Client.h"

Vars g_Vars;

namespace Client
{
	int Hpp::UpdateCurrent, Hpp::UpdateLast;

	bool Hpp::GameActive, Hpp::FirstFrame, Hpp::PanicEnabled;

	void Hpp::ReloadKey ( int keynum )
	{
		if ( keynum == g_Vars.main.reload_key )
		{
			Initial::g_Init.ReloadSettings ( );

			if ( g_Vars.main.language )
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
	}

	void Hpp::PanicKey ( int keynum )
	{
		if ( keynum == g_Vars.main.panic_key )
		{
			PanicEnabled = !PanicEnabled;

			Engine::g_Engine.pfnPlaySoundByName ( PanicEnabled ? "vox/of.wav" : "vox/on.wav", 1 );
		}
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

			Information::g_Local.Speed = 0;
			Information::g_Local.SpeedPtr = ( DWORD )Engine::g_Offset.SpeedHackPtr ( );

			Information::g_Local.g_Net = ( double* )*( PDWORD )( ( DWORD )Engine::g_Engine.pNetAPI->SendRequest + 0x51 );

			if ( IsBadReadPtr ( Information::g_Local.g_Net, sizeof ( double ) ) )
			{
				Information::g_Local.g_Net = ( double* )*( PDWORD )( ( DWORD )Engine::g_Engine.pNetAPI->SendRequest + 0x49 );
			}

			HookUserMessages ( );
			HookEngineMessages ( );

			Initial::g_Init.InitHack ( );

			if ( g_Vars.function.commands )
			{
				Engine::g_Command.ConsoleCommands ( );
			}

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

		if ( !PanicEnabled )
		{
			Information::g_PlayerInfo.HUD_Redraw ( );

			if ( g_Vars.function.esp && g_Vars.esp.enable && !Functions::Visuals::g_ESP.PanicEnabled )
			{
				Functions::Visuals::g_ESP.HUD_Redraw ( );
			}

			if ( g_Vars.function.noflash && g_Vars.noflash.enable )
			{
				Functions::Visuals::g_NoFlash.HUD_Redraw ( );
			}

			if ( g_Vars.function.screeninfo && g_Vars.screeninfo.enable )
			{
				Functions::Visuals::g_ScreenInfo.HUD_Redraw ( );
			}

			if ( g_Vars.function.menu )
			{
				Functions::Visuals::g_Menu.Draw ( g_Vars.menu.pos_x, g_Vars.menu.pos_y );
			}

			if ( g_Vars.function.esp && g_Vars.esp.enable && g_Vars.esp.c4timer && !Information::g_Local.Bomb.isPlanted )
			{
				if ( g_Vars.esp.c4timer == 1 )
				{
					Information::g_Local.Bomb.C4Timer = 0;
				}
				else if ( g_Vars.esp.c4timer == 2 )
				{
					Information::g_Local.Bomb.C4Timer = g_Vars.esp.c4timer_value;
				}
			}
		}
	}

	void Hpp::StudioEntityLight ( struct alight_s *plight )
	{
		cl_entity_s *Entity = Engine::g_Studio.GetCurrentEntity ( );

		if ( !PanicEnabled )
		{
			if ( Entity && Entity->player && Entity->index != Information::g_Local.Index )
			{
				Information::g_PlayerInfo.GetBoneOrigin ( Entity );
				Information::g_PlayerInfo.GetHitboxOrigin ( Entity );
			}
		}

		Engine::g_Studio.StudioEntityLight ( plight );
	}

	int Hpp::HUD_AddEntity ( int type, struct cl_entity_s *ent, const char *modelname )
	{
		if ( !PanicEnabled )
		{
			if ( g_Vars.function.esp && g_Vars.esp.enable )
			{
				Functions::Visuals::g_ESP.HUD_AddEntity ( ent );
			}
		}

		return Engine::g_Client.HUD_AddEntity ( type, ent, modelname );
	}

	int Hpp::HUD_Key_Event ( int down, int keynum, const char *pszCurrentBinding )
	{
		ReloadKey ( keynum );
		PanicKey ( keynum );

		if ( !PanicEnabled )
		{
			if ( g_Vars.function.bhop )
			{
				if ( keynum == g_Vars.bhop.key )
				{
					if ( !Information::g_Local.Alive )
					{
						Functions::Misc::g_BHop.BunnyHopActive = false;
					}
					else
					{
						Functions::Misc::g_BHop.BunnyHopActive = !!down;

						return 0;
					}
				}

				if ( keynum == g_Vars.bhop.standup_key )
				{
					if ( !Information::g_Local.Alive )
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

			if ( g_Vars.function.gstrafe )
			{
				if ( keynum == g_Vars.gstrafe.key )
				{
					if ( !Information::g_Local.Alive )
					{
						Functions::Misc::g_GStrafe.GroundStrafeActive = false;
					}
					else
					{
						Functions::Misc::g_GStrafe.GroundStrafeActive = !!down;

						return 0;
					}
				}

				if ( keynum == g_Vars.gstrafe.standup_key )
				{
					if ( !Information::g_Local.Alive )
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

			if ( g_Vars.function.speed )
			{
				if ( keynum == g_Vars.speed.boost_key )
				{
					if ( !Information::g_Local.Alive )
					{
						Functions::Misc::g_Speed.SpeedBoost = false;
					}
					else
					{
						Functions::Misc::g_Speed.SpeedBoost = !!down;

						return 0;
					}
				}

				if ( keynum == g_Vars.speed.slowmo_key )
				{
					if ( !Information::g_Local.Alive )
					{
						Functions::Misc::g_Speed.SpeedSlowMo = false;
					}
					else
					{
						Functions::Misc::g_Speed.SpeedSlowMo = !!down;

						return 0;
					}
				}
			}

			if ( g_Vars.function.jumpbug )
			{
				if ( keynum == g_Vars.jumpbug.key )
				{
					if ( !Information::g_Local.Alive )
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

			if ( g_Vars.function.edgebug )
			{
				if ( keynum == g_Vars.edgebug.key )
				{
					if ( !Information::g_Local.Alive )
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

			if ( g_Vars.function.menu )
			{
				Functions::Visuals::g_Menu.Menu_KeyEvent ( keynum );
			}

			if ( g_Vars.function.esp && g_Vars.esp.enable )
			{
				Functions::Visuals::g_ESP.PanicKey ( keynum );
			}
		}

		return Engine::g_Client.HUD_Key_Event ( down, keynum, pszCurrentBinding );
	}

	void Hpp::CL_CreateMove ( float frametime, struct usercmd_s *cmd, int active )
	{
		Engine::g_Client.CL_CreateMove ( frametime, cmd, active );

		if ( !PanicEnabled )
		{
			Information::g_Local.FrameTime = frametime;

			if ( g_Vars.function.esp && g_Vars.esp.enable && g_Vars.esp.c4timer && Information::g_Local.Bomb.isPlanted )
			{
				if ( g_Vars.esp.c4timer == 1 )
				{
					Information::g_Local.Bomb.C4Timer += frametime;
				}
				else if ( g_Vars.esp.c4timer == 2 )
				{
					Information::g_Local.Bomb.C4Timer -= frametime;

					if ( Information::g_Local.Bomb.C4Timer < 0 )
					{
						Information::g_Local.Bomb.C4Timer = 0;
					}
				}
			}

			if ( GameActive )
			{			
				Functions::Misc::g_Speed.CL_CreateMove ( );

				if ( Information::g_Local.Alive )
				{
					if ( g_Vars.function.bhop )
					{
						Functions::Misc::g_BHop.CL_CreateMove ( frametime, cmd );
					}

					if ( g_Vars.function.gstrafe )
					{
						Functions::Misc::g_GStrafe.CL_CreateMove ( frametime, cmd );
					}

					if ( g_Vars.function.jumpbug )
					{
						Functions::Misc::g_JumpBug.CL_CreateMove ( frametime, cmd );
					}

					if ( g_Vars.function.edgebug )
					{
						Functions::Misc::g_EdgeBug.CL_CreateMove ( frametime );
					}
				}			

				if ( g_Vars.function.screeninfo && g_Vars.screeninfo.enable && g_Vars.screeninfo.showkeys )
				{
					Functions::Visuals::g_ScreenInfo.CL_CreateMove ( cmd );
				}
			}		
		}
	}

	void Hpp::HookStudio ( )
	{
		Engine::g_pStudio->StudioEntityLight = StudioEntityLight;
	}

	void Hpp::HookFunction ( )
	{
		Engine::g_pClient->HUD_Frame = HUD_Frame;
		Engine::g_pClient->HUD_Redraw = HUD_Redraw;
		Engine::g_pClient->HUD_Key_Event = HUD_Key_Event;
		Engine::g_pClient->HUD_AddEntity = HUD_AddEntity;
		Engine::g_pClient->CL_CreateMove = CL_CreateMove;
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