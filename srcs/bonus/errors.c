/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:05:48 by dguet             #+#    #+#             */
/*   Updated: 2022/07/06 14:05:50 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
