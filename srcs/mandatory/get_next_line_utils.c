/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:47:17 by dguet             #+#    #+#             */
/*   Updated: 2022/05/03 22:14:38 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*gnl_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(sizeof(char) * (gnl_strlen(s) + 1));
	if (!dup)
		return (NULL);
	while (s[i])
	{	
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*sub;

	if (!s)
		return (NULL);
	i = gnl_strlen(s) - start;
	if (len > (unsigned int)i)
		len = i;
	sub = malloc (sizeof (char) * len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{	
		sub[i] = s[i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}

size_t	gnl_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	unsigned int	ret_len;
	unsigned int	i;
	unsigned int	j;
	char			*ret;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	ret_len = gnl_strlen(s1) + gnl_strlen(s2);
	ret = malloc (sizeof (char) * (ret_len + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	j = 0;
	while (s2[j])
		ret[i++] = s2[j++];
	ret[i] = '\0';
	free(s1);
	return (ret);
}

char	*gnl_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
