/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 02:19:11 by jdufour           #+#    #+#             */
/*   Updated: 2021/07/20 23:26:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "typedefs/t_int.h"

int	ft_putint_fd(int n, int fd)
{
	t_uint	abs;
	char	d;

	if (write(fd, "", 0) == -1)
		return (-1);
	abs = n;
	if (n < 0)
	{
		abs = -n;
		write(fd, "-", 1);
	}
	d = abs % 10 + '0';
	if (abs > 9)
		return (ft_putint_fd(abs / 10, fd) + (int)write(fd, &d, 1) + (n < 0));
	return ((int)write(fd, &d, 1) + (n < 0));
}
