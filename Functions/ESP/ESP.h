#pragma once

#include "Main.h"

namespace Functions
{
	class ESP
	{
	private:
		int EntityIndex, SoundIndex;

		//Get distance to player
		inline static float GetPlayerDistance ( struct cl_entity_s *Entity, struct cl_entity_s *Local, bool Meters );
		//Get player box color
		inline static void GetColorPlayerBox ( int Index );
		//Add entity
		inline static void AddEntity ( char* Name, int Important, Vector Origin, BYTE Type );
		//Clear all entities
		inline static void ClearEntity ( );
		//Clear all sounds
		inline static void ClearSound ( );

		inline static void Panic ( bool enabled );

	public:
		static bool PanicEnabled;

		//Drawing player esp
		static void DrawPlayer ( struct cl_entity_s *Entity, struct cl_entity_s *Local, int Index );
		//Drawing world esp
		static void DrawWorld ( );
		//Drawing sound esp
		static void DrawSound ( );
		//Add sound
		static void AddSound ( DWORD Time, Vector Origin );

		static void PanicKey ( int keynum );

		static void HUD_AddEntity ( struct cl_entity_s *Entity );
	};

	extern ESP g_ESP;

	struct sound_s
	{
		Vector Origin;
		DWORD Time;
	};

	extern sound_s sound[MAX_SOUNDS];

	struct entity_s
	{
		char Name[64];
		Vector Origin;
		int Important;
		BYTE Type;
	};

	extern entity_s entity[MAX_ENTITY];

	struct player_box_s
	{
		BYTE color[3];
	};

	extern player_box_s player_box;
}