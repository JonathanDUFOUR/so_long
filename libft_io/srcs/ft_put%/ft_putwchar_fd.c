/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 19:04:21 by jdufour           #+#    #+#             */
/*   Updated: 2021/12/17 20:11:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdint.h>
#include <unistd.h>

/*
	Print the given wild character `wc` on the given file descriptor `fd`
	Return the number of printed bytes
	Return -1 upon failure
*/
int	ft_putwchar_fd(wchar_t const wc, int const fd)
{
	char	buff[4];
	int		size;

	*(uint32_t *)buff = 0;
	buff[3] = wc & 0b01111111;
	size = 1;
	if (wc >= 0x80)
	{
		++size;
		buff[3] = 0b10000000 | (wc & 0b00111111);
		buff[2] = 0b11000000 | ((wc >> 6) & 0b00011111);
		if (wc >= 0x800)
		{
			++size;
			buff[2] = 0b10000000 | ((wc >> 6) & 0b00111111);
			buff[1] = 0b11100000 | ((wc >> 12) & 0b00111111);
			if (wc >= 0x10000)
			{
				++size;
				buff[1] = 0b10000000 | ((wc >> 12) & 0b00111111);
				buff[0] = 0b11110000 | ((wc >> 18) & 0b01111111);
			}
		}
	}
	return ((int)write(fd, buff + (4 - size), size));
}
