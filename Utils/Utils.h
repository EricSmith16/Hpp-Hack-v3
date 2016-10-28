#pragma once

#include "Main.h"

pcmd_t CommandByName ( char* szName );
pfnUserMsgHook HookUserMsg ( char *szMsgName, pfnUserMsgHook pfn );
pfnEngineMsgHook HookEngineMsg ( char *MsgName, pfnEngineMsgHook pfn );

class Util
{
public:
	PCHAR _fastcall Util::itoa ( int i );

	static char* ConvertTypeToRenderString ( BYTE Type );

	static char* _fastcall native_strstr ( char *in, char *str );

	static float _fastcall Interp ( float s1, float s2, float s3, float f1, float f3 );

	static int _fastcall native_strcmp ( char const* _Str1, char const* _Str2, size_t MaxCount );

	static bool _fastcall CalcScreen ( float *pflOrigin, float *pflVecScreen );

	static bool _fastcall PathFree ( Vector Input );

	static void _fastcall MemoryCopy ( void * dst, const void * src, size_t count );
	static void _fastcall MemorySet ( void *Buffer, DWORD Len, DWORD Sym );

	static void _fastcall ConsolePrintColor ( BYTE R, BYTE G, BYTE B, char* String );
	static void _fastcall ConsolePrintColor ( BYTE R, BYTE G, BYTE B, DWORD String );
	static void _fastcall ConsolePrintColor ( BYTE R, BYTE G, BYTE B, BYTE String );
	static void _fastcall ConsolePrintColor ( BYTE R, BYTE G, BYTE B, int String );
	static void _fastcall ConsolePrintColor ( BYTE R, BYTE G, BYTE B, float String );

	static void Parse ( BYTE MaxArray, char *String, int Number[] );
	static void Parse ( BYTE MaxArray, char *String, BYTE Number[] );
};

extern Util g_Util;

extern char itoa_buffer[INT_DIGITS + 2];