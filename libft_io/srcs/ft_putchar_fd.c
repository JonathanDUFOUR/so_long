/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 19:04:21 by jdufour           #+#    #+#             */
/*   Updated: 2021/07/21 23:44:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdint.h>
#include <unistd.h>

int	ft_putchar_fd(wchar_t c, int fd)
{
	char	buff[4];
	int		size;

	*(uint32_t *)buff = 0;
	buff[3] = c & 0b01111111;
	size = 1;
	if (c >= 0x80)
	{
		++size;
		buff[3] = 0b10000000 | (c & 0b00111111);
		buff[2] = 0b11000000 | ((c >> 6) & 0b00011111);
		if (c >= 0x800)
		{
			++size;
			buff[2] = 0b10000000 | ((c >> 6) & 0b00111111);
			buff[1] = 0b11100000 | ((c >> 12) & 0b00111111);
			if (c >= 0x10000)
			{
				++size;
				buff[1] = 0b10000000 | ((c >> 12) & 0b00111111);
				buff[0] = 0b11110000 | ((c >> 18) & 0b01111111);
			}
		}
	}
	return (write(fd, buff + (4 - size), size));
}
