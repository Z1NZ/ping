/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 14:00:01 by srabah            #+#    #+#             */
/*   Updated: 2015/01/27 14:00:04 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*new_str;
	char		*begin_new_str;

	if (!s)
		return (NULL);
	new_str = ft_strnew(len);
	begin_new_str = new_str;
	while (start--)
		s++;
	while (*s && len--)
		*new_str++ = *s++;
	return (begin_new_str);
}
