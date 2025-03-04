/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:13:09 by zamohame          #+#    #+#             */
/*   Updated: 2025/03/03 11:27:00 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_count(t_count *count)
{
	count->p = 0;
	count->c = 0;
	count->e = 0;
}

void	check_map_elements(char **map)
{
	int		i;
	int		j;
	t_count	count;

	init_count(&count);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P')
			{
				ft_printf("Error: Invalid character '%c' at row %d column %d\n",
					map[i][j], i, j);
				exit(1);
			}
			j++;
		}
		i++;
	}
	count_elements(map, &count);
	check_elements_count(count);
}

void	count_elements(char **map, t_count *count)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				count->p++;
			if (map[i][j] == 'C')
				count->c++;
			if (map[i][j] == 'E')
				count->e++;
			j++;
		}
		i++;
	}
}

void	check_elements_count(t_count count)
{
	if (count.p != 1)
	{
		printf("Error: Map must contain exactly one player P\n");
		exit(1);
	}
	if (count.c < 1)
	{
		printf("Error: Map must contain at least one collectible C\n");
		exit(1);
	}
	if (count.e != 1)
	{
		printf("Error: Map must contain exactly one exit E\n");
		exit(1);
	}
}

void	check_map_walls(char **map)
{
}

void	check_map_format(char **map)
{
}

void	check_map_path(char **map)
{
}

void	validate_map(char **map)
{
	check_map_elements(map);
	check_map_walls(map);
	check_map_format(map);
	check_map_path(map);
}
