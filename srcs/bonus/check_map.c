/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:53:41 by dguet             #+#    #+#             */
/*   Updated: 2022/07/05 17:59:44 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

t_error	check_file_extension(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (path[len - 1] == 'r'
		&& path[len - 2] == 'e'
		&& path[len - 3] == 'b'
		&& path[len - 4] == '.'
		&& path[len - 5])
		return (NO_ERROR);
	return (WRONG_FILE_EXTENSION);
}

t_error	check_borders(t_data *data, t_map_check *counters)
{
	if (counters->y == 0 || counters->y == data->h_res - 1)
	{
		if (data->map[counters->y][counters->x] == '1')
			return (NO_ERROR);
	}
	else
		if (data->map[counters->y][0] == '1'
			&& data->map[counters->y][data->w_res - 1] == '1')
			return (NO_ERROR);
	return (MAP_BORDER_ERROR);
}

t_error	check_elements(t_data *data, t_map_check *counters)
{
	if (data->map[counters->y][counters->x] == 'C')
		counters->c_count += 1;
	if (data->map[counters->y][counters->x] == 'E')
		counters->e_count += 1;
	if (data->map[counters->y][counters->x] == 'P')
		counters->p_count += 1;
	if (data->map[counters->y][counters->x] != 'C'
			&& data->map[counters->y][counters->x] != 'E'
			&& data->map[counters->y][counters->x] != 'P'
			&& data->map[counters->y][counters->x] != '1'
			&& data->map[counters->y][counters->x] != '0')
		return (UNKNOWN_MAP_ELEMENT);
	return (NO_ERROR);
}

t_error	check_counters(t_map_check *counters)
{
	if (counters->c_count < 1
		|| counters->e_count < 1
		|| counters->p_count < 1)
		return (INVALID_MAP);
	return (NO_ERROR);
}

t_error	check_map(t_data *data)
{
	t_map_check	counters;
	t_error		error;

	counters = initialize_counters(counters);
	error = NO_ERROR;
	while (counters.y < data->h_res && !error)
	{
		error = check_borders_and_elements(data, counters);
		counters.x = -1;
		counters.y++;
	}
	if (!error)
		error = check_counters(&counters);
	if (error)
		free_map(data);
	return (error);
}
