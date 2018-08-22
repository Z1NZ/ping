/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:54:19 by srabah            #+#    #+#             */
/*   Updated: 2015/01/27 13:54:24 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_item;
	t_list	*origin_list;
	t_list	*previous;

	if (!lst || !f)
		return (NULL);
	new_item = (*f)(lst);
	previous = new_item;
	origin_list = new_item;
	lst = lst->next;
	while (lst)
	{
		new_item = f(lst);
		if (new_item == NULL)
			return (NULL);
		previous->next = new_item;
		previous = new_item;
		lst = lst->next;
	}
	new_item->next = NULL;
	return (origin_list);
}
