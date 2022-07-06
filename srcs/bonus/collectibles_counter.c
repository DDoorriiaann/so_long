/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles_counter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:57:39 by dguet             #+#    #+#             */
/*   Updated: 2022/07/06 13:58:54 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	update_collectibles_counter(t_data *data)
{
	int		win_h;
	int		win_w;
	char	*moves_nb;

	win_h = (data->h_res + 1) * 48;
	win_w = data->w_res * 48;
	moves_nb = ft_itoa(data->game.collectibles_nb);
	mlx_string_put(data->mlx, data->mlx_win,
		win_w - 123, win_h - 21, 16777215, "CHICKENS :");
	mlx_string_put(data->mlx, data->mlx_win,
		win_w - 38, win_h - 21, 16777215, moves_nb);
	free(moves_nb);
	return (0);
}

int	put_collectibles_counter_frame(t_data *data)
{
	int	win_h;
	int	win_w;

	win_h = (data->h_res + 1) * 48;
	win_w = data->w_res * 48;
	mlx_put_image_to_window(data->mlx,
		data->mlx_win, data->game.moves_frame, win_w - 138, win_h - 45);
	return (0);
}
