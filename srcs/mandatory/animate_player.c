#include"so_long.h"

void	player_frame(t_data *data)
{
	if (data->game.player_dir == 1)
	{
		mlx_put_image_to_window(
			data->mlx,
			data->mlx_win,
			data->game.p_anim_r[0],
			data->game.player_w,
			data->game.player_h);
	}
	else
	{
		mlx_put_image_to_window(
			data->mlx,
			data->mlx_win,
			data->game.p_anim_l[0],
			data->game.player_w,
			data->game.player_h);
	}
}