#include "StrafeHelper.h"

#define LEFT	1
#define RIGHT	2

namespace Functions
{
	namespace Misc
	{
		uint8 StrafeHelper::Direction;

		bool StrafeHelper::StrafeHelperActive;

		enum Direction
		{
			FORWARD = 1, RIGHTSIDE = 2, LEFTSIDE = 3, BACK = 4
		};

		enum Mode
		{
			CORRECT, FILTER, DATA, CORRECT_FILTER, CORRECT_DATA, FILTER_DATA, CORRECT_FILTER_DATA
		};

		int StrafeHelper::MouseDirection ( short check )
		{
			if ( Client::BuildInfo.Build > 4554 )
			{
				if ( Engine::g_Engine.pfnGetCvarPointer ( "m_rawinput" )->value )
				{
					if ( check < 0 )
					{
						return LEFT;
					}
					else
					{
						return RIGHT;
					}
				}
				else
				{
					if ( check <= 0 )
					{
						return LEFT;
					}
					else
					{
						return RIGHT;
					}
				}
			}
			else
			{
				if ( check <= 0 )
				{
					return LEFT;
				}
				else
				{
					return RIGHT;
				}
			}
		}

		void StrafeHelper::AutoDirection ( usercmd_s *cmd, short check )
		{
			bool forward = cmd->buttons & IN_FORWARD ? true : false;
			bool back = cmd->buttons & IN_BACK ? true : false;
			bool moveleft = cmd->buttons & IN_MOVELEFT ? true : false;
			bool moveright = cmd->buttons & IN_MOVERIGHT ? true : false;

			if ( moveleft && moveright )
			{
				moveleft = false;
				moveright = false;
			}

			if ( forward && back )
			{
				forward = false;
				back = false;
			}

			if ( Engine::g_pPlayerMove->movetype != 5 )
			{
				if ( Engine::g_pPlayerMove->flags & FL_ONGROUND )
				{
					if ( g_Vars.StrafeHelper.DirectionAuto == 1 )
					{
						if ( ( forward && !back && moveright && !moveleft && MouseDirection ( check ) == RIGHT ) ||
							forward && !back && !moveright && moveleft && MouseDirection ( check ) == LEFT )
						{
							Direction = FORWARD;
						}

						if ( ( forward && !back && moveright && !moveleft && MouseDirection ( check ) == LEFT ) ||
							( !forward && back && moveright && !moveleft && MouseDirection ( check ) == RIGHT ) )
						{
							Direction = RIGHTSIDE;
						}

						if ( ( forward && !back && !moveright && moveleft && MouseDirection ( check ) == RIGHT ) ||
							!forward && back && !moveright && moveleft && MouseDirection ( check ) == LEFT )
						{
							Direction = LEFTSIDE;
						}

						if ( ( !forward && back && moveright && !moveleft && MouseDirection ( check ) == LEFT ) ||
							( !forward && back && !moveright && moveleft && MouseDirection ( check ) == RIGHT ) )
						{
							Direction = BACK;
						}
					}
					else if ( g_Vars.StrafeHelper.DirectionAuto == 2 )
					{
						if ( ( forward && !back && !moveright && !moveleft ) ||
							( forward && !back && moveright && !moveleft && MouseDirection ( check ) == RIGHT ) ||
							forward && !back && !moveright && moveleft && MouseDirection ( check ) == LEFT )
						{
							Direction = FORWARD;
						}

						if ( ( !forward && !back && moveright && !moveleft ) ||
							( forward && !back && moveright && !moveleft && MouseDirection ( check ) == LEFT ) ||
							( !forward && back && moveright && !moveleft && MouseDirection ( check ) == RIGHT ) )
						{
							Direction = RIGHTSIDE;
						}

						if ( ( !forward && !back && !moveright && moveleft ) ||
							( forward && !back && !moveright && moveleft && MouseDirection ( check ) == RIGHT ) ||
							!forward && back && !moveright && moveleft && MouseDirection ( check ) == LEFT )
						{
							Direction = LEFTSIDE;
						}

						if ( ( !forward && back && !moveright && !moveleft ) ||
							( !forward && back && moveright && !moveleft && MouseDirection ( check ) == LEFT ) ||
							( !forward && back && !moveright && moveleft && MouseDirection ( check ) == RIGHT ) )
						{
							Direction = BACK;
						}
					}
				}
			}
			else if ( Engine::g_pPlayerMove->movetype == 5 || Info::g_Local.Player.OnSurf )
			{
				Direction = FORWARD;
			}
		}

