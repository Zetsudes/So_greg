/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   villain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:08:45 by zamohame          #+#    #+#             */
/*   Updated: 2025/04/06 12:41:29 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	update_villain_position(t_data *data, int new_x, int new_y)
{
	data->map->map[data->villain_y][data->villain_x] = '0';
	data->villain_x = new_x;
	data->villain_y = new_y;
	data->map->map[data->villain_y][data->villain_x] = 'V';
}

void	move_villain(t_data *data)
{
	int	new_x;
	int	new_y;

	if (data->villain_x == -1 || data->villain_y == -1)
		return ;
	new_x = data->villain_x;
	new_y = data->villain_y;
	if (data->count.collectible <= 3)
		speed_villain(data, &new_x, &new_y);
	if (data->map->map[new_y][new_x] == '1'
		|| data->map->map[new_y][new_x] == 'E'
		|| data->map->map[new_y][new_x] == 'C')
		return ;
	if (data->map->map[new_y][new_x] == 'P')
	{
		ft_printf("FATALITY! 😈\n");
		cleanup_game(data);
		exit(0);
	}
	update_villain_position(data, new_x, new_y);
}

void	speed_villain(t_data *data, int *new_x, int *new_y)
{
	if (data->player_x > data->villain_x)
		(*new_x)++;
	else if (data->player_x < data->villain_x)
		(*new_x)--;
	if (data->player_y > data->villain_y)
		(*new_y)++;
	else if (data->player_y < data->villain_y)
		(*new_y)--;
}

void	find_villain_position(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->size_y)
	{
		x = 0;
		while (x < data->map->size_x)
		{
			if (data->map->map[y][x] == 'V')
			{
				data->villain_x = x;
				data->villain_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
