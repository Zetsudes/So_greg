/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:13:09 by zamohame          #+#    #+#             */
/*   Updated: 2025/03/03 11:27:00 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    check_map(t_data *data)
{
    int i;
	int x;
	int len;
    char **map;

    i = 0;
    map = data->map->map;
	len = ft_strlen(map[0]);
    while (i < data->map->size_y)
    {
        x = 0;
        while (x < data->map->size_x)
        {
            if (map[i][x] != '0' && map[i][x] != '1' && map[i][x] != 'C' &&
                map[i][x] != 'P' && map[i][x] != 'E')
                handle_error("Error: Invalid character found in map.\n");
            if ((i == 0 || x == 0 || i == data->map->size_y - 1 || x == data->map->size_x - 1) && map[i][x] != '1')
                handle_error("Error: Map borders must be walls\n");
            x++;
        }
        if (ft_strlen(map[i]) != (size_t)len)
            handle_error("Error: Map must be rectangular\n");
        i++;
    }
}

void    check_elements(t_data *data)
{
    int x;
	int y;

    data->count.player = 0;
    data->count.exit = 0;
    data->count.collectibles = 0;
    y = 0;
    while (data->map->map[y])
    {
        x = 0;
        while (data->map->map[y][x])
        {
            if (data->map->map[y][x] == 'P') data->count.player++;
            if (data->map->map[y][x] == 'E') data->count.exit++;
            if (data->map->map[y][x] == 'C') data->count.collectibles++;
            x++;
        }
        y++;
    }
    if (data->count.player != 1)
        handle_error("Error: Map must contain one player\n");
    if (data->count.collectibles < 1)
        handle_error("Error: Nothing to collect man\n");
    if (data->count.exit != 1)
        handle_error("Error: Map must contain one Exit\n");
}

void    validate_map(t_data *data)
{
    check_map(data);
    check_elements(data);
}
