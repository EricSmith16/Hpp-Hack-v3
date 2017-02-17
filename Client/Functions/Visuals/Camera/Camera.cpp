#include "Camera.h"

namespace Functions
{
	namespace Visuals
	{
		float FreeLookAngles[3], FreeLookOffset[3];

		void Camera::ThirdPerson ( ref_params_s *pparams )
		{
			if ( !g_Vars.Camera.SpectatorEnable && !g_Vars.Camera.FreeLookEnable && Info::g_Local.Player.isAlive )
			{
				Vector Offset ( 0, 0, 0 );
				Vector Side, Up, Back;

				VectorMul ( pparams->right, g_Vars.Camera.ThirdPersonSide, Side );
				VectorMul ( pparams->up, g_Vars.Camera.ThirdPersonUp, Up );
				VectorMul ( pparams->forward, -g_Vars.Camera.ThirdPersonBack, Back );

				Offset = Offset + Side;
				Offset = Offset + Up;
				Offset = Offset + Back;

				pparams->vieworg[0] += Offset[0];
				pparams->vieworg[1] += Offset[1];
				pparams->vieworg[2] += Offset[2];
			}
		}

		void Camera::FreeLook ( ref_params_s *pparams )
		{
			g_Util.MemoryCopy ( pparams->vieworg, FreeLookOffset, sizeof ( float ) * 3 );
			g_Util.MemoryCopy ( pparams->simorg, FreeLookOffset, sizeof ( float ) * 3 );
		}

		void Camera::FreeLookCreate ( float frametime, usercmd_s *cmd )
		{
			static bool FreeLook;

			if ( g_Vars.Camera.FreeLookEnable && Info::g_Local.Player.isAlive )
			{
				if ( !FreeLook )
				{
					Engine::g_Engine.GetViewAngles ( FreeLookAngles );

					g_Util.MemorySet ( FreeLookOffset, 0, sizeof ( float ) * 3 );

					FreeLookOffset[0] = Engine::g_pPlayerMove->origin.x;
					FreeLookOffset[1] = Engine::g_pPlayerMove->origin.y;
					FreeLookOffset[2] = Engine::g_pPlayerMove->origin.z + 40;

					FreeLook = true;
				}

				g_Util.MemoryCopy ( cmd->viewangles, FreeLookAngles, sizeof ( float ) * 3 );

				Vector CurrentMove ( 0, 0, 0 );
				Vector Up = Info::g_Local.Up;
				Vector Right = Info::g_Local.Right;
				Vector Forward = Info::g_Local.Forward;

				if ( cmd->buttons & IN_MOVELEFT )
				{
					CurrentMove = CurrentMove + Right * -1;
				}

				if ( cmd->buttons & IN_MOVERIGHT )
				{
					CurrentMove = CurrentMove + Right * 1;
				}

				if ( cmd->buttons & IN_FORWARD )
				{
					CurrentMove = CurrentMove + Forward * 1;
				}

				if ( cmd->buttons & IN_BACK )
				{
					CurrentMove = CurrentMove + Forward * -1;
				}

				if ( cmd->buttons & IN_JUMP )
				{
					CurrentMove = CurrentMove + Up * 0.7f;
				}

				if ( cmd->buttons & IN_DUCK )
				{
					CurrentMove = CurrentMove + Up * -0.7f;
				}

				if ( GetAsyncKeyState ( VK_SHIFT ) )
				{
					CurrentMove = CurrentMove * ( g_Vars.Camera.FreeLookSpeed * frametime / 2 );
				}
				else
				{
					CurrentMove = CurrentMove * ( g_Vars.Camera.FreeLookSpeed * frametime );
				}

				FreeLookOffset[0] += CurrentMove.x;
				FreeLookOffset[1] += CurrentMove.y;
				FreeLookOffset[2] += CurrentMove.z;

				cmd->buttons = 0;
				cmd->sidemove = 0;
				cmd->forwardmove = 0;
			}

			if ( !g_Vars.Camera.FreeLookEnable )
			{
				FreeLook = false;
			}
		}

		void Camera::Spectator ( uint8 ID, ref_params_s *pparams )
		{
			if ( ID > 0 && Info::g_Local.Player.isAlive && Info::g_Player[ID].Valid && !g_Vars.Camera.FreeLookEnable && ID != Info::g_Local.Player.Index )
			{
				Vector Offset ( 0, 0, 0 );			
				Vector Up, Right, Forward, PlayerAngles;
				Vector xUp, xRight, xBack;
				Vector ViewAngles;
				
				Engine::g_Engine.GetViewAngles ( ViewAngles );

				PlayerAngles[0] = ViewAngles.x;
				PlayerAngles[1] = ViewAngles.y;
				PlayerAngles[2] = ViewAngles.z;

				Engine::g_Engine.pfnAngleVectors ( PlayerAngles, Forward, Right, Up );

				VectorMul ( Right, 0, xRight );
				VectorMul ( Up, 27, xUp );
				VectorMul ( Forward, -100, xBack );

				Offset = Info::g_Player[ID].Entity->origin;
				Offset = Offset + xRight;
				Offset = Offset + xUp;
				Offset = Offset + xBack;

				pparams->vieworg[0] = Offset[0];
				pparams->vieworg[1] = Offset[1];
				pparams->vieworg[2] = Offset[2];
			}
		}

		void Camera::SpectatorCreate ( uint8 ID, usercmd_s *cmd )
		{
			if ( ID > 0 && Info::g_Local.Player.isAlive && Info::g_Player[ID].Valid && !g_Vars.Camera.FreeLookEnable )
			{
				cmd->forwardmove = 0;
				cmd->sidemove = 0;
				cmd->buttons = 0;
			}
		}

		void _fastcall Camera::V_CalcRefdef ( ref_params_s *pparams )
		{
			if ( g_Vars.Function.Camera )
			{
				if ( g_Vars.Camera.ThirdPersonEnable )
				{
					ThirdPerson ( pparams );
				}

				if ( g_Vars.Camera.FreeLookEnable )
				{
					FreeLook ( pparams );
				}

				if ( g_Vars.Camera.SpectatorEnable )
				{
					Spectator ( g_Vars.Camera.SpectatorID, pparams );
				}
			}
		}

		void _fastcall Camera::CL_CreateMove ( float frametime, usercmd_s *cmd )
		{
			if ( g_Vars.Camera.FreeLookEnable )
			{
				FreeLookCreate ( frametime, cmd );
			}

			if ( g_Vars.Camera.SpectatorEnable )
			{
				SpectatorCreate ( g_Vars.Camera.SpectatorID, cmd );
			}
		}

		Camera g_Camera;
	}
}