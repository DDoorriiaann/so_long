#include "so_long.h"

void	animate_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx, 
	 							data->mlx_win, 
	 							data->game.p_anim_r[(data->frame) / 5], 
	 							data->game.player_w,
	 							data->game.player_h);
}

int	clock(t_data *data)
{
	
	usleep(1000000/24);
	data->frame++;
	if (data->frame >= 23 || data->frame < 0)
		data->frame = 0;
	animate_player(data);
	ft_putnbr_fd(data->frame, 1);
	ft_putchar(' ');
	return (data->frame);
}