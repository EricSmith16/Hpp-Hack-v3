#pragma once

#include "Main.h"

namespace Initial
{
	class Init
	{
	private:
		static bool PanicEnabled;

		inline static void ReloadSettings ( );
		inline static void Panic ( bool enabled );

	public:
		static void InitHack ( );
		static void LoadSettings ( );

		static void ReloadKey ( int keynum );
		static void PanicKey ( int keynum );
	};

	extern Init g_Init;
}