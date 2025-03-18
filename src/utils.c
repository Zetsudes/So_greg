/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:23:26 by zamohame          #+#    #+#             */
/*   Updated: 2025/03/18 13:55:04 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	handle_error(const char *message)
{
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
		handle_error("Error: Map must contain one player 😔\n");
	if (data->count.collectible < 1)
		handle_error("Error: Nothing to collect man 😔\n");
	if (data->count.exit != 1)
		handle_error("Error: Map must contain one exit 😔\n");
}

void	check_file_extension(char **argv)
{
	char	*extension;

	extension = ft_strchr(argv[1], '.');
	if (extension == NULL || ft_strlen(extension) != 4 || ft_strncmp(extension,
			".ber", 4) != 0)
		handle_error("Error: Not a .ber file 😔\n");
}

void	check_path(t_data *data)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = data->map->map;
	while (map[i][j])
	{
	}
}
