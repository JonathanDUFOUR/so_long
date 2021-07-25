/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:33:23 by jonathan          #+#    #+#             */
/*   Updated: 2021/07/20 23:28:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "typedefs/t_int.h"

int	ft_putuint_fd(t_uint n, int fd)
{
	char	d;

	d = n % 10 + '0';
	if (n > 9)
		return (ft_putuint_fd(n / 10, fd) + (int)write(fd, &d, 1));
	return ((int)write(fd, &d, 1));
}
