/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 14:05:51 by srabah            #+#    #+#             */
/*   Updated: 2015/01/27 14:05:54 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		n;
	int		counter;
	char	*final;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL && s2)
		return (ft_strdup(s2));
	if (s2 == NULL && s1)
		return (ft_strdup(s1));
	counter = 0;
	len = ft_strlen (s1);
	n = len + ft_strlen(s2) + 1;
	if ((final = ft_strnew (n)) == NULL)
		return (NULL);
	while (counter < n)
	{
		if (counter < len)
			final[counter] = s1[counter];
		else
			final[counter] = s2[counter - len];
		counter++;
	}
	return (final);
}
