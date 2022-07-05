#include"so_long.h"

int	update_moves_counter(t_data *data)
{
	ft_putstr_fd("Moves count: ", 1);
	ft_putnbr_fd(data->moves, 1);
	ft_putchar_fd('\n', 1);
	data->moves++;
	return (0);
}