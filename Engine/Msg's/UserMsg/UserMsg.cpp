#include "UserMsg.h"

namespace Engine
{
	pfnUserMsgHook pResetHUD = nullptr;
	pfnUserMsgHook pSetFOV = nullptr;
	pfnUserMsgHook pTeamInfo = nullptr;
	pfnUserMsgHook pCurWeapon = nullptr;
	pfnUserMsgHook pDeathMsg = nullptr;
	pfnUserMsgHook pTextMsg = nullptr;

	void UserMsg::AtRoundStart ( )
	{
		Info::g_Local.Bomb.isPlanted = false;
	}

	int UserMsg::ResetHUD ( const char *pszName, int iSize, void *pbuf )
	{
		AtRoundStart ( );

		return pResetHUD ( pszName, iSize, pbuf );
	}

	int UserMsg::SetFOV ( const char *pszName, int iSize, void *pbuf )
	{
		return pSetFOV ( pszName, iSize, pbuf );
	}

	int UserMsg::TextMsg ( const char *pszName, int iSize, void *pbuf )
	{
		BEGIN_READ ( pbuf, iSize );

		int ID = READ_BYTE ( );

		char *Message = READ_STRING ( );

		if ( *Message )
		{
			if ( !lstrcmpi ( Message, "#Bomb_Planted" ) )
			{
				Info::g_Local.Bomb.isPlanted = true;
			}
			else if ( !lstrcmpi ( Message, "#Target_Bombed" ) || !lstrcmp ( Message, "#Bomb_Defused" ) )
			{
				Info::g_Local.Bomb.isPlanted = false;
			}
		}

		return pTextMsg ( pszName, iSize, pbuf );
	}

	int UserMsg::TeamInfo ( const char *pszName, int iSize, void *pbuf )
	{
		BEGIN_READ ( pbuf, iSize );

		cl_entity_s *Entity = g_Engine.GetLocalPlayer ( );

		int Index = READ_BYTE ( );

		char *Team = READ_STRING ( );

		if ( !lstrcmpi ( Team, TERRORIST_UMSG ) )
		{
			Info::g_Player[Index].Team = TERRORIST;

			if ( Index == Entity->index )
			{
				Info::g_Local.Player.Team = TERRORIST;
			}
		}
		else if ( !lstrcmpi ( Team, CT_UMSG ) )
		{
			Info::g_Player[Index].Team = CT;

			if ( Index == Entity->index )
			{
				Info::g_Local.Player.Team = CT;
			}
		}
		else
		{
			Info::g_Player[Index].Team = SPECTATOR;

			if ( Index == Entity->index )
			{
				Info::g_Local.Player.Team = SPECTATOR;
			}
		}

		return pTeamInfo ( pszName, iSize, pbuf );
	}

	int UserMsg::CurWeapon ( const char *pszName, int iSize, void *pbuf )
	{
		return pCurWeapon ( pszName, iSize, pbuf );
	}

	int UserMsg::DeathMsg ( const char *pszName, int iSize, void *pbuf )
	{
		return pDeathMsg ( pszName, iSize, pbuf );
	}

	UserMsg g_UserMsg;
}