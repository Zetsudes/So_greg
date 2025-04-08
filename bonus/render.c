/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:23:20 by zamohame          #+#    #+#             */
/*   Updated: 2025/04/08 16:26:01 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	load_images(t_data *data)
{
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "assets/wall.xpm",
			&data->img.img_width, &data->img.img_height);
	data->img.floor = mlx_xpm_file_to_image(data->mlx, "assets/floor.xpm",
			&data->img.img_width, &data->img.img_height);
	data->img.player = mlx_xpm_file_to_image(data->mlx, "assets/player.xpm",
			&data->img.img_width, &data->img.img_height);
	load_collectible(data);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, "assets/exit.xpm",
			&data->img.img_width, &data->img.img_height);
	data->img.villain = mlx_xpm_file_to_image(data->mlx, "assets/villain2.xpm",
			&data->img.img_width, &data->img.img_height);
}

void	load_collectible(t_data *data)
{
	data->img.jellyfish[0] = mlx_xpm_file_to_image(data->mlx,
			"assets/leftjelly.xpm", &data->img.img_width,
			&data->img.img_height);
	data->img.jellyfish[1] = mlx_xpm_file_to_image(data->mlx,
			"assets/leftjelly2.xpm", &data->img.img_width,
			&data->img.img_height);
	data->img.jellyfish[2] = mlx_xpm_file_to_image(data->mlx,
			"assets/topjelly.xpm", &data->img.img_width, &data->img.img_height);
	data->img.jellyfish[3] = mlx_xpm_file_to_image(data->mlx,
			"assets/rightjelly.xpm", &data->img.img_width,
			&data->img.img_height);
	data->img.jellyfish[4] = mlx_xpm_file_to_image(data->mlx,
			"assets/rightjelly2.xpm", &data->img.img_width,
			&data->img.img_height);
}

void	render_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map->size_y)
	{
		x = 0;
		while (x < data->map->size_x)
		{
			render_elements(data, x, y);
			x++;
		}
		y++;
	}
}

void	render_elements(t_data *data, int x, int y)
{
	if (data->map->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall, x * 64, y
			* 64);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img.floor, x * 64, y
			* 64);
	if (data->map->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img.player, x * 64,
			y * 64);
	else if (data->map->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.jellyfish[data->jellyfish_anim.current_frame], x * 64, y
			* 64);
	else if (data->map->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img.exit, x * 64, y
			* 64);
	else if (data->map->map[y][x] == 'V')
		mlx_put_image_to_window(data->mlx, data->win, data->img.villain, x * 64,
			y * 64);
}
