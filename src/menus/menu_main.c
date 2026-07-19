#include "delivery_rush.h"

// Print the `visual` object to the centre of the map
static void	print_center(WINDOW *win, int y, const t_visual *visual)
{
	int	x;

	if (visual->ascii)
	{
		x = (WIDTH - strlen(visual->ascii)) / 2;
		mvwprintw(win, y, x, CHAR_FORMAT, visual->ascii);
	}
	else
	{
		x = (WIDTH - wcslen(visual->emoji)) / 2;
		mvwprintw(win, y, x, WIDE_STRING_FORMAT, visual->emoji);
	}
}

// Display a menu
void	render_menu(t_game *game)
{
	t_menu	*menu;

	menu = &game->ui.menu;

	werase(game->win);

	print_center(game->win, 3, menu->current->title);

	for (int i = 0; i < menu->current->item_count; ++i)
	{
		if (i == menu->selected)
			wattron(game->win, A_REVERSE);

		print_center(game->win, 8 + i * 2, menu->current->items[i].text);

		if (i == menu->selected)
			wattroff(game->win, A_REVERSE);
	}

	wrefresh(game->win);
}

// Handle user choice in a menu
void	handle_menu_input(t_game *game, int ch)
{
	t_menu	*menu;

	menu = &game->ui.menu;

	if (ch == KEY_UP)
		menu->selected = (
			menu->selected - 1 + menu->current->item_count
		) % menu->current->item_count;

	if (ch == KEY_DOWN)
		menu->selected = (menu->selected + 1) % menu->current->item_count;

	if (ch == NEW_LINE)
		menu->current->items[menu->selected].action(game);
}
