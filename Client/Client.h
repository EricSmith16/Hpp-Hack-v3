#pragma once

#include "Main.h"

namespace Client
{
	class Hpp
	{
	private:
		static int UpdateCurrent, UpdateLast;
		static int ScreenTimer;

		static bool GameActive;	

		inline static void HookedJumpPressed ( );
		inline static void HookedJumpReleased ( );

		inline static void HookedDuckPressed ( );
		inline static void HookedDuckReleased ( );

		inline static void AntiSnapShot ( );
		inline static void AntiScreenShot ( );

		inline static void ResetFadeColor ( );

		static int CL_IsThirdPerson ( );

		static int HUD_AddEntity ( int type, cl_entity_s *ent, const char *modelname );
		static int HUD_Key_Event ( int down, int keynum, const char *pszCurrentBinding );

		static void HUD_Frame ( double time );
		static void HUD_Redraw ( float time, int intermission );

		static void SetViewAngles ( float * Angles );

		static void CL_CreateMove ( float frametime, usercmd_s *cmd, int active );

		static void V_CalcRefdef ( ref_params_s *pparams );

		static void StudioEntityLight ( alight_s *plight );

		inline static void HookUserMessages ( );
		inline static void HookEngineMessages ( );

	public:
		static float LastScrollTime[2];

		static int ScrollCounter[2];

		static bool FirstFrame, PanicEnabled;
		static bool bSnapShot, bScreenShot;
		static bool JumpPressed, ScrollJump;
		static bool DuckPressed, ScrollDuck;

		static void _fastcall HookStudio ( );
		static void _fastcall HookFunction ( );
	};

	extern Hpp g_Hpp;

	extern GameInfo_t BuildInfo;
}