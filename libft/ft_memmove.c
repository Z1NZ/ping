/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:55:59 by srabah            #+#    #+#             */
/*   Updated: 2015/01/27 13:56:07 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char		*p_s1;
	const unsigned char	*p_s2 = s2;

	if (!n)
		return (s1);
	p_s1 = s1;
	if (p_s2 < p_s1)
	{
		p_s1 += n;
		p_s2 += n;
		while (n--)
			*--p_s1 = *--p_s2;
	}
	else
	{
		while (n--)
			*p_s1++ = *p_s2++;
	}
	return (s1);
}
