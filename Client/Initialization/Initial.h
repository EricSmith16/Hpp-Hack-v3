#pragma once

#include "Main.h"

namespace Initial
{
	class Init
	{
	private:
		inline void FilesCheck ( );

		inline void CreateFileFunctions ( );
		inline void CreateFileMain ( );	
		inline void CreateFileVisuals ( );
		inline void CreateFileMisc ( );
		inline void CreateFileAutoRun ( );

		inline void LoadFileFunctions ( );
		inline void LoadFileMain ( );
		inline void LoadFileVisuals ( );
		inline void LoadFileMisc ( );
		inline void LoadFileAutoRun ( );

		inline void SaveFileMain ( );
		inline void SaveFileVisuals ( );
		inline void SaveFileMisc ( );

	public:
		void _fastcall InitHack ( );

		void _fastcall LoadSettings ( );
		void _fastcall SaveSettings ( );
		void _fastcall ReloadSettings ( );
	};

	extern Init g_Init;
}