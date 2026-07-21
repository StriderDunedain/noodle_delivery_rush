#include "../include/delivery_rush.h"

// Handle user position input
static void	handle_game_input(t_game *game, int ch)
{
	t_vec	next_pos = game->world.player.pos;

	if (ch == QUIT)
		game->state = STATE_EXIT;

	else if (ch == KEY_LEFT)
		next_pos.x--;
	else if (ch == KEY_RIGHT)
		next_pos.x++;

	else if (ch == KEY_UP)
		next_pos.y--;
	else if (ch == KEY_DOWN)
		next_pos.y++;

	if (ch == ESC)
	{
		set_menu(game, &g_pause_menu);
		return ;
	}
	if (is_valid_position(game, next_pos))
		game->world.player.pos = next_pos;
}

// Change the state of the `game`
void	change_state(t_game *game, t_state new_state)
{
	game->state = new_state;
}

// Update the `game`'s world
static void	update_game(t_game *game)
{
	update_students(game);
	update_orders(game);
	update_timer(game);
}

// Render the `game`'s world
static void	render_game(t_game *game)
{
	werase(game->win);
	box(game->win, STANDARD_BORDER, STANDARD_BORDER);

	draw_visual(
		game,
		game->world.player.pos.y,
		game->world.player.pos.x,
		&g_player_visuals,
		A_BOLD
	);

	render_students(game);
	render_orders(game);

	mvwprintw(
		game->win,
		MESSAGE_Y,
		MESSAGE_X,
		STRING_FORMAT, game->ui.message
	);

	wrefresh(game->win);
}

// Initialize the game
static void	game_init(t_game *game)
{
	game->win = newwin(HEIGHT, WIDTH, START_Y, START_X);
	strcpy(game->ui.message, WELCOME_MESSAGE);
	game->state = STATE_MENU;
	game->ui.menu.current = &g_start_menu;
	game->settings.render_mode = RENDER_MODE_TEXT;
	game->progress.game_timer = 0;
	game->progress.current_level = 0;
	game->progress.current_score = 0;
}


int main(void)
{
	t_game	game;
	int		ch;

	srand(time(NULL));

	setlocale(LC_ALL, "");

	initscr();
	noecho();
	curs_set(FALSE);

	game_init(&game);
	keypad(game.win, TRUE);

	wtimeout(game.win, 100);  // prevent blocking to render the first frame

	while (game.state != STATE_EXIT)
		{
			ch = wgetch(game.win);
			switch (game.state)
			{
				// Done
				case STATE_MENU:
					handle_menu_input(&game, ch);
					render_menu(&game);
					break;

				// Done
				case STATE_PLAYING:
					handle_game_input(&game, ch);
					update_game(&game);
					render_game(&game);
					break;

				// TODO: To implement
				// case STATE_LEVEL_COMPLETE:
				// 	update_level_complete(game);
				// 	render_level_complete(game);
				// 	break;

				// Done
				case STATE_GAME_OVER:
					handle_menu_input(&game, ch);
					render_menu(&game);
					break;
			}
		}
	endwin();
}
