#include "delivery_rush.h"


static bool	position_occupied(t_game *game, t_vec vec)
{
	if (is_same_position(vec, game->world.player.pos))
		return true;


	for (int i = 0; i < STUDENT_COUNT; ++i)
		if (is_same_position(vec, game->world.students[i].pos))
			return true;


	for (int i = 0; i < ORDER_TYPE_COUNT; ++i)
		if (is_same_position(vec, game->world.orders[i].pos))
			return true;


	return false;
}


bool	is_valid_position(t_game *game, t_vec pos)
{
	if (!(
		pos.x > 0
		&& pos.x < WIDTH - 1
		&& pos.y > 0
		&& pos.y < HEIGHT - 1
	))
		return false;

	for (int i = 0; i < STUDENT_COUNT; ++i)
		if (is_same_position(pos, game->world.students[i].pos))
			return false;

	return true;
}

bool	is_adjacent(t_vec a, t_vec b)
{
	return (abs(a.x - b.x) + abs(a.y - b.y)) == 1;
}


bool	is_same_position(t_vec a, t_vec b)
{
	return (a.x == b.x) && (a.y == b.y);
}


t_vec	get_random_pos(t_game *game)
{
	t_vec	vec;

	do
	{
		vec.x = rand() % (WIDTH - 2) + 1;
		vec.y = rand() % (HEIGHT - 2) + 1;
	}
	while (position_occupied(game, vec));

	return vec;
}


t_vec	map_center()
{
	t_vec	center;

	center.x = WIDTH / 2;
	center.y = HEIGHT / 2;

	return center;
}