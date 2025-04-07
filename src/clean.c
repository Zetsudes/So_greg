/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:30:05 by zamohame          #+#    #+#             */
/*   Updated: 2025/04/06 16:29:38 by zamohame         ###   ########.fr       */
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
}

void	cleanup_game(t_data *data)
{
	int	i;

	clean_images(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map)
	{
		if (data->map->map)
		{
			i = 0;
			while (i < data->map->size_y)
			{
				if (data->map->map[i])
					free(data->map->map[i]);
				i++;
			}
			free(data->map->map);
		}
		free(data->map);
	}
}

void	free_copy_map(char **map_copy, int size_y)
{
	int	i;

	i = 0;
	while (i < size_y && map_copy[i])
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->map)
	{
		i = 0;
		while (i < map->size_y)
		{
			if (map->map[i])
				free(map->map[i]);
			i++;
		}
		free(map->map);
	}
}

void	free_all(t_data *data, const char *message)
{
	free_map(data->map);
	free(data->map);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_printf(message);
	exit(1);
}
