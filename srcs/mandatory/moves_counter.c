/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:40:04 by dguet             #+#    #+#             */
/*   Updated: 2022/07/05 17:40:10 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	update_moves_counter(t_data *data)
{
	ft_putstr_fd("Moves count: ", 1);
	ft_putnbr_fd(data->moves, 1);
	ft_putchar_fd('\n', 1);
	data->moves++;
	return (0);
}
