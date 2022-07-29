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
	static const t_errordesc	g_errordesc[9] = {
	{NO_ERROR, "No error"},
	{CORRUPTED_FILE, "The map file is corrupted or missing"},
	{WRONG_LINE_LENGTH, "Line length is inconsistent"},
	{MALLOC_ERROR, "Malloc failed to allocate memory"},
	{MAP_TOO_SMALL, "The map is too small"},
	{MAP_BORDER_ERROR, "The map border is inconsistent"},
	{UNKNOWN_MAP_ELEMENT, "The map contains an element from an unknown type"},
	{WRONG_FILE_EXTENSION, "Wrong file extension"},
	{INVALID_MAP, "Invalid map"},
	};

	if (error)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(g_errordesc[error].message, 2);
		ft_putchar_fd('\n', 2);
	}
}
