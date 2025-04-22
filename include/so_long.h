/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:48:51 by zamohame          #+#    #+#             */
/*   Updated: 2025/04/22 16:54:08 by zamohame         ###   ########.fr       */
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
	int		img_width;
	int		img_height;
}			t_img;

typedef struct s_data
{
	t_map	*map;
	t_count	count;
	int		player_x;
	int		player_y;
	int		moves;
	void	*mlx;
	void	*win;
	t_img	img;
}			t_data;

typedef struct s_found
{
	int		collectible;
	int		exit;
}			t_found;

/***** Map checking *****/

void		handle_error(const char *message, t_data *data);
void		exit_error(const char *message, t_data *data);
void		elements_errors(t_data *data);
void		image_error(t_data *data);
void		check_map(t_data *data);
void		check_map_format(t_data *data);
void		check_file_extension(char **argv);
void		check_elements(t_data *data);
void		check_path(t_data *data);
void		validate_map(t_data *data);
void		copy_map(char **src, char **dest, int size_y, t_data *data);
void		flood_fill(char **map, int x, int y, t_found *found);
void		replace_exit_with_wall(char **map, int height);

/***** Map rendering *****/

void		init_elements(t_data *data);
void		load_images(t_data *data);
t_map		read_map(const char *file, t_data *data);
void		render_map(t_data *data);
void		render_elements(t_data *data, int x, int y);

/***** Player handling *****/

void		move_player(t_data *data, int new_x, int new_y);
void		update_position(t_data *data, int new_x, int new_y);
void		find_player_position(t_data *data);

/***** Game *****/

int			close_game(t_data *data);
void		setup_game(t_data *data);
void		setup_window(t_data *data);

/***** Hooks *****/

int			key_hook(int keycode, t_data *data);
void		setup_hooks(t_data *data);

/***** Cleaning *****/

void		cleanup_game(t_data *data);
void		free_copy_map(char **map_copy, int size_y);
void		clean_images(t_data *data);
void		free_map(t_map *map);
void		free_all(t_data *data, const char *message);

#endif
