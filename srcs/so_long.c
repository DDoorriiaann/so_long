/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:08:20 by dguet             #+#    #+#             */
/*   Updated: 2022/05/16 23:50:16 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	quit_game(t_data *data)
{
	int i;

	i = 0;
	mlx_destroy_image(data->mlx, data->game.grass);
	while (i < 5)
	 	mlx_destroy_image(data->mlx, data->game.p_anim_r[i++]);
	i = 0;
	while (i < 6)
		mlx_destroy_image(data->mlx, data->game.enemy_anim[i++]);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	data->game.grass = NULL;
	exit(0);
}

int	deal_key(int key, t_data *data)
{
	//ft_putnbr_fd(key, 1);
	if (key == 65307)
		quit_game(data);
	if (key == 65363)
		move_player(data, 1, 0);
	if (key == 65361)
		move_player(data, -1, 0);
	if (key == 65362)
		move_player(data, 0, -1);
	if (key == 65364)
		move_player(data, 0, 1);
	return(0);
}

void	texture_map(int h_res, int w_res, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < h_res)
	{
		while (j < w_res)
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->game.grass, j * 48 , i * 48);
			j++;
		}
		j = 0;
		i++;
	}
//	mlx_put_image_to_window(data->mlx, data->mlx_win, data->game.p_anim_r[0], data->game.player_w, data->game.player_h);
}

int	main(void)
{
	t_data	data;
	int		h_res;
	int		w_res;
	int		h;
	int		w;

	w_res = 16;
	h_res = 9;
	data.frame = 0;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, w_res * 48, h_res * 48, "so_long");
	
	//malloc_map(h_res, w_res, &data);
	data.game.grass = mlx_xpm_file_to_image(data.mlx, "./images/grass.xpm", &w , &h);
	load_animations(&data);
	data.game.player_w = 3 * 48;
	data.game.player_h = 3 * 48;
	data.game.enemies_nb = 1;
	data.game.enemies_w[0] = 9 * 48;
	data.game.enemies_h[0] = 4 * 48;

	mlx_key_hook(data.mlx_win, deal_key, &data);
	texture_map(h_res, w_res, &data);
//	mlx_put_image_to_window(data.mlx, data.mlx_win, data.game.player, 0, 0);
	mlx_loop_hook(data.mlx, clock, &data);
	mlx_loop(data.mlx);
}