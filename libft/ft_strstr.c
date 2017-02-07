/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 10:56:06 by aratinau          #+#    #+#             */
/*   Updated: 2014/12/17 14:19:40 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (s1[i + j] == s2[j] && s1[i + j] != '\0' && s2[j] != '\0')
				j++;
			if (j == ft_strlen(s2))
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
