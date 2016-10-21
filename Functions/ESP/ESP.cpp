#include "ESP.h"

#pragma warning (disable: 4244)

namespace Functions
{
	float ESP::GetPlayerDistance ( struct cl_entity_s *Entity, struct cl_entity_s *Local, bool Meters )
	{
		if ( Meters )
		{
			return floor ( sqrt ( POW ( abs ( Entity->origin.x - Local->origin.x ) ) + POW ( abs ( Entity->origin.y - Local->origin.y ) ) +
				POW ( abs ( Entity->origin.z - Local->origin.z ) ) ) - 32 ) * 0.025f;
		}
		else
		{
			return floor ( sqrt ( POW ( abs ( Entity->origin.x - Local->origin.x ) ) + POW ( abs ( Entity->origin.y - Local->origin.y ) ) +
				POW ( abs ( Entity->origin.z - Local->origin.z ) ) ) - 32 );
		}
	}

	void ESP::GetColorPlayerBox ( int Index )
	{
		if ( Engine::PlayerTeam[Index] == TERRORIST && Engine::g_Player[Index].Visible )
		{
			player_box.color[0] = Files::g_IniRead.esp.t_vis_color[0];
			player_box.color[1] = Files::g_IniRead.esp.t_vis_color[1];
			player_box.color[2] = Files::g_IniRead.esp.t_vis_color[2];
		}
		else if ( Engine::PlayerTeam[Index] == TERRORIST )
		{
			player_box.color[0] = Files::g_IniRead.esp.t_hide_color[0];
			player_box.color[1] = Files::g_IniRead.esp.t_hide_color[1];
			player_box.color[2] = Files::g_IniRead.esp.t_hide_color[2];
		}
		else if ( Engine::PlayerTeam[Index] == CT && Engine::g_Player[Index].Visible )
		{
			player_box.color[0] = Files::g_IniRead.esp.ct_vis_color[0];
			player_box.color[1] = Files::g_IniRead.esp.ct_vis_color[1];
			player_box.color[2] = Files::g_IniRead.esp.ct_vis_color[2];
		}
		else if ( Engine::PlayerTeam[Index] == CT )
		{
			player_box.color[0] = Files::g_IniRead.esp.ct_hide_color[0];
			player_box.color[1] = Files::g_IniRead.esp.ct_hide_color[1];
			player_box.color[2] = Files::g_IniRead.esp.ct_hide_color[2];
		}
		else if ( Engine::g_Player[Index].Visible )
		{
			player_box.color[0] = 255;
			player_box.color[1] = 255;
			player_box.color[2] = 255;
		}
		else
		{
			player_box.color[0] = 100;
			player_box.color[1] = 100;
			player_box.color[2] = 100;
		}
	}

	void ESP::GetColorFont ( )
	{
		font.color[0] = Files::g_IniRead.esp.font_color[0];
		font.color[1] = Files::g_IniRead.esp.font_color[1];
		font.color[2] = Files::g_IniRead.esp.font_color[2];
	}

