/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:23:26 by zamohame          #+#    #+#             */
/*   Updated: 2025/04/22 14:34:01 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	handle_error(const char *message, t_data *data)
{
	ft_printf(message);
	if (data && data->mlx)
		cleanup_game(data);
	exit(1);
}

void	exit_error(const char *message, t_data *data)
{
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map)
	{
		free_map(data->map);
		free(data->map);
	}
	ft_printf(message);
	exit(1);
}

void	init_elements(t_data *data)
{
	data->count.player = 0;
	data->count.exit = 0;
	data->count.collectible = 0;
}

void	elements_errors(t_data *data)
{
	if (data->count.player != 1)
		exit_error("Error: Map must contain one player 😔\n", data);
	if (data->count.collectible < 1)
		exit_error("Error: Nothing to collect man 😔\n", data);
	if (data->count.exit != 1)
		exit_error("Error: Map must contain one exit 😔\n", data);
}

void	check_file_extension(char **argv)
{
	char	*extension;

	extension = ft_strchr(argv[1], '.');
	if (extension == NULL || ft_strlen(extension) != 4 || ft_strncmp(extension,
			".ber", 4) != 0)
	{
		ft_printf("Error: Not a .ber file 😔\n");
		exit(1);
	}
}
