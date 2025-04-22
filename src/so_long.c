/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:22:47 by zamohame          #+#    #+#             */
/*   Updated: 2025/04/22 13:17:54 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Error: Where's the map 😔\n");
		exit(1);
	}
	check_file_extension(argv);
	data.mlx = mlx_init();
	if (!data.mlx)
		exit_error("Error: mlx_init failed 😔\n", &data);
	data.map = malloc(sizeof(t_map));
	data.map->map = NULL;
	data.map->size_x = 0;
	data.map->size_y = 0;
	*data.map = read_map(argv[1], &data);
	data.moves = 0;
	validate_map(&data);
	find_player_position(&data);
	check_path(&data);
	setup_game(&data);
	setup_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
