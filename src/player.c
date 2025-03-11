
#include "../include/so_long.h"

void    move_player(t_data *data, int new_x, int new_y)
{
    if (data->map->map[new_y][new_x] == '1')
    {
        printf("Can't move, there's a wall!\n");
        return;
    }
    
    data->map->map[data->player_y][data->player_x] = '0'; 
    data->map->map[new_y][new_x] = 'P'; 
    data->player_x = new_x;
    data->player_y = new_y;

    printf("Player moved to (%d, %d)\n", new_y, new_x);
}
