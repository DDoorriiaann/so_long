/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:33:21 by dguet             #+#    #+#             */
/*   Updated: 2022/07/05 17:33:24 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	texture_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->h_res)
	{
		while (j < data->w_res)
		{
			if (data->map[i][j] == 'P')
				put_player(j, i, data);
			else if (data->map[i][j] == '1')
				put_wall(j, i, data);
			else if (data->map[i][j] == 'C')
				put_collectible(j, i, data);
			else if (data->map[i][j] == 'E')
				put_exit(j, i, data);
			else if (data->map[i][j] == '0')
				put_background(j, i, data);
			j++;
		}
		j = 0;
		i++;
	}
	update_moves_counter(data);
}
