#include "Player.h"

namespace Information
{
	bool PlayerInfo::isAlive ( struct cl_entity_s *Entity )
	{
		return Entity->curstate.movetype && Entity->curstate.movetype != 6;
	}

	bool PlayerInfo::isValid ( int Index )
	{
		return g_Local.Entity->index != g_Player[Index].Entity->index && g_Player[Index].Alive &&
			!( g_Player[Index].Entity->curstate.messagenum < g_Local.Entity->curstate.messagenum ) &&
			!( g_Local.Entity->curstate.iuser1 == 4 && g_Local.Entity->curstate.iuser2 == g_Player[Index].Entity->index );
	}

	bool PlayerInfo::isDucked ( int Index )
	{
		return ( g_Player[Index].Entity->curstate.maxs[2] - g_Player[Index].Entity->curstate.mins[2] ) < 54;
	}

	bool PlayerInfo::ScanVisibility ( int Index )
	{
		if ( !Files::g_IniRead.main.scan_visibility )
		{
			if ( g_Util.PathFree ( g_Player[Index].Bone[17] ) )
			{
				return true;
			}
		}
		else if ( Files::g_IniRead.main.scan_visibility == 1 )
		{
			BYTE HitBoxCheckVisible[8] = { 0, 2, 6, 7, 8, 9, 11, 19 };

			for ( BYTE i = 0; i < sizeof ( HitBoxCheckVisible ); ++i )
			{
				if ( g_Util.PathFree ( g_Player[Index].HitBox[HitBoxCheckVisible[i]] ) )
				{
					return true;
				}
			}
		}
		else if ( Files::g_IniRead.main.scan_visibility >= 2 )
		{
			BYTE HitBoxCheckVisible[21] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

			for ( BYTE i = 0; i < sizeof ( HitBoxCheckVisible ); ++i )
			{
				if ( g_Util.PathFree ( g_Player[Index].HitBox[HitBoxCheckVisible[i]] ) )
				{
					return true;
				}
			}
		}

		return false;
	}

	void _fastcall PlayerInfo::UpdateLocalInfo ( )
	{
		g_Local.Entity = Engine::g_Engine.GetLocalPlayer ( );

		g_Local.Alive = isAlive ( g_Local.Entity );

		Engine::g_Engine.pEventAPI->EV_LocalPlayerViewheight ( g_Local.ViewOrg );

		VectorAdd ( g_Local.Entity->origin, g_Local.ViewOrg, g_Local.ViewOrg );
	}

	void _fastcall PlayerInfo::UpdateInfoByIndex ( int Index )
	{
		Engine::g_Engine.pfnGetPlayerInfo ( Index, &g_Player[Index].Info );

		g_Player[Index].Entity = Engine::g_Engine.GetEntityByIndex ( Index );

		g_Player[Index].Alive = isAlive ( g_Player[Index].Entity );
		g_Player[Index].Valid = isValid ( Index );
		g_Player[Index].Ducked = isDucked ( Index );

		g_Player[Index].Visible = ScanVisibility ( Index );
	}

	void _fastcall PlayerInfo::GetBoneOrigin ( struct cl_entity_s *Entity )
	{
		if ( isAlive ( Entity ) )
		{
			typedef float TransformMatrix[MAXSTUDIOBONES][3][4];

			model_t* Model = Engine::g_Studio.SetupPlayerModel ( Entity->index );
			studiohdr_t* StudioHeader = ( studiohdr_t* )Engine::g_Studio.Mod_Extradata ( Model );
			TransformMatrix* BoneTransform = ( TransformMatrix* )Engine::g_Studio.StudioGetBoneTransform ( );

			for ( BYTE i = 0; i < StudioHeader->numbones; ++i )
			{
				g_Player[Entity->index].Bone[i][0] = ( *BoneTransform )[i][0][3];
				g_Player[Entity->index].Bone[i][1] = ( *BoneTransform )[i][1][3];
				g_Player[Entity->index].Bone[i][2] = ( *BoneTransform )[i][2][3];
				g_Player[Entity->index].Bone[i] = g_Player[Entity->index].Bone[i];
			}
		}
	}

	void _fastcall PlayerInfo::GetHitboxOrigin ( struct cl_entity_s *Entity )
	{
		if ( isAlive ( Entity ) )
		{
			Vector BBMin, BBMax;

			typedef float BoneMatrix_t[MAXSTUDIOBONES][3][4];

			model_t* Model = Engine::g_Studio.SetupPlayerModel ( Entity->index );
			studiohdr_t* StudioHeader = ( studiohdr_t* )Engine::g_Studio.Mod_Extradata ( Model );
			BoneMatrix_t* BoneMatrix = ( BoneMatrix_t* )Engine::g_Studio.StudioGetBoneTransform ( );
			mstudiobbox_t* Hitbox = ( mstudiobbox_t* )( ( byte* )StudioHeader + StudioHeader->hitboxindex );

			for ( BYTE i = 0; i < StudioHeader->numhitboxes; ++i )
			{
				VectorTransform ( Hitbox[i].bbmin, ( *BoneMatrix )[Hitbox[i].bone], BBMin );
				VectorTransform ( Hitbox[i].bbmax, ( *BoneMatrix )[Hitbox[i].bone], BBMax );

				g_Player[Entity->index].HitBox[i] = ( BBMax + BBMin ) * 0.5f;
				g_Player[Entity->index].HitBox[i] = g_Player[Entity->index].HitBox[i];
			}
		}
	}

	PlayerInfo g_PlayerInfo;

	local_s g_Local;
	player_s g_Player[33];
}