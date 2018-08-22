/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:54:52 by srabah            #+#    #+#             */
/*   Updated: 2015/01/27 13:55:02 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new_space;

	if (!size)
		return (NULL);
	new_space = (void*)malloc(size * sizeof(void*));
	if (!new_space)
		return (NULL);
	ft_bzero(new_space, size);
	return (new_space);
}
