/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padded_putwchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 01:42:26 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/18 02:37:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_ptf.h"
#include "enum/e_ret.h"

int	padded_putwchar(wchar_t c, uint16_t flags, t_uint padlen)
{
	if (!(flags & (1 << 0)) && padding(' ', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	ft_putchar_fd(c, 1);
	if (flags & (1 << 0) && padding(' ', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	return (SUCCESS);
}
