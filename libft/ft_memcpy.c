/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 21:30:54 by aratinau          #+#    #+#             */
/*   Updated: 2015/05/21 08:17:52 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dp;
	const char	*sp;

	sp = src;
	dp = dst;
	i = 0;
	while (i < n)
	{
		*dp++ = *sp++;
		i++;
	}
	return (dst);
}
