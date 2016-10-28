#pragma once

#include "Main.h"

namespace Functions
{
	class ESP
	{
	private:
		static int EntityIndex, SoundIndex;

		inline static float GetPlayerDistance ( int Index, bool Meters );
		inline static void GetColorPlayerBox ( int Index );

		static void _fastcall AddEntity ( char* Name, int Important, Vector Origin, BYTE Type );

		static void _fastcall ClearEntity ( );
		static void _fastcall ClearSound ( );

		inline static void Panic ( bool enabled );

	public:
		static bool PanicEnabled;

		static void _fastcall DrawPlayer ( int Index );
		static void _fastcall DrawWorld ( );
		static void _fastcall DrawSound ( );

		static void _fastcall AddSound ( DWORD Time, Vector Origin );

		static void PanicKey ( int keynum );

		static void _fastcall HUD_AddEntity ( struct cl_entity_s *Entity );
	};

	extern ESP g_ESP;

	struct sound_s
	{
		Vector Origin;
		DWORD Time;
	};

	extern sound_s Sound[MAX_SOUNDS];

	struct entity_s
	{
		char Name[64];
		Vector Origin;
		int Important;
		BYTE Type;
	};

	extern entity_s Entity[MAX_ENTITY];

	struct player_box_s
	{
		BYTE color[3];
	};

	extern player_box_s player_box;
}