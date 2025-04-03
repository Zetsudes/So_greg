/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:23:15 by zamohame          #+#    #+#             */
/*   Updated: 2025/04/03 13:14:18 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	update_position(t_data *data, int new_x, int new_y)
{
	data->map->map[data->player_y][data->player_x] = '0';
	data->player_x = new_x;
	data->player_y = new_y;
	data->map->map[data->player_y][data->player_x] = 'P';
	data->moves++;
	ft_printf("Move count: %d\n", data->moves);
}

void	move_player(t_data *data, int new_x, int new_y)
{
	if (new_x < 0 || new_y < 0 || new_x >= data->map->size_x
		|| new_y >= data->map->size_y)
		return ;
	if (data->map->map[new_y][new_x] == '1')
		return ;
	if (data->map->map[new_y][new_x] == 'C')
	{
		data->count.collectible--;
		data->map->map[new_y][new_x] = '0';
	}
	if (data->map->map[new_y][new_x] == 'E' && data->count.collectible == 0)
	{
		ft_printf("Quel GOAT! 🐐🎉\n");
		exit(0);
	}
	else if (data->map->map[new_y][new_x] == 'E')
		return ;
	update_position(data, new_x, new_y);
	if (data->moves > 10)
		move_villain(data);
	render_map(data);
}

void	find_player_position(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->size_y)
	{
		x = 0;
		while (x < data->map->size_x)
		{
			if (data->map->map[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	handle_error("Error: No player found 😔\n");
}
