#include "so_long.h"

void	enemies_frame(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->game.enemies_nb)
	{
		mlx_put_image_to_window(
			data->mlx,
			data->mlx_win,
			data->game.enemy_anim[(data->frame) / 8],
			data->game.enemies_w[i],
			data->game.enemies_h[i]);
		i++;
	}
}

void	move_enemies(t_data *data)
{
	int	x_offset;
	int	y_offset;
	int	rand;
	int	i;


	i = 0;
	x_offset = 0;
	y_offset = 0;
	while (i < data->game.enemies_nb)
	{
		rand = ft_rand();
		if (rand == 0)
			x_offset = 1;
		if (rand == 1)
			x_offset = -1;
		if (rand == 2)
			y_offset = 1;
		if (rand == 3)
			y_offset = -1;
		mlx_put_image_to_window(
			data->mlx, data->mlx_win,
			data->game.grass, data->game.enemies_w[i],
			data->game.enemies_h[i]);
		data->game.enemies_w[i] += x_offset * 48;
		data->game.enemies_h[i] += y_offset * 48;
		i++;
	}
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
	enemies_frame(data);
}