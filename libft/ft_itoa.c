/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 19:29:49 by aratinau          #+#    #+#             */
/*   Updated: 2014/12/17 14:21:10 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_length(int n)
{
	int				i;
	unsigned int	nb;

	i = 0;
	if (n < 0)
	{
		i++;
		nb = -n;
	}
	else
	{
		nb = n;
	}
	while (nb >= 10)
	{
		nb /= 10;
		i++;
	}
	return (i + 1);
}

static void		createstr(char *str, int len, unsigned int nb, int neg)
{
	while (len >= 0)
	{
		str[len] = '0' + (nb % 10);
		nb = nb / 10;
		if (neg && len == 1)
			break ;
		len--;
	}
}

char			*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;
	int				len;
	int				neg;

	neg = 0;
	len = ft_length(n);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	len--;
	if (n < 0)
	{
		nb = -n;
		neg = 1;
	}
	else
		nb = n;
	createstr(str, len, nb, neg);
	if (neg)
		str[0] = '-';
	return (str);
}
