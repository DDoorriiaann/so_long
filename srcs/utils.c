#include "so_long.h"

void	animate_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx, 
							data->mlx_win, 
							data->game.p_anim_r[(data->frame) / 5], 
							data->game.player_w,
							data->game.player_h);
}

void	animate_enemies(t_data *data)
{
	// int	i;

	// i = 0;
	// while (i < data->game.enemies_nb)
	// {
	// 	mlx_put_image_to_window(data->mlx,
	// 						data->mlx_win,
	// 						data->game.enemy_anim[(data->frame) / 8], 
	// 						data->game.enemies_w[i],
	// 						data->game.enemies_h[i]);
	// 	i++;
	// }
	//ft_putnbr_fd(data->game.enemies_w[0], 1);
//	ft_putnbr_fd(data->game.enemies_w[0], 1);
//	ft_putnbr_fd(data->game.enemies_h[0], 1);
	mlx_put_image_to_window(data->mlx,
							data->mlx_win,
							data->game.enemy_anim[(data->frame) / 4], 
							data->game.enemies_w[0],
							data->game.enemies_h[0]);
}

int	clock(t_data *data)
{
//	ft_putnbr_fd(data->game.enemies_w[0], 1);
	usleep(1000000/24);
	data->frame++;
	if (data->frame >= 23 || data->frame < 0)
		data->frame = 0;
	animate_player(data);
//	ft_putnbr_fd(data->game.enemies_nb, 1);
	animate_enemies(data);
//	ft_putnbr_fd(data->frame, 1);
//	ft_putchar(' ');
	return (data->frame);
}