/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:02:00 by dguet             #+#    #+#             */
/*   Updated: 2022/07/05 18:09:23 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_counters(t_data *data)
{
	put_moves_counter_frame(data);
	update_moves_counter(data);
	put_collectibles_counter_frame(data);
	update_collectibles_counter(data);
}

void	texture_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i <= data->h_res)
	{
		while (j < data->w_res)
		{
			if (data->map[i][j] == 'P')
				put_player(j, i, data);
			if (data->map[i][j] == '1')
				put_wall(j, i, data);
			if (data->map[i][j] == 'C')
				put_collectible(j, i, data);
			if (data->map[i][j] == 'E')
				put_exit(j, i, data);
			if (data->map[i][j] == '0')
				put_background(j, i, data);
			j++;
		}
		j = 0;
	}
	put_counters(data);
}
