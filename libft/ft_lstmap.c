/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 21:23:35 by aratinau          #+#    #+#             */
/*   Updated: 2015/02/16 21:24:36 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst2;
	t_list	*tmp;

	lst2 = f(lst);
	tmp = lst2;
	lst = lst->next;
	while (lst != NULL)
	{
		tmp->next = f(lst);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (lst2);
}
