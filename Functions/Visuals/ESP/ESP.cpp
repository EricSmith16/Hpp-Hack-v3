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

		void ESP::PanicKey ( int keynum )
		{
			if ( keynum == g_Vars.esp.panic_key )
			{
				PanicEnabled = !PanicEnabled;

				Engine::g_Engine.pfnPlaySoundByName ( PanicEnabled ? "vox/of.wav" : "vox/on.wav", 1 );
			}
		}

		float ESP::GetPlayerDistance ( BYTE Index, bool Meters )
		{
			float Distance = floor ( sqrt ( POW ( abs ( Information::g_Player[Index].Entity->origin.x - Information::g_Local.Entity->origin.x ) ) +
				POW ( abs ( Information::g_Player[Index].Entity->origin.y - Information::g_Local.Entity->origin.y ) ) +
				POW ( abs ( Information::g_Player[Index].Entity->origin.z - Information::g_Local.Entity->origin.z ) ) ) - 32 );

			if ( Meters )
			{
				return Distance < 0 ? 0 : Distance * 0.025f;
			}
			else
			{
				return Distance < 0 ? 0 : Distance;
			}
		}

		void ESP::GetColorPlayerBox ( BYTE Index )
		{
			for ( BYTE i = 0; i < sizeof ( BoxColor ); ++i )
			{
				if ( g_Vars.esp.player_visible_check )
				{
					if ( Information::g_Player[Index].Team == TERRORIST && Information::g_Player[Index].Visible )
					{
						BoxColor[i] = g_Vars.esp.color_t_vis[i];
					}
					else if ( Information::g_Player[Index].Team == TERRORIST )
					{
						BoxColor[i] = g_Vars.esp.color_t_hide[i];
					}
					else if ( Information::g_Player[Index].Team == CT && Information::g_Player[Index].Visible )
					{
						BoxColor[i] = g_Vars.esp.color_ct_vis[i];
					}
					else if ( Information::g_Player[Index].Team == CT )
					{
						BoxColor[i] = g_Vars.esp.color_ct_hide[i];
					}
					else if ( Information::g_Player[Index].Visible )
					{
						BoxColor[i] = 255;
					}
					else
					{
						BoxColor[i] = 200;
					}
				}
				else
				{
					if ( Information::g_Player[Index].Team == TERRORIST )
					{
						BoxColor[i] = g_Vars.esp.color_t_hide[i];
					}
					else if ( Information::g_Player[Index].Team == CT )
					{
						BoxColor[i] = g_Vars.esp.color_ct_hide[i];
					}
					else
					{
						BoxColor[i] = 255;
					}
				}
			}
		}

		void ESP::DrawPlayer ( BYTE Index )
		{
			if ( Information::g_Local.Alive )
			{
				if ( ( g_Vars.esp.player == 1 && Information::g_Player[Index].Team == Information::g_Local.Team ) ||
					( g_Vars.esp.player_visible_only && !Information::g_Player[Index].Visible ) )
				{
					return;
				}
			}
			else
			{
				if ( !g_Vars.esp.player_ignore_death )
				{
					if ( ( g_Vars.esp.player == 1 && Information::g_Player[Index].Team == Information::g_Local.Team ) ||
						( g_Vars.esp.player_visible_only && !Information::g_Player[Index].Visible ) )
					{
						return;
					}
				}
			}

			Vector Top = Vector ( Information::g_Player[Index].Entity->origin.x, Information::g_Player[Index].Entity->origin.y,
				Information::g_Player[Index].Entity->origin.z + Information::g_Player[Index].Entity->curstate.mins.z );

			Vector Bot = Vector ( Information::g_Player[Index].Entity->origin.x, Information::g_Player[Index].Entity->origin.y,
				Information::g_Player[Index].Entity->origin.z + Information::g_Player[Index].Entity->curstate.maxs.z );

			float ScreenTop[2], ScreenBot[2];

			if ( g_Util.CalcScreen ( Top, ScreenTop ) && g_Util.CalcScreen ( Bot, ScreenBot ) )
			{
				float PlayerBoxHeight = Information::g_Player[Index].Ducked ? ( ScreenBot[1] - ScreenTop[1] ) * g_Vars.esp.player_box_size :
					( ScreenBot[1] - ScreenTop[1] ) * 0.9f * g_Vars.esp.player_box_size;

				if ( g_Vars.esp.player_box )
				{
					GetColorPlayerBox ( Index );

					if ( g_Vars.esp.player_box == 1 )
					{
						Renderer::g_Drawing.Box ( int ( ScreenTop[0] - ( PlayerBoxHeight * 0.25f ) ),
							int ( ScreenTop[1] ), int ( PlayerBoxHeight / 2 ), int ( PlayerBoxHeight ),
							g_Vars.esp.player_box_linewidth, BoxColor[0], BoxColor[1], BoxColor[2], 255 );
					}
					else if ( g_Vars.esp.player_box == 2 )
					{
						Renderer::g_Drawing.BoxWithOutLine ( int ( ScreenTop[0] - ( PlayerBoxHeight * 0.25f ) ),
							int ( ScreenTop[1] ), int ( PlayerBoxHeight / 2 ), int ( PlayerBoxHeight ),
							g_Vars.esp.player_box_linewidth, BoxColor[0], BoxColor[1], BoxColor[2], 255 );
					}
				}

				if ( g_Vars.esp.player_name )
				{
					Renderer::g_Verdana.Print ( int ( ScreenTop[0] ), int ( PlayerBoxHeight - 5 + ScreenTop[1] ),
						g_Vars.esp.font_color[0], g_Vars.esp.font_color[1], g_Vars.esp.font_color[2], 255,
						g_Vars.esp.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, Information::g_Player[Index].Info.name );
				}

				if ( g_Vars.esp.player_weapon )
				{
					float PlayerWeaponPos_y = g_Vars.esp.player_distance ? ScreenBot[1] + ( 24 - ( ScreenBot[1] - ScreenTop[1] ) ) :
						ScreenBot[1] + ( 12 - ( ScreenBot[1] - ScreenTop[1] ) );

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

					if ( SequenceInfo[Information::g_Player[Index].Entity->curstate.sequence] == 2 )
					{
						Renderer::g_Verdana.Print ( int ( ScreenTop[0] ), int ( PlayerWeaponPos_y + 12 ), 255, 80,
							80, 255, g_Vars.esp.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, SEQUENCE_RELOADING );
					}
					else if ( SequenceInfo[Information::g_Player[Index].Entity->curstate.sequence] == 5 )
					{
						Renderer::g_Verdana.Print ( int ( ScreenTop[0] ), int ( PlayerWeaponPos_y + 12 ), 255, 80,
							80, 255, g_Vars.esp.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, SEQUENCE_PLANTING );
					}

					model_s *Model = Engine::g_Studio.GetModelByIndex ( Information::g_Player[Index].Entity->curstate.weaponmodel );

					if ( Model && Model->name )
					{
						char WeaponName[64];

						int len = lstrlen ( Model->name + 9 ) - 3;

						lstrcpyn ( WeaponName, Model->name + 9, len );

						WeaponName[len] = '\0';

						Renderer::g_Verdana.Print ( int ( ScreenTop[0] ), int ( PlayerWeaponPos_y ),
							g_Vars.esp.font_color[0], g_Vars.esp.font_color[1], g_Vars.esp.font_color[2], 255,
							g_Vars.esp.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, WeaponName );
					}
				}

				if ( g_Vars.esp.player_distance )
				{
					int DistanceUnits = int ( GetPlayerDistance ( Index, false ) );

					BYTE PlayerDistanceColor[4];

					if ( DistanceUnits >= 0 && DistanceUnits <= 1000 )
					{
						PlayerDistanceColor[0] = 255;
						PlayerDistanceColor[1] = DistanceUnits >= 500 ? g_Util.Interp ( 500, DistanceUnits, 1000, 255, 80 ) : 255;
						PlayerDistanceColor[2] = DistanceUnits <= 500 ? g_Util.Interp ( 0, DistanceUnits, 500, 255, 80 ) : 80;
						PlayerDistanceColor[3] = 255;
					}
					else if ( DistanceUnits > 1000 )
					{
						PlayerDistanceColor[0] = 255;
						PlayerDistanceColor[1] = 80;
						PlayerDistanceColor[2] = 80;
						PlayerDistanceColor[3] = 255;
					}

					if ( g_Vars.esp.player_distance == 1 )
					{
						Renderer::g_Verdana.Print ( int ( ScreenTop[0] ), int ( ScreenBot[1] + ( 12 - ( ScreenBot[1] - ScreenTop[1] ) ) ),
							PlayerDistanceColor[0], PlayerDistanceColor[1], PlayerDistanceColor[2], PlayerDistanceColor[3],
							g_Vars.esp.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, "%d u", DistanceUnits );
					}
					else if ( g_Vars.esp.player_distance == 2 )
					{
						Renderer::g_Verdana.Print ( int ( ScreenTop[0] ), int ( ScreenBot[1] + ( 12 - ( ScreenBot[1] - ScreenTop[1] ) ) ),
							PlayerDistanceColor[0], PlayerDistanceColor[1], PlayerDistanceColor[2], PlayerDistanceColor[3],
							g_Vars.esp.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, "%d m", int ( GetPlayerDistance ( Index, true ) ) );
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
			for ( unsigned short int i = 0; i < EntityIndex; ++i )
			{
				g_Util.MemorySet ( &Entity[i].Name[0], 64, 0 );

				Entity[i].Origin = Vector ( 0, 0, 0 );
				Entity[i].Type = 0;
			}

			EntityIndex = 0;
		}

		void _fastcall ESP::HUD_AddEntity ( cl_entity_s *Entity )
		{
			if ( g_Vars.esp.world && Entity && Entity->model && Entity->model->name && ( g_Vars.esp.world_weapons || g_Vars.esp.world_nades ) )
			{
				if ( g_Util.native_strstr ( Entity->model->name, "w_" ) )
				{
					char Name[64];

					int len = lstrlen ( Entity->model->name + 7 ) - 3;

					lstrcpyn ( Name, Entity->model->name + 7, len );

					Name[len] = '\0';

					if ( g_Util.native_strstr ( Entity->model->name, HEGREN ) )
					{
						AddEntity ( Name, Entity->origin, 3 );
					}
					else if ( g_Util.native_strstr ( Entity->model->name, FLASH ) )
					{
						AddEntity ( Name, Entity->origin, 3 );
					}
					else if ( g_Util.native_strstr ( Entity->model->name, SMOKE ) )
					{
						AddEntity ( Name, Entity->origin, 3 );
					}
					else
					{
						if ( g_Vars.esp.world_weapons )
						{
							AddEntity ( Name, Entity->origin, 1 );
						}
					}
				}
			}

			if ( g_Vars.esp.player && Entity && Entity->index != Information::g_Local.Index &&
				Entity->player && Information::g_Player[Entity->index].Valid && g_Vars.esp.player_barrel )
			{
				if ( Information::g_Local.Alive )
				{
					if ( ( g_Vars.esp.player == 1 && Information::g_Player[Entity->index].Team == Information::g_Local.Team ) ||
						( g_Vars.esp.player_visible_only && !Information::g_Player[Entity->index].Visible ) )
					{
						return;
					}
				}
				else
				{
					if ( !g_Vars.esp.player_ignore_death )
					{
						if ( ( g_Vars.esp.player == 1 && Information::g_Player[Entity->index].Team == Information::g_Local.Team ) ||
							( g_Vars.esp.player_visible_only && !Information::g_Player[Entity->index].Visible ) )
						{
							return;
						}
					}
				}

				int BeamIndex = Engine::g_Engine.pEventAPI->EV_FindModelIndex ( "sprites/laserbeam.spr" );

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

				if ( Information::g_Player[Entity->index].Team == TERRORIST )
				{
					PlayerBarrelColor[0] = 255;
					PlayerBarrelColor[1] = 0;
					PlayerBarrelColor[2] = 0;
				}
				else if ( Information::g_Player[Entity->index].Team == CT )
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
			for ( unsigned short int i = 0; i < EntityIndex; ++i )
			{
				float EntityScreen[2];

				if ( g_Util.CalcScreen ( Entity[i].Origin, EntityScreen ) && Entity[i].Origin.x != 0 )
				{
					float uppt[] = { Entity[i].Origin.x - Information::g_Local.ViewOrg.x, Entity[i].Origin.y - Information::g_Local.ViewOrg.y,
						Entity[i].Origin.z - Information::g_Local.ViewOrg.z };

					float l = sqrt ( VectorLengthSquared ( uppt ) );

					l = max ( 100, l );

					if ( g_Vars.esp.world_weapons && Entity[i].Type == 1 )
					{
						if ( g_Util.native_strstr ( Entity[i].Name, USP ) )
						{
							WEAPON_PARS ( USP );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, GLOCK18 ) )
						{
							WEAPON_PARS ( GLOCK18 );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, DEAGLE ) )
						{
							WEAPON_PARS ( DEAGLE );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, P228 ) )
						{
							WEAPON_PARS ( P228 );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, ELITE ) )
						{
							WEAPON_PARS ( ELITE );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, FIVESEVEN ) )
						{
							WEAPON_PARS ( FIVESEVEN );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, M3 ) )
						{
							WEAPON_PARS ( M3 );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, XM1014 ) )
						{
							WEAPON_PARS ( XM1014 );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, MP5 ) )
						{
							WEAPON_PARS ( MP5 );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, TMP ) )
						{
							WEAPON_PARS ( TMP );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, P90 ) )
						{
							WEAPON_PARS ( P90 );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, MAC10 ) )
						{
							WEAPON_PARS ( MAC10 );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, UMP45 ) )
						{
							WEAPON_PARS ( UMP45 );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, FAMAS ) )
						{
							WEAPON_PARS ( FAMAS );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, SG552 ) )
						{
							WEAPON_PARS ( SG552 );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, AK47 ) )
						{
							WEAPON_PARS ( AK47 );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, M4A1 ) )
						{
							WEAPON_PARS ( M4A1 );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, AUG ) )
						{
							WEAPON_PARS ( AUG );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, SCOUT ) )
						{
							WEAPON_PARS ( SCOUT );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, AWP ) )
						{
							WEAPON_PARS ( AWP );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, G3SG1 ) )
						{
							WEAPON_PARS ( G3SG1 );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, SG550 ) )
						{
							WEAPON_PARS ( SG550 );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, GALIL ) )
						{
							WEAPON_PARS ( GALIL );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, M249 ) )
						{
							WEAPON_PARS ( M249 );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, SHIELD ) )
						{
							WEAPON_PARS ( SHIELD );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, BACKPACK ) )
						{
							WEAPON_PARS_C4 ( BACKPACK );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, THIGHPACK ) )
						{
							WEAPON_PARS ( THIGHPACK );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, C4 ) )
						{
							WEAPON_PARS_C4_PLANTED ( C4_PLANTED );
						}
						else
						{
							Renderer::g_Drawing.Box ( int ( EntityScreen[0] - 2 ), int ( EntityScreen[1] ), 6, 6, 1, 0, 0, 0, 255 );

							Renderer::g_Drawing.Fill ( int ( EntityScreen[0] - 1 ), int ( EntityScreen[1] + 1 ), 4, 4, 255, 150, 50, 255 );

							Renderer::g_Verdana.Print ( int ( EntityScreen[0] ), int ( EntityScreen[1] + 15 ),
								g_Vars.esp.font_color[0], g_Vars.esp.font_color[1], g_Vars.esp.font_color[2], 255,
								g_Vars.esp.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, Entity[i].Name );
						}
					}
					else if ( g_Vars.esp.world_nades && Entity[i].Type == 3 )
					{
						if ( g_Util.native_strstr ( Entity[i].Name, HEGREN ) )
						{
							Renderer::g_Drawing.Circle ( EntityScreen[0], EntityScreen[1], 3000 / l, 25, 2, 255, 50, 50, 255 );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, FLASH ) )
						{
							Renderer::g_Drawing.Circle ( EntityScreen[0], EntityScreen[1], 3000 / l, 25, 2, 255, 255, 255, 255 );
						}
						else if ( g_Util.native_strstr ( Entity[i].Name, SMOKE ) )
						{
							Renderer::g_Drawing.Circle ( EntityScreen[0], EntityScreen[1], 3000 / l, 25, 2, 50, 255, 50, 255 );
						}
					}
				}
			}

			ClearEntity ( );
		}

		void ESP::AddSound ( DWORD Time, Vector Origin )
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
			for ( unsigned short int i = 0; i < SoundIndex; ++i )
			{
				Sound[i].Time = 0;
				Sound[i].Origin = Vector ( 0, 0, 0 );
			}

			SoundIndex = 0;
		}

		void ESP::DrawSound ( )
		{
			for ( unsigned short int i = 0; i < SoundIndex; ++i )
			{
				float uppt[] = { Sound[i].Origin.x - Information::g_Local.ViewOrg.x, Sound[i].Origin.y - Information::g_Local.ViewOrg.y,
					Sound[i].Origin.z - Information::g_Local.ViewOrg.z };

				float l = sqrt ( VectorLengthSquared ( uppt ) );

				l = max ( 100, l );

				float SoundSize = 7020 / l;
				float SoundTime = Sound[i].Time + g_Vars.esp.sound_fade_time;

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
							g_Vars.esp.sound_linewidth, g_Vars.esp.sound_color[0], g_Vars.esp.sound_color[1], g_Vars.esp.sound_color[2],
							g_Util.Interp ( Sound[i].Time, GetTickCount ( ), SoundTime, 255, 0 ) );
					}
				}
			}
		}

		void ESP::DrawC4Timer ( )
		{
			Renderer::g_Font.Print ( Engine::g_Screen.iWidth / 1.5f, 15, g_Vars.esp.font_color[0], g_Vars.esp.font_color[1],
				g_Vars.esp.font_color[2], 255, FL_OUTLINE, "c4timer: %.0f", Information::g_Local.Bomb.C4Timer );
		}

		void _fastcall ESP::HUD_Redraw ( )
		{
			for ( BYTE Index = 1; Index <= Engine::g_Engine.GetMaxClients ( ); ++Index )
			{
				if ( g_Vars.esp.player && Information::g_Player[Index].Valid && Index != Information::g_Local.Index )
				{
					DrawPlayer ( Index );
				}
			}

			if ( g_Vars.esp.world )
			{
				DrawWorld ( );
			}

			if ( g_Vars.esp.sound )
			{
				DrawSound ( );
			}

			if ( g_Vars.esp.c4timer && Information::g_Local.Bomb.isPlanted )
			{
				DrawC4Timer ( );
			}
		}

		ESP g_ESP;

		entity_s Entity[MAX_ENTITY];
		sound_s Sound[MAX_SOUNDS];
	}
}