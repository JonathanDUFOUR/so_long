/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:37:26 by jonathan          #+#    #+#             */
/*   Updated: 2021/08/18 02:37:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "type/t_int.h"

int	ft_putlint_fd(t_lint n, int fd)
{
	t_luint	abs;
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
		return (ft_putlint_fd(abs / 10, fd) + (int)write(fd, &d, 1) + (n < 0));
	return ((int)write(fd, &d, 1) + (n < 0));
}
