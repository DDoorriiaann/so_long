/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:17:07 by dguet             #+#    #+#             */
/*   Updated: 2022/07/05 17:17:38 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	end_game(t_data *data)
{
	ft_putstr_fd("YOU WIN\n", 1);
	update_exit(data, 2);
	quit_game(data);
	return (0);
}

int	is_game_over(t_data *data)
{
	int	player_coord[2];
	int	exit_coord[2];

	player_coord[0] = data->game.player_h;
	player_coord[1] = data->game.player_w;
	exit_coord[0] = data->game.exit_coord[0] * 48;
	exit_coord[1] = data->game.exit_coord[1] * 48;
	if (player_coord[0] == exit_coord[0]
		&& player_coord[1] == exit_coord[1])
		return (1);
	return (0);
}
