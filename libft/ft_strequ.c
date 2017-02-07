/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 19:01:53 by aratinau          #+#    #+#             */
/*   Updated: 2014/11/24 04:09:54 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (ft_strlen(s1) == 0 || ft_strlen(s2) == 0)
		return (1);
	if (ft_strcmp(s1, s2) == 0)
		return (1);
	return (0);
}
