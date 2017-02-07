/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 19:44:43 by aratinau          #+#    #+#             */
/*   Updated: 2015/09/29 19:50:31 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_str(char *s, char *opt)
{
	ft_putstr("\033[");
	ft_putstr(opt);
	ft_putstr("m");
	while (*s != '\0')
		ft_putchar(*s++);
	ft_putstr("\033[0m");
}

int		next_space(char *s, int depart)
{
	size_t	i;

	i = depart;
	if (depart == 0)
		while (s[i] == ' ')
			i++;
	while (ft_strlen(s) > i)
	{
		if (s[i] == ' ' && s[i + 1] != ' ')
			return (i);
		else
			i++;
	}
	return (i);
}

int		traitement_retour_ligne(char *s, t_env *e, t_file **file)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (ft_strlen(s) > i)
	{
		file_append(file,
				ft_atoi(ft_strtrim(ft_strsub(s, i, next_space(s, i) - i))), j);
		j++;
		i = next_space(s, i);
		i++;
	}
	e->nb_c = j;
	return (j);
}

void	file_append(t_file **ref, int a, int line)
{
	t_file	*new_node;

	new_node = (t_file*)malloc(sizeof(t_file));
	new_node->a = a;
	new_node->line = line;
	new_node->next = (*ref);
	(*ref) = new_node;
}
