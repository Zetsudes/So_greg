// #include "minilibx-linux/mlx.h"

// int	main(void)
// {
// 	void	*mlx;
// 	void	*win;

// 	mlx = mlx_init();
// 	if (!mlx)
// 		return (1);
// 	win = mlx_new_window(mlx, 800, 600, "MiniLibX Window");
// 	mlx_loop(mlx);
// 	return (0);
// }
#include "../include/so_long.h"

char    **read_map_from_file(const char *filename, t_data *data)
{
    FILE *file = fopen(filename, "r");
    if (!file)
        handle_error("Error: Could not open map file.\n");
    int fd = fileno(file);
    char **map = malloc(sizeof(char *) * 100);
    char *line = NULL;
    int line_count = 0;

    while ((line = get_next_line(fd)) != NULL)
    {
        map[line_count] = ft_strdup(line); 
        map[line_count][strcspn(map[line_count], "\n")] = '\0';
        if (line_count == 0)
            data->map->size_x = ft_strlen(map[line_count]);
        for (int x = 0; x < data->map->size_x; x++)
        {
            if (map[line_count][x] == 'P')
            {
                data->player_x = x;
                data->player_y = line_count;
                printf("Player starts at (%d, %d)\n", data->player_y, data->player_x);
            }
        }
        line_count++;
    }

    fclose(file);
    data->map->size_y = line_count;
    return map;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        handle_error("Error: Please provide a map file.\n");

    t_data data;
    data.map = malloc(sizeof(t_map));
    data.count.player = 0;
    data.count.exit = 0;
    data.count.collectibles = 0;

    data.map->map = read_map_from_file(argv[1], &data);
    check_map(&data);
    check_elements(&data);

    printf("Map is valid! Starting game...\n");
    game_loop(&data);

    for (int i = 0; i < data.map->size_y; i++)
        free(data.map->map[i]);
    free(data.map->map);
    free(data.map);

    return 0;
}

