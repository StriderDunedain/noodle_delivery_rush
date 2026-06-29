#include "delivery_rush.h"


void	update_students(t_game *game)
{
	for (int i = 0; i < STUDENT_COUNT; ++i)
		if (
			is_adjacent(
				game->world.player.pos,
				game->world.students[i].pos
			)
			&& game->world.students[i].active
			&& game->world.player.has_order
		)
		{
			game->world.students[i].active = false;
			game->world.player.has_order = false;
			game->ui.message_timer = MESSAGE_LIFETIME;
			game->progress.current_score++;
			snprintf(
				game->ui.message,
				sizeof(game->ui.message),
				NOODLES_DELIVERED_MESSAGE,
				game->progress.current_score
			);
		}
}


void	update_orders(t_game *game)
{
	for (int i = 0; i < ORDER_TYPE_COUNT; ++i)
	{
		if (
			is_same_position(
				game->world.player.pos,
				game->world.orders[i].pos
			)
			&& game->world.orders[i].active
			&& !game->world.player.has_order
		)
		{
			game->world.orders[i].active = false;
			game->world.player.has_order = true;
			game->ui.message_timer = MESSAGE_LIFETIME;
			snprintf(
				game->ui.message,
				sizeof(game->ui.message),
				ORDER_PICKUP_MESSAGE,
				g_order_names[game->world.orders[i].type]
			);
			break;  // prevent multiple pick-ups
		}
		// TODO: Add lifetimer counter decrease here
	}
}


void	update_timer(t_game *game)
{
	if (game->ui.message_timer > 0)
	{
		game->ui.message_timer--;
		if (game->ui.message_timer == 0)
			snprintf(
				game->ui.message,
				sizeof(game->ui.message),
				SCORE_MESSAGE,
				game->progress.current_score
			);
	}
}