/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 15:57:02 by aratinau          #+#    #+#             */
/*   Updated: 2014/12/17 14:10:38 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	char	*trim;
	int		start;

	if (!s)
		return (NULL);
	start = 0;
	while (ft_isblank(*s))
		s++;
	start--;
	len = ft_strlen(s);
	while (*s && ft_isblank(*(s + len - 1)))
		len--;
	trim = ft_strsub(s, 0, len);
	if (!s || !trim)
		return (NULL);
	return ((char*)trim);
}
