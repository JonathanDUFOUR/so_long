/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvrt_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:35:14 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/02 16:06:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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

inline static void	__padded_putlluint_oct_fd(
	t_lluint const nb,
	int const len,
	t_ctx *const ctx)
{
	int	padlen;

	padlen = ctx->fwidth - ctx->prec - !!(ctx->flags & (1 << 4));
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1)))
		padding_fd(' ', padlen, ctx->fd);
	if (ctx->flags & (1 << 4))
		write(1, "0", 1);
	if (ctx->flags & (1 << 1))
		padding_fd('0', padlen, ctx->fd);
	padlen = ctx->prec - len;
	if (padlen)
		padding_fd('0', padlen, ctx->fd);
	ft_putlluint_base_fd(nb, "01234567", ctx->fd);
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->fwidth - ctx->prec - !!(ctx->flags & (1 << 4));
		padding_fd(' ', padlen, ctx->fd);
	}
}

void	cvrt_o(t_ctx *const ctx, va_list va)
{
	t_lluint const	nb = __get_right_type(ctx, va);
	int				len;

	if (!ctx->prec && !nb)
	{
		padding_fd(' ', ctx->fwidth, ctx->fd);
		ctx->len += ctx->fwidth;
		return ;
	}
	if (!nb)
		ctx->flags &= ~(1 << 4);
	len = (int)ft_lluintlen_base(nb, 8);
	if (ctx->prec < len)
		ctx->prec = len;
	if (ctx->fwidth < (ctx->prec + !!(ctx->flags & (1 << 4))))
		ctx->fwidth = ctx->prec + !!(ctx->flags & (1 << 4));
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > len)
		__padded_putlluint_oct_fd(nb, len, ctx);
	else
		ft_putlluint_base_fd(nb, "01234567", ctx->fd);
}
