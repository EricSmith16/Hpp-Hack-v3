#pragma once

#include "Main.h"

namespace Information
{
	struct bomb_s
	{
		float C4Timer;

		bool isPlanted;
	};

	struct local_s
	{
		bomb_s Bomb;
		cl_entity_s *Entity;	

		Vector ViewOrg;

		DWORD SpeedPtr, Speed;

		double *g_Net;

		float FrameTime, FPS;
		float GroundAngle, HeightGround;
		float HeightPlane, Height;
		float EdgeDistance, FallDamage;
		float EdgeOffset;

		int Team, Index;

		bool Alive, SlowDown;
	};

	extern local_s g_Local;

	struct player_s
	{
		hud_player_info_t Info;
		cl_entity_s *Entity;	

		Vector Bone[53], HitBox[21];

		int Team;

		bool Valid, Visible, Ducked;
	};

	extern player_s g_Player[33];

	class PlayerInfo
	{
	private:
		inline float GetGroundAngle ( );	
		inline float GetEdgeDistance ( );
		inline float GetFallDamage ( );
		inline void GetHeightGround ( );

		inline bool isAlive ( );
		inline bool isDucked ( int Index );
		inline bool isValid ( int Index );

		bool _fastcall ScanVisibility ( int Index );

	public:
		void _fastcall UpdateLocalInfo ( );
		void _fastcall UpdateInfoByIndex ( int Index );

		void _fastcall GetBoneOrigin ( struct cl_entity_s *Entity );
		void _fastcall GetHitboxOrigin ( struct cl_entity_s *Entity );

		void _fastcall HUD_Redraw ( );
	};

	extern PlayerInfo g_PlayerInfo;
}