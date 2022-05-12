/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:10:40 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/02 17:07:27 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "internal.h"
#include "buffer.h"
#include "e_ret.h"

void	padding_fd(int const c, int padlen, int const fd)
{
	char const	buff[BUFF_SIZE] = {c};

	while (padlen >= BUFF_SIZE)
	{
		write(fd, buff, BUFF_SIZE);
		padlen -= BUFF_SIZE;
	}
	write(fd, buff, padlen);
}
