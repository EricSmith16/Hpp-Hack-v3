#pragma once

#include "Main.h"

struct CameraStruct
{
	float ThirdPersonEnable, ThirdPersonSide;
	float ThirdPersonUp, ThirdPersonBack;

	float FreeLookEnable, FreeLookSpeed;

	float SpectatorEnable, SpectatorID;

	BYTE ThirdPersonSwitchKey;
	BYTE FreeLookSwitchKey;
	BYTE SpectatorSwitchKey;
};

struct StrafeHelperStruct
{
	float Active, Mode, Type, MinimalSpeed;
	float CorrectSpeed, CorrectLimit, CorrectLimitSmooth;
	float Boost, Direction, DirectionAuto;
	float KeyEmulation, StrafeLimit;

	BYTE Key, SwitchKey;
};

struct EdgeBugStruct
{
	float AutoEnable, AutoDamage;
	float Speed, SpeedFinal, SpeedOffset;

	BYTE Key;
};

struct JumpBugStruct
{
	float AutoEnable, AutoPercentage, AutoDamage;
	float SlowMotion, SlowDown;

	BYTE Key;
};

struct SpeedStruct
{
	float Value, EngineValue;
	float SpeedType, Boost, SlowMotion;

	BYTE BoostKey, SlowMotionKey;
};

struct GStrafeStruct
{
	char *DistanceString, *CountString;

	float Distance[2], Count[2];

	float ScrollEmulation, ScrollDirection;
	float SlowDownScale, FallRun, StandUpFallVelocity;

	BYTE Key, StandUpKey;
};

struct BHopStruct
{
	char *DistanceString;

	float Distance[2];

	float ScrollEmulation, ScrollDirection;
	float NoSlowDown, OnLadder;
	float StandUpAuto, StandUpFallVelocity;

	BYTE Key, StandUpKey;
};

struct ScreenInfoStruct
{
	char* FontColorString;

	float FontColor[3];

	float Enable, FPS, CopyRight, ShowKeys;
	float Kreedz, Time, FontOutLine;
};

struct NoFlashStruct
{
	char *FadeColorString;

	float FadeColor[3];

	float Enable, FadeColorRandom, FadeLimit;
	float ShowPercentage, FontOutLine;
};

struct ESPStruct
{
	char *ColorTHideString, *ColorTVisString;
	char *ColorCTHideString, *ColorCTVisString;
	char *SoundColorString, *FontColorString;

	float ColorTHide[3], ColorTVis[3];
	float ColorCTHide[3], ColorCTVis[3];
	float SoundColor[3], FontColor[3];

	float Enable, Player, PlayerVisibleOnly;
	float PlayerBox, PlayerBoxLineWidth, PlayerName;
	float PlayerWeapon, PlayerDistance, PlayerBarrel;
	float WorldItems, WorldNades;
	float C4Timer, C4TimerValue;
	float Sound, SoundLineWidth, SoundFadeTime;
	float FontOutLine;

	BYTE PanicKey;
};

struct MainStruct
{
	float PlayerVisibleScan, PlayerValidCheck;
	float FontOutLineQuality;
	float AntiScreenEnable, AntiScreenTimer;

	bool Launguage;

	BYTE ReloadKey, PanicKey, AntiScreenKey;
};

struct MenuStruct
{
	char *BoxColorString, *BoxFillColorString;
	char *BoxSelectColorString, *TextColorString;

	float BoxColor[4], BoxFillColor[4];
	float BoxSelectColor[4], TextColor[4];

	float Pos_x, Pos_y;
	float BoxHeight, BoxWidth;

	BYTE Key;
};

struct FunctionStruct
{
	bool Speed, BunnyHop, GroundStrafe;
	bool JumpBug, EdgeBug, StrafeHelper;

	bool ESP, NoFlash, ScreenInfo, Menu;
	bool Camera;

	bool Commands, CommandsBinds;
};

class Vars
{
public:
	CameraStruct Camera;
	StrafeHelperStruct StrafeHelper;
	EdgeBugStruct EdgeBug;
	JumpBugStruct JumpBug;
	SpeedStruct Speed;
	GStrafeStruct GStrafe;
	BHopStruct BHop;
	ScreenInfoStruct ScreenInfo;
	NoFlashStruct NoFlash;
	ESPStruct ESP;
	MainStruct Main;
	MenuStruct Menu;
	FunctionStruct Function;
};

extern Vars g_Vars;