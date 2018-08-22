/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:58:15 by srabah            #+#    #+#             */
/*   Updated: 2015/01/27 13:58:21 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "libft.h"

void		ft_putstr_fd(char const *s, int fd)
{
	size_t	len_s;

	len_s = ft_strlen(s);
	write(fd, s, len_s);
}
