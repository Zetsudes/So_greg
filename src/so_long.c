/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:22:47 by zamohame          #+#    #+#             */
/*   Updated: 2025/04/06 16:09:38 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		exit_error("Error: Where's the map 😔\n");
	check_file_extension(argv);
	data.mlx = mlx_init();
	if (!data.mlx)
		exit_error("Error: mlx_init failed 😔\n");
	data.map = malloc(sizeof(t_map));
	*data.map = read_map(argv[1], &data);
	data.moves = 0;
	validate_map(&data);
	find_player_position(&data);
	find_villain_position(&data);
	check_path(&data);
	setup_game(&data);
	setup_hooks(&data);
	mlx_loop_hook(data.mlx, update_animation, &data);
	mlx_loop(data.mlx);
	return (0);
}
