/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:09:28 by zamohame          #+#    #+#             */
/*   Updated: 2025/04/22 16:53:46 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	flood_fill(char **map, int x, int y, t_found *found)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'C')
		found->collectible++;
	else if (map[y][x] == 'E')
		found->exit++;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, found);
	flood_fill(map, x - 1, y, found);
	flood_fill(map, x, y + 1, found);
	flood_fill(map, x, y - 1, found);
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

void	replace_exit_with_wall(char **map, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
}

void	check_path(t_data *data)
{
	char	**map_copy;
	t_found	found;

	found.collectible = 0;
	found.exit = 0;
	map_copy = malloc(sizeof(char *) * (data->map->size_y + 1));
	if (!map_copy)
		exit_error("Error: Memory allocation failed 😔\n", data);
	copy_map(data->map->map, map_copy, data->map->size_y, data);
	replace_exit_with_wall(map_copy, data->map->size_y);
	flood_fill(map_copy, data->player_x, data->player_y, &found);
	free_copy_map(map_copy, data->map->size_y);
	if (found.collectible != data->count.collectible)
		exit_error("Error: Map has unreachable elements 😔\n", data);
}
