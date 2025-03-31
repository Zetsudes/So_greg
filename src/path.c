
#include "../include/so_long.h"

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

void	copy_map(char **src, char **dest, int size_y)
{
	int i = 0;
	while (i < size_y)
	{
		dest[i] = ft_strdup(src[i]);
		if (!dest[i])
			handle_error("Error: Memory allocation failed 😔\n");
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
		handle_error("Error: Memory allocation failed 😔\n");
	copy_map(data->map->map, map_copy, data->map->size_y);
	flood_fill(map_copy, data->player_x, data->player_y);
	y = 0;
	while (y < data->map->size_y)
	{
		x = 0;
		while (x < data->map->size_x)
		{
			if (map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
				handle_error("Error: Map has unreachable elements 😔\n");
			x++;
		}
		free(map_copy[y]);
		y++;
	}
	free(map_copy);
}