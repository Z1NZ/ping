/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:54:10 by srabah            #+#    #+#             */
/*   Updated: 2015/01/27 13:54:15 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*p_lst;

	p_lst = lst;
	while (p_lst)
	{
		f(p_lst);
		p_lst = p_lst->next;
	}
}
