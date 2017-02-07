/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 19:25:09 by aratinau          #+#    #+#             */
/*   Updated: 2015/01/10 00:41:08 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	int				j;
	unsigned char	*s3;
	unsigned char	*s4;

	s3 = (unsigned char*)s1;
	s4 = (unsigned char*)s2;
	j = 0;
	i = 0;
	while (s3[i] != '\0' || s4[i] != '\0')
	{
		if (s3[i] != s4[i])
		{
			j = s3[i] - s4[i];
			return (j);
		}
		i++;
	}
	if (s3[i] == s4[i] && s4[i] == '\0')
		return (0);
	return (j);
}
