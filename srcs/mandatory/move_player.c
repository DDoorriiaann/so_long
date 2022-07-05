#include "so_long.h"

void	move_player_down(t_data *data)
{
	int	h;
	int	w;

	h = data->game.player_h;
	w = data->game.player_w;
	if (data->map[(h / 48) + 1][w / 48] != '1'
	&& data->map[(h / 48) + 1][w / 48] != 'E')
		move_player(data, 0, 1);
}

void	move_player_up(t_data *data)
{
	int	h;
	int	w;

	h = data->game.player_h;
	w = data->game.player_w;
	if (data->map[(h / 48) - 1][w / 48] != '1'
	&& data->map[(h / 48) - 1][w / 48] != 'E')
		move_player(data, 0, -1);
}

void	move_player_left(t_data *data)
{
	int	h;
	int	w;

	h = data->game.player_h;
	w = data->game.player_w;
	if (data->map[h / 48][(w / 48) - 1] != '1'
	&& data->map[h / 48][(w / 48) - 1] != 'E')
		move_player(data, -1, 0);
	data->game.player_dir = -1;
}

void	move_player_right(t_data *data)
{
	int	h;
	int	w;

	h = data->game.player_h;
	w = data->game.player_w;
	if (data->map[h / 48][(w / 48) + 1] != '1'
	&& data->map[h / 48][(w / 48) + 1] != 'E')
		move_player(data, 1, 0);
	data->game.player_dir = 1;
}

void	move_player(t_data *data, int x_offset, int y_offset)
{
	int	h;
	int	w;

	h = data->game.player_h;
	w = data->game.player_w;
	if (is_game_over(data))
		return;
	put_moves_counter_frame(data);
	update_moves_counter(data);
	if (is_game_over(data))
		return ;
	data->idle_time = 0;
	mlx_put_image_to_window(
		data->mlx,
		data->mlx_win,
		data->game.grass,
		data->game.player_w,
		data->game.player_h);
	if (data->map[(h / 48) + y_offset][(w / 48) + x_offset] == 'C')
		remove_collectible(data, y_offset, x_offset);
	data->game.player_w += x_offset * 48;
	data->game.player_h += y_offset * 48;
	player_frame(data);
	if (is_game_over(data))
		end_game(data);
}