#include "ESP.h"

#pragma warning (disable: 4244)

namespace Functions
{
	int ESP::EntityIndex, ESP::SoundIndex;

	bool ESP::PanicEnabled = false;

	float ESP::GetPlayerDistance ( int Index, bool Meters )
	{
		if ( Meters )
		{
			return floor ( sqrt ( POW ( abs ( Information::g_Player[Index].Entity->origin.x - Information::g_Local.Entity->origin.x ) ) +
				POW ( abs ( Information::g_Player[Index].Entity->origin.y - Information::g_Local.Entity->origin.y ) ) +
				POW ( abs ( Information::g_Player[Index].Entity->origin.z - Information::g_Local.Entity->origin.z ) ) ) - 32 ) * 0.025f;
		}
		else
		{
			return floor ( sqrt ( POW ( abs ( Information::g_Player[Index].Entity->origin.x - Information::g_Local.Entity->origin.x ) ) +
				POW ( abs ( Information::g_Player[Index].Entity->origin.y - Information::g_Local.Entity->origin.y ) ) +
				POW ( abs ( Information::g_Player[Index].Entity->origin.z - Information::g_Local.Entity->origin.z ) ) ) - 32 );
		}
	}

	void ESP::GetColorPlayerBox ( int Index )
	{
		if ( Information::g_Player[Index].Team == TERRORIST && Information::g_Player[Index].Visible )
		{
			player_box.color[0] = 255;
			player_box.color[1] = 255;
			player_box.color[2] = 0;
		}
		else if ( Information::g_Player[Index].Team == TERRORIST )
		{
			player_box.color[0] = 255;
			player_box.color[1] = 0;
			player_box.color[2] = 0;
		}
		else if ( Information::g_Player[Index].Team == CT && Information::g_Player[Index].Visible )
		{
			player_box.color[0] = 0;
			player_box.color[1] = 255;
			player_box.color[2] = 255;
		}
		else if ( Information::g_Player[Index].Team == CT )
		{
			player_box.color[0] = 0;
			player_box.color[1] = 0;
			player_box.color[2] = 255;
		}
		else if ( Information::g_Player[Index].Visible )
		{
			player_box.color[0] = 255;
			player_box.color[1] = 255;
			player_box.color[2] = 255;
		}
		else
		{
			player_box.color[0] = 200;
			player_box.color[1] = 200;
			player_box.color[2] = 200;
		}
	}

