/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:19:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/23 01:51:29 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_ptf.h"
#include "enums/e_ret.h"

static t_llint	get_right_type(t_ctx *ctx, va_list va)
{
	if (ctx->flags & (1 << 5))
		return ((t_llint)va_arg(va, t_lint));
	else if (ctx->flags & (1 << 6))
		return ((t_llint)va_arg(va, t_llint));
	else if (ctx->flags & (1 << 7))
		return ((t_llint)((t_hint)va_arg(va, int)));
	else if (ctx->flags & (1 << 8))
		return ((t_llint)((t_hhint)va_arg(va, int)));
	else
		return ((t_llint)va_arg(va, int));
}

int	get_arg_d(t_ctx *ctx, va_list va)
{
	t_llint	n;
	t_uint	len;

	n = get_right_type(ctx, va);
	if (!ctx->prec && !n)
	{
		if (ctx->flags & (1 << 2) || ctx->flags & (1 << 3))
			flag_exception(ctx);
		if (padding(' ', ctx->fwidth) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
		ctx->len += ctx->fwidth;
		return (SUCCESS);
	}
	len = dlen(n);
	if (ctx->prec < (len - (n < 0)))
		ctx->prec = len - (n < 0);
	if (ctx->fwidth < (ctx->prec + !!((n < 0) || (ctx->flags & (1 << 2))
				|| (ctx->flags & (1 << 3)))))
		ctx->fwidth = ctx->prec + !!((n < 0) || (ctx->flags & (1 << 2))
				|| (ctx->flags & (1 << 3)));
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > len)
		return (padded_putllint(n, len, ctx));
	ft_putllint_fd(n, 1);
	return (SUCCESS);
}
