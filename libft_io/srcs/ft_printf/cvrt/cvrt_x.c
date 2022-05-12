/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_x_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:39:16 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/18 05:17:52 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"
#include "internal.h"
#include "e_ret.h"
#include "e_style.h"

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

inline static void	__do_right_put_fd(
	t_lluint const nb,
	int const style,
	int const fd)
{
	if (style == LOWER)
		ft_putlluint_base_fd(nb, "0123456789abcdef", fd);
	else if (style == UPPER)
		ft_putlluint_base_fd(nb, "0123456789ABCDEF", fd);
}

inline static void	__padded_putlluint_hexa_fd(
	t_lluint const nb,
	int const len,
	t_ctx *const ctx,
	int const style)
{
	int	padlen;

	padlen = ctx->fwidth - ctx->prec - !!(ctx->flags & (1 << 4)) * 2;
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1)))
		padding_fd(' ', padlen, ctx->fd);
	if (ctx->flags & (1 << 4) && style == LOWER)
		write(ctx->fd, "0x", 2);
	if (ctx->flags & (1 << 4) && style == UPPER)
		write(ctx->fd, "0X", 2);
	if (ctx->flags & (1 << 1))
		padding_fd('0', padlen, ctx->fd);
	padlen = ctx->prec - len;
	if (padlen)
		padding_fd('0', padlen, ctx->fd);
	__do_right_put_fd(nb, style, ctx->fd);
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->fwidth - ctx->prec - !!(ctx->flags & (1 << 4)) * 2;
		padding_fd(' ', padlen, ctx->fd);
	}
}

void	cvrt_x_lower(t_ctx *const ctx, va_list va)
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
	len = (int)ft_lluintlen_base(nb, 16);
	if (ctx->prec < len)
		ctx->prec = len;
	if (ctx->fwidth < (ctx->prec + !!(ctx->flags & (1 << 4)) * 2))
		ctx->fwidth = ctx->prec + !!(ctx->flags & (1 << 4)) * 2;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > len)
		return (__padded_putlluint_hexa_fd(nb, len, ctx, LOWER));
	ft_putlluint_base_fd(nb, "0123456789abcdef", ctx->fd);
}

void	cvrt_x_upper(t_ctx *const ctx, va_list va)
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
	len = (int)ft_lluintlen_base(nb, 16);
	if (ctx->prec < len)
		ctx->prec = len;
	if (ctx->fwidth < (ctx->prec + !!(ctx->flags & (1 << 4)) * 2))
		ctx->fwidth = ctx->prec + !!(ctx->flags & (1 << 4)) * 2;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > len)
		return (__padded_putlluint_hexa_fd(nb, len, ctx, UPPER));
	ft_putlluint_base_fd(nb, "0123456789ABCDEF", ctx->fd);
}
