/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:50:32 by dguet             #+#    #+#             */
/*   Updated: 2022/07/05 17:50:35 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	player_frame(t_data *data)
{
	if (data->game.player_dir == 1)
	{
		mlx_put_image_to_window(
			data->mlx,
			data->mlx_win,
			data->game.p_anim_r[(data->frame) / 5],
			data->game.player_w,
			data->game.player_h);
	}
	else
	{
		mlx_put_image_to_window(
			data->mlx,
			data->mlx_win,
			data->game.p_anim_l[(data->frame) / 5],
			data->game.player_w,
			data->game.player_h);
	}
}
