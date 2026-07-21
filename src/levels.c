#include "../include/delivery_rush.h"

const t_level	g_levels[] = {
	{
		.required_orders = 5,
		.time_limit = 60
	},
	{
		.required_orders = 8,
		.time_limit = 55
	},
	{
		.required_orders = 12,
		.time_limit = 50
	},
	{
		.required_orders = 16,
		.time_limit = 45
	},
	{
		.required_orders = 20,
		.time_limit = 40
	}
};


void	load_level(t_game *game, int level)
{
	;
}