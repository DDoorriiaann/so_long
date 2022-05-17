/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:12:11 by dguet             #+#    #+#             */
/*   Updated: 2022/04/15 18:27:29 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr_base(long int nbr, char *base)
{
	int		base_len;
	char	tmp;

	nbr = nbr;
	base_len = ft_strlen(base);
	if (base_len == 0 || base_len == 1)
		return ;
	if (base_len > 1)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr = -nbr;
		}
		if (nbr >= base_len)
			ft_putnbr_base((int)nbr / base_len, base);
		tmp = base[nbr % base_len];
		write(1, &tmp, 1);
	}
}
