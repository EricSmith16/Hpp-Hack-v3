#include "ESP.h"

namespace Functions
{
	namespace Visuals
	{
		bool ESP::PanicEnabled;

		ESP::ESP ( )
		{
			EntityIndex = 0;
			SoundIndex = 0;

			BoxColor[0] = 0;
			BoxColor[1] = 0;
			BoxColor[2] = 0;
		}

		void _fastcall ESP::PanicKey ( int keynum )
		{
			if ( keynum == g_Vars.ESP.PanicKey )
			{
				PanicEnabled = !PanicEnabled;

				Engine::g_Engine.pfnPlaySoundByName ( PanicEnabled ? "vox/of.wav" : "vox/on.wav", 1 );
			}
		}

		float ESP::GetPlayerDistance ( uint8 Index, bool Meters )
		{
			float Distance = floor ( sqrt ( POW ( abs ( Info::g_Player[Index].Entity->origin.x - Info::g_Local.Entity->origin.x ) ) +
				POW ( abs ( Info::g_Player[Index].Entity->origin.y - Info::g_Local.Entity->origin.y ) ) +
				POW ( abs ( Info::g_Player[Index].Entity->origin.z - Info::g_Local.Entity->origin.z ) ) ) - 32 );

			if ( Meters )
			{
				return Distance < 0 ? 0 : Distance * 0.025f;
			}
			else
			{
				return Distance < 0 ? 0 : Distance;
			}
		}

		void ESP::GetColorPlayerBox ( uint8 Index )
		{
			for ( uint8 i = 0; i < sizeof ( BoxColor ); ++i )
			{
				if ( Info::g_Player[Index].Team == TERRORIST && Info::g_Player[Index].Visible )
				{
					BoxColor[i] = g_Vars.ESP.ColorTVis[i];
				}
				else if ( Info::g_Player[Index].Team == TERRORIST )
				{
					BoxColor[i] = g_Vars.ESP.ColorTHide[i];
				}
				else if ( Info::g_Player[Index].Team == CT && Info::g_Player[Index].Visible )
				{
					BoxColor[i] = g_Vars.ESP.ColorCTVis[i];
				}
				else if ( Info::g_Player[Index].Team == CT )
				{
					BoxColor[i] = g_Vars.ESP.ColorCTHide[i];
				}
				else if ( Info::g_Player[Index].Visible )
				{
					BoxColor[i] = 255;
				}
				else
				{
					BoxColor[i] = 200;
				}
			}
		}

		void ESP::ItemWeaponPars ( char* Weapon, unsigned short Index )
		{
			float EntityScreen[2];

			if ( g_Util.CalcScreen ( Entity[Index].Origin, EntityScreen ) && Entity[Index].Origin.x != 0 )
			{
				if ( g_Vars.ESP.WorldItems && Entity[Index].Type == 1 )
				{
					if ( g_Util.NativeStrStr ( Entity[Index].Name, Weapon ) )
					{
						Renderer::g_Drawing.Box ( int ( EntityScreen[0] - 2 ), int ( EntityScreen[1] ), 6, 6, 1, 0, 0, 0, 255 );

						Renderer::g_Drawing.FillArea ( int ( EntityScreen[0] - 1 ), int ( EntityScreen[1] + 1 ), 4, 4, 255, 120, 50, 255 );

						Renderer::g_Verdana.Print ( int ( EntityScreen[0] ), int ( EntityScreen[1] + 15 ), g_Vars.ESP.FontColor[0],
							g_Vars.ESP.FontColor[1], g_Vars.ESP.FontColor[2], 255, g_Vars.ESP.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, Weapon );
					}
				}
			}
		}

