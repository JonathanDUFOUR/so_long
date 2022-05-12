/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvrt_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:29:36 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/02 17:01:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <unistd.h>
#include "ft_io.h"
#include "internal.h"
#include "e_ret.h"

inline static void	__padded_putchar_fd(
	char const c,
	uint16_t const flags,
	int const padlen,
	int const fd)
{
	if (!(flags & (1 << 0)))
		padding_fd(' ', padlen, fd);
	ft_putchar_fd(c, fd);
	if (flags & (1 << 0))
		padding_fd(' ', padlen, fd);
}

inline static void	__padded_putwchar_fd(
	wchar_t const wc,
	uint16_t const flags,
	int const padlen,
	int const fd)
{
	if (!(flags & (1 << 0)))
		padding_fd(' ', padlen, fd);
	ft_putwchar_fd(wc, fd);
	if (flags & (1 << 0))
		padding_fd(' ', padlen, fd);
}

inline static void	__get_char(t_ctx *const ctx, va_list va)
{
	char const	c = (char)va_arg(va, int);

	if (!ctx->fwidth)
		ctx->fwidth = 1;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > 1)
		__padded_putchar_fd(c, ctx->flags, ctx->fwidth - 1, ctx->fd);
	else
		ft_putchar_fd(c, 1);
}

inline static void	__get_wchar(t_ctx *ctx, va_list va)
{
	wchar_t const	wc = va_arg(va, wchar_t);
	int				len;

	len = int_wclen(wc);
	if (ctx->fwidth < len)
		ctx->fwidth = len;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > 1)
		__padded_putwchar_fd(wc, ctx->flags, ctx->fwidth - len, ctx->fd);
	else
		ft_putwchar_fd(wc, 1);
}

void	cvrt_c(t_ctx *ctx, va_list va)
{
	if (ctx->flags & (1 << 5))
		__get_wchar(ctx, va);
	else
		__get_char(ctx, va);
}
