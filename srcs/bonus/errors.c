#include "so_long.h"

void	throw_error(t_error error)
{
	if (error)
	{	
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(g_errordesc[error].message, 2);
		ft_putchar_fd('\n', 2);
	}
}