/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:24:47 by dguet             #+#    #+#             */
/*   Updated: 2022/07/05 17:28:22 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	check_file_extension(t_data *data, char *path)
{
	int	len;

	len = ft_strlen(path);
	if (path[len - 1] != 'r'
		|| path[len - 2] != 'e'
		|| path[len - 3] != 'b'
		|| path[len - 4] != '.'
		|| (!path[len - 5] && path[len - 5] == '\\'))
		data->error = WRONG_FILE_EXTENSION;
}

void	check_borders(t_data *data, t_map_check *counters)
{
	if (counters->y == 0 || counters->y == data->h_res - 1)
	{
		if (data->map[counters->y][counters->x] == '1')
			return ;
	}
	else
		if (data->map[counters->y][0] == '1'
			&& data->map[counters->y][data->w_res - 1] == '1')
			return ;
	data->error = MAP_BORDER_ERROR;
}

void	check_elements(t_data *data, t_map_check *counters)
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
			data->error = UNKNOWN_MAP_ELEMENT;
}

void	check_counters(t_data *data, t_map_check *counters)
{
	if (counters->c_count < 1
		|| counters->e_count < 1
		|| counters->p_count < 1)
		data->error = INVALID_MAP;
}

void	check_map(t_data *data)
{
	t_map_check	counters;

	counters = initialize_counters(counters);
	check_lines_len(data);
	while (counters.y < data->h_res && !data->error)
	{
		check_borders_and_elements(data, &counters);
		counters.x = -1;
		counters.y++;
	}
	if (!data->error)
		check_counters(data, &counters);
	if (data->error)
		free_map(data);
}
