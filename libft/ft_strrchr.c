/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 14:01:04 by srabah            #+#    #+#             */
/*   Updated: 2015/01/27 14:03:39 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*found_at;

	found_at = 0;
	while (*s)
	{
		if (*s == (char)c)
			found_at = (char*)s;
		s++;
	}
	found_at = (*s == (char)c) ? (char*)s : found_at;
	return (found_at);
}
