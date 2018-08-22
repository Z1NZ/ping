/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 14:00:16 by srabah            #+#    #+#             */
/*   Updated: 2015/01/27 14:00:26 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static size_t	count_tok(char const *s, char c)
{
	char const	*p_s = s;
	size_t		counter;

	counter = 0;
	while (*p_s)
	{
		if (*p_s == c)
			p_s++;
		else
		{
			counter++;
			while (*p_s && *p_s != c)
				p_s++;
		}
	}
	return (counter);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**big_array;
	size_t		i;
	size_t		nb_tok;
	char const	*tok;
	char const	*tok_next;

	big_array = NULL;
	if ((tok = s))
	{
		nb_tok = count_tok(s, c);
		if ((big_array = (char**)malloc((nb_tok + 1) * sizeof(char*))))
		{
			i = 0;
			big_array[nb_tok] = NULL;
			while ((tok_next = ft_strchr(tok, c)))
			{
				if (tok_next - tok > 0)
					big_array[i++] = ft_strsub(s, tok - s, tok_next - tok);
				tok = tok_next + 1;
			}
			if ((tok_next = ft_strchr(tok, '\0')) - tok > 0)
				big_array[i++] = ft_strsub(s, tok - s, tok_next - tok);
		}
	}
	return (big_array);
}
