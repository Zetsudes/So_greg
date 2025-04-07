/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:09:28 by zamohame          #+#    #+#             */
/*   Updated: 2025/04/06 16:40:05 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

void	copy_map(char **src, char **dest, int size_y, t_data *data)
{
	int	i;

	i = 0;
	while (i < size_y)
	{
		dest[i] = ft_strdup(src[i]);
		if (!dest[i])
			handle_error("Error: Memory allocation failed 😔\n", data);
		i++;
	}
	dest[i] = NULL;
}

void	check_path(t_data *data)
{
	char	**map_copy;
	int		y;
	int		x;

	map_copy = malloc(sizeof(char *) * (data->map->size_y + 1));
	if (!map_copy)
		exit_error("Error: Memory allocation failed 😔\n");
	copy_map(data->map->map, map_copy, data->map->size_y, data);
	flood_fill(map_copy, data->player_x, data->player_y);
	y = 0;
	while (y < data->map->size_y)
	{
		x = 0;
		while (x < data->map->size_x)
		{
			if (map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
			{
				free_copy_map(map_copy, data->map->size_y);
				free_all(data, "Error: Map has unreachable elements 😔\n");
			}
			x++;
		}
		y++;
	}
	free_copy_map(map_copy, data->map->size_y);
}
