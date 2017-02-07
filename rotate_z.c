/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 18:36:26 by aratinau          #+#    #+#             */
/*   Updated: 2015/09/29 17:55:50 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_z(t_list **nodes, float theta)
{
	float		x;
	float		y;
	t_list		*lst;
	t_node		*current_node;

	lst = *nodes;
	while (lst != NULL)
	{
		current_node = (t_node*)lst->content;
		x = current_node->x;
		y = current_node->y;
		current_node->x = x * cos(theta / 6) - y * sin(theta / 6);
		current_node->y = y * cos(theta / 6) + x * sin(theta / 6);
		lst = lst->next;
	}
}
