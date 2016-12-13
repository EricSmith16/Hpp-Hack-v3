#include "Utils.h"

#pragma warning (disable: 4996)

pcmd_t CommandByName ( char* szName )
{
	pcmd_t pCmd = Engine::g_Engine.pfnGetCmdList ( );

	while ( pCmd )
	{
		if ( !lstrcmp ( pCmd->name, szName ) )
		{
			return pCmd;
		}

		pCmd = pCmd->next;
	}

	return 0;
}

PUserMsg UserMsgByName ( char* szMsgName )
{
	PUserMsg Ptr = Engine::g_pUserMsgBase;

	while ( Ptr->next )
	{
		if ( !lstrcmp ( Ptr->name, szMsgName ) )
		{
			return Ptr;
		}

		Ptr = Ptr->next;
	}

	Ptr->pfn = 0;

	return Ptr;
}

pfnUserMsgHook HookUserMsg ( char *szMsgName, pfnUserMsgHook pfn )
{
	pfnUserMsgHook Original = nullptr;
	PUserMsg Ptr = UserMsgByName ( szMsgName );

	if ( Ptr->pfn )
	{
		Original = Ptr->pfn;
		Ptr->pfn = pfn;
	}

	return Original;
}

PEngineMsg EngineMsgByName ( char* MsgName )
{
	PEngineMsg Ptr = Engine::g_pEngineMsgBase;

	while ( lstrcmp ( Ptr->name, SVC_MESSAGES_PATTERN ) )
	{
		if ( !lstrcmp ( Ptr->name, MsgName ) )
		{
			return Ptr;
		}

		++Ptr;
	}

	Ptr->pfn = 0;

	return Ptr;
}

pfnEngineMsgHook HookEngineMsg ( char *MsgName, pfnEngineMsgHook pfn )
{
	pfnEngineMsgHook Original = nullptr;
	PEngineMsg Ptr = EngineMsgByName ( MsgName );

	if ( Ptr->pfn )
	{
		Original = Ptr->pfn;
		Ptr->pfn = pfn;
	}
	else
	{
		Engine::g_Offset.Error ( true, ENGINEMSG_ERROR, MsgName );
	}

	return Original;
}

void _fastcall Util::MemoryCopy ( void * dst, const void * src, size_t count )
{
	_asm
	{
		mov	edi, [dst]
		mov	esi, [src]
		mov	ecx, [count]
		rep	movsb
	}
}

void _fastcall Util::MemorySet ( void *buffer, DWORD len, DWORD sym )
{
	_asm
	{
		pushad
		mov edi, [buffer]
		mov ecx, [len]
		mov eax, [sym]
		rep stosb
		popad
	}
}


void _fastcall Util::ConsolePrintColor ( BYTE R, BYTE G, BYTE B, char* String )
{
	PColor24 Ptr = Engine::Console_TextColor;
	TColor24 DefaultColor = *Ptr;

	Ptr->R = R;
	Ptr->G = G;
	Ptr->B = B;

	Engine::g_Engine.Con_Printf ( "%s", String );

	*Ptr = DefaultColor;
}

void _fastcall Util::ConsolePrintColor ( BYTE R, BYTE G, BYTE B, DWORD String )
{
	PColor24 Ptr = Engine::Console_TextColor;
	TColor24 DefaultColor = *Ptr;

	Ptr->R = R;
	Ptr->G = G;
	Ptr->B = B;

	Engine::g_Engine.Con_Printf ( "%d", String );

	*Ptr = DefaultColor;
}

void _fastcall Util::ConsolePrintColor ( BYTE R, BYTE G, BYTE B, BYTE String )
{
	PColor24 Ptr = Engine::Console_TextColor;
	TColor24 DefaultColor = *Ptr;

	Ptr->R = R;
	Ptr->G = G;
	Ptr->B = B;

	Engine::g_Engine.Con_Printf ( "%d", String );

	*Ptr = DefaultColor;
}

void _fastcall Util::ConsolePrintColor ( BYTE R, BYTE G, BYTE B, int String )
{
	PColor24 Ptr = Engine::Console_TextColor;
	TColor24 DefaultColor = *Ptr;

	Ptr->R = R;
	Ptr->G = G;
	Ptr->B = B;

	Engine::g_Engine.Con_Printf ( "%d", String );

	*Ptr = DefaultColor;
}

void _fastcall Util::ConsolePrintColor ( BYTE R, BYTE G, BYTE B, float String )
{
	PColor24 Ptr = Engine::Console_TextColor;
	TColor24 DefaultColor = *Ptr;

	Ptr->R = R;
	Ptr->G = G;
	Ptr->B = B;

	Engine::g_Engine.Con_Printf ( "%.1f", String );

	*Ptr = DefaultColor;
}

