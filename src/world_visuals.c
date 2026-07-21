#include "../include/delivery_rush.h"


const t_visual	g_player_visuals = {'P', L"🛵"};
const t_visual	g_student_visuals = {'S', L"🧑‍🎓"};

const char	*g_order_names[ORDER_TYPE_COUNT] = {
	[ORDER_NOODLES] = "Noodles",
	[ORDER_SALAD] 	= "Chicken Salad",
	[ORDER_MOCHI]	= "Mochi",
	[ORDER_ROLLS]	= "Spring Rolls"
};

const t_visual g_order_visuals[ORDER_TYPE_COUNT] = {
	[ORDER_NOODLES] = {'N', L"🍜"},
	[ORDER_SALAD]   = {'C', L"🥗"},
	[ORDER_MOCHI]   = {'M', L"🍡"},
	[ORDER_ROLLS]   = {'R', L"🍣"}
};
