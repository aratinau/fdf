/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:51:40 by aratinau          #+#    #+#             */
/*   Updated: 2015/03/16 18:00:27 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		n;
	char		*dest;

	n = ft_strlen((char *)s1);
	dest = (char *)malloc(sizeof(*s1) * n + 1);
	if (dest == NULL)
		return (NULL);
	dest[n] = '\0';
	while (n-- > 0)
		dest[n] = s1[n];
	return (dest);
}
