/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbytes_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:12:50 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/20 22:39:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"

int	ft_putbytes_fd(void *addr, size_t size, int fd)
{
	int	ret;

	if (!addr || write(fd, "", 0) == -1)
		return (-1);
	ret = 0;
	while (size--)
	{
		ret += ft_putbyte_fd(*((uint8_t *)(addr + size)), fd);
		if (size)
			ret += write(1, " ", 1);
	}
	return (ret);
}
