#pragma once

#include "Main.h"

namespace Files
{
	class IniWrite
	{
	public:
		void _fastcall Camera ( );
		void _fastcall StrafeHelper ( );
		void _fastcall EdgeBug ( );
		void _fastcall JumpBug ( );
		void _fastcall Speed ( );
		void _fastcall GStrafe ( );
		void _fastcall BunnyHop ( );
		void _fastcall ScreenInfo ( );
		void _fastcall NoFlash ( );
		void _fastcall ESP ( );
		void _fastcall Main ( );
		void _fastcall Menu ( );
	};

	extern IniWrite g_IniWrite;
}