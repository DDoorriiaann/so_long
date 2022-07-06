/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:06:07 by dguet             #+#    #+#             */
/*   Updated: 2022/07/06 14:06:08 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	load_background(t_data *data)
{
	int	w;
	int	h;

	data->game.grass = mlx_xpm_file_to_image(
			data->mlx, "./images/grass.xpm", &w, &h);
	data->game.moves_frame = mlx_xpm_file_to_image(
			data->mlx, "./images/buttons/moves_frame.xpm", &w, &h);
	return (0);
}

int	load_walls(t_data *data)
{
	int	w;
	int	h;

	data->game.wall = mlx_xpm_file_to_image(
			data->mlx, "./images/walls/wall.xpm", &w, &h);
	return (0);
}

int	load_collectible(t_data *data)
{
	int	w;
	int	h;

	data->game.collectible = mlx_xpm_file_to_image(
			data->mlx, "./images/collectible.xpm", &w, &h);
	return (0);
}

int	load_exit(t_data *data)
{
	int	w;
	int	h;

	data->game.exit[0] = mlx_xpm_file_to_image(
			data->mlx, "./images/exit/exit_closed2.xpm", &w, &h);
	data->game.exit[1] = mlx_xpm_file_to_image(
			data->mlx, "./images/exit/exit_open.xpm", &w, &h);
	data->game.exit[2] = mlx_xpm_file_to_image(
			data->mlx, "./images/exit/exit_game_over.xpm", &w, &h);
	return (0);
}

int	load_textures(t_data *data)
{
	load_background(data);
	load_walls(data);
	load_collectible(data);
	load_exit(data);
	return (0);
}
