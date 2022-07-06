/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:03:25 by dguet             #+#    #+#             */
/*   Updated: 2022/07/06 14:03:26 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animate_player(t_data *data)
{
	if (data->idle_time < 3)
		player_frame(data);
	else
	{
		mlx_put_image_to_window(
			data->mlx,
			data->mlx_win,
			data->game.p_anim_s[(data->frame) / 4],
			data->game.player_w,
			data->game.player_h);
	}
}

int	ft_rand(void)
{
	static int	seed = 69;
	long int	ret;

	ret = (long int)&ret;
	ret /= seed++;
	return (ret % 4);
}

int	clock(t_data *data)
{
	if (is_game_over(data))
		return (1);
	usleep(1000000 / 24);
	data->frame++;
	if (data->frame >= 23 || data->frame < 0)
	{	
		data->frame = 0;
		data->idle_time++;
	}
	animate_player(data);
	return (data->frame);
}
