/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:23:20 by zamohame          #+#    #+#             */
/*   Updated: 2025/04/12 16:01:57 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_images(t_data *data)
{
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "assets/wall.xpm",
			&data->img.img_width, &data->img.img_height);
	data->img.floor = mlx_xpm_file_to_image(data->mlx, "assets/floor.xpm",
			&data->img.img_width, &data->img.img_height);
	data->img.player = mlx_xpm_file_to_image(data->mlx, "assets/player.xpm",
			&data->img.img_width, &data->img.img_height);
	data->img.collectible = mlx_xpm_file_to_image(data->mlx, "assets/col.xpm",
			&data->img.img_width, &data->img.img_height);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, "assets/exit.xpm",
			&data->img.img_width, &data->img.img_height);
}

void	image_error(t_data *data)
{
	clean_images(data);
	if (!data->img.wall || !data->img.floor || !data->img.player
		|| !data->img.exit || !data->img.collectible)
		free_all(data, "whats up with the image bro 😔\n");
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
	image_error(data);
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
		mlx_put_image_to_window(data->mlx, data->win, data->img.collectible, x
			* 64, y * 64);
	else if (data->map->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img.exit, x * 64, y
			* 64);
}
