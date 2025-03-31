/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:48:51 by zamohame          #+#    #+#             */
/*   Updated: 2025/03/18 15:50:04 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../greg_lib/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_count
{
	int		player;
	int		exit;
	int		collectible;
	int		villain;
}			t_count;

typedef struct s_map
{
	char	**map;
	int		size_x;
	int		size_y;
}			t_map;

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
	void	*villain;
	int		img_width;
	int		img_height;
}			t_img;

typedef struct s_data
{
	t_map	*map;
	t_count	count;
	int		player_x;
	int		player_y;
	int		villain_x;
	int		villain_y;
	int		moves;
	void	*mlx;
	void	*win;
	t_img	img;
}			t_data;

/***** Map checking *****/

void		handle_error(const char *message);
void		elements_errors(t_data *data);
void		check_map(t_data *data);
void		check_map_format(t_data *data);
void		check_file_extension(char **argv);
void		check_elements(t_data *data);
void		check_path(t_data *data);
void		validate_map(t_data *data);
void		copy_map(char **src, char **dest, int size_y);
void		flood_fill(char **map, int x, int y);

/***** Map rendering *****/

void		init_elements(t_data *data);
void		load_images(t_data *data);
t_map		read_map(const char *filename);
void		render_map(t_data *data);
void		render_elements(t_data *data, int x, int y);
void		render_villain(t_data *data, int x, int y);

/***** Player handling *****/

void		move_player(t_data *data, int new_x, int new_y);
void		update_position(t_data *data, int new_x, int new_y);
void		find_player_position(t_data *data);

/***** Villain handling *****/

void		move_villain(t_data *data, int new_x, int new_y);
void		update_villain_position(t_data *data, int new_x, int new_y);
void		find_villain_position(t_data *data);

/***** Game *****/

int			close_game(t_data *data);
void		setup_game(t_data *data);
void		setup_window(t_data *data);

/***** Hooks *****/

int			key_hook(int keycode, t_data *data);
void		setup_hooks(t_data *data);
void		display_moves(t_data *data);

#endif
