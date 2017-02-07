/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:43:09 by aratinau          #+#    #+#             */
/*   Updated: 2014/12/17 14:13:52 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	t;
	char	*rslt;

	i = 0;
	t = ft_strlen(s1) + ft_strlen(s2);
	j = ft_strlen(s1);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	rslt = s1;
	while (i + j <= t && i < n)
	{
		rslt[i + j] = s2[i];
		i++;
	}
	rslt[i + j] = '\0';
	return (rslt);
}