		void StrafeHelper::Correct ( short check )
		{
			float ViewAngles[3];

			Engine::g_Engine.GetViewAngles ( ViewAngles );

			if ( MouseDirection ( check ) == LEFT )
			{
				ViewAngles[1] += g_Vars.StrafeHelper.CorrectSpeed;
			}
			else if ( MouseDirection ( check ) == RIGHT )
			{
				ViewAngles[1] -= g_Vars.StrafeHelper.CorrectSpeed;
			}

			Engine::g_Engine.SetViewAngles ( ViewAngles );
		}

		void StrafeHelper::Filter ( usercmd_s *cmd, short check )
		{
			switch ( Direction )
			{
			case FORWARD:
				cmd->forwardmove = 0;

				cmd->buttons &= ~IN_FORWARD;
				cmd->buttons &= ~IN_BACK;

				if ( MouseDirection ( check ) == LEFT && cmd->buttons & IN_MOVERIGHT )
				{
					cmd->sidemove = 0;

					cmd->buttons &= ~IN_MOVERIGHT;
				}

				if ( MouseDirection ( check ) == RIGHT && cmd->buttons & IN_MOVELEFT )
				{
					cmd->sidemove = 0;

					cmd->buttons &= ~IN_MOVELEFT;
				}

				break;

			case RIGHTSIDE:
				cmd->sidemove = 0;

				cmd->buttons &= ~IN_MOVERIGHT;
				cmd->buttons &= ~IN_MOVELEFT;

				if ( MouseDirection ( check ) == LEFT && cmd->buttons & IN_BACK )
				{
					cmd->forwardmove = 0;

					cmd->buttons &= ~IN_BACK;
				}

				if ( MouseDirection ( check ) == RIGHT && cmd->buttons & IN_FORWARD )
				{
					cmd->forwardmove = 0;

					cmd->buttons &= ~IN_FORWARD;
				}

				break;

			case LEFTSIDE:
				cmd->sidemove = 0;

				cmd->buttons &= ~IN_MOVELEFT;
				cmd->buttons &= ~IN_MOVERIGHT;

				if ( MouseDirection ( check ) == LEFT && cmd->buttons & IN_FORWARD )
				{
					cmd->forwardmove = 0;

					cmd->buttons &= ~IN_FORWARD;
				}

				if ( MouseDirection ( check ) == RIGHT && cmd->buttons & IN_BACK )
				{
					cmd->forwardmove = 0;

					cmd->buttons &= ~IN_BACK;
				}

				break;

			case BACK:
				cmd->forwardmove = 0;

				cmd->buttons &= ~IN_BACK;
				cmd->buttons &= ~IN_FORWARD;

				if ( MouseDirection ( check ) == LEFT && cmd->buttons & IN_MOVELEFT )
				{
					cmd->sidemove = 0;

					cmd->buttons &= ~IN_MOVELEFT;
				}

				if ( MouseDirection ( check ) == RIGHT && cmd->buttons & IN_MOVERIGHT )
				{
					cmd->sidemove = 0;

					cmd->buttons &= ~IN_MOVERIGHT;
				}

				break;
			}
		}

