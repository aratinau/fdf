/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:36:09 by aratinau          #+#    #+#             */
/*   Updated: 2014/11/24 20:50:04 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		j;
	int		t;
	char	*rslt;

	i = 0;
	t = ft_strlen(s1) + ft_strlen(s2);
	j = ft_strlen(s1);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	rslt = s1;
	while (i + j <= t)
	{
		rslt[i + j] = s2[i];
		i++;
	}
	rslt[i + j] = '\0';
	return (rslt);
}
