/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putluint_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:42:00 by jonathan          #+#    #+#             */
/*   Updated: 2021/07/20 23:27:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "typedefs/t_int.h"

int	ft_putluint_fd(t_luint n, int fd)
{
	char	d;

	if (write(fd, "", 0) == -1)
		return (-1);
	d = n % 10 + '0';
	if (n > 9)
		return (ft_putluint_fd(n / 10, fd) + (int)write(fd, &d, 1));
	return ((int)write(1, &d, 1));
}
