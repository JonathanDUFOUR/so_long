/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlluint_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 00:18:03 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/23 00:18:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "typedefs/t_int.h"

int	ft_putlluint_fd(t_lluint n, int fd)
{
	char	d;

	if (write(fd, "", 0) == -1)
		return (-1);
	d = n % 10 + '0';
	if (n > 9)
		return (ft_putlluint_fd(n / 10, fd) + (int)write(fd, &d, 1));
	return ((int)write(1, &d, 1));
}
