/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 22:58:15 by dguet             #+#    #+#             */
/*   Updated: 2022/07/26 22:58:17 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

t_error	check_borders_and_elements(t_data *data, t_map_check *counters)
{
	t_error		error;

	error = NO_ERROR;
	while (++counters->x < data->w_res && ! error)
	{
		error = check_borders(data, counters);
		if (!error)
			error = check_elements(data, counters);
	}
	return (error);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->h_res)
		free(data->map[i++]);
	free(data->map);
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
