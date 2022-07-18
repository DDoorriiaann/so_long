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

t_error	ber_to_array(int fd, t_data *data)
{
	char	*line;
	int		i;

	data->map = malloc(sizeof(char *) * (data->h_res));
	i = 0;
	while (i < data->h_res)
	{
		line = get_next_line(fd);
		if (!line)
			return (MALLOC_ERROR);
		data->map[i] = ft_strdup(line);
		free(line);
		line = NULL;
		i++;
	}
	return (NO_ERROR);
}

t_error	get_map_size(int fd, t_data *data)
{
	char	*line;
	int		line_len;
	int		i;
	t_error	error;

	i = 0;
	error = NO_ERROR;
	line = get_next_line(fd);
	if (!line)
		return (MALLOC_ERROR);
	line_len = ft_strlen(line);
	if (line_len == 0 || (line[0] == '\n' && line_len == 1))
			error = MAP_TOO_SMALL;
	while (line != NULL)
	{
		if (((int)ft_strlen(line) != line_len)
			&& ((int)ft_strlen(line) == \
			line_len - 1 && line[line_len - 1] != '\0'))
				error = WRONG_LINE_LENGTH;
		free(line);
		i++;
		line = get_next_line(fd);
	}
	free(line);
	data->w_res = line_len - 1;
	data->h_res = i;
	return (error);
}

int	open_map(char *pathname)
{
	int	fd;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

t_error	parse_map(char *pathname, t_data *data)
{
	int		fd;
	t_error	error_code;

	error_code = 0;
	if (!pathname)
		return (1);
	fd = open_map(pathname);
	if (fd == -1)
		return (CORRUPTED_FILE);
	error_code = get_map_size(fd, data);
	close(fd);
	if (error_code)
		return (error_code);
	fd = open_map(pathname);
	if (fd == -1)
		return (CORRUPTED_FILE);
	error_code = ber_to_array(fd, data);
	error_code = check_map(data);
	if (error_code)
		return (error_code);
	close(fd);
	return (NO_ERROR);
}
