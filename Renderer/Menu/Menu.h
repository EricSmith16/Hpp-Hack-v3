#pragma once

#include "Main.h"

namespace Renderer
{
	struct m_entry
	{
		char Name[32];

		BYTE Color[3];
	};

	struct s_entry
	{
		char Name[32];
		char* Help;

		int* Value;
		int Min;
		int Max;
		int Step;
	};

	class Menu
	{
	private:
		HANDLE Heap;
		PCHAR Value;

		DWORD LastSaveTime;
		DWORD LastLoadTime;

		int M_EntryPos;
		int M_EntrySize;

		int S_EntryPos;
		int S_EntrySize;

		bool SubMenu;
		bool Help;

		m_entry menu_entry[MAX_MENU_COUNT];
		s_entry subm_entry[MAX_SUB_MENU_COUNT];

		void Add ( char* Name, BYTE r, BYTE g, BYTE b );
		void AddSub ( char* Name, int* Value, int Min, int Max, int Step, char* Help );

		void Clear ( );

	public:
		bool Visible;
		bool DisableReload;
		bool ExitMenu;

		Menu ( );

		void Initialize ( );

		void Draw ( int x, int y );
		void KeyEvent ( int keynum );
	};

	extern Menu g_Menu;
}