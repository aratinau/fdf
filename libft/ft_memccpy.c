/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 01:12:28 by aratinau          #+#    #+#             */
/*   Updated: 2015/01/10 02:04:49 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*cpy_src;
	unsigned char	*cpy_dst;

	i = 0;
	cpy_src = (unsigned char*)src;
	cpy_dst = (unsigned char*)dst;
	while (i < n)
	{
		cpy_dst[i] = cpy_src[i];
		if (cpy_src[i] == (unsigned char)c)
			return (void*)(cpy_dst + i + 1);
		i++;
	}
	return (NULL);
}
