#include "ScreenInfo.h"
#include <ctime>

namespace Functions
{
	namespace Visuals
	{
		bool ScreenInfo::Forward, ScreenInfo::Backward;
		bool ScreenInfo::MoveLeft, ScreenInfo::MoveRight;
		bool ScreenInfo::Duck, ScreenInfo::Jump;

		void ScreenInfo::DrawFps ( )
		{
			Renderer::g_Font.Print ( 8, 15, g_Vars.ScreenInfo.FontColor[0], g_Vars.ScreenInfo.FontColor[1], g_Vars.ScreenInfo.FontColor[2],
				255, g_Vars.ScreenInfo.FontOutLine ? FL_OUTLINE : FL_NONE, "%.0f fps", Info::g_Local.FPS );
		}

		void ScreenInfo::DrawCopyRight ( )
		{
			Renderer::g_Font.Print ( Engine::g_Screen.iWidth / 2, 15, g_Vars.ScreenInfo.FontColor[0], g_Vars.ScreenInfo.FontColor[1], 
				g_Vars.ScreenInfo.FontColor[2], 255, g_Vars.ScreenInfo.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, COPYRIGHT_TEXT );
		}

		void ScreenInfo::DrawTime ( )
		{
			char DateString[9], TimeString[9];

			_strdate_s ( DateString );
			_strtime_s ( TimeString );

			Renderer::g_Font.Print ( Engine::g_Screen.iWidth - 119, 15, g_Vars.ScreenInfo.FontColor[0], g_Vars.ScreenInfo.FontColor[1],
				g_Vars.ScreenInfo.FontColor[2], 255, g_Vars.ScreenInfo.FontOutLine ? FL_OUTLINE : FL_NONE, "Time: %s", TimeString );

			Renderer::g_Font.Print ( Engine::g_Screen.iWidth - 119, 30, g_Vars.ScreenInfo.FontColor[0], g_Vars.ScreenInfo.FontColor[1],
				g_Vars.ScreenInfo.FontColor[2], 255, g_Vars.ScreenInfo.FontOutLine ? FL_OUTLINE : FL_NONE, "Date: %s", DateString );
		}