		void StrafeHelper::Data ( usercmd_s *cmd, short check )
		{
			switch ( Direction )
			{
			case FORWARD:
				if ( !( cmd->buttons & IN_BACK ) )
				{
					if ( cmd->buttons & IN_FORWARD )
					{
						if ( MouseDirection ( check ) == LEFT )
						{
							cmd->forwardmove = 176.776703;
							cmd->sidemove = -176.776703;

							cmd->buttons |= IN_MOVELEFT;
						}
						else if ( MouseDirection ( check ) == RIGHT )
						{
							cmd->forwardmove = 176.776703;
							cmd->sidemove = 176.776703;

							cmd->buttons |= IN_MOVERIGHT;
						}
					}
					else
					{
						if ( MouseDirection ( check ) == LEFT )
						{
							cmd->forwardmove = g_Vars.StrafeHelper.Boost;
							cmd->sidemove = -250;

							cmd->buttons |= IN_MOVELEFT;
						}
						else if ( MouseDirection ( check ) == RIGHT )
						{
							cmd->forwardmove = g_Vars.StrafeHelper.Boost;
							cmd->sidemove = 250;

							cmd->buttons |= IN_MOVERIGHT;
						}
					}
				}

				break;

			case RIGHTSIDE:
				if ( !( cmd->buttons & IN_MOVELEFT ) )
				{
					if ( cmd->buttons & IN_MOVERIGHT )
					{
						if ( MouseDirection ( check ) == LEFT )
						{
							cmd->sidemove = 176.776703;
							cmd->forwardmove = 176.776703;

							cmd->buttons |= IN_FORWARD;
						}
						else if ( MouseDirection ( check ) == RIGHT )
						{
							cmd->sidemove = 176.776703;
							cmd->forwardmove = -176.776703;

							cmd->buttons |= IN_BACK;
						}
					}
					else
					{
						if ( MouseDirection ( check ) == LEFT )
						{
							cmd->sidemove = g_Vars.StrafeHelper.Boost;
							cmd->forwardmove = 250;

							cmd->buttons |= IN_FORWARD;
						}
						else if ( MouseDirection ( check ) == RIGHT )
						{
							cmd->sidemove = g_Vars.StrafeHelper.Boost;
							cmd->forwardmove = -250;

							cmd->buttons |= IN_BACK;
						}
					}
				}

				break;

			case LEFTSIDE:
				if ( !( cmd->buttons & IN_MOVERIGHT ) )
				{
					if ( cmd->buttons & IN_MOVELEFT )
					{
						if ( MouseDirection ( check ) == LEFT )
						{
							cmd->sidemove = -176.776703;
							cmd->forwardmove = -176.776703;

							cmd->buttons |= IN_BACK;
						}
						else if ( MouseDirection ( check ) == RIGHT )
						{
							cmd->sidemove = -176.776703;
							cmd->forwardmove = 176.776703;

							cmd->buttons |= IN_FORWARD;
						}
					}
					else
					{
						if ( MouseDirection ( check ) == LEFT )
						{
							cmd->sidemove = -g_Vars.StrafeHelper.Boost;
							cmd->forwardmove = -250;

							cmd->buttons |= IN_BACK;
						}
						else if ( MouseDirection ( check ) == RIGHT )
						{
							cmd->sidemove = -g_Vars.StrafeHelper.Boost;
							cmd->forwardmove = 250;

							cmd->buttons |= IN_FORWARD;
						}
					}
				}

				break;

			case BACK:
				if ( !( cmd->buttons & IN_FORWARD ) )
				{
					if ( cmd->buttons & IN_BACK )
					{
						if ( MouseDirection ( check ) == LEFT )
						{
							cmd->forwardmove = -176.776703;
							cmd->sidemove = 176.776703;

							cmd->buttons |= IN_MOVERIGHT;
						}
						else if ( MouseDirection ( check ) == RIGHT )
						{
							cmd->forwardmove = -176.776703;
							cmd->sidemove = -176.776703;

							cmd->buttons |= IN_MOVELEFT;
						}
					}
					else
					{
						if ( MouseDirection ( check ) == LEFT )
						{
							cmd->forwardmove = -g_Vars.StrafeHelper.Boost;
							cmd->sidemove = 250;

							cmd->buttons |= IN_MOVERIGHT;
						}
						else if ( MouseDirection ( check ) == RIGHT )
						{
							cmd->forwardmove = -g_Vars.StrafeHelper.Boost;
							cmd->sidemove = -250;

							cmd->buttons |= IN_MOVELEFT;
						}
					}
				}

				break;
			}
		}

