/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:55:15 by srabah            #+#    #+#             */
/*   Updated: 2015/01/27 13:55:19 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*p_s = s;

	while (n--)
	{
		if (*p_s == (unsigned char)c)
			return ((void*)p_s);
		p_s++;
	}
	return (NULL);
}
