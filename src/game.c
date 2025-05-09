/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:22:59 by zamohame          #+#    #+#             */
/*   Updated: 2025/04/08 16:13:58 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	setup_game(t_data *data)
{
	setup_window(data);
	find_player_position(data);
	load_images(data);
	render_map(data);
}

void	setup_window(t_data *data)
{
	int	window_width;
	int	window_height;

	window_width = data->map->size_x * 64;
	window_height = data->map->size_y * 64;
	data->win = mlx_new_window(data->mlx, window_width, window_height,
			"so_long");
	if (!data->win)
		handle_error("Error: Failed to create window 😔\n", data);
}