		void StrafeHelper::KeyEmulation ( short check )
		{
			switch ( Direction )
			{
			case FORWARD:
				if ( MouseDirection ( check ) == LEFT )
				{
					Engine::g_Engine.pfnClientCmd ( "-moveright;+moveleft" );
				}
				else if ( MouseDirection ( check ) == RIGHT )
				{
					Engine::g_Engine.pfnClientCmd ( "-moveleft;+moveright" );
				}

				break;

			case RIGHTSIDE:
				if ( MouseDirection ( check ) == LEFT )
				{
					Engine::g_Engine.pfnClientCmd ( "-back;+forward" );
				}
				else if ( MouseDirection ( check ) == RIGHT )
				{
					Engine::g_Engine.pfnClientCmd ( "-forward;+back" );
				}

				break;

			case LEFTSIDE:
				if ( MouseDirection ( check ) == LEFT )
				{
					Engine::g_Engine.pfnClientCmd ( "-forward;+back" );
				}
				else if ( MouseDirection ( check ) == RIGHT )
				{
					Engine::g_Engine.pfnClientCmd ( "-back;+forward" );
				}

				break;

			case BACK:
				if ( MouseDirection ( check ) == LEFT )
				{
					Engine::g_Engine.pfnClientCmd ( "-moveleft;+moveright" );
				}
				else if ( MouseDirection ( check ) == RIGHT )
				{
					Engine::g_Engine.pfnClientCmd ( "-moveright;+moveleft" );
				}

				break;
			}
		}

		void _fastcall StrafeHelper::SetViewAngles ( float *Angles )
		{
			if ( g_Vars.StrafeHelper.Mode == CORRECT || g_Vars.StrafeHelper.Mode == CORRECT_FILTER ||
				g_Vars.StrafeHelper.Mode == CORRECT_DATA || g_Vars.StrafeHelper.Mode == CORRECT_FILTER_DATA )
			{
				if ( Engine::g_pPlayerMove->flags & FL_ONGROUND || Engine::g_pPlayerMove->movetype == 5 || !( Engine::g_pPlayerMove->waterlevel < 2 ) ||
					Info::g_Local.Player.OnSurf || Engine::g_pPlayerMove->velocity.Length2D ( ) <= g_Vars.StrafeHelper.MinimalSpeed )
				{

				}
				else
				{
					float ViewAngles[3];

					Engine::g_Engine.GetViewAngles ( ViewAngles );

					float AngleDifferent = Angles[1] - ViewAngles[1];

					if ( AngleDifferent > 180 )
					{
						AngleDifferent -= 360;
					}

					if ( AngleDifferent < -180 )
					{
						AngleDifferent += 360;
					}

					if ( g_Vars.StrafeHelper.CorrectLimit )
					{
						if ( AngleDifferent > g_Vars.StrafeHelper.CorrectLimit )
						{
							Angles[1] = ViewAngles[1] + g_Vars.StrafeHelper.CorrectLimitSmooth;
						}

						if ( AngleDifferent < -g_Vars.StrafeHelper.CorrectLimit )
						{
							Angles[1] = ViewAngles[1] - g_Vars.StrafeHelper.CorrectLimitSmooth;
						}
					}

					Engine::g_Engine.SetViewAngles ( Angles );
				}
			}
		}

