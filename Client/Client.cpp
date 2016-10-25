#include "Client.h"

namespace Client
{
	void Hpp::HUD_Frame ( double time )
	{
		if ( !Engine::FirstFrame )
		{
			Engine::g_Screen.iSize = sizeof ( SCREENINFO );

			Engine::g_Offset.HLType = Engine::g_Studio.IsHardware ( ) + 1;

			Engine::g_Local.ppmove = ( playermove_t* )Engine::g_Offset.PlayerMovePtr ( );

			Engine::g_Offset.ConsoleColorInitalize ( );
			Engine::g_Offset.GetGameInfo ( &BuildInfo );

			Engine::g_pUserMsgBase = ( PUserMsg )Engine::g_Offset.FindUserMsgBase ( );
			Engine::g_pEngineMsgBase = ( PEngineMsg )Engine::g_Offset.FindSVCMessages ( );

			Engine::g_pScreenFade = *( screenfade_t** )( ( DWORD )Engine::g_Engine.pfnSetScreenFade + 0x17 );

			if ( IsBadReadPtr ( Engine::g_pScreenFade, sizeof ( screenfade_t ) ) )
			{
				Engine::g_pScreenFade = *( screenfade_t** )( ( DWORD )Engine::g_Engine.pfnSetScreenFade + 0x18 );
			}

			HookUserMessages ( );
			HookEngineMessages ( );

			Initial::g_Init.LoadSettings ( );
			Initial::g_Init.InitHack ( );

			Engine::FirstFrame = true;
		}

		Engine::g_Engine.pfnGetScreenInfo ( &Engine::g_Screen );

		Engine::g_Client.HUD_Frame ( time );
	}

	void Hpp::HUD_Redraw ( float time, int intermission )
	{
		Engine::g_Client.HUD_Redraw ( time, intermission );

		struct cl_entity_s *Local = Engine::g_Engine.GetLocalPlayer ( );

		Engine::g_PlayerInfo.UpdateLocalEntity ( Local );

		for ( BYTE Index = 1; Index <= Engine::g_Engine.GetMaxClients ( ); ++Index )
		{
			struct cl_entity_s *Entity = Engine::g_Engine.GetEntityByIndex ( Index );

			if ( Index != Local->index )
			{
				Engine::g_PlayerInfo.UpdatePlayerInfo ( Entity, Local, Index );

				if ( Files::g_IniRead.function.esp && Files::g_IniRead.esp.enable )
				{
					if ( Files::g_IniRead.esp.player && Engine::g_Player[Index].Valid )
					{
						Functions::g_ESP.DrawPlayer ( Entity, Local, Index );
					}
				}
			}
		}

		if ( Files::g_IniRead.function.esp && Files::g_IniRead.esp.enable )
		{
			if ( Files::g_IniRead.esp.world )
			{
				Functions::g_ESP.DrawWorld ( );
			}

			if ( Files::g_IniRead.esp.sound )
			{
				Functions::g_ESP.DrawSound ( );
			}
		}

		if ( Files::g_IniRead.function.noflash && Files::g_IniRead.noflash.enable )
		{
			Functions::g_NoFlash.HUD_Redraw ( );
		}

		Renderer::g_Menu.Draw ( Engine::g_Screen.iWidth / 8, Engine::g_Screen.iHeight / 6 );
	}

	void Hpp::StudioEntityLight ( struct alight_s *plight )
	{
		struct cl_entity_s *Entity = Engine::g_Studio.GetCurrentEntity ( );
		struct cl_entity_s *Local = Engine::g_Engine.GetLocalPlayer ( );

		if ( Entity->player && Entity->index != Local->index )
		{
			Engine::g_PlayerInfo.GetBoneOrigin ( Entity, Local );
			Engine::g_PlayerInfo.GetHitboxOrigin ( Entity, Local );
		}

		Engine::g_Studio.StudioEntityLight ( plight );
	}

	int Hpp::HUD_AddEntity ( int type, struct cl_entity_s *ent, const char *modelname )
	{
		if ( Files::g_IniRead.function.esp && Files::g_IniRead.esp.enable && Files::g_IniRead.esp.world )
		{
			Functions::g_ESP.HUD_AddEntity ( ent );
		}

		return Engine::g_Client.HUD_AddEntity ( type, ent, modelname );
	}

	int Hpp::HUD_Key_Event ( int down, int keynum, const char *pszCurrentBinding )
	{
		Renderer::g_Menu.KeyEvent ( keynum );

		Initial::g_Init.ReloadKey ( keynum );
		Initial::g_Init.PanicKey ( keynum );

		if ( Files::g_IniRead.function.esp )
		{
			Functions::g_ESP.PanicKey ( keynum );
		}

		return Engine::g_Client.HUD_Key_Event ( down, keynum, pszCurrentBinding );
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
	}

	void Hpp::HookUserMessages ( )
	{
		Engine::pResetHUD = HookUserMsg ( RESET_HUD, Engine::g_UserMsg.ResetHUD );
		Engine::pSetFOV = HookUserMsg ( SET_FOV, Engine::g_UserMsg.SetFOV );
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