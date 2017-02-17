#include "Player.h"

namespace Info
{
	void PlayerInfo::isAliveEntity ( )
	{
		g_Local.Player.isAlive = g_Local.Entity->curstate.movetype && g_Local.Entity->curstate.movetype != 6;
	}

	void PlayerInfo::isDuckedEntity ( uint8 Index )
	{
		g_Player[Index].Ducked = g_Player[Index].Entity->curstate.maxs[2] - g_Player[Index].Entity->curstate.mins[2] < 54;
	}

	void PlayerInfo::isValidEntity ( uint8 Index )
	{
		if ( g_Vars.Main.PlayerValidCheck == 1 )
		{
			g_Player[Index].Valid = g_Player[Index].Entity->curstate.movetype && g_Player[Index].Entity->curstate.movetype != 6 &&
				!( g_Local.Entity->curstate.iuser1 == 4 && g_Local.Entity->curstate.iuser2 == Index ) &&
				!( g_Player[Index].Entity->curstate.messagenum < g_Local.Entity->curstate.messagenum );
		}
		else if ( g_Vars.Main.PlayerValidCheck == 2 )
		{
			g_Player[Index].Valid = g_Local.Entity && g_Player[Index].Entity->curstate.movetype &&
				!( g_Local.Entity->curstate.iuser1 == 4 && g_Local.Entity->curstate.iuser2 == Index ) &&
				!( g_Player[Index].Entity->curstate.messagenum < g_Local.Entity->curstate.messagenum );
		}
	}

	void PlayerInfo::isVisibleEntity ( uint8 Index )
	{
		if ( g_Vars.Main.PlayerVisibleScan == 1 )
		{
			BYTE HitBoxCheckVisible[8] = { 0, 2, 6, 7, 8, 9, 11, 19 };

			for ( BYTE i = 0; i < sizeof ( HitBoxCheckVisible ); ++i )
			{
				if ( !g_Util.PathFree ( g_Player[Index].HitBox[HitBoxCheckVisible[i]] ) )
				{
					g_Player[Index].Visible = false;

					continue;
				}
				else
				{
					g_Player[Index].Visible = true;

					break;
				}
			}
		}
		else if ( g_Vars.Main.PlayerVisibleScan == 2 )
		{
			BYTE HitBoxCheckVisible[21] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

			for ( BYTE i = 0; i < sizeof ( HitBoxCheckVisible ); ++i )
			{
				if ( !g_Util.PathFree ( g_Player[Index].HitBox[HitBoxCheckVisible[i]] ) )
				{
					g_Player[Index].Visible = false;

					continue;
				}
				else
				{
					g_Player[Index].Visible = true;

					break;
				}
			}
		}
		else if ( !g_Vars.Main.PlayerVisibleScan )
		{
			g_Player[Index].Visible = false;
		}
	}

	void PlayerInfo::GetGroundAngle ( )
	{
		Vector Origin = Engine::g_pPlayerMove->origin;

		Origin[2] = -4096;

		pmtrace_t *Trace = Engine::g_Engine.PM_TraceLine ( Engine::g_pPlayerMove->origin, Origin, 1, Engine::g_pPlayerMove->flags & FL_DUCKING ? 1 : 0, -1 );

		g_Local.GroundAngle = acos ( Trace->plane.normal[2] ) / M_PI * 180;
	}

	void PlayerInfo::GetHeightGround ( )
	{
		Vector Origin = Engine::g_pPlayerMove->origin;

		Origin[2] = -4096;

		pmtrace_t *Trace = Engine::g_Engine.PM_TraceLine ( Engine::g_pPlayerMove->origin, Origin, 1,
			( Engine::g_pPlayerMove->flags & FL_DUCKING ) ? 1 : 0, -1 );

		g_Local.HeightGround = Engine::g_pPlayerMove->origin.z - Trace->endpos.z;

		pmtrace_t PlayerTrace;

		Engine::g_Engine.pEventAPI->EV_SetTraceHull ( Engine::g_pPlayerMove->flags & FL_DUCKING ? 1 : 0 );

		Engine::g_Engine.pEventAPI->EV_PlayerTrace ( Engine::g_pPlayerMove->origin, Trace->endpos,
			PM_GLASS_IGNORE | PM_STUDIO_BOX, g_Local.Player.Index, &PlayerTrace );

		if ( PlayerTrace.fraction < 1 )
		{
			g_Local.HeightGround = PlayerTrace.endpos.z - Engine::g_pPlayerMove->origin.z;

			uint8 Index = Engine::g_Engine.pEventAPI->EV_IndexFromTrace ( &PlayerTrace );

			if ( Index >= 1 && Index <= Engine::g_Engine.GetMaxClients ( ) )
			{
				float Distance = Engine::g_pPlayerMove->origin.z - ( ( Engine::g_pPlayerMove->flags & FL_DUCKING ?
					1 : 0 ) == 0 ? 32 : 18 ) - g_Player[Index].Entity->origin.z - g_Local.HeightGround;

				if ( Distance < 30 )
				{
					g_Local.HeightGround -= 14;
				}
			}
		}

		Vector OriginHull = Engine::g_pPlayerMove->origin;

		OriginHull[2] = -4096;

		pmtrace_t *TraceHull = Engine::g_Engine.PM_TraceLine ( Engine::g_pPlayerMove->origin, OriginHull, 1, 2, -1 );

		g_Local.HeightPlane = Engine::g_pPlayerMove->origin.z - TraceHull->endpos.z - ( Engine::g_pPlayerMove->usehull == 1 ? 18 : 36 );
		g_Local.Height = g_Local.HeightGround;

		if ( g_Local.GroundAngle >= 0.1f )
		{
			if ( ( g_Local.HeightPlane - g_Local.HeightGround ) <= 20 )
			{
				g_Local.Height = g_Local.HeightPlane;
			}
		}
	}

