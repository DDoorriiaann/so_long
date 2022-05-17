#include "so_long.h"

void	player_frame(t_data *data)
{
	mlx_put_image_to_window(data->mlx, 
	 							data->mlx_win, 
	 							data->game.p_anim_r[(data->frame) / 5], 
	 							data->game.player_w,
	 							data->game.player_h);
}

void	move_player(t_data *data,int x_offset, int y_offset)
{
	
	mlx_put_image_to_window(data->mlx, 
							data->mlx_win, 
							data->game.grass, 
							data->game.player_w,
							data->game.player_h);
	data->game.player_w += x_offset * 48;
	data->game.player_h += y_offset * 48;
	// if (x_offset < 0)
	// {
	// 	mlx_put_image_to_window(data->mlx, 
	// 							data->mlx_win, 
	// 							data->game.player_l, 
	// 							data->game.player_w,
	// 							data->game.player_h);
	// }
	// else
	// {
	// 	mlx_put_image_to_window(data->mlx, 
	// 							data->mlx_win, 
	// 							data->game.player_r, 
	// 							data->game.player_w,
	// 							data->game.player_h);
	// }
	player_frame(data);
	
}