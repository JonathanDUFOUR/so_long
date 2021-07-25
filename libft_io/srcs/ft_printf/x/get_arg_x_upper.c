/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_x_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:39:27 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/18 05:17:52 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ptf.h"
#include "enums/e_ret.h"

static t_lluint	get_right_type(t_ctx *ctx, va_list va)
{
	if (ctx->flags & (1 << 5))
		return ((t_lluint)va_arg(va, t_luint));
	else if (ctx->flags & (1 << 6))
		return ((t_lluint)va_arg(va, t_lluint));
	else if (ctx->flags & (1 << 7))
		return ((t_lluint)((t_huint)va_arg(va, t_uint)));
	else if (ctx->flags & (1 << 8))
		return ((t_lluint)((t_hhuint)va_arg(va, t_uint)));
	else
		return ((t_lluint)va_arg(va, t_uint));
}

int	get_arg_x_upper(t_ctx *ctx, va_list va)
{
	t_lluint	n;
	uint32_t	len;

	n = get_right_type(ctx, va);
	if (!ctx->prec && !n)
	{
		if (padding(' ', ctx->fwidth) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
		ctx->len += ctx->fwidth;
		return (SUCCESS);
	}
	if (!n)
		ctx->flags &= ~(1 << 4);
	len = xlen(n);
	if (ctx->prec < len)
		ctx->prec = len;
	if (ctx->fwidth < (ctx->prec + 2 * !!(ctx->flags & (1 << 4))))
		ctx->fwidth = ctx->prec + 2 * !!(ctx->flags & (1 << 4));
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > len)
		return (padded_putlluint_hexa(n, len, ctx, UPPER));
	putlluint_hexa(n, 'A');
	return (SUCCESS);
}
