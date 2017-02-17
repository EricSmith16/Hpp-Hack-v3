#pragma once

#include "Main.h"

namespace Engine
{
	class Command
	{
	private:
		static bool Return;

		inline static uint8 GetFunctionIndex ( char *CommandName );

		inline static uint8 SetKeyCommand ( );

		inline static void ExecConfig ( );

		inline static void Reload ( );
		inline static void Save ( );
		inline static void Panic ( );
		inline static void PlayerVisibleScan ( );
		inline static void PlayerValidCheck ( );
		inline static void FontOutLineQuality ( );

		inline static void AntiScreen ( );
		inline static void AntiScreenEnable ( );
		inline static void AntiScreenTimer ( );

		inline static void Menu ( );
		inline static void MenuPos_x ( );
		inline static void MenuPos_y ( );
		inline static void MenuBoxHeight ( );
		inline static void MenuBoxWidth ( );
		inline static void MenuBoxColor ( );
		inline static void MenuBoxFillColor ( );		
		inline static void MenuBoxSelectColor ( );
		inline static void MenuTextColor ( );

		inline static void ESPEnable ( );
		inline static void ESPPlayer ( );
		inline static void ESPPlayerVisibleOnly ( );
		inline static void ESPPlayerBox ( );
		inline static void ESPPlayerBoxLineWidth ( );
		inline static void ESPPlayerBoxTVis ( );
		inline static void ESPPlayerBoxTHide ( );
		inline static void ESPPlayerBoxCTVis ( );
		inline static void ESPPlayerBoxCTHide ( );
		inline static void ESPPlayerName ( );
		inline static void ESPPlayerWeapon ( );
		inline static void ESPPlayerDistance ( );
		inline static void ESPPlayerBarrel ( );
		inline static void ESPWorldItems ( );
		inline static void ESPWorldNades ( );
		inline static void ESPC4Timer ( );
		inline static void ESPC4TimerValue ( );
		inline static void ESPSound ( );
		inline static void ESPSoundLineWidth ( );
		inline static void ESPSoundFadeTime ( );
		inline static void ESPSoundColor ( );
		inline static void ESPFontOutLine ( );
		inline static void ESPFontColor ( );
		inline static void ESPPanic ( );

		inline static void NoFlashEnable ( );
		inline static void NoFlashFadeLimit ( );
		inline static void NoFlashFadeColor ( );
		inline static void NoFlashFadeColorRandom ( );
		inline static void NoFlashShowPercentage ( );
		inline static void NoFlashFontOutLine ( );

		inline static void ScreenInfoEnable ( );
		inline static void ScreenInfoFPS ( );
		inline static void ScreenInfoCopyRight ( );
		inline static void ScreenInfoTime ( );
		inline static void ScreenInfoShowKeys ( );
		inline static void ScreenInfoKreedz ( );
		inline static void ScreenInfoFontColor ( );
		inline static void ScreenInfoFontOutLine ( );

		inline static void Speed ( );
		inline static void SpeedEngine ( );
		inline static void SpeedType ( );
		inline static void SpeedBoost ( );
		inline static void SpeedBoostOn ( );
		inline static void SpeedBoostOff ( );
		inline static void SpeedSlowMo ( );
		inline static void SpeedSlowMoOn ( );
		inline static void SpeedSlowMoOff ( );

		inline static void BunnyHopScrollEmulation ( );
		inline static void BunnyHopScrollDirection ( );
		inline static void BunnyHopDistance ( );
		inline static void BunnyHopNoSlowDown ( );
		inline static void BunnyHopOnLadder ( );
		inline static void BunnyHopStandUpAuto ( );
		inline static void BunnyHopStandUpFallVelocity ( );
		inline static void BunnyHopStandUpOn ( );
		inline static void BunnyHopStandUpOff ( );
		inline static void BunnyHopOn ( );
		inline static void BunnyHopOff ( );

		inline static void GroundStrafeScrollEmulation ( );
		inline static void GroundStrafeScrollDirection ( );
		inline static void GroundStrafeDistance ( );
		inline static void GroundStrafeCount ( );
		inline static void GroundStrafeFallRun ( );
		inline static void GroundStrafeSlowDownScale ( );
		inline static void GroundStrafeStandUpFallVelocity ( );
		inline static void GroundStrafeStandUpOn ( );
		inline static void GroundStrafeStandUpOff ( );
		inline static void GroundStrafeOn ( );
		inline static void GroundStrafeOff ( );

		inline static void JumpBugAuto ( );
		inline static void JumpBugAutoDamage ( );
		inline static void JumpBugAutoPercentage ( );
		inline static void JumpBugSlowDown ( );
		inline static void JumpBugSlowMotion ( );
		inline static void JumpBugOn ( );
		inline static void JumpBugOff ( );

		inline static void EdgeBugAuto ( );
		inline static void EdgeBugAutoDamage ( );
		inline static void EdgeBugSpeed ( );
		inline static void EdgeBugSpeedFinal ( );
		inline static void EdgeBugSpeedOffset ( );
		inline static void EdgeBugOn ( );
		inline static void EdgeBugOff ( );

		inline static void StrafeHelperActive ( );
		inline static void StrafeHelperMode ( );
		inline static void StrafeHelperType ( );
		inline static void StrafeHelperCorrectSpeed ( );
		inline static void StrafeHelperCorrectLimit ( );
		inline static void StrafeHelperCorrectLimitSmooth ( );
		inline static void StrafeHelperKeyEmulation ( );
		inline static void StrafeHelperBoost ( );
		inline static void StrafeHelperMinimalSpeed ( );
		inline static void StrafeHelperDirection ( );
		inline static void StrafeHelperDirectionAuto ( );
		inline static void StrafeHelperStrafeLimit ( );
		inline static void StrafeHelperSwitch ( );
		inline static void StrafeHelperOn ( );
		inline static void StrafeHelperOff ( );

		inline static void ThirdPersonEnable ( );
		inline static void ThirdPersonPositionSide ( );
		inline static void ThirdPersonPositionUp ( );
		inline static void ThirdPersonPositionBack ( );
		inline static void ThirdPersonSwitch ( );

		inline static void FreeLookEnable ( );
		inline static void FreeLookSpeed ( );
		inline static void FreeLookSwitch ( );

		inline static void SpectatorEnable ( );
		inline static void SpectatorID ( );
		inline static void SpectatorSwitch ( );

		static void Bind ( );

		inline static void BindIs ( BYTE Key, char *act, char *Command );

		static void Unbind ( );
		static void UnbindAll ( );

	public:
		static void _fastcall ConsoleCommands ( );
	};

	extern Command g_Command;
}