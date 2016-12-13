#include "ScreenInfo.h"
#include <ctime>

namespace Functions
{
	namespace Visuals
	{
		ScreenInfo::ScreenInfo ( )
		{
			Color[0] = 0;
			Color[1] = 0;
			Color[2] = 0;
		}

		bool ScreenInfo::Forward = false;
		bool ScreenInfo::MoveLeft = false;
		bool ScreenInfo::MoveRight = false;
		bool ScreenInfo::Backward = false;
		bool ScreenInfo::Duck = false;
		bool ScreenInfo::Jump = false;

		void ScreenInfo::ForwardPressed ( )
		{
			Forward = true;
		}

		void ScreenInfo::ForwardNoPressed ( )
		{
			Forward = false;
		}

		void ScreenInfo::MoveLeftPressed ( )
		{
			MoveLeft = true;
		}

		void ScreenInfo::MoveLeftNoPressed ( )
		{
			MoveLeft = false;
		}

		void ScreenInfo::MoveRightPressed ( )
		{
			MoveRight = true;
		}

		void ScreenInfo::MoveRightNoPressed ( )
		{
			MoveRight = false;
		}

		void ScreenInfo::BackwardPressed ( )
		{
			Backward = true;
		}

		void ScreenInfo::BackwardNoPressed ( )
		{
			Backward = false;
		}

		void ScreenInfo::DuckPressed ( )
		{
			Duck = true;
		}

		void ScreenInfo::DuckNoPressed ( )
		{
			Duck = false;
		}

		void ScreenInfo::JumpPressed ( )
		{
			Jump = true;
		}

		void ScreenInfo::JumpNoPressed ( )
		{
			Jump = false;
		}

		void ScreenInfo::GetColor ( )
		{
			for ( BYTE i = 0; i < sizeof ( Color ); ++i )
			{
				Color[i] = g_Vars.screeninfo.color[i];
			}
		}

		void ScreenInfo::DrawFps ( )
		{

			Renderer::g_Font.Print ( 8, 15, Color[0], Color[1], Color[2], 255,
				g_Vars.screeninfo.font_outline ? FL_OUTLINE : FL_NONE, "%.0f fps", Information::g_Local.FPS );
		}

		void ScreenInfo::DrawCopyRight ( )
		{
			Renderer::g_Font.Print ( int ( Engine::g_Screen.iWidth / 2 ), 15, Color[0], Color[1], Color[2],
				255, g_Vars.screeninfo.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, COPYRIGHT_TEXT );
		}

		void ScreenInfo::DrawTime ( )
		{
			char DateString[9], TimeString[9];

			_strdate_s ( DateString );
			_strtime_s ( TimeString );

			Renderer::g_Font.Print ( int ( Engine::g_Screen.iWidth - 119 ), 15, Color[0], Color[1],
				Color[2], 255, g_Vars.screeninfo.font_outline ? FL_OUTLINE : FL_NONE, "Time: %s", TimeString );

			Renderer::g_Font.Print ( int ( Engine::g_Screen.iWidth - 119 ), 30, Color[0], Color[1],
				Color[2], 255, g_Vars.screeninfo.font_outline ? FL_OUTLINE : FL_NONE, "Date: %s", DateString );
		}

		void ScreenInfo::DrawShowKeys ( )
		{
			int DrawShowKeysForwardPos_x = Forward ? ( Engine::g_Screen.iWidth / 2 ) - 1 : Engine::g_Screen.iWidth / 2;
			int DrawShowKeysForwardPos_y = int ( Engine::g_Screen.iHeight / 2.35f );

			int DrawKreedzFontOutLine = g_Vars.screeninfo.font_outline;

			Renderer::g_Font.Print ( DrawShowKeysForwardPos_x, DrawShowKeysForwardPos_y, Color[0], Color[1], Color[2],
				Forward ? 255 : 200, DrawKreedzFontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, "  %s  ", Forward ? "W" : "." );

			int DrawShowKeysMoveRightPos_x = MoveRight ? ( Engine::g_Screen.iWidth / 2 ) + 15 : ( Engine::g_Screen.iWidth / 2 ) + 16;
			int DrawShowKeysMoveRightPos_y = DrawShowKeysForwardPos_y + 18;

			Renderer::g_Font.Print ( DrawShowKeysMoveRightPos_x, DrawShowKeysMoveRightPos_y, Color[0], Color[1], Color[2],
				MoveRight ? 255 : 200, DrawKreedzFontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, "%s", MoveRight ? "D" : "." );

			int DrawShowKeysMoveLeftPos_x = MoveLeft ? ( Engine::g_Screen.iWidth / 2 ) - 15 : ( Engine::g_Screen.iWidth / 2 ) - 16;
			int DrawShowKeysMoveLeftPos_y = DrawShowKeysMoveRightPos_y;

			Renderer::g_Font.Print ( DrawShowKeysMoveLeftPos_x, DrawShowKeysMoveLeftPos_y, Color[0], Color[1], Color[2],
				MoveLeft ? 255 : 200, DrawKreedzFontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, "%s", MoveLeft ? "A" : "." );

			int DrawShowKeysBackwardPos_x = Backward ? ( Engine::g_Screen.iWidth / 2 ) - 1 : Engine::g_Screen.iWidth / 2;
			int DrawShowKeysBackwardPos_y = DrawShowKeysMoveRightPos_y;

			Renderer::g_Font.Print ( DrawShowKeysBackwardPos_x, DrawShowKeysBackwardPos_y, Color[0], Color[1], Color[2],
				Backward ? 255 : 200, DrawKreedzFontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, "%s", Backward ? "S" : "." );

			int DrawShowKeysJumpPos_x = ( Engine::g_Screen.iWidth / 2 ) + 45;
			int DrawShowKeysJumpPos_y = Jump ? DrawShowKeysForwardPos_y : DrawShowKeysForwardPos_y + 2;

			Renderer::g_Font.Print ( DrawShowKeysJumpPos_x, DrawShowKeysJumpPos_y, Color[0], Color[1], Color[2],
				Jump ? 255 : 200, DrawKreedzFontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, "%s", Jump ? "jump" : "-" );

			int DrawShowKeysDuckPos_x = DrawShowKeysJumpPos_x;
			int DrawShowKeysDuckPos_y = Duck ? DrawShowKeysMoveRightPos_y : DrawShowKeysMoveRightPos_y + 2;

			Renderer::g_Font.Print ( DrawShowKeysDuckPos_x, DrawShowKeysDuckPos_y, Color[0], Color[1], Color[2],
				Duck ? 255 : 200, DrawKreedzFontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, "%s", Duck ? "duck" : "-" );
		}

