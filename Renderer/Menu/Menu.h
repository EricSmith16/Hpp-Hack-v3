#pragma once

#include "Main.h"

namespace Functions
{
	namespace Visuals
	{
		struct m_entry
		{
			char Name[32];

			BYTE Color[3];

			bool Space, Value, Active;
		};

		struct s_entry
		{
			char Name[32], *Help;

			float *Value, Step;
			float Min, Max;

			bool bFloat, Space;
		};

		class Menu
		{
		private:
			bool Visible, ExitMenu;

			void Add ( char* Name, BYTE r, BYTE g, BYTE b, bool Space, bool Active );
			void AddSub ( char* Name, float* Value, float Min, float Max, float Step, char* Help, bool bFloat, bool Space );

			void Clear ( );

		public:
			Menu ( );

			m_entry MenuEntry[MAX_MENU_COUNT];
			s_entry SubmEntry[MAX_SUB_MENU_COUNT];

			int M_EntryPos, M_EntrySize;
			int S_EntryPos, S_EntrySize;

			bool SubMenu;

			void Initialize ( );

			void Draw ( int x, int y );

			void Menu_KeyEvent ( int keynum );
		};

		extern Menu g_Menu;
	}
}