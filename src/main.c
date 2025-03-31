/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:22:47 by zamohame          #+#    #+#             */
/*   Updated: 2025/03/18 16:02:25 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		handle_error("Error: Where's the map 😔\n");
	data.mlx = mlx_init();
	if (!data.mlx)
		handle_error("Error: mlx_init failed 😔\n");
	data.map = malloc(sizeof(t_map));
	*data.map = read_map(argv[1]);
	data.moves = 0;
	check_file_extension(argv);
	validate_map(&data);
	check_path(&data);
	setup_game(&data);
	setup_hooks(&data);
	return (0);
}
