#pragma once

#include "Main.h"

namespace Engine
{
	class Offset
	{
	private:
		DWORD HwDll, SwDll, HlMod;
		DWORD HwBase, HwSize, HwEnd;
		DWORD ClBase, ClSize, ClEnd;
		DWORD HlBase, HlSize, HlEnd;
		DWORD VgBase, VgSize, VgEnd;

		DWORD _fastcall FindString ( PCHAR String, DWORD Start, DWORD End, DWORD Offset );
		DWORD _fastcall FindPattern ( PCHAR Pattern, DWORD PtLen, DWORD Start, DWORD End, DWORD Offset );

		DWORD FindGameConsole ( );

		inline DWORD GetModuleSize ( DWORD Address );
		inline DWORD FindPushString ( DWORD Start, DWORD End, DWORD Address );
		inline DWORD FarProc ( DWORD Address, DWORD LB, DWORD HB );
		inline DWORD Absolute ( DWORD Address );

		ULONG _fastcall __findmemoryclone ( const ULONG Start, const ULONG End, const ULONG Clone, UINT Size );
		BOOL _fastcall __comparemem ( const UCHAR *Buff1, const UCHAR *Buff2, UINT Size );

		inline ULONG __findreference ( const ULONG Start, const ULONG End, const ULONG Address );	

		inline void GetRenderType ( );

	public:
		DWORD FindClientTable ( );
		DWORD FindEngineTable ( );
		DWORD FindStudioTable ( );
		DWORD FindUserMsgBase ( );
		DWORD FindSVCMessages ( );

		PVOID PlayerMovePtr ( );

		int HLType;

		bool GetModuleInfo ( );

		void Error ( bool Exit, char* Message, ... );
		void ConsoleColorInitalize ( );
		void GetGameInfo ( pGameInfo_s GameInfo );
	};

	extern Offset g_Offset;
}