		void ScreenInfo::DrawShowKeys ( )
		{
			float ClientTime = Engine::g_Engine.GetClientTime ( );

			if ( Client::g_Hpp.ScrollJump )
			{
				++Client::g_Hpp.ScrollCounter[0];

				Client::g_Hpp.LastScrollTime[0] = ClientTime + 0.15f;
			}

			if ( Client::g_Hpp.ScrollDuck )
			{
				++Client::g_Hpp.ScrollCounter[1];

				Client::g_Hpp.LastScrollTime[1] = ClientTime + 0.15f;
			}

			short DrawShowKeysForwardPos_x = Forward ? ( Engine::g_Screen.iWidth / 2 ) - 1 : Engine::g_Screen.iWidth / 2;
			short DrawShowKeysForwardPos_y = int ( Engine::g_Screen.iHeight / 2.35f );

			Renderer::g_Font.Print ( DrawShowKeysForwardPos_x, DrawShowKeysForwardPos_y, g_Vars.ScreenInfo.FontColor[0], g_Vars.ScreenInfo.FontColor[1],
				g_Vars.ScreenInfo.FontColor[2], Forward ? 255 : 200, g_Vars.ScreenInfo.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, "  %s  ", Forward ? "W" : "." );

			short DrawShowKeysMoveRightPos_x = MoveRight ? ( Engine::g_Screen.iWidth / 2 ) + 15 : ( Engine::g_Screen.iWidth / 2 ) + 16;
			short DrawShowKeysMoveRightPos_y = DrawShowKeysForwardPos_y + 18;

			Renderer::g_Font.Print ( DrawShowKeysMoveRightPos_x, DrawShowKeysMoveRightPos_y, g_Vars.ScreenInfo.FontColor[0], g_Vars.ScreenInfo.FontColor[1],
				g_Vars.ScreenInfo.FontColor[2], MoveRight ? 255 : 200, g_Vars.ScreenInfo.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, "%s", MoveRight ? "D" : "." );

			short DrawShowKeysMoveLeftPos_x = MoveLeft ? ( Engine::g_Screen.iWidth / 2 ) - 15 : ( Engine::g_Screen.iWidth / 2 ) - 16;
			short DrawShowKeysMoveLeftPos_y = DrawShowKeysMoveRightPos_y;

			Renderer::g_Font.Print ( DrawShowKeysMoveLeftPos_x, DrawShowKeysMoveLeftPos_y, g_Vars.ScreenInfo.FontColor[0], g_Vars.ScreenInfo.FontColor[1],
				g_Vars.ScreenInfo.FontColor[2], MoveLeft ? 255 : 200, g_Vars.ScreenInfo.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, "%s", MoveLeft ? "A" : "." );

			short DrawShowKeysBackwardPos_x = Backward ? ( Engine::g_Screen.iWidth / 2 ) - 1 : Engine::g_Screen.iWidth / 2;
			short DrawShowKeysBackwardPos_y = DrawShowKeysMoveRightPos_y;

			Renderer::g_Font.Print ( DrawShowKeysBackwardPos_x, DrawShowKeysBackwardPos_y, g_Vars.ScreenInfo.FontColor[0], g_Vars.ScreenInfo.FontColor[1],
				g_Vars.ScreenInfo.FontColor[2], Backward ? 255 : 200, g_Vars.ScreenInfo.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, "%s", Backward ? "S" : "." );

			short DrawShowKeysJumpPos_x = ( Engine::g_Screen.iWidth / 2 ) + 45;
			short DrawShowKeysJumpPos_y = Jump ? DrawShowKeysForwardPos_y : DrawShowKeysForwardPos_y + 2;

			Renderer::g_Font.Print ( DrawShowKeysJumpPos_x, DrawShowKeysJumpPos_y, g_Vars.ScreenInfo.FontColor[0], g_Vars.ScreenInfo.FontColor[1],
				g_Vars.ScreenInfo.FontColor[2], Jump ? 255 : 200, g_Vars.ScreenInfo.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, "%s", Jump ? "jump" : "-" );

			if ( Client::g_Hpp.LastScrollTime[0] - ClientTime > 1.0 )
			{
				Client::g_Hpp.LastScrollTime[0] = 0;
			}

			if ( Client::g_Hpp.LastScrollTime[0] > ClientTime )
			{
				Renderer::g_Font.Print ( DrawShowKeysJumpPos_x + 60, DrawShowKeysForwardPos_y, g_Vars.ScreenInfo.FontColor[0], g_Vars.ScreenInfo.FontColor[1],
					g_Vars.ScreenInfo.FontColor[2], 255, g_Vars.ScreenInfo.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, "scroll: %d", Client::g_Hpp.ScrollCounter[0] );
			}
			else
			{
				if ( Client::g_Hpp.ScrollCounter[0] > 0 )
				{
					Client::g_Hpp.ScrollCounter[0] = 0;
				}
			}

			Client::g_Hpp.ScrollJump = false;
			Client::g_Hpp.JumpPressed = false;

			short DrawShowKeysDuckPos_x = DrawShowKeysJumpPos_x;
			short DrawShowKeysDuckPos_y = Duck ? DrawShowKeysMoveRightPos_y : DrawShowKeysMoveRightPos_y + 2;

			Renderer::g_Font.Print ( DrawShowKeysDuckPos_x, DrawShowKeysDuckPos_y, g_Vars.ScreenInfo.FontColor[0], g_Vars.ScreenInfo.FontColor[1],
				g_Vars.ScreenInfo.FontColor[2], Duck ? 255 : 200, g_Vars.ScreenInfo.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, "%s", Duck ? "duck" : "-" );
		
			if ( Client::g_Hpp.LastScrollTime[1] - ClientTime > 1.0 )
			{
				Client::g_Hpp.LastScrollTime[1] = 0;
			}

			if ( Client::g_Hpp.LastScrollTime[1] > ClientTime )
			{
				Renderer::g_Font.Print ( DrawShowKeysDuckPos_x + 60, DrawShowKeysMoveRightPos_y, g_Vars.ScreenInfo.FontColor[0], g_Vars.ScreenInfo.FontColor[1],
					g_Vars.ScreenInfo.FontColor[2], 255, g_Vars.ScreenInfo.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, "scroll: %d", Client::g_Hpp.ScrollCounter[1] );
			}
			else
			{
				if ( Client::g_Hpp.ScrollCounter[1] > 0 )
				{
					Client::g_Hpp.ScrollCounter[1] = 0;
				}
			}

			Client::g_Hpp.ScrollDuck = false;
			Client::g_Hpp.DuckPressed = false;
		}

