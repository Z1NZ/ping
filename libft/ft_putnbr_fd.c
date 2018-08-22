/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:57:36 by srabah            #+#    #+#             */
/*   Updated: 2015/01/30 18:07:19 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	u_nbr;

	u_nbr = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		u_nbr = -n;
	}
	if (u_nbr / 10)
		ft_putnbr_fd(u_nbr / 10, fd);
	ft_putchar_fd(u_nbr % 10 + '0', fd);
}
