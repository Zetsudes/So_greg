/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:18:43 by zamohame          #+#    #+#             */
/*   Updated: 2025/04/06 13:02:12 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_animations(t_data *data)
{
	data->jellyfish_anim.frame_counter = 0;
	data->jellyfish_anim.current_frame = 0;
	data->jellyfish_anim.anim_speed = 300;
}

int	update_animation(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	update_jellyfish_animation(data);
	render_map(data);
	display_moves(data);
	return (0);
}

void	update_jellyfish_animation(t_data *data)
{
	data->jellyfish_anim.frame_counter++;
	if (data->jellyfish_anim.frame_counter >= data->jellyfish_anim.anim_speed)
	{
		data->jellyfish_anim.frame_counter = 0;
		data->jellyfish_anim.current_frame = (data->jellyfish_anim.current_frame
				+ 1) % 4;
	}
}
