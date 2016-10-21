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

		inline DWORD GetModuleSize ( DWORD Address );

		inline DWORD FindString ( PCHAR String, DWORD Start, DWORD End, DWORD Offset );
		inline DWORD FindPattern ( PCHAR Pattern, DWORD PtLen, DWORD Start, DWORD End, DWORD Offset );
		inline DWORD FindPushString ( DWORD Start, DWORD End, DWORD Address );

		inline DWORD FarProc ( DWORD Address, DWORD LB, DWORD HB );

		inline DWORD Absolute ( DWORD Address );

		inline DWORD FindGameConsole ( );

		inline ULONG __findmemoryclone ( const ULONG Start, const ULONG End, const ULONG Clone, UINT Size );
		inline ULONG __findreference ( const ULONG Start, const ULONG End, const ULONG Address );

		inline BOOL __comparemem ( const UCHAR *Buff1, const UCHAR *Buff2, UINT Size );

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