	void PlayerInfo::GetEdgeDistance ( )
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

		g_Local.EdgeDistance = mind;
	}

	void PlayerInfo::GetFallDamage ( )
	{
		float FallDamage = g_Util.EndSpeed ( Engine::g_pPlayerMove->flFallVelocity,
			Engine::g_Engine.pfnGetGravity ( ), 0.01f, g_Local.Height ) - PLAYER_MAX_SAFE_FALL_SPEED;

		g_Local.FallDamage = FallDamage * DAMAGE_FOR_FALL_SPEED < 0 ? 0 : FallDamage * DAMAGE_FOR_FALL_SPEED;
	}

	void PlayerInfo::UpdateLocalInfo ( )
	{
		g_Local.Entity = Engine::g_Engine.GetLocalPlayer ( );

		g_Local.FPS = 1 / g_Local.FrameTime;

		g_Local.AngleSpeed = ( g_Local.Angles )[1] - ( Engine::g_pPlayerMove->angles )[1];

		while ( g_Local.AngleSpeed < -180 )
		{
			g_Local.AngleSpeed += 360;
		}

		while ( g_Local.AngleSpeed > 180 )
		{
			g_Local.AngleSpeed -= 360;
		}

		g_Local.Angles = Engine::g_pPlayerMove->angles;

		g_Local.Player.Index = g_Local.Entity->index;

		isAliveEntity ( );

		GetGroundAngle ( );
		GetHeightGround ( );
		GetEdgeDistance ( );
		GetFallDamage ( );

		g_Local.Player.OnSurf = g_Local.GroundAngle > 45 && g_Local.HeightGround < 1;

		Engine::g_Engine.pEventAPI->EV_LocalPlayerViewheight ( g_Local.Player.ViewOrg );

		VectorAdd ( g_Local.Entity->origin, g_Local.Player.ViewOrg, g_Local.Player.ViewOrg );
	}

	void PlayerInfo::UpdateInfoByIndex ( uint8 Index )
	{
		Engine::g_Engine.pfnGetPlayerInfo ( Index, &g_Player[Index].Info );

		g_Player[Index].Entity = Engine::g_Engine.GetEntityByIndex ( Index );

		isValidEntity ( Index );
		isDuckedEntity ( Index );
		isVisibleEntity ( Index );
	}

	void PlayerInfo::GetBoneOrigin ( cl_entity_s *Entity )
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

	void PlayerInfo::GetHitBoxOrigin ( cl_entity_s *Entity )
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

	void _fastcall PlayerInfo::HUD_Redraw ( )
	{
		UpdateLocalInfo ( );

		for ( uint8 Index = 1; Index <= Engine::g_Engine.GetMaxClients ( ); ++Index )
		{
			if ( Index != g_Local.Player.Index )
			{
				UpdateInfoByIndex ( Index );
			}
		}
	}

	void _fastcall PlayerInfo::StudioEntityLight ( )
	{
		cl_entity_s *Entity = Engine::g_Studio.GetCurrentEntity ( );

		if ( Entity->player && Entity->index != g_Local.Player.Index && g_Player[Entity->index].Valid )
		{
			g_PlayerInfo.GetBoneOrigin ( Entity );
			g_PlayerInfo.GetHitBoxOrigin ( Entity );
		}
	}

	PlayerInfo g_PlayerInfo;

	LocalStruct g_Local;

	PlayerStruct g_Player[33];
}