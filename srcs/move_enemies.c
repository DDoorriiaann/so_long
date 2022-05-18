#include "so_long.h"

void	enemies_frame(t_data *data)
{
	int i;

	i = 0;
	while (i < data->game.enemies_nb)
	{
		mlx_put_image_to_window(data->mlx,
							data->mlx_win,
							data->game.enemy_anim[(data->frame) / 8], 
							data->game.enemies_w[i],
							data->game.enemies_h[i]);
		i++;
	}
}

void	move_enemies(t_data *data)
{
	int x_offset; 
	int y_offset;

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