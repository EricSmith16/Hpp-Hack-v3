#include "Main.h"

namespace Engine
{
	PColor24 Console_TextColor;
	SCREENINFO g_Screen;
	PUserMsg g_pUserMsgBase;
	PEngineMsg g_pEngineMsgBase;

	cl_clientfunc_t *g_pClient = nullptr;
	cl_enginefunc_t *g_pEngine = nullptr;
	engine_studio_api_t *g_pStudio = nullptr;
	screenfade_t *g_pScreenFade = nullptr;
	playermove_t *g_pPlayerMove = nullptr;

	cl_clientfunc_t g_Client;
	cl_enginefunc_t g_Engine;
	engine_studio_api_t g_Studio;

	char* BaseDir;
}

DWORD WINAPI ProcessReload ( LPVOID lpThreadParameter );

DWORD WINAPI CheatEntry ( LPVOID lpThreadParameter )
{
	static HANDLE ProcessReloadThread = 0;

	if ( ProcessReloadThread )
	{
		TerminateThread ( ProcessReloadThread, 0 );
		CloseHandle ( ProcessReloadThread );
	}

	BYTE FindCounter = 0;

StartHook:

	if ( FindCounter == FIND_COUNTER_VALUE )
	{
		if ( !Engine::g_pClient )
		{
			Engine::g_Offset.Error ( true, CLIENT_FIND_ERROR );
		}

		if ( !Engine::g_pEngine )
		{
			Engine::g_Offset.Error ( true, ENGINE_FIND_ERROR );
		}

		if ( !Engine::g_pStudio )
		{
			Engine::g_Offset.Error ( true, STUDIO_FIND_ERROR );
		}

		if ( !Engine::g_pPlayerMove )
		{
			Engine::g_Offset.Error ( true, PPMOVE_PTR_ERROR );
		}

		if ( !Engine::g_pUserMsgBase )
		{
			Engine::g_Offset.Error ( true, USERMSG_ERROR );
		}

		if ( !Engine::g_pEngineMsgBase )
		{
			Engine::g_Offset.Error ( true, ENGINE_MSG_BASE );
		}
	}

	Sleep ( 50 );

	++FindCounter;

	if ( Engine::g_Offset.GetModuleInfo ( ) )
	{
		DWORD ClientTable = Engine::g_Offset.FindClientTable ( );

		if ( ClientTable )
		{
			Engine::g_pClient = ( cl_clientfunc_t* )ClientTable;

			g_Util.MemoryCopy ( &Engine::g_Client, Engine::g_pClient, sizeof ( cl_clientfunc_t ) );

			if ( Engine::g_Client.Initialize )
			{
				DWORD EngineTable = Engine::g_Offset.FindEngineTable ( );

				if ( EngineTable )
				{
					Engine::g_pEngine = ( cl_enginefunc_t* )EngineTable;

					g_Util.MemoryCopy ( &Engine::g_Engine, Engine::g_pEngine, sizeof ( cl_enginefunc_t ) );

					if ( Engine::g_Engine.V_CalcShake )
					{
						DWORD StudioTable = Engine::g_Offset.FindStudioTable ( );

						if ( StudioTable )
						{
							Engine::g_pStudio = ( engine_studio_api_t* )StudioTable;

							g_Util.MemoryCopy ( &Engine::g_Studio, Engine::g_pStudio, sizeof ( engine_studio_api_t ) );

							if ( Engine::g_Studio.StudioSetupSkin )
							{
								DWORD PlayerMove = ( DWORD )Engine::g_Offset.PlayerMove ( );

								if ( PlayerMove )
								{
									Engine::g_pPlayerMove = ( playermove_t* )PlayerMove;

									DWORD UserMsg = Engine::g_Offset.FindUserMsgBase ( );

									if ( UserMsg )
									{
										Engine::g_pUserMsgBase = ( PUserMsg )UserMsg;

										DWORD EngineMsg = Engine::g_Offset.FindSVCMessages ( );

										if ( EngineMsg )
										{
											Engine::g_pEngineMsgBase = ( PEngineMsg )EngineMsg;

											while ( !Client::g_Hpp.FirstFrame )
											{
												Client::g_Hpp.HookFunction ( );
												Client::g_Hpp.HookStudio ( );

												Sleep ( 50 );
											}

											ProcessReloadThread = CreateThread ( 0, 0, ProcessReload, 0, 0, 0 );
										}
										else
										{
											goto StartHook;
										}
									}
									else
									{
										goto StartHook;
									}
								}
								else
								{
									goto StartHook;
								}
							}
							else
							{
								goto StartHook;
							}
						}
						else
						{
							goto StartHook;
						}
					}
					else
					{
						goto StartHook;
					}
				}
				else
				{
					goto StartHook;
				}
			}
			else
			{
				goto StartHook;
			}
		}
		else
		{
			goto StartHook;
		}
	}
	else
	{
		goto StartHook;
	}

	return 0;
}

DWORD WINAPI ProcessReload ( LPVOID lpThreadParameter )
{
	while ( true )
	{
		if ( Client::g_Hpp.FirstFrame )
		{
			if ( !Engine::g_Offset.GetModuleInfo ( ) )
			{
				Client::g_Hpp.FirstFrame = false;
			}
		}
		else
		{
			CreateThread ( 0, 0, CheatEntry, 0, 0, 0 );
		}

		Sleep ( 50 );
	}

	return 0;
}

BOOL WINAPI DllMain ( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved )
{
	if ( fdwReason == DLL_PROCESS_ATTACH )
	{
		DisableThreadLibraryCalls ( hinstDLL );

		Engine::BaseDir = ( char* )HeapAlloc ( GetProcessHeap ( ), HEAP_ZERO_MEMORY, MAX_PATH );

		GetModuleFileName ( hinstDLL, Engine::BaseDir, MAX_PATH );

		char* Position = Engine::BaseDir + lstrlen ( Engine::BaseDir );

		while ( Position >= Engine::BaseDir && *Position != '\\' )
		{
			--Position;
		}

		Position[1] = 0;

		CreateThread ( 0, 0, CheatEntry, 0, 0, 0 );

		return TRUE;
	}

	return FALSE;
}