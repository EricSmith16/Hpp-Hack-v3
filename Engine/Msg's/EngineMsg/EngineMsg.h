#pragma once

#include "Main.h"

namespace Engine
{
	class EngineMsg
	{
	public:
		static void MSG_SaveReadCount ( );
		static void MSG_RestoreReadCount ( );

		static void SVC_Sound ( );
		static void SVC_SpawnStaticSound ( );
		static void SVC_NewUserMsg ( );
		static void SVC_UpdateUserInfo ( );
		static void SVC_StuffText ( );
		static void SVC_SendCvarValue ( );
		static void SVC_SendCvarValue2 ( );
		static void SVC_Director ( );
	};

	extern EngineMsg g_EngineMsg;

	typedef byte ( *HL_MSG_ReadByte )( );
	typedef short ( *HL_MSG_ReadShort )( );
	typedef int ( *HL_MSG_ReadLong )( );
	typedef float ( *HL_MSG_ReadFloat )( );
	typedef char* ( *HL_MSG_ReadString )( );
	typedef float ( *HL_MSG_ReadCoord )( );
	typedef void ( *HL_MSG_ReadBitVec3Coord )( float* fa );
	typedef int ( *HL_MSG_ReadBits )( int Count );
	typedef void ( *HL_MSG_StartBitReading )( sizebuf_t* buffer );
	typedef void ( *HL_MSG_EndBitReading )( sizebuf_t* buffer );

	extern int* MSG_ReadCount;
	extern int* MSG_CurrentSize;
	extern int* MSG_BadRead;

	extern int MSG_SavedReadCount;

	extern sizebuf_t* MSG_Buffer;

	extern HL_MSG_ReadByte MSG_ReadByte;
	extern HL_MSG_ReadShort MSG_ReadShort;
	extern HL_MSG_ReadLong MSG_ReadLong;
	extern HL_MSG_ReadFloat MSG_ReadFloat;
	extern HL_MSG_ReadString MSG_ReadString;
	extern HL_MSG_ReadCoord MSG_ReadCoord;
	extern HL_MSG_ReadBitVec3Coord MSG_ReadBitVec3Coord;
	extern HL_MSG_ReadBits MSG_ReadBits;
	extern HL_MSG_StartBitReading MSG_StartBitReading;
	extern HL_MSG_EndBitReading MSG_EndBitReading;

	extern pfnEngineMsgHook pSVC_sound;
	extern pfnEngineMsgHook pSVC_SpawnStaticSound;
	extern pfnEngineMsgHook pSVC_NewUserMsg;
	extern pfnEngineMsgHook pSVC_UpdateUserInfo;
	extern pfnEngineMsgHook pSVC_StuffText;
	extern pfnEngineMsgHook pSVC_SendCvarValue;
	extern pfnEngineMsgHook pSVC_SendCvarValue2;
	extern pfnEngineMsgHook pSVC_Director;
}