		void ESP::ItemWeaponParsC4 ( unsigned short Index )
		{
			float EntityScreen[2];

			if ( g_Util.CalcScreen ( Entity[Index].Origin, EntityScreen ) && Entity[Index].Origin.x != 0 )
			{
				if ( g_Vars.ESP.WorldItems && Entity[Index].Type == 1 )
				{
					if ( g_Util.NativeStrStr ( Entity[Index].Name, C4_PLANTED ) )
					{
						Renderer::g_Drawing.Box ( int ( EntityScreen[0] - 2 ), int ( EntityScreen[1] ), 6, 6, 1, 0, 0, 0, 255 );

						Renderer::g_Drawing.FillArea ( int ( EntityScreen[0] - 1 ), int ( EntityScreen[1] + 1 ), 4, 4, 255, 0, 0, 255 );

						Renderer::g_Verdana.Print ( int ( EntityScreen[0] ), int ( EntityScreen[1] + 15 ), g_Vars.ESP.FontColor[0],
							g_Vars.ESP.FontColor[1], g_Vars.ESP.FontColor[2], 255, g_Vars.ESP.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, C4 );
					}
				}
			}
		}

		void ESP::ItemWeaponParsC4Planted ( unsigned short Index )
		{
			float EntityScreen[2];

			if ( g_Util.CalcScreen ( Entity[Index].Origin, EntityScreen ) && Entity[Index].Origin.x != 0 )
			{
				if ( g_Vars.ESP.WorldItems && Entity[Index].Type == 1 )
				{
					if ( g_Util.NativeStrStr ( Entity[Index].Name, C4 ) )
					{
						Renderer::g_Drawing.Box ( int ( EntityScreen[0] - 2 ), int ( EntityScreen[1] ), 6, 6, 1, 0, 0, 0, 255 );

						Renderer::g_Drawing.FillArea ( int ( EntityScreen[0] - 1 ), int ( EntityScreen[1] + 1 ), 4, 4, 255, 0, 0, 255 );

						Renderer::g_Verdana.Print ( int ( EntityScreen[0] ), int ( EntityScreen[1] + 15 ), g_Vars.ESP.FontColor[0],
							g_Vars.ESP.FontColor[1], g_Vars.ESP.FontColor[2], 255, g_Vars.ESP.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, C4_PLANTED );

						if ( g_Vars.ESP.C4Timer && Info::g_Local.Bomb.isPlanted )
						{
							Renderer::g_Verdana.Print ( int ( EntityScreen[0] ), int ( EntityScreen[1] + 15 ) + 12,
								g_Vars.ESP.FontColor[0], g_Vars.ESP.FontColor[1], g_Vars.ESP.FontColor[2], 255,
								g_Vars.ESP.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, "time: %.2f", Info::g_Local.Bomb.C4Timer );
						}
					}
				}
			}
		}

