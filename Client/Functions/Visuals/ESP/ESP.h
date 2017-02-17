#pragma once

#include "Main.h"

namespace Functions
{
	namespace Visuals
	{
		struct SoundStruct
		{
			Vector Origin;

			DWORD Time;
		};

		extern SoundStruct Sound[MAX_SOUNDS];

		struct EntityStruct
		{
			char Name[64];

			Vector Origin;

			BYTE Type;
		};

		extern EntityStruct Entity[MAX_ENTITY];

		class ESP
		{
		private:
			unsigned short EntityIndex, SoundIndex;

			BYTE BoxColor[3];

			inline float GetPlayerDistance ( uint8 Index, bool Meters );
			inline void GetColorPlayerBox ( uint8 Index );

			inline void ItemWeaponPars ( char* Weapon, unsigned short Index );
			inline void ItemWeaponParsC4 ( unsigned short Index );
			inline void ItemWeaponParsC4Planted ( unsigned short Index );

			inline void DrawPlayer ( uint8 Index );
			inline void DrawWorld ( );
			inline void DrawSound ( );
			inline void DrawC4Timer ( );

			inline void AddEntity ( char* Name, Vector Origin, BYTE Type );

			inline void ClearEntity ( );
			inline void ClearSound ( );

		public:
			ESP ( );

			static bool PanicEnabled;

			void _fastcall PanicKey ( int keynum );

			void _fastcall AddSound ( DWORD Time, Vector Origin );

			void _fastcall HUD_AddEntity ( cl_entity_s *Entity );
			void _fastcall HUD_Redraw ( );
		};

		extern ESP g_ESP;
	}
}