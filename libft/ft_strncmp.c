/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 19:48:25 by aratinau          #+#    #+#             */
/*   Updated: 2014/11/25 14:23:26 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*s3;
	unsigned char	*s4;

	s3 = (unsigned char*)s1;
	s4 = (unsigned char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s3[i] == s4[i] && s3[i] != '\0' && n > 1)
	{
		i++;
		n--;
	}
	return (s3[i] - s4[i]);
}
