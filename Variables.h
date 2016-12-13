#pragma once

#include "Main.h"

struct edgebug_s
{
	float auto_enable, auto_damage;

	float speed, distance;
	float distance_auto;

	int key;
};

struct jumpbug_s
{
	float auto_enable, auto_percentage;
	float auto_damage, slowmotion;

	float slowdown, slowdown_distance;

	int key;
};

struct speed_s
{
	float value, engine_value;

	float speed_type, boost, slowmo;

	int boost_key, slowmo_key;
};

struct gstrafe_s
{
	char *distance_string, *count_string;

	float distance[2], distance_type, count[2];

	float mouse_wheel_emulation, mouse_wheel_direction;
	float slowdown_scale, slowdown_groundangle;
	float fallrun, standup_fallvelocity;

	int key, standup_key;
};

struct bhop_s
{
	char *distance_string;

	float distance[2], distance_type;

	float mouse_wheel_emulation, mouse_wheel_direction;
	float noslowdown, in_water, on_ladder;
	float standup, standup_fallvelocity, standup_groundangle;

	int key, standup_key;
};

struct screeninfo_s
{
	char* color_string;

	float color[3];

	float enable, fps, copyright;
	float showkeys, kreedz, time;
	float debug;

	float font_outline;
};

struct noflash_s
{
	char *fade_color_string;

	float fade_color[3];

	float enable, fade_color_random;
	float fade_limit, show_percentage;

	float font_outline;
};

struct esp_s
{
	char *color_t_hide_string, *color_t_vis_string;
	char *color_ct_hide_string, *color_ct_vis_string;
	char *sound_color_string, *font_color_string;

	float color_t_hide[3], color_t_vis[3];
	float color_ct_hide[3], color_ct_vis[3];
	float sound_color[3], font_color[3];

	float enable;

	float player, player_ignore_death;
	float player_visible_check, player_visible_only;

	float player_box, player_box_linewidth, player_box_size;

	float player_name, player_weapon;
	float player_distance, player_barrel;

	float world, world_weapons, world_nades;

	float c4timer, c4timer_value;

	float sound, sound_linewidth, sound_fade_time;

	float font_outline;

	int panic_key;
};

struct main_s
{
	float player_scan_visibility;
	float player_valid_check;
	float font_outline_quality;

	int reload_key, panic_key;

	bool language;
};

struct menu_s
{
	char *box_color_string;
	char *fill_color_string;
	char *text_color_string;
	char *select_color_string;

	float box_color[4], fill_color[4];
	float text_color[4], select_color[4];

	float pos_x, pos_y;
	float box_height, box_width;

	int key;
};

struct function_s
{
	bool gstrafe;
	bool bhop;
	bool speed;
	bool jumpbug;
	bool edgebug;
	bool esp;
	bool noflash;
	bool screeninfo;
	bool menu;
	bool commands;
	bool commands_binds;
};

class Vars
{
public:
	edgebug_s edgebug;
	jumpbug_s jumpbug;
	speed_s speed;
	gstrafe_s gstrafe;
	bhop_s bhop;
	screeninfo_s screeninfo;
	noflash_s noflash;
	esp_s esp;
	main_s main;
	menu_s menu;
	function_s function;
};

extern Vars g_Vars;