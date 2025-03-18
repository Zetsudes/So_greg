/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:31:45 by zamohame          #+#    #+#             */
/*   Updated: 2025/03/18 16:06:02 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display_ui(t_data *data)
{
	char	*moves_text;
	char	*prefix;
	char	*display;

	prefix = "Moves: ";
	moves_text = ft_itoa(data->moves);
	display = ft_strjoin(prefix, moves_text);
	mlx_string_put(data->mlx, data->win, 80, 80, 000000, display);
	free(moves_text);
	free(display);
}
