#include "Player.h"

#pragma warning (disable: 4800)

namespace Information
{
	bool PlayerInfo::isAlive ( )
	{
		return g_Local.Entity && g_Local.Entity->curstate.movetype && g_Local.Entity->curstate.movetype != 6;
	}

	bool PlayerInfo::isDucked ( int Index )
	{
		return ( g_Player[Index].Entity->curstate.maxs[2] - g_Player[Index].Entity->curstate.mins[2] ) < 54;
	}

	bool PlayerInfo::isValid ( int Index )
	{
		if ( g_Vars.main.player_valid_check == 1 )
		{
			return g_Player[Index].Entity->curstate.movetype && g_Player[Index].Entity->curstate.movetype != 6 &&
				!( g_Local.Entity->curstate.iuser1 == 4 && g_Local.Entity->curstate.iuser2 == Index ) &&
				!( g_Player[Index].Entity->curstate.messagenum < g_Local.Entity->curstate.messagenum );
		}
		else if ( g_Vars.main.player_valid_check == 2 )
		{
			return g_Local.Entity && g_Player[Index].Entity->curstate.movetype &&
				!( g_Local.Entity->curstate.iuser1 == 4 && g_Local.Entity->curstate.iuser2 == Index ) &&
				!( g_Player[Index].Entity->curstate.messagenum < g_Local.Entity->curstate.messagenum );
		}

		return 0;
	}

