#pragma once

#include "Main.h"

namespace Initial
{
	class Init
	{
	private:
		inline void CreateFileFunctions ( );
		inline void CreateFileMain ( );	
		inline void CreateFileVisuals ( );
		inline void CreateFileMisc ( );
		inline void CreateFileAutoRun ( );

	public:
		void _fastcall InitHack ( );

		void _fastcall LoadSettings ( );
		void _fastcall SaveSettings ( );
		void _fastcall ReloadSettings ( );

		void _fastcall RunScript ( char *ScriptName );
	};

	extern Init g_Init;
}