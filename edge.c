/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 17:46:11 by aratinau          #+#    #+#             */
/*   Updated: 2015/09/29 17:49:29 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	process_edge_first(t_list **edge_lst, t_env **e)
{
	int			i;
	int			a;
	t_edge		*buf_edge;
	t_list		*lst_edge;

	i = 0;
	a = 1;
	while (i < ((*e)->nb_c * (*e)->nb_l))
	{
		if (a % (*e)->nb_c != 0)
		{
			buf_edge = (t_edge*)malloc(sizeof(t_edge));
			buf_edge->a = i;
			buf_edge->b = a;
			lst_edge = ft_lstnew(buf_edge, sizeof(t_edge));
			ft_lstadd(edge_lst, lst_edge);
			free(buf_edge);
		}
		a++;
		i++;
	}
}

void	process_edge_last(t_list **edge_lst, t_env **e)
{
	int			w;
	int			b;
	t_list		*lst_edge;
	t_edge		*buf_edge;

	w = (*e)->nb_c;
	b = 0;
	while (w < ((*e)->nb_c * (*e)->nb_l))
	{
		buf_edge = (t_edge*)malloc(sizeof(t_edge));
		buf_edge->a = b;
		buf_edge->b = w;
		lst_edge = ft_lstnew(buf_edge, sizeof(t_edge));
		ft_lstadd(edge_lst, lst_edge);
		b++;
		w++;
		free(buf_edge);
	}
}
