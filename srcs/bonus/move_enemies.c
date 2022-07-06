/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:12:52 by dguet             #+#    #+#             */
/*   Updated: 2022/07/06 14:02:09 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemies_frame(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->game.enemies_nb)
	{
		mlx_put_image_to_window(
			data->mlx,
			data->mlx_win,
			data->game.enemy_anim[(data->frame) / 8],
			data->game.enemies_w[i],
			data->game.enemies_h[i]);
		i++;
	}
}

void	put_grass(t_data *data)
{
	mlx_put_image_to_window(
		data->mlx, data->mlx_win,
		data->game.grass, data->game.enemies_w[i],
		data->game.enemies_h[i]);
	data->game.enemies_w[i] += x_offset * 48;
	data->game.enemies_h[i] += y_offset * 48;
}

void	move_enemies(t_data *data)
{
	int	x_offset;
	int	y_offset;
	int	rand;
	int	i;

	i = 0;
	x_offset = 0;
	y_offset = 0;
	while (i < data->game.enemies_nb)
	{
		rand = ft_rand();
		if (rand == 0)
			x_offset = 1;
		if (rand == 1)
			x_offset = -1;
		if (rand == 2)
			y_offset = 1;
		if (rand == 3)
			y_offset = -1;
		i++;
	}
	enemies_frame(data);
}
