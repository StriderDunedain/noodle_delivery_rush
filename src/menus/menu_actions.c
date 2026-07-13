#include "delivery_rush.h"


#define LEVEL_TIME 0  // TODO: Implement later

// SECTION: Static functions
static void	set_difficulty(t_game *game, t_difficulty difficulty)
{
	game->settings.difficulty = difficulty;
}



// SECTION: Open menus
void	set_menu(t_game *game, const t_menu_def *menu)
{
	game->ui.menu.current = menu;
	game->ui.menu.selected = 0;

	change_state(game, STATE_MENU);
}
void	action_open_difficulty(t_game *game)
{
	set_menu(game, &g_difficulty_menu);
}

void	action_main_menu(t_game *game)
{
	set_menu(game, &g_start_menu);
}

void	action_pause(t_game *game)
{
	set_menu(game, &g_pause_menu);
}

void	action_quit(t_game *game)
{
	change_state(game, STATE_EXIT);
}



// SECTION: Choose difficulty
void	action_easy(t_game *game)
{
	set_difficulty(game, DIFFICULTY_EASY);
}
void	action_normal(t_game *game)
{
	set_difficulty(game, DIFFICULTY_NORMAL);
}
void	action_hard(t_game *game)
{
	set_difficulty(game, DIFFICULTY_HARD);
}


// SECTION: Miscellaneous
void	action_new_game(t_game *game)
{
	game->progress.current_level = 0;
	game->progress.current_score = 0;
	game->progress.prev_level_score = 0;
	game->progress.game_timer = LEVEL_TIME;

	game->world.player.pos = map_center();
	game->world.player.has_order = false;

	load_level(game, game->progress.current_level);

	change_state(game, STATE_PLAYING);
}

void	action_toggle_emojis(t_game *game)
{
	if (game->settings.render_mode == RENDER_TEXT)
		game->settings.render_mode = RENDER_EMOJI;
	else
		game->settings.render_mode = RENDER_TEXT;
}

void	action_resume(t_game *game)
{
	change_state(game, STATE_PLAYING);
}

void	action_restart(t_game *game)
{
	action_new_game(game);
}

