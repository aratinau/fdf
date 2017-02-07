/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 14:15:34 by aratinau          #+#    #+#             */
/*   Updated: 2015/05/04 18:20:26 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*ft_strnjoin(char const *s1, char const *s2, size_t s2len)
{
	int		i;
	size_t	j;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	len = (ft_strlen(s1) + s2len);
	if ((str = (char *)malloc(sizeof(char) * (len + 1))))
	{
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0' && j < s2len)
		{
			str[i] = s2[j];
			i++;
			j++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

int				process(char **line, char *str, size_t *cursor, ssize_t *size)
{
	*line = ft_strjoin(*line, str + *cursor);
	*cursor = *size;
	if (*line == NULL)
		return (-1);
	return (-2);
}

int				l_read(char **line, char *str, size_t *cursor, char *newlinepos)
{
	*line = ft_strnjoin(*line, str + *cursor, newlinepos - (str + *cursor));
	*cursor = (newlinepos + 1) - str;
	return (1);
}

void			init(ssize_t *size, int const fd, char *str, size_t *cursor)
{
	*size = read(fd, str, BUFF_SIZE);
	str[*size] = '\0';
	*cursor = 0;
}

int				get_next_line(int const fd, char **line)
{
	static char			str[BUFF_SIZE + 1];
	static size_t		cursor;
	static ssize_t		size;
	char				*newlinepos;

	if (line == NULL)
		return (-1);
	*line = ft_strnew(0);
	while (42)
	{
		if ((ssize_t)cursor >= size)
			init(&size, fd, str, &cursor);
		if (size <= 0)
			return (size);
		newlinepos = ft_strchr(str + cursor, '\n');
		if (newlinepos == NULL)
		{
			if (process(line, str, &cursor, &size) != -2)
				return (-1);
		}
		else
			return (l_read(line, str, &cursor, newlinepos));
	}
}
