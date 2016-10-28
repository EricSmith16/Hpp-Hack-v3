#pragma once

#include "Main.h"

namespace Files
{
	struct noflash_s
	{
		char* fade_color_string;

		int fade_color[3];

		int enable;

		int fade_color_random;
		int fade_limit;

		int show_percentage;
	};

	struct esp_s
	{
		int enable;

		int player;
		int player_visible_only;
		int player_box;
		int player_name;
		int player_weapon;
		int player_distance;

		int world;
		int world_weapons;
		int world_nades;
		int world_sprites;

		int sound;
		int sound_fade_time;

		int panic_key;
	};

	struct main_s
	{
		int reload_key;
		int panic_key;

		int scan_visibility;

		bool language;
	};

	struct function_s
	{
		bool esp;
		bool noflash;
		bool menu;
	};

	class IniRead
	{
	public:
		noflash_s noflash;
		esp_s esp;
		main_s main;
		function_s function;

		static void NoFlash ( );
		static void ESP ( );
		static void Main ( );
		static void Functions ( );
	};

	extern IniRead g_IniRead;
}