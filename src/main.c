#include "delivery_rush.h"


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

	if (is_valid_position(game, next_pos))
		game->world.player.pos = next_pos;
}

void	change_state(t_game *game, t_state new_state)
{
	game->state = new_state;
}

static void	update_game(t_game *game)
{
	update_students(game);
	update_orders(game);
	update_timer(game);
}


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


static void	game_init(t_game *game)
{
	game->win = newwin(HEIGHT, WIDTH, START_Y, START_X);
	strcpy(game->ui.message, WELCOME_MESSAGE);
	game->state = STATE_MENU;
	game->ui.menu.current = &g_start_menu;
	game->settings.render_mode = RENDER_TEXT;
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
				// TODO: Doing now
				case STATE_MENU:
					handle_menu_input(&game, ch);
					render_menu(&game);
					break;

				// DONE: Should work fine
				case STATE_PLAYING:
					handle_game_input(&game, ch);
					update_game(&game);
					render_game(&game);
					break;

				// TODO: To implement
				// case STATE_LEVEL_COMPLETE:
				// 	update_level_complete(game);
				// 	render_level_complete(game);
				// 	handle_pause_menu(game);
				// 	break;

				// TODO: To implement
				// case STATE_GAME_OVER:
				// 	update_game_over(game);
				// 	render_game_over(game);
				// 	handle_game_over_menu(game);
				// 	break;
			}
		}

	endwin();
}