		void StrafeHelper::StrafeHelperFunc ( usercmd_s *cmd, short check )
		{
			static int8 StrafeCounter, LastDirection;

			static bool Reset;

			if ( Engine::g_pPlayerMove->flags & FL_ONGROUND || Engine::g_pPlayerMove->movetype == 5 || !( Engine::g_pPlayerMove->waterlevel < 2 ) ||
				Info::g_Local.Player.OnSurf || Engine::g_pPlayerMove->velocity.Length2D ( ) <= g_Vars.StrafeHelper.MinimalSpeed )
			{
				if ( g_Vars.StrafeHelper.KeyEmulation )
				{
					if ( Reset )
					{
						Engine::g_Engine.pfnClientCmd ( "-moveright;-moveleft;-back;-forward" );

						Reset = false;
					}
				}

				StrafeCounter = 0;
				LastDirection = 0;
			}
			else
			{
				if ( LastDirection != -1 && MouseDirection ( check ) == LEFT )
				{
					LastDirection = -1;

					++StrafeCounter;
				}
				if ( LastDirection != 1 && MouseDirection ( check ) == RIGHT )
				{
					LastDirection = 1;

					++StrafeCounter;
				}

				if ( StrafeCounter <= g_Vars.StrafeHelper.StrafeLimit || !g_Vars.StrafeHelper.StrafeLimit )
				{
					if ( g_Vars.StrafeHelper.Mode == CORRECT || g_Vars.StrafeHelper.Mode == CORRECT_FILTER ||
						g_Vars.StrafeHelper.Mode == CORRECT_DATA || g_Vars.StrafeHelper.Mode == CORRECT_FILTER_DATA )
					{
						Correct ( check );
					}

					if ( g_Vars.StrafeHelper.Mode == FILTER || g_Vars.StrafeHelper.Mode == CORRECT_FILTER ||
						g_Vars.StrafeHelper.Mode == FILTER_DATA || g_Vars.StrafeHelper.Mode == CORRECT_FILTER_DATA )
					{
						Filter ( cmd, check );
					}

					if ( g_Vars.StrafeHelper.Mode == DATA || g_Vars.StrafeHelper.Mode == CORRECT_FILTER_DATA ||
						g_Vars.StrafeHelper.Mode == CORRECT_DATA || g_Vars.StrafeHelper.Mode == FILTER_DATA )
					{
						g_Vars.StrafeHelper.KeyEmulation ? KeyEmulation ( check ) : Data ( cmd, check );
					}

					Reset = true;
				}
			}
		}

		void _fastcall StrafeHelper::CL_CreateMove ( float frametime, usercmd_s *cmd, short check )
		{
			if ( g_Vars.StrafeHelper.Active || StrafeHelperActive )
			{
				if ( Client::BuildInfo.Build > 4554 )
				{
					Engine::g_Engine.pfnGetCvarPointer ( "cl_mousegrab" )->value = 0;

					if ( g_Vars.StrafeHelper.Type == 1 )
					{
						Engine::g_Engine.pfnGetCvarPointer ( "m_filter" )->value = 0;
					}
					else if ( g_Vars.StrafeHelper.Type == 2 )
					{
						Engine::g_Engine.pfnGetCvarPointer ( "m_filter" )->value = 1;
					}
				}
				else
				{
					if ( g_Vars.StrafeHelper.Type == 1 )
					{
						Engine::g_Engine.pfnGetCvarPointer ( "m_filter" )->value = 0;
					}
					else if ( g_Vars.StrafeHelper.Type == 2 )
					{
						Engine::g_Engine.pfnGetCvarPointer ( "m_filter" )->value = 1;
					}
				}

				g_Vars.StrafeHelper.DirectionAuto ? AutoDirection ( cmd, check ) : Direction = g_Vars.StrafeHelper.Direction;

				StrafeHelperFunc ( cmd, check );
			}
		}

		StrafeHelper g_StrafeHelper;
	}
}