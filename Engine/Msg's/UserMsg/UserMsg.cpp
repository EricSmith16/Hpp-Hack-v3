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
		Information::g_Local.Bomb.isPlanted = false;
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
				Information::g_Local.Bomb.isPlanted = true;
			}
			else if ( !lstrcmpi ( Message, "#Target_Bombed" ) || !lstrcmp ( Message, "#Bomb_Defused" ) )
			{
				Information::g_Local.Bomb.isPlanted = false;
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
			Information::g_Player[Index].Team = TERRORIST;

			if ( Index == Entity->index )
			{
				Information::g_Local.Team = TERRORIST;
			}
		}
		else if ( !lstrcmpi ( Team, CT_UMSG ) )
		{
			Information::g_Player[Index].Team = CT;

			if ( Index == Entity->index )
			{
				Information::g_Local.Team = CT;
			}
		}
		else
		{
			Information::g_Player[Index].Team = SPECTATOR;

			if ( Index == Entity->index )
			{
				Information::g_Local.Team = SPECTATOR;
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