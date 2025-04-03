/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:22:59 by zamohame          #+#    #+#             */
/*   Updated: 2025/04/03 16:25:17 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	setup_game(t_data *data)
{
	setup_window(data);
	find_player_position(data);
	find_villain_position(data);
	init_animations(data);
	load_images(data);
	render_map(data);
	display_moves(data);
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