		void ESP::DrawPlayer ( uint8 Index )
		{
			if ( Info::g_Local.Player.isAlive )
			{
				if ( ( g_Vars.ESP.Player == 1 && Info::g_Player[Index].Team == Info::g_Local.Player.Team ) ||
					( g_Vars.ESP.PlayerVisibleOnly && !Info::g_Player[Index].Visible ) )
				{
					return;
				}
			}

			Vector Top = Vector ( Info::g_Player[Index].Entity->origin.x, Info::g_Player[Index].Entity->origin.y,
				Info::g_Player[Index].Entity->origin.z + Info::g_Player[Index].Entity->curstate.mins.z );

			Vector Bot = Vector ( Info::g_Player[Index].Entity->origin.x, Info::g_Player[Index].Entity->origin.y,
				Info::g_Player[Index].Entity->origin.z + Info::g_Player[Index].Entity->curstate.maxs.z );

			float ScreenTop[2], ScreenBot[2];

			if ( g_Util.CalcScreen ( Top, ScreenTop ) && g_Util.CalcScreen ( Bot, ScreenBot ) )
			{
				float Height = ScreenBot[1] - ScreenTop[1];
				float PlayerBoxHeight = Info::g_Player[Index].Ducked ? Height : Height * 0.9f;

				if ( g_Vars.ESP.PlayerBox )
				{
					GetColorPlayerBox ( Index );

					if ( g_Vars.ESP.PlayerBox == 1 )
					{
						Renderer::g_Drawing.Box ( int ( ScreenTop[0] - ( PlayerBoxHeight * 0.25f ) ), int ( ScreenTop[1] ), int ( PlayerBoxHeight / 2 ),
							int ( PlayerBoxHeight ), g_Vars.ESP.PlayerBoxLineWidth, BoxColor[0], BoxColor[1], BoxColor[2], 255 );
					}
					else if ( g_Vars.ESP.PlayerBox == 2 )
					{
						Renderer::g_Drawing.BoxOutLine ( int ( ScreenTop[0] - ( PlayerBoxHeight * 0.25f ) ), int ( ScreenTop[1] ), int ( PlayerBoxHeight / 2 ),
							int ( PlayerBoxHeight ), g_Vars.ESP.PlayerBoxLineWidth, BoxColor[0], BoxColor[1], BoxColor[2], 255 );
					}
				}

				if ( g_Vars.ESP.PlayerName )
				{
					Renderer::g_Verdana.Print ( int ( ScreenTop[0] ), int ( PlayerBoxHeight - 5 + ScreenTop[1] ),
						g_Vars.ESP.FontColor[0], g_Vars.ESP.FontColor[1], g_Vars.ESP.FontColor[2], 255,
						g_Vars.ESP.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, Info::g_Player[Index].Info.name );
				}

				if ( g_Vars.ESP.PlayerWeapon )
				{
					float Weapon = ScreenBot[1] + ( 12 - ( ScreenBot[1] - ScreenTop[1] ) );
					float DistanceWeapon = ScreenBot[1] + ( 24 - ( ScreenBot[1] - ScreenTop[1] ) );
					float PlayerWeaponPos_y = g_Vars.ESP.PlayerDistance ? DistanceWeapon : Weapon;

					int SequenceInfo[] =
					{
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 1, 2, 0, 1, 2, 0, 1, 2, 0,
						1, 2, 0, 1, 1, 2, 0, 1, 1, 2,
						0, 1, 2, 0, 1, 2, 0, 1, 2, 0,
						1, 2, 0, 1, 2, 0, 1, 2, 0, 1,
						2, 0, 1, 2, 0, 0, 0, 4, 0, 4,
						0, 5, 0, 5, 0, 0, 1, 1, 2, 0,
						1, 1, 2, 0, 1, 0, 1, 0, 1, 2,
						0, 1, 2, 3, 3, 3, 3, 3, 3, 3,
						3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
						3
					};

					if ( SequenceInfo[Info::g_Player[Index].Entity->curstate.sequence] == 2 )
					{
						Renderer::g_Verdana.Print ( int ( ScreenTop[0] ), int ( PlayerWeaponPos_y + 12 ), 255, 80,
							80, 255, g_Vars.ESP.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, SEQUENCE_RELOADING );
					}
					else if ( SequenceInfo[Info::g_Player[Index].Entity->curstate.sequence] == 5 )
					{
						Renderer::g_Verdana.Print ( int ( ScreenTop[0] ), int ( PlayerWeaponPos_y + 12 ), 255, 80,
							80, 255, g_Vars.ESP.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, SEQUENCE_PLANTING );
					}

					model_s *Model = Engine::g_Studio.GetModelByIndex ( Info::g_Player[Index].Entity->curstate.weaponmodel );

					if ( Model && Model->name )
					{
						char WeaponName[64];

						short len = lstrlen ( Model->name + 9 ) - 3;

						lstrcpyn ( WeaponName, Model->name + 9, len );

						WeaponName[len] = '\0';

						Renderer::g_Verdana.Print ( int ( ScreenTop[0] ), int ( PlayerWeaponPos_y ), g_Vars.ESP.FontColor[0], g_Vars.ESP.FontColor[1],
							g_Vars.ESP.FontColor[2], 255, g_Vars.ESP.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, WeaponName );
					}
				}

				if ( g_Vars.ESP.PlayerDistance )
				{
					float DistancePos_y = ScreenBot[1] + ( 12 - ( ScreenBot[1] - ScreenTop[1] ) );

					short DistanceUnits = int ( GetPlayerDistance ( Index, false ) );
					short DistanceMeters = int ( GetPlayerDistance ( Index, true ) );

					BYTE PlayerDistanceColor[3];

					if ( DistanceUnits >= 0 && DistanceUnits <= 1000 )
					{
						PlayerDistanceColor[0] = 255;
						PlayerDistanceColor[1] = DistanceUnits >= 500 ? g_Util.Interp ( 500, DistanceUnits, 1000, 255, 80 ) : 255;
						PlayerDistanceColor[2] = DistanceUnits <= 500 ? g_Util.Interp ( 0, DistanceUnits, 500, 255, 80 ) : 80;
					}
					else if ( DistanceUnits > 1000 )
					{
						PlayerDistanceColor[0] = 255;
						PlayerDistanceColor[1] = 80;
						PlayerDistanceColor[2] = 80;
					}

					if ( g_Vars.ESP.PlayerDistance == 1 )
					{
						Renderer::g_Verdana.Print ( int ( ScreenTop[0] ), int ( DistancePos_y ), PlayerDistanceColor[0], PlayerDistanceColor[1],
							PlayerDistanceColor[2], 255, g_Vars.ESP.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, "%d u", DistanceUnits );
					}
					else if ( g_Vars.ESP.PlayerDistance == 2 )
					{
						Renderer::g_Verdana.Print ( int ( ScreenTop[0] ), int ( DistancePos_y ), PlayerDistanceColor[0], PlayerDistanceColor[1],
							PlayerDistanceColor[2], 255, g_Vars.ESP.FontOutLine ? FL_CENTER | FL_OUTLINE : FL_CENTER, "%d m", DistanceMeters );
					}
				}
			}
		}

