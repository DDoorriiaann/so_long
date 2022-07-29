/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:37:16 by dguet             #+#    #+#             */
/*   Updated: 2022/07/05 17:38:33 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

void	add_counters_space(t_data *data)
{
	char	*line;
	int		i;

	line = malloc(data->w_res + 1);
	if (!line)
	{
		data->error = MALLOC_ERROR;
		return ;
	}
	i = 0;
	while (i < data->w_res)
	{
		line[i] = '0';
		i++;
	}
	line[i] = '\0';
	data->map[data->h_res] = ft_strdup(line);
	free(line);
}

void	ber_to_array(int fd, t_data *data)
{
	char	*line;
	int		i;

	data->map = malloc(sizeof(char *) * (data->h_res + 1));
	i = 0;
	while (i < data->h_res)
	{
		line = get_next_line(fd);
		if (!line)
		{
			data->error = MALLOC_ERROR;
			return ;
		}
		data->map[i] = ft_strdup(line);
		free(line);
		line = NULL;
		i++;
	}
	add_counters_space(data);
}

void	get_map_size(int fd, t_data *data)
{
	char	*line;
	int		line_len;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
	{
		data->error = MALLOC_ERROR;
		return ;
	}
	line_len = ft_strlen(line);
	if (line_len == 0 || (line[0] == '\n' && line_len == 1))
			data->error = MAP_TOO_SMALL;
	while (line != NULL)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	free(line);
	data->w_res = line_len - 1;
	data->h_res = i;
}

int	open_map(char *pathname)
{
	int	fd;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

void	parse_map(char *pathname, t_data *data)
{
	int		fd;

	if (!pathname)
		data->error = CORRUPTED_FILE;
	if (!data->error)
	{
		fd = open_map(pathname);
		if (fd == -1)
			data->error = CORRUPTED_FILE;
		if (!data->error)
			get_map_size(fd, data);
		close(fd);
	}
	if (data->error)
		return ;
	fd = open_map(pathname);
	if (fd == -1)
		data->error = CORRUPTED_FILE;
	if (!data->error)
		ber_to_array(fd, data);
	if (!data->error)
		check_map(data);
	close(fd);
}