	bool _fastcall PlayerInfo::ScanVisibility ( int Index )
	{
		if ( g_Vars.main.player_scan_visibility == 1 )
		{
			if ( g_Util.PathFree ( g_Player[Index].Bone[17] ) )
			{
				return true;
			}
		}
		else if ( g_Vars.main.player_scan_visibility == 2 )
		{
			static BYTE HitBoxCheckVisible[8] = { 0, 2, 6, 7, 8, 9, 11, 19 };

			for ( BYTE i = 0; i < sizeof ( HitBoxCheckVisible ); ++i )
			{
				if ( g_Util.PathFree ( g_Player[Index].HitBox[HitBoxCheckVisible[i]] ) )
				{
					return true;
				}
			}
		}
		else if ( g_Vars.main.player_scan_visibility == 3 )
		{
			static BYTE HitBoxCheckVisible[21] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

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

	float PlayerInfo::GetGroundAngle ( )
	{
		Vector tmp = Engine::g_pPlayerMove->origin;

		tmp[2] = -4096;

		pmtrace_t *trace = Engine::g_Engine.PM_TraceLine ( Engine::g_pPlayerMove->origin, tmp, 1, ( Engine::g_pPlayerMove->flags & FL_DUCKING ) ? 1 : 0, -1 );

		return acos ( trace->plane.normal[2] ) / M_PI * 180;
	}

	void PlayerInfo::GetHeightGround ( )
	{
		Vector tmp = Engine::g_pPlayerMove->origin;

		tmp[2] = -4096;

		pmtrace_t *trace = Engine::g_Engine.PM_TraceLine ( Engine::g_pPlayerMove->origin, tmp, 1, ( Engine::g_pPlayerMove->flags & FL_DUCKING ) ? 1 : 0, -1 );

		g_Local.HeightGround = Engine::g_pPlayerMove->origin.z - trace->endpos.z;

		pmtrace_t PlayerTrace;

		Engine::g_Engine.pEventAPI->EV_SetTraceHull ( Engine::g_pPlayerMove->flags & FL_DUCKING ? 1 : 0 );
		Engine::g_Engine.pEventAPI->EV_PlayerTrace ( Engine::g_pPlayerMove->origin, trace->endpos, PM_GLASS_IGNORE | PM_STUDIO_BOX, g_Local.Index, &PlayerTrace );

		if ( PlayerTrace.fraction < 1.0f )
		{
			g_Local.HeightGround = PlayerTrace.endpos.z - Engine::g_pPlayerMove->origin.z;

			int id = Engine::g_Engine.pEventAPI->EV_IndexFromTrace ( &PlayerTrace );

			if ( id >= 1 && id <= Engine::g_Engine.GetMaxClients ( ) )
			{
				float distance = Engine::g_pPlayerMove->origin.z - ( ( Engine::g_pPlayerMove->flags & FL_DUCKING ?
					1 : 0 ) == 0 ? 32 : 18 ) - g_Player[id].Entity->origin.z - g_Local.HeightGround;

				if ( distance < 30 )
				{
					g_Local.HeightGround -= 14;
				}
			}
		}

		Vector tmp_hull = Engine::g_pPlayerMove->origin; tmp_hull[2] = -4096;

		pmtrace_t *trace_hull = Engine::g_Engine.PM_TraceLine ( Engine::g_pPlayerMove->origin, tmp_hull, 1, 2, -1 );

		g_Local.HeightPlane = Engine::g_pPlayerMove->origin.z - trace_hull->endpos.z - ( Engine::g_pPlayerMove->usehull == 1 ? 18 : 36 );

		g_Local.Height = g_Local.HeightGround;

		if ( g_Local.GroundAngle >= 0.1f )
		{
			if ( ( g_Local.HeightPlane - g_Local.HeightGround ) <= 20 )
			{
				g_Local.Height = g_Local.HeightPlane;
			}
		}
	}

	float PlayerInfo::GetEdgeDistance ( )
	{
		float mind = 250;

		TraceEdge ( -1, 0 );
		TraceEdge ( 1, 0 );
		TraceEdge ( 0, 1 );
		TraceEdge ( 0, -1 );
		TraceEdge ( -1, -1 );
		TraceEdge ( 1, 1 );
		TraceEdge ( 1, -1 );
		TraceEdge ( -1, 1 );

		return mind;
	}

	float PlayerInfo::GetFallDamage ( )
	{
		return g_Util.EndSpeed ( Engine::g_pPlayerMove->flFallVelocity, 
			Engine::g_Engine.pfnGetGravity ( ), 0.01f, g_Local.Height ) - PLAYER_MAX_SAFE_FALL_SPEED;
	}

	void _fastcall PlayerInfo::UpdateLocalInfo ( )
	{
		g_Local.Entity = Engine::g_Engine.GetLocalPlayer ( );

		g_Local.FPS = 1 / g_Local.FrameTime;
	
		g_Local.GroundAngle = GetGroundAngle ( );
		g_Local.EdgeDistance = GetEdgeDistance ( );

		GetHeightGround ( );

		g_Local.FallDamage = ( GetFallDamage ( ) * DAMAGE_FOR_FALL_SPEED ) < 0 ? 0 : ( GetFallDamage ( ) * DAMAGE_FOR_FALL_SPEED );

		g_Local.Index = g_Local.Entity->index;

		g_Local.Alive = isAlive ( );

		Engine::g_Engine.pEventAPI->EV_LocalPlayerViewheight ( g_Local.ViewOrg );

		VectorAdd ( g_Local.Entity->origin, g_Local.ViewOrg, g_Local.ViewOrg );
	}

	void _fastcall PlayerInfo::UpdateInfoByIndex ( int Index )
	{
		Engine::g_Engine.pfnGetPlayerInfo ( Index, &g_Player[Index].Info );

		g_Player[Index].Entity = Engine::g_Engine.GetEntityByIndex ( Index );

		g_Player[Index].Valid = isValid ( Index );
		g_Player[Index].Ducked = isDucked ( Index );

		g_Player[Index].Visible = ScanVisibility ( Index );
	}

	void _fastcall PlayerInfo::HUD_Redraw ( )
	{
		UpdateLocalInfo ( );

		for ( BYTE Index = 1; Index <= Engine::g_Engine.GetMaxClients ( ); ++Index )
		{
			if ( Index != g_Local.Index )
			{
				UpdateInfoByIndex ( Index );
			}
		}
	}

	void _fastcall PlayerInfo::GetBoneOrigin ( struct cl_entity_s *Entity )
	{
		if ( g_Player[Entity->index].Valid )
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
		if ( g_Player[Entity->index].Valid )
		{
			Vector BBMin, BBMax;

			typedef float BoneMatrix_t[MAXSTUDIOBONES][3][4];

			model_t* Model = Engine::g_Studio.SetupPlayerModel ( Entity->index );
			studiohdr_t* StudioHeader = ( studiohdr_t* )Engine::g_Studio.Mod_Extradata ( Model );
			BoneMatrix_t* BoneMatrix = ( BoneMatrix_t* )Engine::g_Studio.StudioGetBoneTransform ( );
			mstudiobbox_t* Hitbox = ( mstudiobbox_t* )( ( BYTE* )StudioHeader + StudioHeader->hitboxindex );

			for ( BYTE i = 0; i < StudioHeader->numhitboxes; ++i )
			{
				VectorTransform ( Hitbox[i].bbmin, ( *BoneMatrix )[Hitbox[i].bone], BBMin );
				VectorTransform ( Hitbox[i].bbmax, ( *BoneMatrix )[Hitbox[i].bone], BBMax );

				g_Player[Entity->index].HitBox[i] = ( BBMax + BBMin ) / 2;
				g_Player[Entity->index].HitBox[i] = g_Player[Entity->index].HitBox[i];
			}
		}
	}

	PlayerInfo g_PlayerInfo;

	local_s g_Local;
	player_s g_Player[33];
}