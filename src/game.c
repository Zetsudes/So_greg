
#include "../include/so_long.h"

void    game_loop(t_data *data)
{
    char input;

    while (1)
    {
        printf("Enter move (W/A/S/D): ");
        scanf(" %c", &input);

        if (input == 'W' || input == 'w')
            move_player(data, data->player_x, data->player_y - 1);
        else if (input == 'S' || input == 's')
            move_player(data, data->player_x, data->player_y + 1);
        else if (input == 'A' || input == 'a')
            move_player(data, data->player_x - 1, data->player_y);
        else if (input == 'D' || input == 'd')
            move_player(data, data->player_x + 1, data->player_y);
        else if (input == 'Q' || input == 'q')
        {
            printf("Game Over!\n");
            break;
        }
    }
}
