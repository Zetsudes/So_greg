/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:23:04 by zamohame          #+#    #+#             */
/*   Updated: 2025/04/08 16:18:13 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_game(t_data *data)
{
	cleanup_game(data);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_game(data);
	else if (keycode == XK_w)
		move_player(data, data->player_x, data->player_y - 1);
	else if (keycode == XK_s)
		move_player(data, data->player_x, data->player_y + 1);
	else if (keycode == XK_a)
		move_player(data, data->player_x - 1, data->player_y);
	else if (keycode == XK_d)
		move_player(data, data->player_x + 1, data->player_y);
	return (0);
}

void	setup_hooks(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->win, 17, 0, close_game, data);
}
