#pragma once

#include "Main.h"

namespace Files
{
	class IniRead
	{
	public:
		void EdgeBug ( );
		void JumpBug ( );
		void Speed ( );
		void GStrafe ( );
		void BHop ( );
		void ScreenInfo ( );
		void NoFlash ( );
		void ESP ( );
		void Main ( );
		void Menu ( );
		void Functions ( );
	};

	extern IniRead g_IniRead;
}