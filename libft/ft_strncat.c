/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 14:02:00 by srabah            #+#    #+#             */
/*   Updated: 2015/01/27 14:02:04 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*s1_begin;

	s1_begin = s1;
	while (*s1)
		s1++;
	while (n--)
	{
		if (!(*s1++ = *s2++))
			return (s1_begin);
	}
	*s1 = '\0';
	return (s1_begin);
}
