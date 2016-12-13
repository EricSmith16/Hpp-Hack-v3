#pragma once

#include "Main.h"

namespace Engine
{
	class Command
	{
	public:
		static int Function ( char *Command );

		static void ConsoleCommands ( );	

		static void Bind ( );
		static void UnBind ( );
		static void UnBindAll ( );

		static void ExecConfig ( );

		static void ReloadSettings ( );
		static void Panic ( );
		static void PlayerScanVisibility ( );
		static void PlayerValidCheck ( );
		static void FontOutLineQuality ( );

		static void MenuPos_x ( );
		static void MenuPos_y ( );
		static void MenuBoxHeight ( );
		static void MenuBoxColor ( );
		static void MenuFillColor ( );
		static void MenuTextColor ( );
		static void MenuSelectColor ( );

		static void ESPEnable ( );
		static void ESPPlayer ( );
		static void ESPPlayerVisibleCheck ( );
		static void ESPPlayerVisibleOnly ( );
		static void ESPPlayerIgnoreDeath ( );
		static void ESPPlayerBox ( );
		static void ESPPlayerBoxLineWidth ( );
		static void ESPPlayerBoxSize ( );
		static void ESPPlayerBoxTVis ( );
		static void ESPPlayerBoxTHide ( );
		static void ESPPlayerBoxCTVis ( );
		static void ESPPlayerBoxCTHide ( );
		static void ESPPlayerName ( );
		static void ESPPlayerWeapon ( );
		static void ESPPlayerDistance ( );
		static void ESPPlayerBarrel ( );
		static void ESPWorld ( );
		static void ESPWorldWeapons ( );
		static void ESPWorldNades ( );
		static void ESPC4Timer ( );
		static void ESPC4TimerValue ( );
		static void ESPSound ( );
		static void ESPSoundLineWidth ( );
		static void ESPSoundFadeTime ( );
		static void ESPSoundColor ( );
		static void ESPFontOutLine ( );
		static void ESPFontColor ( );
		static void ESPPanic ( );

		static void NoFlashEnable ( );
		static void NoFlashFadeLimit ( );
		static void NoFlashFadeColor ( );
		static void NoFlashFadeColorRandom ( );
		static void NoFlashShowPercentage ( );
		static void NoFlashFontOutLine ( );

		static void ScreenInfoEnable ( );
		static void ScreenInfoFPS ( );
		static void ScreenInfoCopyRight ( );
		static void ScreenInfoTime ( );
		static void ScreenInfoShowKeys ( );
		static void ScreenInfoKreedz ( );
		static void ScreenInfoColor ( );
		static void ScreenInfoFontOutLine ( );

		static void Speed ( );
		static void SpeedEngine ( );
		static void SpeedType ( );
		static void SpeedBoost ( );
		static void SpeedBoostOn ( );
		static void SpeedBoostOff ( );
		static void SpeedSlowMo ( );
		static void SpeedSlowMoOn ( );
		static void SpeedSlowMoOff ( );

		static void BunnyHopMouseWheelEmulation ( );
		static void BunnyHopMouseWheelDirection ( );
		static void BunnyHopDistanceType ( );
		static void BunnyHopDistance ( );	
		static void BunnyHopNoSlowDown ( );
		static void BunnyHopInWater ( );
		static void BunnyHopOnLadder ( );
		static void BunnyHopStandUp ( );
		static void BunnyHopStandUpFallVelocity ( );
		static void BunnyHopStandUpGroundAngle ( );
		static void BunnyHopStandUpOn ( );
		static void BunnyHopStandUpOff ( );
		static void BunnyHopOn ( );
		static void BunnyHopOff ( );

		static void GroundStrafeMouseWheelEmulation ( );
		static void GroundStrafeMouseWheelDirection ( );
		static void GroundStrafeDistanceType ( );
		static void GroundStrafeDistance ( );
		static void GroundStrafeCount ( );
		static void GroundStrafeFallRun ( );
		static void GroundStrafeSlowDownScale ( );
		static void GroundStrafeSlowDownGroundAngle ( );
		static void GroundStrafeStandUpFallVelocity ( );
		static void GroundStrafeStandUpOn ( );
		static void GroundStrafeStandUpOff ( );
		static void GroundStrafeOn ( );
		static void GroundStrafeOff ( );

		static void JumpBugAuto ( );
		static void JumpBugAutoDamage ( );
		static void JumpBugAutoPercentage ( );
		static void JumpBugSlowDown ( );
		static void JumpBugSlowDownDistance ( );
		static void JumpBugSlowMotion ( );
		static void JumpBugOn ( );
		static void JumpBugOff ( );

		static void EdgeBugAuto ( );
		static void EdgeBugAutoDamage ( );
		static void EdgeBugSpeed ( );
		static void EdgeBugDistance ( );
		static void EdgeBugDistanceAuto ( );
		static void EdgeBugOn ( );
		static void EdgeBugOff ( );
	};

	extern Command g_Command;
}