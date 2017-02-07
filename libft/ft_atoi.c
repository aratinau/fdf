/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:13:55 by aratinau          #+#    #+#             */
/*   Updated: 2015/01/04 19:08:09 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int result;
	int sign;

	result = 0;
	while (*str == ' ' || *str == '\n' || \
			*str == '\v' || *str == '\t' || *str == '\r' || *str == '\f')
	{
		str++;
	}
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
