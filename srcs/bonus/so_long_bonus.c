/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:08:20 by dguet             #+#    #+#             */
/*   Updated: 2022/07/06 14:08:47 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quit_game(t_data *data)
{
	destroy_images(data);
	destroy_game(data);
	exit(0);
	return (0);
}

void	set_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, 17, 0, quit_game, data);
}

int	deal_key(int key, t_data *data)
{
	if (key == 65307)
		quit_game(data);
	if (key == 65363 || key == 100)
		move_player_right(data);
	if (key == 65361 || key == 97)
		move_player_left(data);
	if (key == 65362 || key == 119)
		move_player_up(data);
	if (key == 65364 || key == 115)
		move_player_down(data);
	return (0);
}

int	initialize_game(t_data *data)
{
	data->moves = 0;
	data->frame = 0;
	data->idle_time = 0;
	data->game.player_dir = 1;
	data->game.collectibles_nb = 0;
	data->game.exit_status = 0;
	data->game.player_h = 0;
	data->game.player_w = 0;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(
			data->mlx, data->w_res * 48,
			(data->h_res + 1) * 48, "so_long");
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (1);
	data.error = NO_ERROR;
	data.error = check_file_extension(argv[1]);
	if (!data.error)
		data.error = parse_map(argv[1], &data);
	if (data.error)
	{
		throw_error(data.error);
		return (1);
	}
	initialize_game(&data);
	load_textures(&data);
	texture_map(&data);
	load_animations(&data);
	mlx_key_hook(data.mlx_win, deal_key, &data);
	mlx_loop_hook(data.mlx, clock, &data);
	set_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
