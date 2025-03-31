
#include "../include/so_long.h"

void	update_villain_position(t_data *data, int new_x, int new_y)
{
	data->map->map[data->villain_y][data->villain_x] = '0'; // Clear old position
	data->villain_x = new_x;
	data->villain_y = new_y;
	data->map->map[data->villain_y][data->villain_x] = 'V'; // Move villain
}

void	move_villain(t_data *data)
{
	int new_x;
	int new_y;

    new_x = data->villain_x;
    new_y; = data->villain_y;
	if (data->player_x > data->villain_x)
		new_x++;
	else if (data->player_x < data->villain_x)
		new_x--;
	if (data->player_y > data->villain_y)
		new_y++;
	else if (data->player_y < data->villain_y)
		new_y--;
	if (data->map->map[new_y][new_x] == '1' || data->map->map[new_y][new_x] == 'E')
		return ;
	if (data->map->map[new_y][new_x] == 'P')
	{
		ft_printf("FATALITY! 😈\n");
		exit(0);
	}
	update_villain_position(data, new_x, new_y);
}


void	find_villain_position(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->size_y)
	{
		x = 0;
		while (x < data->map->size_x)
		{
			if (data->map->map[y][x] == 'P')
			{
				data->villain_x = x;
				data->villain_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	handle_error("Error: Villain position not found 😔\n");
}