#include "declarations.h"
#include "constants.h"
#include "types.h"

// START MENU
const t_menu_item	g_start_items[] = {
	{START_GAME_OPTION, action_new_game},
	{SELECT_DIFFICULTY_OPTION, action_open_difficulty},
	{TOGGLE_EMOJIS_OPTION, action_toggle_emojis},
	{QUIT_OPTION, action_quit}
};

const t_menu_def	g_start_menu = {
	START_MENU_TITLE,
	g_start_items,
	ARRAY_SIZE(g_start_items)
};


// DIFFICULTY MENU
const t_menu_item	g_difficulty_items[] = {
	{EASY_OPTION, action_easy},
	{NORMAL_OPTION, action_normal},
	{HARD_OPTION, action_hard}
};

const t_menu_def g_difficulty_menu = {
	DIFFICULTY_MENU_TITLE,
	g_difficulty_items,
	ARRAY_SIZE(g_difficulty_items)
};


// PAUSE MENU
const t_menu_item g_pause_items[] = {
	{RESUME_OPTION, action_resume},
	{RESTART_OPTION, action_restart},
	{MAIN_MENU_OPTION, action_main_menu},
	{QUIT_OPTION, action_quit},
};

const t_menu_def	g_pause_menu = {
	PAUSE_MENU_TITLE,
	g_pause_items,
	ARRAY_SIZE(g_pause_items)
};


// GAME OVER MENU
const t_menu_item g_game_over_items[] = {
	{START_GAME_OPTION, action_new_game},
	{MAIN_MENU_OPTION, action_main_menu},
	{QUIT_OPTION, action_quit}
};

const t_menu_def g_game_over_menu = {
	GAME_OVER_MENU_TITLE,
	g_game_over_items,
	ARRAY_SIZE(g_game_over_items)
};