		void ESP::AddEntity ( char* Name, Vector Origin, BYTE Type )
		{
			if ( EntityIndex < MAX_ENTITY )
			{
				lstrcpy ( Entity[EntityIndex].Name, Name );

				Entity[EntityIndex].Origin = Origin;
				Entity[EntityIndex].Type = Type;

				++EntityIndex;
			}
			else
			{
				ClearEntity ( );
			}
		}

		void ESP::ClearEntity ( )
		{
			for ( unsigned short i = 0; i < EntityIndex; ++i )
			{
				g_Util.MemorySet ( &Entity[i].Name[0], 64, 0 );

				Entity[i].Origin = Vector ( 0, 0, 0 );
				Entity[i].Type = 0;
			}

			EntityIndex = 0;
		}

		void _fastcall ESP::HUD_AddEntity ( cl_entity_s *Entity )
		{
			if ( Entity && Entity->model && Entity->model->name && ( g_Vars.ESP.WorldItems || g_Vars.ESP.WorldNades ) )
			{
				if ( g_Util.NativeStrStr ( Entity->model->name, "w_" ) )
				{
					char Name[64];

					short len = lstrlen ( Entity->model->name + 7 ) - 3;

					lstrcpyn ( Name, Entity->model->name + 7, len );

					Name[len] = '\0';

					if ( g_Util.NativeStrStr ( Entity->model->name, HEGREN ) )
					{
						AddEntity ( Name, Entity->origin, 3 );
					}
					else if ( g_Util.NativeStrStr ( Entity->model->name, FLASH ) )
					{
						AddEntity ( Name, Entity->origin, 3 );
					}
					else if ( g_Util.NativeStrStr ( Entity->model->name, SMOKE ) )
					{
						AddEntity ( Name, Entity->origin, 3 );
					}
					else
					{
						if ( g_Vars.ESP.WorldItems )
						{
							AddEntity ( Name, Entity->origin, 1 );
						}
					}
				}
			}

			if ( g_Vars.ESP.Player && Entity && Entity->index != Info::g_Local.Player.Index &&
				Entity->player && Info::g_Player[Entity->index].Valid && g_Vars.ESP.PlayerBarrel )
			{
				if ( Info::g_Local.Player.isAlive )
				{
					if ( ( g_Vars.ESP.Player == 1 && Info::g_Player[Entity->index].Team == Info::g_Local.Player.Team ) ||
						( g_Vars.ESP.PlayerVisibleOnly && !Info::g_Player[Entity->index].Visible ) )
					{
						return;
					}
				}

				short BeamIndex = Engine::g_Engine.pEventAPI->EV_FindModelIndex ( "sprites/laserbeam.spr" );

				Vector End, Up, Right, Forward;

				Vector EntityViewOrg = Entity->origin;

				if ( Entity->curstate.usehull == 0 )
				{
					EntityViewOrg[2] += 17;
				}
				else if ( Entity->curstate.usehull == 1 )
				{
					EntityViewOrg[2] += 12;
				}

				Engine::g_Engine.pfnAngleVectors ( Entity->angles, Forward, Right, Up );

				Forward[2] = -Forward[2];

				Vector Begin = EntityViewOrg;

				BYTE PlayerBarrelColor[3];

				if ( Info::g_Player[Entity->index].Team == TERRORIST )
				{
					PlayerBarrelColor[0] = 255;
					PlayerBarrelColor[1] = 0;
					PlayerBarrelColor[2] = 0;
				}
				else if ( Info::g_Player[Entity->index].Team == CT )
				{
					PlayerBarrelColor[0] = 0;
					PlayerBarrelColor[1] = 0;
					PlayerBarrelColor[2] = 255;
				}
				else
				{
					PlayerBarrelColor[0] = 200;
					PlayerBarrelColor[1] = 200;
					PlayerBarrelColor[2] = 200;
				}

				End = Begin + Forward * 8000;

				Engine::g_Engine.pEfxAPI->R_BeamPoints ( Begin, End, BeamIndex, 0.001f, 0.9f, 0, 32,
					2, 0, 0, PlayerBarrelColor[0], PlayerBarrelColor[1], PlayerBarrelColor[2] );
			}
		}