		void ScreenInfo::DrawKreedz ( )
		{
			short DrawKreedzPos_x = Engine::g_Screen.iWidth / 2;
			short DrawKreedzHSpeedPos_y = Engine::g_Screen.iHeight / 1.75f;

			Renderer::g_Font.Print ( DrawKreedzPos_x, DrawKreedzHSpeedPos_y, g_Vars.ScreenInfo.FontColor[0], g_Vars.ScreenInfo.FontColor[1], g_Vars.ScreenInfo.FontColor[2],
				255, g_Vars.ScreenInfo.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, "HSpeed: %.0f", Engine::g_pPlayerMove->velocity.Length2D ( ) );

			short DrawKreedzVSpeedPos_y = DrawKreedzHSpeedPos_y + 15;

			Renderer::g_Font.Print ( DrawKreedzPos_x, DrawKreedzVSpeedPos_y, g_Vars.ScreenInfo.FontColor[0], g_Vars.ScreenInfo.FontColor[1], g_Vars.ScreenInfo.FontColor[2],
				255, g_Vars.ScreenInfo.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, "VSpeed: %.0f", abs ( Engine::g_pPlayerMove->flFallVelocity ) );

			short DrawKreedzHeightPos_y = DrawKreedzVSpeedPos_y + 15;

			Renderer::g_Font.Print ( DrawKreedzPos_x, DrawKreedzHeightPos_y, g_Vars.ScreenInfo.FontColor[0], g_Vars.ScreenInfo.FontColor[1], g_Vars.ScreenInfo.FontColor[2],
				255, g_Vars.ScreenInfo.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, "Height: %.0f", Info::g_Local.HeightGround );

			short DrawKreedzEdgeDistancePos_y = DrawKreedzHeightPos_y + 15;

			Renderer::g_Font.Print ( DrawKreedzPos_x, DrawKreedzEdgeDistancePos_y, g_Vars.ScreenInfo.FontColor[0], g_Vars.ScreenInfo.FontColor[1], g_Vars.ScreenInfo.FontColor[2],
				255, g_Vars.ScreenInfo.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, "EdgeDistance: %.0f", Info::g_Local.EdgeDistance );

			short DrawKreedzGroundAnglePos_y = DrawKreedzEdgeDistancePos_y + 15;

			Renderer::g_Font.Print ( DrawKreedzPos_x, DrawKreedzGroundAnglePos_y, g_Vars.ScreenInfo.FontColor[0], g_Vars.ScreenInfo.FontColor[1], g_Vars.ScreenInfo.FontColor[2],
				255, g_Vars.ScreenInfo.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, "GroundAngle: %.0f", Info::g_Local.GroundAngle );

			short DrawKreedzFallDamagePos_y = DrawKreedzGroundAnglePos_y + 15;

			Renderer::g_Font.Print ( DrawKreedzPos_x, DrawKreedzFallDamagePos_y, g_Vars.ScreenInfo.FontColor[0], g_Vars.ScreenInfo.FontColor[1], g_Vars.ScreenInfo.FontColor[2],
				255, g_Vars.ScreenInfo.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, "FallDamage: %.0f", Info::g_Local.FallDamage );
		}

		void _fastcall ScreenInfo::HUD_Redraw ( )
		{
			if ( g_Vars.ScreenInfo.FPS )
			{
				DrawFps ( );
			}

			if ( g_Vars.ScreenInfo.CopyRight )
			{
				DrawCopyRight ( );
			}

			if ( g_Vars.ScreenInfo.Time )
			{
				DrawTime ( );
			}

			if ( Info::g_Local.Player.isAlive )
			{
				if ( g_Vars.ScreenInfo.ShowKeys )
				{
					DrawShowKeys ( );
				}

				if ( g_Vars.ScreenInfo.Kreedz )
				{
					DrawKreedz ( );
				}
			}
		}

		void _fastcall ScreenInfo::CL_CreateMove ( usercmd_s *cmd )
		{
			Forward = cmd->buttons & IN_FORWARD ? true : false;
			Backward = cmd->buttons & IN_BACK ? true : false;
			MoveLeft = cmd->buttons & IN_MOVELEFT ? true : false;
			MoveRight = cmd->buttons & IN_MOVERIGHT ? true : false;
			Duck = cmd->buttons & IN_DUCK ? true : false;
			Jump = cmd->buttons & IN_JUMP ? true : false;
		}

		ScreenInfo g_ScreenInfo;
	}
}