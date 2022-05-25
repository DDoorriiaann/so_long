/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line      .c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:50:06 by dguet             #+#    #+#             */
/*   Updated: 2022/05/04 01:43:36 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include<stddef.h>

int	check_line_end(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		return (1);
	return (0);
}

char	*ft_get_line(char *backup)
{
	char	*line;
	char	*end;

	end = gnl_strchr(backup, '\n');
	line = gnl_substr(backup, 0, ((end - backup)) + 1);
	return (line);
}

char	*find_line(char **backup, char **end, char **buff)
{
	char	*line;

	if (*backup && **backup && gnl_strchr(*backup, '\n'))
		*end = gnl_strdup(gnl_strchr(*backup, '\n'));
	else
	{
		line = gnl_strdup(*backup);
		free(*backup);
		*backup = NULL;
		free(*buff);
		return (line);
	}
	return (NULL);
}

char	*find_line_check_end(char **backup, char **end, char **buff)
{
	char	*line;

	line = find_line(backup, end, buff);
	if (line)
		return (line);
	if (**end)
	{
		line = ft_get_line(*backup);
		free(*backup);
		*backup = NULL;
		if (*(*end + 1))
			*backup = gnl_strdup(*end + 1);
		free(*end);
	}
	else
	{
		line = gnl_strdup(*backup);
		free(*backup);
		*backup = NULL;
	}
	free(*buff);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*backup[2048];
	int			bytes_read;
	char		*buff;
	char		*end;

	end = NULL;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	buff[0] = '\0';
	bytes_read = 1;
	while (bytes_read > 0 && check_line_end(buff) == 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buff), NULL);
		buff[bytes_read] = '\0';
		if (bytes_read != 0)
			backup[fd] = gnl_strjoin(backup[fd], buff);
	}
	if (!backup[fd])
		return (free(buff), NULL);
	return (find_line_check_end(&backup[fd], &end, &buff));
}