		void ESP::DrawWorld ( )
		{
			for ( unsigned short Index = 0; Index < EntityIndex; ++Index )
			{
				ItemWeaponPars ( USP, Index );
				ItemWeaponPars ( GLOCK18, Index );
				ItemWeaponPars ( DEAGLE, Index );
				ItemWeaponPars ( P228, Index );
				ItemWeaponPars ( ELITE, Index );
				ItemWeaponPars ( FIVESEVEN, Index );
				ItemWeaponPars ( M3, Index );
				ItemWeaponPars ( XM1014, Index );
				ItemWeaponPars ( MP5, Index );
				ItemWeaponPars ( TMP, Index );
				ItemWeaponPars ( P90, Index );
				ItemWeaponPars ( MAC10, Index );
				ItemWeaponPars ( UMP45, Index );
				ItemWeaponPars ( FAMAS, Index );
				ItemWeaponPars ( SG552, Index );
				ItemWeaponPars ( AK47, Index );
				ItemWeaponPars ( M4A1, Index );
				ItemWeaponPars ( AUG, Index );
				ItemWeaponPars ( SCOUT, Index );
				ItemWeaponPars ( AWP, Index );
				ItemWeaponPars ( G3SG1, Index );
				ItemWeaponPars ( SG550, Index );
				ItemWeaponPars ( GALIL, Index );
				ItemWeaponPars ( M249, Index );
				ItemWeaponPars ( SHIELD, Index );
				ItemWeaponPars ( BACKPACK, Index );
				ItemWeaponPars ( THIGHPACK, Index );
				ItemWeaponParsC4 ( Index );
				ItemWeaponParsC4Planted ( Index );

				float EntityScreen[2];

				if ( g_Util.CalcScreen ( Entity[Index].Origin, EntityScreen ) && Entity[Index].Origin.x != 0 )
				{
					float uppt[] = { Entity[Index].Origin.x - Info::g_Local.Player.ViewOrg.x, Entity[Index].Origin.y - Info::g_Local.Player.ViewOrg.y,
						Entity[Index].Origin.z - Info::g_Local.Player.ViewOrg.z };

					float l = sqrt ( VectorLengthSquared ( uppt ) );

					l = max ( 100, l );

					if ( g_Vars.ESP.WorldNades && Entity[Index].Type == 3 )
					{
						if ( g_Util.NativeStrStr ( Entity[Index].Name, HEGREN ) )
						{
							Renderer::g_Drawing.Circle ( EntityScreen[0], EntityScreen[1], 3000 / l, 25, 2, 255, 50, 50, 255 );
						}
						else if ( g_Util.NativeStrStr ( Entity[Index].Name, FLASH ) )
						{
							Renderer::g_Drawing.Circle ( EntityScreen[0], EntityScreen[1], 3000 / l, 25, 2, 255, 255, 255, 255 );
						}
						else if ( g_Util.NativeStrStr ( Entity[Index].Name, SMOKE ) )
						{
							Renderer::g_Drawing.Circle ( EntityScreen[0], EntityScreen[1], 3000 / l, 25, 2, 50, 255, 50, 255 );
						}
					}
				}
			}

			ClearEntity ( );
		}

