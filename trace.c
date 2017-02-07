/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 18:36:31 by aratinau          #+#    #+#             */
/*   Updated: 2015/09/29 19:31:30 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_equal_x(t_two_dim *two_dim, double *x, double *y, t_env *e)
{
	if (two_dim->y1 >= two_dim->y2)
	{
		*y = two_dim->y2;
		while (*y <= two_dim->y1)
		{
			mlx_pixel_put(e->mlx, e->win, *x, *y, COLOR);
			*y = *y + e->qualite;
		}
	}
	else if (two_dim->y1 <= two_dim->y2)
	{
		*y = two_dim->y1;
		while (*y <= two_dim->y2)
		{
			mlx_pixel_put(e->mlx, e->win, *x, *y, COLOR);
			*y = *y + e->qualite;
		}
	}
}

void	draw_coord(t_two_dim *t_d, t_env *e)
{
	double x;
	double y;

	x = t_d->x1;
	if (t_d->x1 == t_d->x2)
		x_equal_x(t_d, &x, &y, e);
	else if (x <= t_d->x2)
	{
		while (x <= t_d->x2)
		{
			mlx_pixel_put(e->mlx, e->win, x,
t_d->y1 + (((t_d->y2 - t_d->y1) * (x - t_d->x1)) / (t_d->x2 - t_d->x1)), COLOR);
			x = x + e->qualite;
		}
	}
	else if (x >= t_d->x2)
	{
		while (x >= t_d->x2)
		{
			mlx_pixel_put(e->mlx, e->win, x,
t_d->y1 + (((t_d->y2 - t_d->y1) * (x - t_d->x1)) / (t_d->x2 - t_d->x1)), COLOR);
			x = x - e->qualite;
		}
	}
}

void	procress_nodes_edges(t_node *c_node, t_edge *c_edge, t_two_dim *two_dim)
{
	if (c_node->numero_node == c_edge->a)
	{
		two_dim->x1 = c_node->x;
		two_dim->y1 = c_node->y;
	}
	if (c_node->numero_node == c_edge->b)
	{
		two_dim->x2 = c_node->x;
		two_dim->y2 = c_node->y;
	}
}

void	process_two_dim(t_two_dim *two_dim, t_env *e)
{
	two_dim->x1 = two_dim->x1 + e->pos_x;
	two_dim->y1 = two_dim->y1 + e->pos_y;
	two_dim->x2 = two_dim->x2 + e->pos_x;
	two_dim->y2 = two_dim->y2 + e->pos_y;
}

void	trace(t_list **nodes, t_list **edges, t_env *e)
{
	t_list		*lst_nodes;
	t_list		*lst_edges;
	t_node		*current_node;
	t_edge		*current_edge;
	t_two_dim	two_dim;

	current_edge = NULL;
	current_node = NULL;
	lst_nodes = *nodes;
	lst_edges = *edges;
	while (lst_edges != NULL)
	{
		lst_nodes = *nodes;
		current_edge = (t_edge*)lst_edges->content;
		while (lst_nodes != NULL)
		{
			current_node = (t_node*)lst_nodes->content;
			procress_nodes_edges(current_node, current_edge, &two_dim);
			lst_nodes = lst_nodes->next;
		}
		lst_edges = lst_edges->next;
		process_two_dim(&two_dim, e);
		draw_coord(&two_dim, e);
	}
}
