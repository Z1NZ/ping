/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:55:07 by srabah            #+#    #+#             */
/*   Updated: 2015/01/27 13:55:11 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char			*p_s1;
	const char		*p_s2 = s2;

	if (!s1 || !s2)
		return (NULL);
	p_s1 = s1;
	while (n--)
	{
		*p_s1++ = *p_s2;
		if (*p_s2 == c)
			return (p_s1);
		p_s2++;
	}
	return (0);
}
