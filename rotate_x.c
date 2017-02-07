/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 18:36:16 by aratinau          #+#    #+#             */
/*   Updated: 2015/09/29 17:53:26 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_list **nodes, float theta)
{
	float		y;
	float		z;
	t_list		*lst;
	t_node		*current_node;

	lst = *nodes;
	while (lst != NULL)
	{
		current_node = (t_node*)lst->content;
		y = current_node->y;
		z = current_node->z;
		current_node->y = y * cos(theta / 6) - z * sin(theta / 6);
		current_node->z = z * cos(theta / 6) + y * sin(theta / 6);
		lst = lst->next;
	}
}
