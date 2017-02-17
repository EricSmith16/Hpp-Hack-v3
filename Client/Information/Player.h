#pragma once

#include "Main.h"

namespace Info
{
	struct BombStruct
	{
		float C4Timer;

		bool isPlanted;
	};

	struct LocalPlayerStruct
	{
		Vector ViewOrg;
		
		DWORD Speed;

		int Team, Index;

		bool isAlive, OnSurf;
	};

	struct LocalStruct
	{
		LocalPlayerStruct Player;
		BombStruct Bomb;

		cl_entity_s *Entity;

		Vector Angles, Forward, Right, Up;

		double *g_Net;

		float FPS, FrameTime, EdgeDistance;
		float GroundAngle, FallDamage, AngleSpeed;
		float HeightGround, HeightPlane, Height;
	};

	extern LocalStruct g_Local;

	struct PlayerStruct
	{
		hud_player_info_t Info;
		cl_entity_s *Entity;	

		Vector Bone[53], HitBox[21];

		int Team;

		bool Valid, Visible, Ducked;
	};

	extern PlayerStruct g_Player[33];

	class PlayerInfo
	{
	private:	
		inline void GetGroundAngle ( );
		inline void GetHeightGround ( );
		inline void GetEdgeDistance ( );
		inline void GetFallDamage ( );

		inline void isAliveEntity ( );
		inline void isValidEntity ( uint8 Index );
		inline void isDuckedEntity ( uint8 Index );
		inline void isVisibleEntity ( uint8 Index );

		inline void UpdateLocalInfo ( );
		inline void UpdateInfoByIndex ( uint8 Index );

		inline void GetBoneOrigin ( cl_entity_s *Entity );
		inline void GetHitBoxOrigin ( cl_entity_s *Entity );

	public:		
		void _fastcall HUD_Redraw ( );
		void _fastcall StudioEntityLight ( );
	};

	extern PlayerInfo g_PlayerInfo;
}