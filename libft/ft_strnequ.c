/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 06:57:44 by aratinau          #+#    #+#             */
/*   Updated: 2014/11/24 04:10:39 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (ft_strlen(s1) == 0 || ft_strlen(s2) == 0)
		return (1);
	if (ft_strncmp(s1, s2, n) == 0)
		return (1);
	return (0);
}
