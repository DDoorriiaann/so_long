/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:39:30 by dguet             #+#    #+#             */
/*   Updated: 2022/07/06 13:57:18 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	destroy_images(t_data *data)
{
	int	i;

	mlx_destroy_image(data->mlx, data->game.grass);
	mlx_destroy_image(data->mlx, data->game.wall);
	mlx_destroy_image(data->mlx, data->game.collectible);
	mlx_destroy_image(data->mlx, data->game.moves_frame);
	i = 0;
	while (i < 5)
		mlx_destroy_image(data->mlx, data->game.p_anim_r[i++]);
	i = 0;
	while (i < 5)
		mlx_destroy_image(data->mlx, data->game.p_anim_l[i++]);
	i = 0;
	while (i < 6)
		mlx_destroy_image(data->mlx, data->game.p_anim_s[i++]);
	i = 0;
	while (i < 3)
		mlx_destroy_image(data->mlx, data->game.exit[i++]);
}

void	destroy_game(t_data *data)
{
	int	i;

	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	data->game.grass = NULL;
	data->game.wall = NULL;
	i = 0;
	while (i <= data->h_res)
		free(data->map[i++]);
	free(data->map);
}
