/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:01:33 by dguet             #+#    #+#             */
/*   Updated: 2022/07/05 18:01:35 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	load_enemies(t_data *data)
{
	int	i;

	i = 0;
	data->game.enemies_nb = 0;
	while (i < data->game.enemies_nb)
	{	
		data->game.enemies_w[i] = ft_rand() * 9 * 48;
		data->game.enemies_h[i] = ft_rand() * 4 * 48;
		i++;
	}
	return (0);
}
