#pragma once

#include "Main.h"

namespace Client
{
	class Hpp
	{
	private:
		static int HUD_AddEntity ( int type, struct cl_entity_s *ent, const char *modelname );
		static int HUD_Key_Event ( int down, int keynum, const char *pszCurrentBinding );

		static void HUD_Frame ( double time );
		static void HUD_Redraw ( float time, int intermission );
		static void StudioEntityLight ( struct alight_s *plight );

		inline static void HookUserMessages ( );
		inline static void HookEngineMessages ( );

	public:
		static bool FirstFrame;

		static void HookStudio ( );
		static void HookFunction ( );	
	};

	extern Hpp g_Hpp;

	extern GameInfo_t BuildInfo;
}