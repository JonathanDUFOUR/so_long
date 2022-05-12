/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvrt_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:39:05 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/02 16:44:59 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "internal.h"
#include "e_ret.h"

inline static t_lluint	__get_right_type(t_ctx *const ctx, va_list va)
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

inline static void	__padded_putlluint_fd(
	t_lluint const nb,
	int const len,
	t_ctx *const ctx)
{
	int	padlen;

	padlen = ctx->fwidth - ctx->prec;
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1)))
		padding_fd(' ', padlen, ctx->fd);
	if (ctx->flags & (1 << 1))
		padding_fd('0', padlen, ctx->fd);
	padlen = ctx->prec - len;
	if (padlen)
		padding_fd('0', padlen, ctx->fd);
	ft_putlluint_fd(nb, ctx->fd);
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->fwidth - ctx->prec;
		padding_fd(' ', padlen, ctx->fd);
	}
}

void	cvrt_u(t_ctx *const ctx, va_list va)
{
	t_lluint const	nb = __get_right_type(ctx, va);
	int				len;

	if (!ctx->prec && !nb)
	{
		padding_fd(' ', ctx->fwidth, ctx->fd);
		ctx->len += ctx->fwidth;
		return ;
	}
	len = (int)ft_lluintlen(nb);
	if (ctx->prec < len)
		ctx->prec = len;
	if (ctx->fwidth < ctx->prec)
		ctx->fwidth = ctx->prec;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > len)
		__padded_putlluint_fd(nb, len, ctx);
	else
		ft_putlluint_fd(nb, ctx->fd);
}
