/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:13:13 by dguet             #+#    #+#             */
/*   Updated: 2022/07/05 18:13:24 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	update_exit(t_data *data, int code)
{
	if (code == 1)
	{
		data->game.exit_status = 1;
		put_exit(data->game.exit_coord[1], data->game.exit_coord[0], data);
		data->map[data->game.exit_coord[0]][data->game.exit_coord[1]] = 'X';
	}
	if (code == 2)
	{
		data->game.exit_status = 2;
		put_exit(data->game.exit_coord[1], data->game.exit_coord[0], data);
	}
	return (0);
}

int	remove_collectible(t_data *data, int y_offset, int x_offset)
{
	int	h;
	int	w;

	h = data->game.player_h;
	w = data->game.player_w;
	data->map[(h / 48) + y_offset][(w / 48) + x_offset] = '0';
	data->game.collectibles_nb--;
	put_collectibles_counter_frame(data);
	update_collectibles_counter(data);
	if (data->game.collectibles_nb == 0)
		update_exit(data, 1);
	return (0);
}
