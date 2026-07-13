#ifndef DECLARATIONS_H
# define DECLARATIONS_H

# include <stdbool.h>

# define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))


// coordinates.c
t_vec	get_random_pos(t_game *game);
t_vec	map_center();
bool	is_adjacent(t_vec a, t_vec b);
bool	is_valid_position(t_game *game, t_vec pos);
bool	is_same_position(t_vec a, t_vec b);


// update.c
void	update_orders(t_game *game);
void	update_students(t_game *game);
void	update_timer(t_game *game);


// render.c
void	render_students(t_game *game);
void	render_orders(t_game *game);
void	draw_visual(
	t_game *game,
	int y,
	int x,
	const t_visual *visual,
	int attrs
);


// main_menu.c
void	render_menu(t_game *game);
void	handle_menu_input(t_game *game, int ch);


// menu_actions.c
// section: open menus
void	set_menu(t_game *game, const t_menu_def *menu);
void	action_open_difficulty(t_game *game);
void	action_main_menu(t_game *game);
void	action_pause(t_game *game);
void	action_quit(t_game *game);

// section: choose difficulty
void	action_easy(t_game *game);
void	action_normal(t_game *game);
void	action_hard(t_game *game);

// section: miscellaneous
void	action_new_game(t_game *game);
void	action_toggle_emojis(t_game *game);
void	action_resume(t_game *game);
void	action_restart(t_game *game);


// main.c
void	change_state(t_game *game, t_state new_state);

// levels.c
void	load_level(t_game *game, int level);

#endif
