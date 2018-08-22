/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 14:02:17 by srabah            #+#    #+#             */
/*   Updated: 2015/01/27 14:02:24 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	int		i;
	size_t	len;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	new_str = ft_strnew(len);
	if (!new_str)
		return (NULL);
	while (s[i])
	{
		new_str[i] = f(s[i]);
		i++;
	}
	return (new_str);
}
