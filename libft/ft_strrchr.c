/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 13:32:05 by aratinau          #+#    #+#             */
/*   Updated: 2014/12/17 14:13:52 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*s1;
	unsigned char	c2;
	int				i;

	c2 = c;
	s1 = (char *)s;
	i = ft_strlen(s1);
	while (i >= 0)
	{
		if (s1[i] == c2)
			return (s1 + (i));
		i--;
	}
	return (NULL);
}
