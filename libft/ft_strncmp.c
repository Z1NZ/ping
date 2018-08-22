/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 14:01:51 by srabah            #+#    #+#             */
/*   Updated: 2015/01/27 14:01:55 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (n--)
	{
		if (*s1 != *s2)
			return (*(unsigned char*)(s1) - *(unsigned char*)(s2));
		if (!*s1 || !*s2)
			break ;
		s1++;
		s2++;
	}
	return (0);
}
