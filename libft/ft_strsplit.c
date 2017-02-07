/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 21:21:59 by aratinau          #+#    #+#             */
/*   Updated: 2015/04/03 18:28:05 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words_by_char_c(char const *s, char c)
{
	int state;
	int nb_words;

	state = 0;
	nb_words = 0;
	while (*s != '\0')
	{
		if (state == 0 && *s != c)
		{
			state = 1;
			++nb_words;
		}
		if (state == 1 && *s == c)
		{
			state = 0;
		}
		++s;
	}
	return (nb_words);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**rslt;
	int		nb_word;
	int		start;
	int		end;
	int		word;

	start = 0;
	end = 0;
	word = 0;
	if (s == NULL)
		return (NULL);
	nb_word = ft_count_words_by_char_c(s, c) + 1;
	rslt = (char **)malloc(sizeof(char*) * (nb_word + 1));
	while (s[start] != '\0')
	{
		while (s[start] == c && s[start] != '\0')
			start++;
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		rslt[word++] = ft_strsub(s, start, end - start);
		start = end;
	}
	rslt[ft_count_words_by_char_c(s, c)] = 0;
	return (rslt);
}
