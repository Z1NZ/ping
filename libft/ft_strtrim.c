/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:59:51 by srabah            #+#    #+#             */
/*   Updated: 2015/01/27 13:59:55 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int		ft_isspace_only(int c)
{
	if (c == ' ' ||\
		c == '\t' ||\
		c == '\n')
		return (1);
	else
		return (0);
}

static int		ft_strisspace(char *s)
{
	size_t	len;

	len = ft_strlen(s);
	while (ft_isspace_only(*s))
	{
		s++;
		len--;
	}
	if (!len)
		return (1);
	else
		return (0);
}

char			*ft_strtrim(char const *s)
{
	char const		*begin_s = s;
	unsigned int	start;
	unsigned int	end;

	start = 0;
	end = 0;
	if (!s)
		return (NULL);
	if (ft_strisspace((char*)s))
		return (ft_strdup(""));
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
	{
		start++;
		s++;
	}
	while (*s)
		s++;
	s--;
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
	{
		end++;
		s--;
	}
	return (ft_strsub(begin_s, (unsigned int)start,
	ft_strlen(begin_s) - start - end));
}