	void _fastcall ESP::DrawPlayer ( int Index )
	{
		if ( Information::g_Local.Alive && ( Files::g_IniRead.esp.player == 1 && Information::g_Player[Index].Team == Information::g_Local.Team ) ||
			( Files::g_IniRead.esp.player_visible_only && !Information::g_Player[Index].Visible ) )
		{
			return;
		}

		Vector Top = Vector ( Information::g_Player[Index].Entity->origin.x, Information::g_Player[Index].Entity->origin.y,
			Information::g_Player[Index].Entity->origin.z + Information::g_Player[Index].Entity->curstate.mins.z );

		Vector Bot = Vector ( Information::g_Player[Index].Entity->origin.x, Information::g_Player[Index].Entity->origin.y,
			Information::g_Player[Index].Entity->origin.z + Information::g_Player[Index].Entity->curstate.maxs.z );

		float ScreenTop[2], ScreenBot[2];

		if ( g_Util.CalcScreen ( Top, ScreenTop ) && g_Util.CalcScreen ( Bot, ScreenBot ) )
		{
			float _h = ScreenBot[1] - ScreenTop[1];
			float height = Information::g_Player[Index].Ducked ? _h : _h * 0.9f;

			if ( Files::g_IniRead.esp.player_box )
			{
				GetColorPlayerBox ( Index );

				float x = ScreenTop[0] - ( height * 0.25f );

				float width = height * 0.5f;

				switch ( Files::g_IniRead.esp.player_box )
				{
				case 1:
					Renderer::g_Drawing.Box ( ( int )x, ( int )ScreenTop[1], ( int )width, ( int )height, 1,
						player_box.color[0], player_box.color[1], player_box.color[2], 255 );

					break;

				case 2:
					Renderer::g_Drawing.BoxWithOutLine ( ( int )x, ( int )ScreenTop[1], ( int )width, ( int )height,
						1, player_box.color[0], player_box.color[1], player_box.color[2], 255 );

					break;
				}
			}

			if ( Files::g_IniRead.esp.player_name )
			{
				float y = height - 5 + ScreenTop[1];

				Renderer::g_Verdana.Print ( ( int )ScreenTop[0], ( int )y, 255, 255,
					255, 255, FL_CENTER | FL_OUTLINE, Information::g_Player[Index].Info.name );
			}

			if ( Files::g_IniRead.esp.player_weapon )
			{
				float y = Files::g_IniRead.esp.player_distance ?

					ScreenBot[1] + ( 24 - ( ScreenBot[1] - ScreenTop[1] ) ) :

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

				switch ( SequenceInfo[Information::g_Player[Index].Entity->curstate.sequence] )
				{
				case 2:
					Renderer::g_Verdana.Print ( ( int )ScreenTop[0], ( int )y + 12, 255, 80, 80, 255, FL_CENTER | FL_OUTLINE, SEQUENCE_RELOADING );

					break;

				case 5:
					Renderer::g_Verdana.Print ( ( int )ScreenTop[0], ( int )y + 12, 255, 80, 80, 255, FL_CENTER | FL_OUTLINE, SEQUENCE_PLANTING );

					break;
				}

				struct model_s *Model = Engine::g_Studio.GetModelByIndex ( Information::g_Player[Index].Entity->curstate.weaponmodel );

				if ( Model->name )
				{
					char WeaponName[64];

					int len = lstrlen ( Model->name + 9 ) - 3;

					lstrcpyn ( WeaponName, Model->name + 9, len );

					WeaponName[len] = '\0';

					Renderer::g_Verdana.Print ( ( int )ScreenTop[0], ( int )y, 255, 255, 255, 255, FL_CENTER | FL_OUTLINE, WeaponName );
				}
			}

			if ( Files::g_IniRead.esp.player_distance )
			{
				float y = ScreenBot[1] + ( 12 - ( ScreenBot[1] - ScreenTop[1] ) );

				int DistanceMeters, DistanceUnits;

				switch ( Files::g_IniRead.esp.player_distance )
				{
				case 1:
					DistanceUnits = ( int )GetPlayerDistance ( Index, false );

					if ( DistanceUnits >= 1000 )
					{
						Renderer::g_Verdana.Print ( ( int )ScreenTop[0], ( int )y, 255, 90, 90, 255, FL_CENTER | FL_OUTLINE, "%d u", DistanceUnits );
					}
					else
					{
						Renderer::g_Verdana.Print ( ( int )ScreenTop[0], ( int )y, 255, 255, 255, 255, FL_CENTER | FL_OUTLINE, "%d u", DistanceUnits );
					}

					break;

				case 2:
					DistanceMeters = ( int )GetPlayerDistance ( Index, true );

					if ( DistanceMeters >= 25 )
					{
						Renderer::g_Verdana.Print ( ( int )ScreenTop[0], ( int )y, 255, 90, 90, 255, FL_CENTER | FL_OUTLINE, "%d m", DistanceMeters );
					}
					else
					{
						Renderer::g_Verdana.Print ( ( int )ScreenTop[0], ( int )y, 255, 255, 255, 255, FL_CENTER | FL_OUTLINE, "%d m", DistanceMeters );
					}

					break;
				}
			}
		}
	}

	void ESP::AddEntity ( char* Name, int Important, Vector Origin, BYTE Type )
	{
		if ( EntityIndex < MAX_ENTITY )
		{
			lstrcpy ( Entity[EntityIndex].Name, Name );

			Entity[EntityIndex].Important = Important;
			Entity[EntityIndex].Origin = Origin;
			Entity[EntityIndex].Type = Type;

			++EntityIndex;
		}
		else
		{
			ClearEntity ( );
		}
	}