		void _fastcall ESP::AddSound ( DWORD Time, Vector Origin )
		{
			if ( SoundIndex < MAX_SOUNDS )
			{
				Sound[SoundIndex].Time = Time;
				Sound[SoundIndex].Origin = Origin;

				++SoundIndex;
			}
			else
			{
				ClearSound ( );
			}
		}

		void ESP::ClearSound ( )
		{
			for ( unsigned short i = 0; i < SoundIndex; ++i )
			{
				Sound[i].Time = 0;
				Sound[i].Origin = Vector ( 0, 0, 0 );
			}

			SoundIndex = 0;
		}

		void ESP::DrawSound ( )
		{
			for ( unsigned short i = 0; i < SoundIndex; ++i )
			{
				float uppt[] = { Sound[i].Origin.x - Info::g_Local.Player.ViewOrg.x, Sound[i].Origin.y - Info::g_Local.Player.ViewOrg.y,
					Sound[i].Origin.z - Info::g_Local.Player.ViewOrg.z };

				float l = sqrt ( VectorLengthSquared ( uppt ) );

				l = max ( 100, l );

				float SoundSize = 7020 / l;
				float SoundTime = Sound[i].Time + g_Vars.ESP.SoundFadeTime;

				if ( SoundTime <= GetTickCount ( ) )
				{
					Sound[i].Time = 0;
					Sound[i].Origin = Vector ( 0, 0, 0 );
				}
				else
				{
					float SoundScreen[2];

					float SoundSize_S = g_Util.Interp ( Sound[i].Time, GetTickCount ( ), SoundTime, SoundSize, 0 );

					if ( g_Util.CalcScreen ( Sound[i].Origin, SoundScreen ) )
					{
						Renderer::g_Drawing.Box ( SoundScreen[0] - ( SoundSize_S / 2 ), SoundScreen[1] - ( SoundSize_S / 2 ),
							g_Util.Interp ( Sound[i].Time, GetTickCount ( ), SoundTime, SoundSize, 0 ),
							g_Util.Interp ( Sound[i].Time, GetTickCount ( ), SoundTime, SoundSize, 0 ),
							g_Vars.ESP.SoundLineWidth, g_Vars.ESP.SoundColor[0], g_Vars.ESP.SoundColor[1], g_Vars.ESP.SoundColor[2],
							g_Util.Interp ( Sound[i].Time, GetTickCount ( ), SoundTime, 255, 0 ) );
					}
				}
			}
		}

		void ESP::DrawC4Timer ( )
		{
			Renderer::g_Font.Print ( int ( Engine::g_Screen.iWidth / 1.5f ), 15, g_Vars.ESP.FontColor[0], g_Vars.ESP.FontColor[1],
				g_Vars.ESP.FontColor[2], 255, FL_OUTLINE, "c4timer: %.0f", Info::g_Local.Bomb.C4Timer );
		}

		void _fastcall ESP::HUD_Redraw ( )
		{
			for ( uint8 Index = 1; Index <= Engine::g_Engine.GetMaxClients ( ); ++Index )
			{
				if ( g_Vars.ESP.Player && Info::g_Player[Index].Valid && Index != Info::g_Local.Player.Index )
				{
					DrawPlayer ( Index );
				}
			}

			if ( g_Vars.ESP.WorldItems || g_Vars.ESP.WorldNades )
			{
				DrawWorld ( );
			}

			if ( g_Vars.ESP.Sound )
			{
				DrawSound ( );
			}

			if ( g_Vars.ESP.C4Timer && Info::g_Local.Bomb.isPlanted )
			{
				DrawC4Timer ( );
			}
		}

		ESP g_ESP;

		SoundStruct Sound[MAX_SOUNDS];
		EntityStruct Entity[MAX_ENTITY];
	}
}