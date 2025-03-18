/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:22:59 by zamohame          #+#    #+#             */
/*   Updated: 2025/03/18 16:02:58 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_loop(t_data *data)
{
	mlx_key_hook(data->win, key_hook, data);
	mlx_loop(data->mlx);
}

void	setup_game(t_data *data)
{
	setup_window(data);
	find_player_position(data);
	load_images(data);
	render_map(data);
	display_ui(data);
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
		handle_error("Error: Failed to create window 😔\n");
}