	void _fastcall ESP::ClearEntity ( )
	{
		for ( int i = 0; i < EntityIndex; ++i )
		{
			g_Util.MemorySet ( &Entity[i].Name[0], 64, 0 );

			Entity[i].Important = 0;
			Entity[i].Origin = Vector ( 0, 0, 0 );
			Entity[i].Type = 0;
		}

		EntityIndex = 0;
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

	void _fastcall ESP::DrawWorld ( )
	{
		for ( int i = 0; i < EntityIndex; ++i )
		{
			float EntityScreen[2];

			if ( g_Util.CalcScreen ( Entity[i].Origin, EntityScreen ) && Entity[i].Origin.x != 0 )
			{
				float uppt[] = { Entity[i].Origin.x - Information::g_Local.ViewOrg.x, Entity[i].Origin.y - Information::g_Local.ViewOrg.y,
					Entity[i].Origin.z - Information::g_Local.ViewOrg.z };

				float l = sqrt ( VectorLengthSquared ( uppt ) );

				l = max ( 100, l );

				if ( Files::g_IniRead.esp.world_weapons && Entity[i].Type == 1 )
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
						WEAPON_PARS_C4 ( C4 );
					}
					else
					{
						Renderer::g_Drawing.Box ( ( int )EntityScreen[0] - 2, ( int )EntityScreen[1], 6, 6, 1, 0, 0, 0, 255 );

						Renderer::g_Drawing.Fill ( ( int )EntityScreen[0] - 1, ( int )EntityScreen[1] + 1, 4, 4, 255, 150, 50, 255 );

						Renderer::g_Verdana.Print ( ( int )EntityScreen[0], ( int )EntityScreen[1] + 15,
							255, 255, 255, 255, FL_CENTER | FL_OUTLINE, Entity[i].Name );
					}
				}
				else if ( Files::g_IniRead.esp.world_sprites && Entity[i].Type == 2 )
				{
					float size = 3900 / l;

					Renderer::g_Drawing.Box ( EntityScreen[0], EntityScreen[1], size, size, 1, 255, 255, 200, 80 );
				}
				else if ( Files::g_IniRead.esp.world_nades && Entity[i].Type == 3 )
				{
					float rad = 3000 / l;

					if ( g_Util.native_strstr ( Entity[i].Name, HEGREN ) )
					{
						Renderer::g_Drawing.Circle ( EntityScreen[0], EntityScreen[1], rad, 50, 2, 255, 50, 50, 255 );
					}
					else if ( g_Util.native_strstr ( Entity[i].Name, FLASH ) )
					{
						Renderer::g_Drawing.Circle ( EntityScreen[0], EntityScreen[1], rad, 50, 2, 255, 255, 255, 255 );
					}
					else if ( g_Util.native_strstr ( Entity[i].Name, SMOKE ) )
					{
						Renderer::g_Drawing.Circle ( EntityScreen[0], EntityScreen[1], rad, 50, 2, 50, 255, 50, 255 );
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

	void _fastcall ESP::ClearSound ( )
	{
		for ( int i = 0; i < SoundIndex; ++i )
		{
			Sound[i].Time = 0;
			Sound[i].Origin = Vector ( 0, 0, 0 );
		}

		SoundIndex = 0;
	}

	void _fastcall ESP::DrawSound ( )
	{
		for ( short i = 0; i < SoundIndex; ++i )
		{
			float uppt[] = { Sound[i].Origin.x - Information::g_Local.ViewOrg.x, Sound[i].Origin.y - Information::g_Local.ViewOrg.y,
				Sound[i].Origin.z - Information::g_Local.ViewOrg.z };

			float l = sqrt ( VectorLengthSquared ( uppt ) );

			l = max ( 100, l );

			float size = 7020 / l;

			float time = ( float )Sound[i].Time + Files::g_IniRead.esp.sound_fade_time;

			if ( time <= GetTickCount ( ) )
			{
				Sound[i].Time = 0;
				Sound[i].Origin = Vector ( 0, 0, 0 );
			}
			else
			{
				float SoundScreen[2];

				float size_z = g_Util.Interp ( ( float )Sound[i].Time, ( float )GetTickCount ( ), time, size, 0 );

				if ( g_Util.CalcScreen ( Sound[i].Origin, SoundScreen ) )
				{
					Renderer::g_Drawing.Box ( SoundScreen[0] - size_z / 2, SoundScreen[1] - size_z / 2,
						g_Util.Interp ( ( float )Sound[i].Time, ( float )GetTickCount ( ), time, size, 0 ),
						g_Util.Interp ( ( float )Sound[i].Time, ( float )GetTickCount ( ), time, size, 0 ),
						1, 255, 255, 255, g_Util.Interp ( ( float )Sound[i].Time, ( float )GetTickCount ( ), time, 255, 0 ) );
				}
			}
		}
	}

	void ESP::Panic ( bool enabled )
	{
		enabled ? Files::g_IniRead.esp.enable = 0 : Files::g_IniRead.esp.enable = 1;
	}

	void ESP::PanicKey ( int keynum )
	{
		if ( keynum == Files::g_IniRead.esp.panic_key )
		{
			PanicEnabled = !PanicEnabled;

			Panic ( PanicEnabled );

			Engine::g_Engine.pfnPlaySoundByName ( PanicEnabled ? "vox/of.wav" : "vox/on.wav", 1 );
		}
	}

	ESP g_ESP;

	entity_s Entity[MAX_ENTITY];
	sound_s Sound[MAX_SOUNDS];

	player_box_s player_box;
}