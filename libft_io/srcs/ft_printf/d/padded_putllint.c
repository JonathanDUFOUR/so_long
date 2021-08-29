/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padded_putllint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 00:45:59 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/18 02:37:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_ptf.h"
#include "enum/e_ret.h"

static t_uint	field_width_padlen(t_llint n, t_ctx *ctx)
{
	return (ctx->fwidth
		- ctx->prec
		- !!((n < 0) || (ctx->flags & (1 << 2)) || (ctx->flags & (1 << 3))));
}

int	padded_putllint(t_llint n, t_uint len, t_ctx *ctx)
{
	t_uint	padlen;

	padlen = field_width_padlen(n, ctx);
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1))
		&& padding(' ', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	if (n < 0)
		write(1, "-", 1);
	else if (ctx->flags & (1 << 2))
		write(1, "+", 1);
	else if (ctx->flags & (1 << 3))
		write(1, " ", 1);
	if (ctx->flags & (1 << 1) && padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	padlen = ctx->prec - (len - (n < 0));
	if (padlen && padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	ft_putlluint_fd((n < 0) * (-n) + (n >= 0) * n, 1);
	if (ctx->flags & (1 << 0))
	{
		padlen = field_width_padlen(n, ctx);
		if (padding(' ', padlen) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
	}
	return (SUCCESS);
}
