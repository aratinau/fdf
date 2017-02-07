/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 10:31:42 by aratinau          #+#    #+#             */
/*   Updated: 2014/12/17 14:19:40 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char		c;
	char		sc;
	size_t		len;
	int			go;

	go = 0;
	if ((c = *s2++) != '\0')
	{
		len = ft_strlen(s2);
		while (!go || ft_strncmp(s1, s2, len) != 0)
		{
			go = 1;
			if ((sc = *s1++) == '\0' || n-- < 1)
				return (NULL);
			while (sc != c)
			{
				if ((sc = *s1++) == '\0' || n-- < 1)
					return (NULL);
			}
			if (len > n)
				return (NULL);
		}
		s1--;
	}
	return ((char *)s1);
}
