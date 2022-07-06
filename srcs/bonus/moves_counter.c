/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:01:45 by dguet             #+#    #+#             */
/*   Updated: 2022/07/05 18:01:47 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	update_moves_counter(t_data *data)
{
	int		win_h;
	char	*moves_nb;

	win_h = (data->h_res + 1) * 48;
	moves_nb = ft_itoa(data->moves);
	mlx_string_put(data->mlx, data->mlx_win,
		24, win_h - 21, 16777215, "MOVES : ");
	mlx_string_put(data->mlx, data->mlx_win,
		94, win_h - 21, 16777215, moves_nb);
	free(moves_nb);
	data->moves++;
	return (0);
}

int	put_moves_counter_frame(t_data *data)
{
	int	win_h;

	win_h = (data->h_res + 1) * 48;
	mlx_put_image_to_window(data->mlx,
		data->mlx_win, data->game.moves_frame, 8, win_h - 45);
	return (0);
}
