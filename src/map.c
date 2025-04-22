/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:13:09 by zamohame          #+#    #+#             */
/*   Updated: 2025/04/22 14:16:55 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	validate_map(t_data *data)
{
	check_map(data);
	check_map_format(data);
	check_elements(data);
}

void	check_map(t_data *data)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = data->map->map;
	while (i < data->map->size_y)
	{
		j = 0;
		while (j < data->map->size_x)
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'P' && map[i][j] != 'E')
				exit_error("Error: Invalid character found in map 😔\n", data);
			if ((i == 0 || j == 0 || i == data->map->size_y - 1
					|| j == data->map->size_x - 1) && map[i][j] != '1')
				exit_error("Error: Map borders must be walls 😔\n", data);
			j++;
		}
		i++;
	}
}

void	check_map_format(t_data *data)
{
	int		i;
	int		len;
	char	**map;

	map = data->map->map;
	if (!map[0])
		exit_error("Error: Map is empty 😔\n", data);
	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != (size_t)len)
			exit_error("Error: Map must be rectangular 😔\n", data);
		i++;
	}
	if (i == len)
		exit_error("Error: Map cannot be square 😔\n", data);
}

void	check_elements(t_data *data)
{
	int	x;
	int	y;

	init_elements(data);
	y = 0;
	while (data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			if (data->map->map[y][x] == 'P')
				data->count.player++;
			if (data->map->map[y][x] == 'E')
				data->count.exit++;
			if (data->map->map[y][x] == 'C')
				data->count.collectible++;
			x++;
		}
		y++;
	}
	elements_errors(data);
}

t_map	read_map(const char *file, t_data *data)
{
	t_map	map_data;
	char	*line;
	int		fd;
	int		line_count;

	line_count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error("Error: Could not open map 😔\n", data);
	map_data.map = malloc(sizeof(char *) * 101);
	if (!map_data.map)
		handle_error("Error: Memory allocation failed 😔\n", data);
	line = get_next_line(fd);
	while (line)
	{
		map_data.map[line_count++] = ft_strtrim(line, " \n");
		if (line_count == 1)
			map_data.size_x = ft_strlen(map_data.map[0]);
		free(line);
		line = get_next_line(fd);
	}
	map_data.map[line_count] = NULL;
	close(fd);
	map_data.size_y = line_count;
	return (map_data);
}
