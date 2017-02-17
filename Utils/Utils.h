#pragma once

#include "Main.h"

pcmd_t CommandByName ( char* szName );
pfnUserMsgHook HookUserMsg ( char *szMsgName, pfnUserMsgHook pfn );
pfnEngineMsgHook HookEngineMsg ( char *MsgName, pfnEngineMsgHook pfn );

class Util
{
public:
	char *Prefix;

	char* _fastcall ConvertTypeToRenderString ( BYTE Type );
	char* _fastcall PrefHack ( char *sz1, char *sz2, char *sz3 );
	char* _fastcall NativeStrStr ( char *in, char *str );

	float _fastcall Interp ( float s1, float s2, float s3, float f1, float f3 );
	float _fastcall EndSpeed ( float StartSpeed, float Gravity, float FrameTime, float Distance );

	int _fastcall native_strcmp ( char const* _Str1, char const* _Str2, size_t MaxCount );

	bool _fastcall CalcScreen ( float *pflOrigin, float *pflVecScreen );
	bool _fastcall PathFree ( Vector Input );

	void _fastcall MemoryCopy ( void * dst, const void * src, size_t count );
	void _fastcall MemorySet ( void *buffer, DWORD len, DWORD sym );

	void _fastcall ConsolePrintColor ( BYTE R, BYTE G, BYTE B, char* String );
	void _fastcall ConsolePrintColor ( BYTE R, BYTE G, BYTE B, DWORD String );
	void _fastcall ConsolePrintColor ( BYTE R, BYTE G, BYTE B, BYTE String );
	void _fastcall ConsolePrintColor ( BYTE R, BYTE G, BYTE B, int String );
	void _fastcall ConsolePrintColor ( BYTE R, BYTE G, BYTE B, float String );
	void _fastcall ConsolePrintColor_int ( BYTE R, BYTE G, BYTE B, float String );

	void _fastcall Parse ( BYTE MaxArray, char *String, float Number[] );
	void _fastcall Parse ( BYTE MaxArray, char *String, BYTE Number[] );

	void _fastcall StrReplace ( char* buf, const char* search, const char* replace );

	void _fastcall MyVectorAngles ( const float *Forward, float *Angles );
	void _fastcall RotateInvisible ( float FixedYaw, float FixedPitch, usercmd_s *cmd );
	void _fastcall SlowHorizontalVelocity ( float to, float frametime, usercmd_s *cmd );

	void _fastcall RunScript ( char *ScriptName );

	void _fastcall HookCommand ( char *CmdName, xcommand_t *CmdPointer, void ( *Function )( void ) );
};

extern Util g_Util;