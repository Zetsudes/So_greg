/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:48:51 by zamohame          #+#    #+#             */
/*   Updated: 2025/03/03 11:13:01 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../greg_lib/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <math.h>
# include <string.h>

typedef struct s_count
{
    int player;
    int exit;
    int collectibles;
} t_count;

typedef struct s_map
{
    char **map;   
    int size_x;   
    int size_y;    
} t_map;

typedef struct s_data
{
    t_map *map;     
    t_count count;
    int player_x;
    int player_y;  
} t_data;

void    handle_error(const char *message);
void    check_map(t_data *data);
void    check_elements(t_data *data);
void    validate_map(t_data *data);
char    **read_map_from_file(const char *filename, t_data *data);
void    move_player(t_data *data, int new_x, int new_y);
void    game_loop(t_data *data);




#endif