	void ESP::DrawPlayer ( struct cl_entity_s *Entity, struct cl_entity_s *Local, int Index )
	{
		if ( Engine::g_Local.Alive )
		{
			if ( ( Files::g_IniRead.esp.player == 1 && Engine::PlayerTeam[Index] == Engine::g_Local.Team ) ||
				( Files::g_IniRead.esp.player_visible_only && !Engine::g_Player[Index].Visible ) )
			{
				return;
			}
		}

		Vector Top = Vector ( Entity->origin.x, Entity->origin.y, Entity->origin.z + Entity->curstate.mins.z );
		Vector Bot = Vector ( Entity->origin.x, Entity->origin.y, Entity->origin.z + Entity->curstate.maxs.z );

		float ScreenTop[2], ScreenBot[2];

		if ( g_Util.CalcScreen ( Top, ScreenTop ) && g_Util.CalcScreen ( Bot, ScreenBot ) )
		{
			float height = Engine::g_Player[Index].Ducked ? ScreenBot[1] - ScreenTop[1] : ( ScreenBot[1] - ScreenTop[1] ) * 0.9f;

			if ( Files::g_IniRead.esp.player_box )
			{
				GetColorPlayerBox ( Index );

				float x = ScreenTop[0] - ( height * 0.25f );

				float width = height * 0.5f;

				float linewidth = Files::g_IniRead.esp.player_box_linewidth;

				Files::g_IniRead.esp.player_box_outline ?

					Renderer::g_Drawing.DrawShadowBox ( ( int )x, ( int )ScreenTop[1], ( int )width, ( int )height,
						linewidth, player_box.color[0], player_box.color[1], player_box.color[2], 255 ) :

					Renderer::g_Drawing.DrawBox ( ( int )x, ( int )ScreenTop[1], ( int )width, ( int )height, linewidth,
						player_box.color[0], player_box.color[1], player_box.color[2], 255 );
			}

			if ( Files::g_IniRead.esp.player_name )
			{
				GetColorFont ( );

				float y = height - 5 + ScreenTop[1];

				Renderer::g_Verdana.Print ( ScreenTop[0], y, font.color[0], font.color[1], font.color[2], 255,
					Files::g_IniRead.esp.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, Engine::g_Player[Index].Info.name );
			}

			if ( Files::g_IniRead.esp.player_weapon )
			{
				GetColorFont ( );

				float y = Files::g_IniRead.esp.player_distance ? ScreenBot[1] + ( 24 - ( ScreenBot[1] - ScreenTop[1] ) ) :
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

				switch ( SequenceInfo[Entity->curstate.sequence] )
				{
				case 2:
					Renderer::g_Verdana.Print ( ScreenTop[0], y + 12, 255, 100, 100, 255,
						Files::g_IniRead.esp.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, SEQUENCE_RELOADING );

					break;

				case 5:
					Renderer::g_Verdana.Print ( ScreenTop[0], y + 12, 255, 100, 100, 255,
						Files::g_IniRead.esp.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, SEQUENCE_PLANTING );

					break;
				}

				struct model_s *Model = Engine::g_Studio.GetModelByIndex ( Entity->curstate.weaponmodel );

				if ( Model->name )
				{
					char WeaponName[64];

					int Len = lstrlen ( Model->name + 9 ) - 3;

					lstrcpyn ( WeaponName, Model->name + 9, Len );

					WeaponName[Len] = '\0';

					Renderer::g_Verdana.Print ( ScreenTop[0], y, font.color[0], font.color[1], font.color[2],
						255, Files::g_IniRead.esp.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, WeaponName );
				}
			}

			if ( Files::g_IniRead.esp.player_distance )
			{
				GetColorFont ( );

				float y = ScreenBot[1] + ( 12 - ( ScreenBot[1] - ScreenTop[1] ) );

				switch ( Files::g_IniRead.esp.player_distance )
				{
				case 1:
					Renderer::g_Verdana.Print ( ScreenTop[0], y, font.color[0],
						font.color[1], font.color[2], 255, Files::g_IniRead.esp.font_outline ?
						FL_CENTER | FL_OUTLINE : FL_CENTER, "%.0f u", GetPlayerDistance ( Entity, Local, false ) );

					break;

				case 2:
					Renderer::g_Verdana.Print ( ScreenTop[0], y, font.color[0],
						font.color[1], font.color[2], 255, Files::g_IniRead.esp.font_outline ?
						FL_CENTER | FL_OUTLINE : FL_CENTER, "%.0f m", GetPlayerDistance ( Entity, Local, true ) );

					break;
				}
			}
		}
	}

	void ESP::AddEntity ( char* Name, int Important, Vector Origin, BYTE Type )
	{
		if ( g_ESP.EntityIndex < MAX_ENTITY )
		{
			lstrcpy ( entity[g_ESP.EntityIndex].Name, Name );

			entity[g_ESP.EntityIndex].Important = Important;
			entity[g_ESP.EntityIndex].Origin = Origin;
			entity[g_ESP.EntityIndex].Type = Type;

			++g_ESP.EntityIndex;
		}
		else
		{
			ClearEntity ( );
		}
	}

	void ESP::ClearEntity ( )
	{
		for ( int i = 0; i < g_ESP.EntityIndex; ++i )
		{
			g_Util.MemorySet ( &entity[i].Name[0], 64, 0 );

			entity[i].Important = 0;
			entity[i].Origin = Vector ( 0, 0, 0 );
			entity[i].Type = 0;
		}

		g_ESP.EntityIndex = 0;
	}

