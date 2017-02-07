/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 03:48:19 by aratinau          #+#    #+#             */
/*   Updated: 2014/12/17 14:13:52 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*rslt;
	size_t	i;
	char	*a;
	char	*b;

	i = 0;
	if (!dst || !src || len <= 0)
		return ((void*)NULL);
	a = (char *)src;
	b = (char *)dst;
	rslt = (char *)malloc(sizeof(char) * (len + 1));
	if (!rslt)
		return ((void*)NULL);
	while (len > i)
	{
		rslt[i] = a[i];
		i++;
	}
	i = 0;
	while (len > i)
	{
		b[i] = rslt[i];
		i++;
	}
	return (dst);
}
