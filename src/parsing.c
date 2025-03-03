#include "../include/so_long.h"

void	check_map_elements(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P')
			{
				ft_printf("Error :\n Invalid character '%c' at row %d, column
					%d", map[i][j], i, j);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_elements_count(char **map)
{
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
