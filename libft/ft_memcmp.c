/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:55:23 by srabah            #+#    #+#             */
/*   Updated: 2015/01/27 13:55:31 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*p_s1 = s1;
	const unsigned char		*p_s2 = s2;

	while (n--)
	{
		if (*p_s1 != *p_s2)
			return (*p_s1 - *p_s2);
		else
		{
			p_s1++;
			p_s2++;
		}
	}
	return (0);
}
