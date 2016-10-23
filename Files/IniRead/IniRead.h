#pragma once

#include "Main.h"

namespace Files
{
	struct noflash_s
	{
		char* fade_color_string;

		int show_percentage;
		int fade_limit;

		BYTE fade_color[3];

		bool enable;
		bool fade_color_random;
		bool font_outline;
	};

	struct esp_s
	{
		char* t_vis_color_string;
		char* t_hide_color_string;
		char* ct_vis_color_string;
		char* ct_hide_color_string;
		char* font_color_string;
		char* sound_color_string;

		int sound_fade_time;

		int player;
		int player_box_linewidth;
		int player_distance;

		int panic_key;

		BYTE t_vis_color[3];
		BYTE t_hide_color[3];
		BYTE ct_vis_color[3];
		BYTE ct_hide_color[3];
		BYTE font_color[3];
		BYTE sound_color[3];

		bool enable;

		bool player_visible_only;
		bool player_box;
		bool player_box_outline;
		bool player_name;
		bool player_weapon;

		bool world;
		bool world_weapons;
		bool world_nades;
		bool world_sprites;

		bool font_outline;
		bool sound;
	};

	struct main_s
	{
		int reload_key;
		int panic_key;

		bool language;
	};

	struct function_s
	{
		bool esp;
		bool noflash;
	};

	class IniRead
	{
	public:
		noflash_s noflash;
		esp_s esp;
		main_s main;
		function_s function;

		void NoFlash ( );
		void ESP ( );
		void Main ( );
		void Functions ( );
	};

	extern IniRead g_IniRead;
}