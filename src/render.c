#include "delivery_rush.h"


// Put the `visual` at `y` and `x`
void	draw_visual(
	t_game *game,
	int y,
	int x,
	const t_visual *visual,
	int attrs
)
{
	if (game->settings.render_mode == RENDER_MODE_EMOJI)
		mvwprintw(game->win, y, x, WIDE_STRING_FORMAT, visual->emoji);
	else
		mvwaddch(game->win, y, x, visual->ascii | attrs);
}

// Render students on screen
void	render_students(t_game *game)
{
	for (int i = 0; i < STUDENT_COUNT; ++i)
	{
		if (game->world.students[i].active)
			draw_visual(
				game,
				game->world.students[i].pos.y,
				game->world.students[i].pos.x,
				&g_student_visuals,
				A_BOLD
			);
	}
}

// Render orders on screen
void	render_orders(t_game *game)
{
	t_order	order;

	for (int i = 0; i < ORDER_TYPE_COUNT; ++i)
	{
		order = game->world.orders[i];
		if (game->world.orders[i].active)
			draw_visual(
				game,
				order.pos.y,
				order.pos.x,
				&g_order_visuals[order.type],
				A_ITALIC
			);
	}
}
