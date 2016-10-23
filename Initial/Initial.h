#pragma once

#include "Main.h"

namespace Initial
{
	class Init
	{
	private:
		static bool PanicEnabled;

		inline void ReloadSettings ( );
		inline void Panic ( bool enabled );

	public:
		void InitHack ( );

		void LoadSettings ( );

		void ReloadKey ( int keynum );
		void PanicKey ( int keynum );
	};

	extern Init g_Init;
}