void _fastcall Util::ConsolePrintColor_int ( BYTE R, BYTE G, BYTE B, float String )
{
	PColor24 Ptr = Engine::Console_TextColor;
	TColor24 DefaultColor = *Ptr;

	Ptr->R = R;
	Ptr->G = G;
	Ptr->B = B;

	Engine::g_Engine.Con_Printf ( "%.0f", String );

	*Ptr = DefaultColor;
}

char* _fastcall Util::ConvertTypeToRenderString ( BYTE Type )
{
	char* RenderTypeGL = "OpenGL";
	char* RenderTypeD3 = "D3D";
	char* RenderTypeSF = "Software";

	switch ( Type )
	{
	case 1:
		return RenderTypeSF;

	case 2:
		return RenderTypeGL;

	case 3:
		return RenderTypeD3;

	default:
		return "unknown";
	}
}

bool _fastcall Util::CalcScreen ( float *pflOrigin, float *pflVecScreen )
{
	int Result = Engine::g_Engine.pTriAPI->WorldToScreen ( pflOrigin, pflVecScreen );

	if ( pflVecScreen[0] < 1 && pflVecScreen[1] < 1 && pflVecScreen[0] > -1 && pflVecScreen[1] > -1 && !Result )
	{
		pflVecScreen[0] = pflVecScreen[0] * ( Engine::g_Screen.iWidth / 2 ) + ( Engine::g_Screen.iWidth / 2 );
		pflVecScreen[1] = -pflVecScreen[1] * ( Engine::g_Screen.iHeight / 2 ) + ( Engine::g_Screen.iHeight / 2 );

		return true;
	}

	return false;
}

bool _fastcall Util::PathFree ( Vector Input )
{
	pmtrace_t *Trace = Engine::g_Engine.PM_TraceLine ( Information::g_Local.ViewOrg, Input, 0, 2, -1 );

	return ( Trace->fraction >= 1.0f );
}

void _fastcall Util::Parse ( BYTE MaxArray, char *String, float Number[] )
{
	char* Parsing = strtok ( String, "," );

	BYTE i = 0;

	while ( Parsing && i <= ( MaxArray ) )
	{
		Number[i] = atoi ( Parsing );
		Parsing = strtok ( 0, "," );
		++i;
	}
}

void _fastcall Util::Parse ( BYTE MaxArray, char *String, BYTE Number[] )
{
	char* Parsing = strtok ( String, "," );

	BYTE i = 0;

	while ( Parsing && i <= ( MaxArray ) )
	{
		Number[i] = atoi ( Parsing );
		Parsing = strtok ( 0, "," );
		++i;
	}
}

int _fastcall Util::native_strcmp ( char const* _Str1, char const* _Str2, size_t MaxCount )
{
	if ( !MaxCount )
	{
		return 0;
	}

	while ( --MaxCount && *_Str1 && *_Str1 == *_Str2 )
	{
		++_Str1;
		++_Str2;
	}

	return *( BYTE * )_Str1 - *( BYTE * )_Str2;
}

char* _fastcall Util::native_strstr ( char *in, char *str )
{
	char c = *str++;

	if ( !c )
	{
		return ( char * )in;
	}

	size_t len = lstrlen ( str );

	do
	{
		char sc;

		do
		{
			sc = *in++;

			if ( !sc )
			{
				return ( char * )0;
			}
		} while ( sc != c );
	} while ( native_strcmp ( in, str, len ) );

	return ( char * )( in - 1 );
}

float _fastcall Util::Interp ( float s1, float s2, float s3, float f1, float f3 )
{
	if ( s2 == s1 )
	{
		return f1;
	}

	if ( s2 == s3 )
	{
		return f3;
	}

	if ( s3 == s1 )
	{
		return f1;
	}

	return f1 + ( ( s2 - s1 ) / ( s3 - s1 ) ) * ( ( f3 - f1 ) );
}

char* _fastcall Util::PrefHack ( char *sz1, char *sz2, char *sz3 )
{
	char *o = new char[256];

	strcpy ( o, sz1 );
	strcat ( o, sz2 );
	strcat ( o, sz3 );

	return o;
}

void _fastcall Util::StrReplace ( char* buf, const char* search, const char* replace )
{
	char* p = buf;

	int l1 = strlen ( search );
	int l2 = strlen ( replace );

	while ( p = strstr ( p, search ) )
	{
		memmove ( p + l2, p + l1, strlen ( p + l1 ) + 1 );
		memcpy ( p, replace, l2 );

		p += l2;
	}
}

