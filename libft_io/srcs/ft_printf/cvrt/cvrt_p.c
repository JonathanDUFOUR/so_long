/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvrt_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:38:29 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/02 17:02:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"
#include "internal.h"
#include "e_ret.h"

inline static void	__padded_putaddr_fd(
	t_lluint const nb,
	int const len,
	t_ctx *const ctx)
{
	int	padlen;

	padlen = ctx->fwidth - ctx->prec - 2;
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1)))
		padding_fd(' ', padlen, ctx->fd);
	write(ctx->fd, "0x", 2);
	if (ctx->flags & (1 << 1))
		padding_fd('0', padlen, ctx->fd);
	padlen = ctx->prec - len;
	if (padlen)
		padding_fd('0', padlen, ctx->fd);
	ft_putlluint_base_fd(nb, "0123456789abcdef", ctx->fd);
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->fwidth - ctx->prec - 2;
		padding_fd(' ', padlen, ctx->fd);
	}
}

#ifdef __APPLE__

void	cvrt_p(t_ctx *const ctx, va_list va)
{
	t_lluint const	nb = va_arg(va, t_lluint);
	int				len;

	if (!ctx->prec && !nb)
	{
		if (ctx->fwidth < 2)
			ctx->fwidth = 2;
		padding_fd(' ', ctx->fwidth - 2, ctx->fd);
		ctx->len += ctx->fwidth;
		write(ctx->fd, "0x", 2);
		return ;
	}
	len = (int)ft_lluintlen_base(nb, 16);
	if (ctx->prec < len)
		ctx->prec = len;
	if (ctx->fwidth < (ctx->prec + 2))
		ctx->fwidth = ctx->prec + 2;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > (len + 2))
		__padded_putaddr_fd(nb, len, ctx);
	else
	{
		write(ctx->fd, "0x", 2);
		ft_putlluint_base_fd(nb, "0123456789abcdef", ctx->fd);
	}
}

#endif
#ifdef __linux__

void	cvrt_p(t_ctx *const ctx, va_list va)
{
	t_lluint const	nb = va_arg(va, t_lluint);
	int				len;

	if (!nb)
	{
		putnil(ctx);
		return ;
	}
	len = (int)ft_lluintlen_base(nb, 16);
	if (ctx->prec < len)
		ctx->prec = len;
	if (ctx->fwidth < (ctx->prec + 2))
		ctx->fwidth = ctx->prec + 2;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > (len + 2))
		__padded_putaddr_fd(nb, len, ctx);
	else
	{
		write(ctx->fd, "0x", 2);
		ft_putlluint_base_fd(nb, "0123456789abcdef", ctx->fd);
	}
}

#endif
