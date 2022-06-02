#include "so_long.h"

void	player_frame(t_data *data)
{
	if (data->game.player_dir == 1)
	{
		mlx_put_image_to_window(
			data->mlx,
			data->mlx_win,
			data->game.p_anim_r[(data->frame) / 5],
			data->game.player_w,
			data->game.player_h);
	}
	else
	{
		mlx_put_image_to_window(
			data->mlx,
			data->mlx_win,
			data->game.p_anim_l[(data->frame) / 5],
			data->game.player_w,
			data->game.player_h);
	}
}

void	move_player_left(t_data *data)
{
	int	h;
	int	w;

	h = data->game.player_h;
	w = data->game.player_w;
	if (data->map[h / 48][(w / 48) - 1] != '1' )
		move_player(data, -1, 0);
	data->game.player_dir = -1;
}

void	move_player_right(t_data *data)
{
	int	h;
	int	w;

	h = data->game.player_h;
	w = data->game.player_w;
	if (data->map[h / 48][(w / 48) + 1] != '1')
		move_player(data, 1, 0);
	data->game.player_dir = 1;
}

void	move_player(t_data *data,int x_offset, int y_offset)
{
	int	h;
	int	w;

	h = data->game.player_h;
	w = data->game.player_w;
	data->idle_time = 0;
	mlx_put_image_to_window(
		data->mlx,
		data->mlx_win,
		data->game.grass,
		data->game.player_w,
		data->game.player_h);
	if (data->map[(h / 48) + y_offset][(w / 48) + x_offset] == 'C')
	{
		data->map[(h / 48) + y_offset][(w / 48) + x_offset] = '0';
		data->game.collectibles_nb--;
		if (data->game.collectibles_nb == 0)
		{
			data->game.exit_status = 1;
			put_exit(data->game.exit_coord[1], data->game.exit_coord[0], data);
		}
	}
	put_moves_counter_frame(data);
	update_moves_counter(data);
	data->game.player_w += x_offset * 48;
	data->game.player_h += y_offset * 48;
	player_frame(data);
}