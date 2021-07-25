/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padded_putnwstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:03:18 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/23 01:22:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_ptf.h"
#include "enums/e_ret.h"

int	padded_putnwstr(wchar_t *s, t_ctx *ctx, t_uint len, t_uint size)
{
	len = ctx->prec;
	if (!(ctx->flags & (1 << 0))
		&& padding(' ', ctx->fwidth - size) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	while (len--)
		if (ft_putchar_fd(*s++, 1) == -1)
			return (WRITE_ERRNO);
	if (ctx->flags & (1 << 0)
		&& padding(' ', ctx->fwidth - size) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	return (SUCCESS);
}
