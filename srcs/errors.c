#include "so_long.h"

void	throw_error(int error)
{
	if (error)
		ft_putstr_fd("ERROR", 1);
}