float _fastcall Util::EndSpeed ( float StartSpeed, float Gravity, float FrameTime, float Distance )
{
	while ( Distance > 2 )
	{
		StartSpeed += Gravity * FrameTime;

		float dist = StartSpeed * FrameTime;

		Distance -= dist;
	}

	return StartSpeed;
}

void _fastcall Util::MyVectorAngles ( const float *Forward, float *Angles )
{
	float Temp, Yaw, Pitch;

	if ( Forward[1] == 0 && Forward[0] == 0 )
	{
		Yaw = 0;

		if ( Forward[2] > 0 )
		{
			Pitch = 270;
		}
		else
		{
			Pitch = 90;
		}
	}
	else
	{
		Yaw = ( atan2 ( Forward[1], Forward[0] ) * 180 / M_PI );

		if ( Yaw < 0 )
		{
			Yaw += 360;
		}

		Temp = sqrt ( Forward[0] * Forward[0] + Forward[1] * Forward[1] );
		Pitch = ( atan2 ( -Forward[2], Temp ) * 180 / M_PI );

		if ( Pitch < 0 )
		{
			Pitch += 360;
		}
	}

	Angles[0] = Pitch;
	Angles[1] = Yaw;
	Angles[2] = 0;

	while ( Angles[0] < -89 )
	{
		Angles[0] += 180;
		Angles[1] += 180;
	}

	while ( Angles[0] > 89 )
	{
		Angles[0] -= 180;
		Angles[1] += 180;
	}

	while ( Angles[1] < -180 )
	{
		Angles[1] += 360;
	}

	while ( Angles[1] > 180 )
	{
		Angles[1] -= 360;
	}
}

void _fastcall Util::RotateInvisible ( float FixedYaw, float FixedPitch, usercmd_s *cmd )
{
	Vector ViewForward, ViewRight, ViewUp, AimForward, AimRight, AimUp, Temp, VectorAngles;

	float Forward = cmd->forwardmove;
	float Right = cmd->sidemove;
	float Up = cmd->upmove;

	VectorCopy ( cmd->viewangles, VectorAngles );

	Engine::g_Engine.pfnAngleVectors ( Vector ( 0.0f, VectorAngles.y, 0.0f ), ViewForward, ViewRight, ViewUp );

	VectorAngles.y += FixedYaw;

	Engine::g_Engine.pfnAngleVectors ( Vector ( 0.0f, VectorAngles.y, 0.0f ), AimForward, AimRight, AimUp );

	float NewForward = DotProduct ( Forward * ViewForward.Normalize ( ), AimForward ) + 
		DotProduct ( Right * ViewRight.Normalize ( ), AimForward ) + DotProduct ( Up * ViewUp.Normalize ( ), AimForward );

	float NewRight = DotProduct ( Forward * ViewForward.Normalize ( ), AimRight ) + 
		DotProduct ( Right * ViewRight.Normalize ( ), AimRight ) + DotProduct ( Up * ViewUp.Normalize ( ), AimRight );

	float NewUp = DotProduct ( Forward * ViewForward.Normalize ( ), AimUp ) + 
		DotProduct ( Right * ViewRight.Normalize ( ), AimUp ) + DotProduct ( Up * ViewUp.Normalize ( ), AimUp );

	if ( FixedPitch > 81 )
	{
		cmd->forwardmove = -NewForward;
	}
	else
	{
		cmd->forwardmove = NewForward;
	}

	cmd->sidemove = NewRight;
	cmd->upmove = NewUp;
}

void _fastcall Util::SlowHorizontalVelocity ( float to, float frametime, usercmd_s *cmd )
{
	Information::g_Local.SlowDown = true;

	float Velocity = ( ( Engine::g_pPlayerMove->velocity.Length ( ) + 
		Engine::g_pPlayerMove->velocity.Length ( ) * frametime ) - to ) / ( frametime * 100 );

	float Speed[3] = 
	{ 
		Engine::g_pPlayerMove->velocity.x / Engine::g_pPlayerMove->velocity.Length ( ), 
		Engine::g_pPlayerMove->velocity.y / Engine::g_pPlayerMove->velocity.Length ( ),
		0
	};

	float AnglesSpeed[3];

	MyVectorAngles ( Speed, AnglesSpeed );

	float AnglesDifferent = AnglesSpeed[1] - cmd->viewangles[1];

	while ( AnglesDifferent < -180 )
	{
		AnglesDifferent += 360;
	}

	while ( AnglesDifferent > 180 )
	{
		AnglesDifferent -= 360;
	}

	cmd->forwardmove = -Velocity;
	cmd->sidemove = 0;

	RotateInvisible ( -( AnglesSpeed[1] - cmd->viewangles[1] ), 0, cmd );
}

Util g_Util;