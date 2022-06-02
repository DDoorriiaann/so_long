#include"so_long.h"

int	update_moves_counter(t_data *data)
{
	int		win_h;
	char	*moves_nb;

	win_h = (data->h_res + 1) * 48;
	moves_nb = ft_itoa(data->moves);
	mlx_string_put(data->mlx, data->mlx_win, 28, win_h - 21, 16777215, "MOVES : ");
	mlx_string_put(data->mlx, data->mlx_win, 98, win_h - 21, 16777215, moves_nb);
	free(moves_nb);
	ft_putstr_fd("Moves count: ", 1);
	ft_putnbr_fd(data->moves, 1);
	ft_putchar_fd('\n', 1);
	data->moves++;
	return (0);
}

int	put_moves_counter_frame(t_data *data)
{
	int	win_h;

	win_h = (data->h_res + 1) * 48;
	mlx_put_image_to_window(data->mlx,
		data->mlx_win, data->game.moves_frame, 8, win_h - 45);
	return (0);
}