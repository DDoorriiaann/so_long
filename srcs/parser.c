#include "get_next_line.h"
#include "so_long.h"

int	check_map(int fd, t_data *data)
{
	char	*line;
	int		i;

	data->map = malloc(sizeof(char *) * data->h_res);
	i = 0;
	while (i < data->h_res)
	{
		line = get_next_line(fd);
		if (!line)
			return (1);
		// data->map[i] = malloc(strlen(line) + 1);
		data->map[i] = ft_strdup(line);
		free(line);
		line = NULL;
		i++;
	}
	// i = 0;
	// while (data->map[i])
	// 	printf("%s", data->map[i++]);
	return (0);
}

int	get_map_size(int fd, t_data *data)
{
	char	*line;
	int		line_len;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (1);
	line_len = ft_strlen(line);
	if (line_len == 0)
		return (1);
	while (line != NULL)
	{
		if ((int)ft_strlen(line) != line_len)
			return (1);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	data->w_res = line_len - 1;
	data->h_res = i;
	return (0);
}

int	open_map(char *pathname)
{
	int	fd;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

int	parse_map(char *pathname, t_data *data)
{
	int	fd;
	int	error_code;

	if (!pathname)
		return (1);
	fd = open_map(pathname);
	error_code = get_map_size(fd, data);
	close(fd);
	if (error_code)
		return (error_code);
	fd = open_map(pathname);
	error_code = check_map(fd, data);
	if (error_code)
		return (error_code);
	return (0);
}