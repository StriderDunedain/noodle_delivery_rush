#ifndef TYPES_H
# define TYPES_H

# include <ncurses.h>
# include <wchar.h>
# include "constants.h"


typedef struct s_game t_game;


typedef enum e_state
{
	STATE_MENU,
	STATE_PLAYING,
	STATE_LEVEL_COMPLETE,
	STATE_GAME_OVER,
	STATE_EXIT,

	STATE_COUNT
}	t_state;


typedef enum e_render_mode
{
	RENDER_TEXT,
	RENDER_EMOJI,

	RENDER_MODE_COUNT
}	t_render_mode;

typedef enum e_order_type
{
	ORDER_NOODLES,
	ORDER_SALAD,
	ORDER_MOCHI,
	ORDER_ROLLS,

	ORDER_TYPE_COUNT
}	t_order_type;

typedef enum e_difficulty
{
	DIFFICULTY_EASY,
	DIFFICULTY_NORMAL,
	DIFFICULTY_HARD
}	t_difficulty;






typedef struct s_visual
{
	const char		ascii;
	const wchar_t	*emoji;
}	t_visual;


typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;





typedef struct s_order
{
	t_vec			pos;

	t_order_type	type;

	int				lifetime;
	bool			active;
}	t_order;

typedef struct s_player
{
	t_vec			pos;
	// t_order	*carried_order
	bool			has_order;
}	t_player;

typedef struct s_student
{
	t_vec			pos;
	bool			active;
}	t_student;




typedef struct s_menu_item
{
	const char	*text;
	void		(*action)(t_game *);
}	t_menu_item;

typedef struct s_menu_def
{
	const char			*title;
	const t_menu_item	*items;
	int					item_count;
}	t_menu_def;

typedef struct s_menu
{
	const t_menu_def	*current;
	int					selected;
}	t_menu;



typedef struct s_difficulty_item
{
	const char		*label;
	t_difficulty	value;
}	t_difficulty_item;






typedef struct s_settings
{
	t_render_mode	render_mode;
	t_difficulty	difficulty;
}	t_settings;


typedef struct s_progress
{
	int	current_level;
	int	current_score;
	int	prev_level_score;
	int	game_timer;
}	t_progress;


typedef struct s_world
{
	t_player	player;
	t_student	students[STUDENT_COUNT];
	t_order		orders[MAX_ORDERS];
}	t_world;

typedef struct s_ui
{
	t_menu			menu;

	char			message[128];  // just a default for a message
	int				message_timer;
}	t_ui;



typedef struct s_game
{
	WINDOW			*win;

	t_state			state;

	t_settings		settings;
	t_progress		progress;
	t_world			world;
	t_ui			ui;
}	t_game;

#endif
