#pragma once

#include "Main.h"

namespace Functions
{
	namespace Visuals
	{
		struct M_Entry
		{
			char Name[32];

			BYTE Color[3];

			bool Space, Value, Active;
		};

		struct S_Entry
		{
			char Name[32];

			float *Value, Step;
			float Min, Max;

			bool Float, Space;
		};

		class Menu
		{
		private:
			inline void Add ( char* Name, BYTE Red, BYTE Green, BYTE Blue, bool Space, bool Active );
			inline void AddSub ( char* Name, float* Value, float Min, float Max, float Step, bool Float, bool Space );

			inline void Clear ( );

		public:
			Menu ( );

			M_Entry MenuEntry[MAX_MENU_COUNT];
			S_Entry SubmEntry[MAX_SUB_MENU_COUNT];

			short M_EntryPos, M_EntrySize;
			short S_EntryPos, S_EntrySize;

			bool SubMenu, Visible;

			void _fastcall Initialize ( );

			void _fastcall Draw ( int Pos_x, int Pos_y );

			void _fastcall HUD_Key_Event ( int keynum );
		};

		extern Menu g_Menu;
	}
}