	void ESP::HUD_AddEntity ( struct cl_entity_s *Entity )
	{
		if ( Entity->model->name && ( Files::g_IniRead.esp.world_weapons || Files::g_IniRead.esp.world_nades ) )
		{
			int Important = 0;

			if ( g_Util.native_strstr ( Entity->model->name, "w_" ) )
			{
				char Name[64];

				int Len = lstrlen ( Entity->model->name + 7 ) - 3;

				lstrcpyn ( Name, Entity->model->name + 7, Len );

				Name[Len] = '\0';

				if ( g_Util.native_strstr ( Entity->model->name, HEGREN ) )
				{
					Important = 1;

					AddEntity ( Name, Important, Entity->origin, 3 );
				}
				else if ( g_Util.native_strstr ( Entity->model->name, FLASH ) )
				{
					Important = 2;

					AddEntity ( Name, Important, Entity->origin, 3 );
				}
				else if ( g_Util.native_strstr ( Entity->model->name, SMOKE ) )
				{
					Important = 3;

					AddEntity ( Name, Important, Entity->origin, 3 );
				}
				else
				{
					if ( Files::g_IniRead.esp.world_weapons )
					{
						AddEntity ( Name, Important, Entity->origin, 1 );
					}
				}
			}
		}

		if ( Entity->model->name && Files::g_IniRead.esp.world_sprites )
		{
			if ( !g_Util.native_strstr ( Entity->model->name, "w_" ) && g_Util.native_strstr ( Entity->model->name, ".spr" ) )
			{
				AddEntity ( 0, 0, Entity->origin, 2 );
			}
		}
	}

