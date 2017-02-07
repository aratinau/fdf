/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 17:28:10 by aratinau          #+#    #+#             */
/*   Updated: 2015/09/29 17:28:46 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_xyz	init_xyz(t_env *e)
{
	t_xyz		tmp_point;

	tmp_point.x = 0;
	tmp_point.y = 100;
	tmp_point.z = e->zoom;
	return (tmp_point);
}

void	process_xyz(t_xyz *tmp_point, t_env *e, int *ct_ligne_dur)
{
	if (*ct_ligne_dur < e->nb_c)
		tmp_point->x = tmp_point->x + e->zoom;
	else
	{
		tmp_point->x = e->zoom;
		*ct_ligne_dur = 0;
		tmp_point->z = tmp_point->z + e->zoom;
	}
}

void	buffering_node(t_node *buf_node, t_xyz tmp_point, int c)
{
	buf_node->x = tmp_point.x;
	buf_node->y = tmp_point.y;
	buf_node->z = tmp_point.z;
	buf_node->numero_node = c;
}

void	process_node(t_list **node_lst, t_file **file, t_env **e)
{
	t_node		*buf_node;
	t_list		*lst_node;
	int			c;
	int			ct_ligne_dur;
	t_xyz		tmp_point;

	c = 0;
	ct_ligne_dur = 0;
	tmp_point = init_xyz(*e);
	while (*file != NULL)
	{
		process_xyz(&tmp_point, *e, &ct_ligne_dur);
		if ((*file)->a != 0)
			tmp_point.y = -1 * ((*file)->a * 10);
		else
			tmp_point.y = 0;
		buf_node = (t_node*)malloc(sizeof(t_node));
		buffering_node(buf_node, tmp_point, c);
		lst_node = ft_lstnew(buf_node, sizeof(t_node));
		ft_lstadd(*(&node_lst), lst_node);
		c++;
		ct_ligne_dur++;
		*file = (*file)->next;
		free(buf_node);
	}
}
