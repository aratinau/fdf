/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 18:36:21 by aratinau          #+#    #+#             */
/*   Updated: 2015/09/29 17:56:23 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_y(t_list **nodes, float theta)
{
	float		x;
	float		z;
	t_list		*lst;
	t_node		*current_node;

	lst = *nodes;
	while (lst != NULL)
	{
		current_node = (t_node*)lst->content;
		x = current_node->x;
		z = current_node->z;
		current_node->x = x * cos(theta / 6) - z * sin(theta / 6);
		current_node->z = z * cos(theta / 6) + x * sin(theta / 6);
		lst = lst->next;
	}
}
