#pragma once

#include "Main.h"

namespace Information
{
	class PlayerInfo
	{
	private:
		inline static bool isAlive ( struct cl_entity_s *Entity );
		inline static bool isValid ( int Index );
		inline static bool isDucked ( int Index );

		static bool ScanVisibility ( int Index );

	public:
		static void _fastcall UpdateLocalInfo ( );
		static void _fastcall UpdateInfoByIndex ( int Index );
		static void _fastcall GetBoneOrigin ( struct cl_entity_s *Entity );
		static void _fastcall GetHitboxOrigin ( struct cl_entity_s *Entity );
	};

	extern PlayerInfo g_PlayerInfo;

	struct local_s
	{
		cl_entity_s *Entity;
		playermove_t *ppmove;

		Vector ViewOrg;

		int Team;

		bool Alive;
	};

	extern local_s g_Local;

	struct player_s
	{
		cl_entity_s *Entity;
		hud_player_info_t Info;

		Vector Bone[53], HitBox[21];

		int Team;

		bool Ducked, Valid;
		bool Visible, Alive;
	};

	extern player_s g_Player[33];
}