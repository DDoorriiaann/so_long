/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:07:17 by dguet             #+#    #+#             */
/*   Updated: 2022/07/06 14:07:19 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_background(int w, int h, t_data *data)
{
	mlx_put_image_to_window(data->mlx,
		data->mlx_win, data->game.grass, w * 48, h * 48);
}

void	put_wall(int w, int h, t_data *data)
{
	mlx_put_image_to_window(data->mlx,
		data->mlx_win, data->game.wall, w * 48, h * 48);
}

void	put_collectible(int w, int h, t_data *data)
{
	data->game.collectibles_nb++;
	mlx_put_image_to_window(data->mlx,
		data->mlx_win, data->game.collectible, w * 48, h * 48);
}

void	put_exit(int w, int h, t_data *data)
{
	data->game.exit_coord[0] = h;
	data->game.exit_coord[1] = w;
	if (data->game.exit_status == 0)
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->game.exit[0], w * 48, h * 48);
	if (data->game.exit_status == 1)
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->game.exit[1], w * 48, h * 48);
	if (data->game.exit_status == 2)
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->game.exit[2], w * 48, h * 48);
}

void	put_player(int w, int h, t_data *data)
{
	data->game.player_h = h * 48;
	data->game.player_w = w * 48;
}
