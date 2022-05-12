/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbytes_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:12:50 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/24 15:25:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"

/*
	Print the first `size` bytes pointed by the given pointer `addr` in binary
	on the given file descriptor `fd`
	Return the number of printed bytes
	Return -1 upon failure
*/
int	ft_putbytes_fd(void const *addr, size_t const size, int const fd)
{
	int		ret;
	size_t	i;

	if (write(fd, "", 0) == -1)
		return (-1);
	ret = 0;
	i = 0;
	while (i < size)
	{
		ret += ft_putbyte_fd(*(uint8_t *)(addr + i), fd);
		if (++i < size)
			ret += (int)write(fd, " ", 1);
	}
	return (ret);
}
