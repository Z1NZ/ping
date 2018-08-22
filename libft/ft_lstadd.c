/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:53:12 by srabah            #+#    #+#             */
/*   Updated: 2015/01/27 13:53:21 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*new_next;

	new_next = *alst;
	*alst = new;
	new->next = new_next;
}
