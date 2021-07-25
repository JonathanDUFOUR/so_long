/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putllint_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 00:11:35 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/23 00:12:28 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "typedefs/t_int.h"

int	ft_putllint_fd(t_llint n, int fd)
{
	t_lluint	abs;
	char		d;

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
		return (ft_putllint_fd(abs / 10, fd) + (int)write(fd, &d, 1) + (n < 0));
	return ((int)write(fd, &d, 1) + (n < 0));
}
