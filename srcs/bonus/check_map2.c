/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 22:58:02 by dguet             #+#    #+#             */
/*   Updated: 2022/07/26 22:58:05 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	check_borders_and_elements(t_data *data, t_map_check *counters)
{
	while (++counters->x < data->w_res && !data->error)
	{
		check_borders(data, counters);
		if (!data->error)
			check_elements(data, counters);
	}
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->h_res)
		free(data->map[i++]);
	free(data->map);
}

void	check_lines_len(t_data *data)
{
	int	i;
	int	line_len;

	i = 0;
	line_len = ft_strlen(data->map[i]);
	while (++i < data->h_res - 1)
	{
		if (((int)ft_strlen(data->map[i]) != line_len))
			data->error = WRONG_LINE_LENGTH;
	}
	if (data->map[i][line_len - 1] == '\0'
		&& data->map[i][line_len - 2] == '1')
		return ;
	if (((int)ft_strlen(data->map[i]) != line_len)
		|| (data->map[i][line_len - 1] != '\n'))
			data->error = WRONG_LINE_LENGTH;
}

t_map_check	initialize_counters(t_map_check counters)
{
	counters.x = -1;
	counters.y = 0;
	counters.c_count = 0;
	counters.e_count = 0;
	counters.p_count = 0;
	return (counters);
}
