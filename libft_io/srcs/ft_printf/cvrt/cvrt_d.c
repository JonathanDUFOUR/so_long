/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvrt_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:19:49 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/02 16:04:29 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"
#include "internal.h"
#include "e_ret.h"

inline static t_llint	__get_right_type(t_ctx *const ctx, va_list va)
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

inline static void	__flag_exception(t_ctx *const ctx)
{
	if (ctx->flags & (1 << 2))
		write(1, "+", 1);
	else if (ctx->flags & (1 << 3))
		write(1, " ", 1);
	if (ctx->fwidth)
		--ctx->fwidth;
	++ctx->len;
}

inline static int	__fwidth_padlen(t_llint const nb, t_ctx *const ctx)
{
	return (ctx->fwidth
		- ctx->prec
		- !!((nb < 0) || (ctx->flags & (1 << 2)) || (ctx->flags & (1 << 3))));
}

inline static void	__padded_putllint_fd(
	t_llint const nb,
	int const len,
	t_ctx *const ctx)
{
	int	padlen;

	padlen = __fwidth_padlen(nb, ctx);
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1)))
		padding_fd(' ', padlen, ctx->fd);
	if (nb < 0)
		write(ctx->fd, "-", 1);
	else if (ctx->flags & (1 << 2))
		write(ctx->fd, "+", 1);
	else if (ctx->flags & (1 << 3))
		write(ctx->fd, " ", 1);
	if (ctx->flags & (1 << 1))
		padding_fd('0', padlen, ctx->fd);
	padlen = ctx->prec - (len - (nb < 0));
	if (padlen)
		padding_fd('0', padlen, ctx->fd);
	if (nb < 0)
		ft_putlluint_fd((t_lluint)(-nb), ctx->fd);
	else
		ft_putlluint_fd((t_lluint)nb, ctx->fd);
	if (ctx->flags & (1 << 0))
	{
		padlen = __fwidth_padlen(nb, ctx);
		padding_fd(' ', padlen, ctx->fd);
	}
}

void	cvrt_d(t_ctx *const ctx, va_list va)
{
	t_llint const	nb = __get_right_type(ctx, va);
	int				len;

	if (!ctx->prec && !nb)
	{
		if (ctx->flags & (1 << 2) || ctx->flags & (1 << 3))
			__flag_exception(ctx);
		padding_fd(' ', ctx->fwidth, ctx->fd);
		ctx->len += ctx->fwidth;
		return ;
	}
	len = (int)ft_llintlen(nb);
	if (ctx->prec < (len - (nb < 0)))
		ctx->prec = len - (nb < 0);
	if (ctx->fwidth < (ctx->prec + !!((nb < 0) || (ctx->flags & (1 << 2))
				|| (ctx->flags & (1 << 3)))))
		ctx->fwidth = ctx->prec + !!((nb < 0) || (ctx->flags & (1 << 2))
				|| (ctx->flags & (1 << 3)));
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > len)
		__padded_putllint_fd(nb, len, ctx);
	else
		ft_putllint_fd(nb, ctx->fd);
}
