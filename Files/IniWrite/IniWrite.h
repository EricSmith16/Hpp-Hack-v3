#pragma once

#include "Main.h"

namespace Files
{
	class IniWrite
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
	};

	extern IniWrite g_IniWrite;
}