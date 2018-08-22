/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:51:15 by srabah            #+#    #+#             */
/*   Updated: 2015/01/27 13:51:18 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_atoi(const char *str)
{
	int		number;
	char	scalar;

	number = 0;
	scalar = 1;
	while (*str != '\0' && ft_isspace((unsigned char)*str))
		str++;
	if (*str != '\0' && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			scalar = -1;
		str++;
	}
	while (*str != '\0' && ft_isdigit((unsigned char)*str))
	{
		number *= 10;
		number += *str - '0';
		str++;
	}
	return (scalar * number);
}
