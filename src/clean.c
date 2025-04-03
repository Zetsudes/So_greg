/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:30:05 by zamohame          #+#    #+#             */
/*   Updated: 2025/04/03 16:09:18 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	clean_images(t_data *data)
{
	int	i;

	if (data->img.wall)
		mlx_destroy_image(data->mlx, data->img.wall);
	if (data->img.floor)
		mlx_destroy_image(data->mlx, data->img.floor);
	if (data->img.player)
		mlx_destroy_image(data->mlx, data->img.player);
	if (data->img.exit)
		mlx_destroy_image(data->mlx, data->img.exit);
	if (data->img.villain)
		mlx_destroy_image(data->mlx, data->img.villain);
	i = 0;
	while (i < 5)
	{
		if (data->img.jellyfish[i])
			mlx_destroy_image(data->mlx, data->img.jellyfish[i]);
		i++;
	}
	data->img.wall = NULL;
	data->img.floor = NULL;
	data->img.player = NULL;
	data->img.exit = NULL;
	data->img.villain = NULL;
}

void	free_map(t_data *data)
{
	int	i;

	if (data->map)
	{
		i = 0;
		while (i < data->map->size_y)
		{
			if (data->map->map[i])
				free(data->map->map[i]);
			i++;
		}
		if (data->map->map)
			free(data->map->map);
		free(data->map);
	}
}
