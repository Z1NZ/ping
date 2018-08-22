/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 14:00:08 by srabah            #+#    #+#             */
/*   Updated: 2015/01/27 14:00:12 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	len;

	if (!*s2)
		return ((char*)s1);
	len = ft_strlen(s2);
	while (*s1)
	{
		if (!ft_memcmp(s1++, s2, len))
			return ((char*)s1 - 1);
	}
	return (0);
}
