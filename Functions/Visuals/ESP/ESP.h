#pragma once

#include "Main.h"

namespace Functions
{
	namespace Visuals
	{
		class ESP
		{
		private:
			unsigned short int EntityIndex, SoundIndex;

			BYTE BoxColor[3];

			inline float GetPlayerDistance ( BYTE Index, bool Meters );
			inline void GetColorPlayerBox ( BYTE Index );

			inline void DrawPlayer ( BYTE Index );
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

			BYTE Type;
		};

		extern entity_s Entity[MAX_ENTITY];
	}
}