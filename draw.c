/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 18:36:08 by aratinau          #+#    #+#             */
/*   Updated: 2015/09/29 17:46:34 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_file *file, t_env *e)
{
	t_list		*node_lst;
	t_list		*edge_lst;

	node_lst = NULL;
	edge_lst = NULL;
	process_node(&node_lst, &file, &e);
	process_edge_first(&edge_lst, &e);
	process_edge_last(&edge_lst, &e);
	rotate_y(&node_lst, e->theta_y);
	rotate_x(&node_lst, e->theta_x);
	rotate_z(&node_lst, e->theta_z);
	trace(&node_lst, &edge_lst, e);
}