	void ESP::DrawWorld ( )
	{
		for ( int i = 0; i < g_ESP.EntityIndex; ++i )
		{
			float EntityScreen[2];

			if ( g_Util.CalcScreen ( entity[i].Origin, EntityScreen ) && entity[i].Origin.x != 0 )
			{
				float uppt[] = { entity[i].Origin.x - Engine::g_Local.ViewOrg.x,
					entity[i].Origin.y - Engine::g_Local.ViewOrg.y, entity[i].Origin.z - Engine::g_Local.ViewOrg.z };

				float l = sqrt ( VectorLengthSquared ( uppt ) );

				l = max ( 100, l );

				if ( Files::g_IniRead.esp.world_weapons && entity[i].Type == 1 )
				{
					if ( g_Util.native_strstr ( entity[i].Name, USP ) )
					{
						WEAPON_PARS ( USP );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, GLOCK18 ) )
					{
						WEAPON_PARS ( GLOCK18 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, DEAGLE ) )
					{
						WEAPON_PARS ( DEAGLE );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, P228 ) )
					{
						WEAPON_PARS ( P228 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, ELITE ) )
					{
						WEAPON_PARS ( ELITE );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, FIVESEVEN ) )
					{
						WEAPON_PARS ( FIVESEVEN );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, M3 ) )
					{
						WEAPON_PARS ( M3 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, XM1014 ) )
					{
						WEAPON_PARS ( XM1014 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, MP5 ) )
					{
						WEAPON_PARS ( MP5 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, TMP ) )
					{
						WEAPON_PARS ( TMP );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, P90 ) )
					{
						WEAPON_PARS ( P90 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, MAC10 ) )
					{
						WEAPON_PARS ( MAC10 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, UMP45 ) )
					{
						WEAPON_PARS ( UMP45 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, FAMAS ) )
					{
						WEAPON_PARS ( FAMAS );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, SG552 ) )
					{
						WEAPON_PARS ( SG552 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, AK47 ) )
					{
						WEAPON_PARS ( AK47 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, M4A1 ) )
					{
						WEAPON_PARS ( M4A1 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, AUG ) )
					{
						WEAPON_PARS ( AUG );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, SCOUT ) )
					{
						WEAPON_PARS ( SCOUT );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, AWP ) )
					{
						WEAPON_PARS ( AWP );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, G3SG1 ) )
					{
						WEAPON_PARS ( G3SG1 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, SG550 ) )
					{
						WEAPON_PARS ( SG550 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, GALIL ) )
					{
						WEAPON_PARS ( GALIL );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, M249 ) )
					{
						WEAPON_PARS ( M249 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, SHIELD ) )
					{
						WEAPON_PARS ( SHIELD );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, BACKPACK ) )
					{
						WEAPON_PARS ( BACKPACK );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, THIGHPACK ) )
					{
						WEAPON_PARS ( THIGHPACK );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, C4 ) )
					{
						WEAPON_PARS ( C4 );
					}
					else
					{
						Renderer::g_Drawing.DrawBox ( ( int )EntityScreen[0] - 2, ( int )EntityScreen[1], 6, 6, 1, 0, 0, 0, 255 );

						Renderer::g_Drawing.FillArea ( ( int )EntityScreen[0] - 1, ( int )EntityScreen[1] + 1, 4, 4, 255, 100, 0, 255 );

						Renderer::g_Verdana.Print ( EntityScreen[0], EntityScreen[1] + 15, Files::g_IniRead.esp.font_color[0],
							Files::g_IniRead.esp.font_color[1], Files::g_IniRead.esp.font_color[2], 255,
							Files::g_IniRead.esp.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, entity[i].Name );
					}
				}
				else if ( entity[i].Type == 2 && Files::g_IniRead.esp.world_sprites )
				{
					float size = 3900 / l;

					Renderer::g_Drawing.DrawBox ( EntityScreen[0], EntityScreen[1], size, size, 1, 255, 255, 200, 80 );
				}
				else if ( entity[i].Type == 3 && Files::g_IniRead.esp.world_nades )
				{
					float rad = 3000 / l;

					if ( g_Util.native_strstr ( entity[i].Name, HEGREN ) )
					{
						Renderer::g_Drawing.DrawCircle ( EntityScreen[0], EntityScreen[1], rad, 100, 2, 255, 50, 50, 255 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, FLASH ) )
					{
						Renderer::g_Drawing.DrawCircle ( EntityScreen[0], EntityScreen[1], rad, 100, 2, 255, 255, 255, 255 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, SMOKE ) )
					{
						Renderer::g_Drawing.DrawCircle ( EntityScreen[0], EntityScreen[1], rad, 100, 2, 50, 255, 50, 255 );
					}
				}
			}
		}

		ClearEntity ( );
	}

	void ESP::AddSound ( DWORD Time, Vector Origin )
	{
		if ( g_ESP.SoundIndex < MAX_SOUNDS )
		{
			sound[g_ESP.SoundIndex].Time = Time;
			sound[g_ESP.SoundIndex].Origin = Origin;

			++g_ESP.SoundIndex;
		}
		else
		{
			ClearSound ( );
		}
	}

	void ESP::ClearSound ( )
	{
		for ( int i = 0; i < g_ESP.SoundIndex; ++i )
		{
			sound[i].Time = 0;
			sound[i].Origin = Vector ( 0, 0, 0 );
		}

		g_ESP.SoundIndex = 0;
	}

	void ESP::DrawSound ( )
	{
		for ( short i = 0; i < g_ESP.SoundIndex; ++i )
		{
			float uppt[] = { sound[i].Origin.x - Engine::g_Local.ViewOrg.x,
				sound[i].Origin.y - Engine::g_Local.ViewOrg.y, sound[i].Origin.z - Engine::g_Local.ViewOrg.z };

			float l = sqrt ( VectorLengthSquared ( uppt ) );

			l = max ( 100, l );

			float size = 7020 / l;

			float Time = ( float )sound[i].Time + Files::g_IniRead.esp.sound_fade_time;

			if ( Time <= GetTickCount ( ) )
			{
				sound[i].Time = 0;
				sound[i].Origin = Vector ( 0, 0, 0 );
			}
			else
			{
				float SoundScreen[2];

				float size_z = g_Util.Interp ( ( float )sound[i].Time, ( float )GetTickCount ( ), Time, size, 0 );

				if ( g_Util.CalcScreen ( sound[i].Origin, SoundScreen ) )
				{
					Renderer::g_Drawing.DrawBox ( SoundScreen[0] - size_z / 2, SoundScreen[1] - size_z / 2,
						g_Util.Interp ( ( float )sound[i].Time, ( float )GetTickCount ( ), Time, size, 0 ),
						g_Util.Interp ( ( float )sound[i].Time, ( float )GetTickCount ( ), Time, size, 0 ), 1,
						Files::g_IniRead.esp.sound_color[0], Files::g_IniRead.esp.sound_color[1], Files::g_IniRead.esp.sound_color[2],
						( BYTE )g_Util.Interp ( ( float )sound[i].Time, ( float )GetTickCount ( ), Time, 255, 0 ) );
				}
			}
		}
	}

	ESP g_ESP;

	entity_s entity[MAX_ENTITY];
	sound_s sound[MAX_SOUNDS];

	player_box_s player_box;
	font_s font;
}