		void ScreenInfo::DrawKreedz ( )
		{
			int DrawKreedzPos_x = Engine::g_Screen.iWidth / 2;
			int DrawKreedzHSpeedPos_y = Engine::g_Screen.iHeight / 1.75f;

			Renderer::g_Font.Print ( DrawKreedzPos_x, DrawKreedzHSpeedPos_y, Color[0], Color[1], Color[2], 255,
				g_Vars.screeninfo.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, "HSpeed: %.0f", Engine::g_pPlayerMove->velocity.Length2D ( ) );

			int DrawKreedzVSpeedPos_y = DrawKreedzHSpeedPos_y + 15;

			Renderer::g_Font.Print ( DrawKreedzPos_x, DrawKreedzVSpeedPos_y, Color[0], Color[1], Color[2], 255,
				g_Vars.screeninfo.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, "VSpeed: %.0f", abs ( Engine::g_pPlayerMove->flFallVelocity ) );

			int DrawKreedzHeightPos_y = DrawKreedzVSpeedPos_y + 15;

			Renderer::g_Font.Print ( DrawKreedzPos_x, DrawKreedzHeightPos_y, Color[0], Color[1], Color[2], 255,
				g_Vars.screeninfo.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, "Height: %.0f", Information::g_Local.HeightGround );

			int DrawKreedzEdgeDistancePos_y = DrawKreedzHeightPos_y + 15;

			Renderer::g_Font.Print ( DrawKreedzPos_x, DrawKreedzEdgeDistancePos_y, Color[0], Color[1], Color[2], 255,
				g_Vars.screeninfo.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, "EdgeDistance: %.0f", Information::g_Local.EdgeDistance );

			int DrawKreedzGroundAnglePos_y = DrawKreedzEdgeDistancePos_y + 15;

			Renderer::g_Font.Print ( DrawKreedzPos_x, DrawKreedzGroundAnglePos_y, Color[0], Color[1], Color[2], 255,
				g_Vars.screeninfo.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, "GroundAngle: %.0f", Information::g_Local.GroundAngle );

			int DrawKreedzFallDamagePos_y = DrawKreedzGroundAnglePos_y + 15;

			Renderer::g_Font.Print ( DrawKreedzPos_x, DrawKreedzFallDamagePos_y, Color[0], Color[1], Color[2], 255,
				g_Vars.screeninfo.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, "FallDamage: %.0f", Information::g_Local.FallDamage );
		}

		void ScreenInfo::HUD_Redraw ( )
		{
			GetColor ( );

			if ( g_Vars.screeninfo.fps )
			{
				DrawFps ( );
			}

			if ( g_Vars.screeninfo.copyright )
			{
				DrawCopyRight ( );
			}

			if ( g_Vars.screeninfo.time )
			{
				DrawTime ( );
			}

			if ( Information::g_Local.Alive )
			{
				if ( g_Vars.screeninfo.showkeys )
				{
					DrawShowKeys ( );
				}

				if ( g_Vars.screeninfo.kreedz )
				{
					DrawKreedz ( );
				}
			}
		}

		void ScreenInfo::CL_CreateMove ( usercmd_s *cmd )
		{
			cmd->buttons & IN_FORWARD ? ForwardPressed ( ) : ForwardNoPressed ( );
			cmd->buttons & IN_MOVELEFT ? MoveLeftPressed ( ) : MoveLeftNoPressed ( );
			cmd->buttons & IN_MOVERIGHT ? MoveRightPressed ( ) : MoveRightNoPressed ( );
			cmd->buttons & IN_BACK ? BackwardPressed ( ) : BackwardNoPressed ( );
			cmd->buttons & IN_DUCK ? DuckPressed ( ) : DuckNoPressed ( );
			cmd->buttons & IN_JUMP ? JumpPressed ( ) : JumpNoPressed ( );
		}

		ScreenInfo g_ScreenInfo;
	}
}