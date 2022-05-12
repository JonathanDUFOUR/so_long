/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvrt_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:38:14 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/02 17:03:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"
#include "internal.h"
#include "e_ret.h"

void	padded_putnstr_fd(char const *str, t_ctx *const ctx)
{
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1)))
		padding_fd(' ', ctx->fwidth - ctx->prec, ctx->fd);
	if (ctx->flags & (1 << 1))
		padding_fd('0', ctx->fwidth - ctx->prec, ctx->fd);
	write(ctx->fd, str, (size_t)ctx->prec);
	if (ctx->flags & (1 << 0))
		padding_fd(' ', ctx->fwidth - ctx->prec, ctx->fd);
}

inline static void	__padded_putnwstr_fd(
	wchar_t const *wstr,
	t_ctx *const ctx,
	int len,
	int const size)
{
	len = ctx->prec;
	if (!(ctx->flags & (1 << 0)))
		padding_fd(' ', ctx->fwidth - size, ctx->fd);
	while (len--)
		ft_putwchar_fd(*wstr++, ctx->fd);
	if (ctx->flags & (1 << 0))
		padding_fd(' ', ctx->fwidth - size, ctx->fd);
}

inline static void	__get_char_ptr(t_ctx *const ctx, va_list va)
{
	char const	*str = va_arg(va, char *);
	int			len;

	if (!str)
	{
		putnull(ctx);
		return ;
	}
	len = int_strlen(str);
	if (!ctx->precised || ctx->prec > len)
		ctx->prec = len;
	if (ctx->fwidth < ctx->prec)
		ctx->fwidth = ctx->prec;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > ctx->prec)
		padded_putnstr_fd(str, ctx);
	else
		write(ctx->fd, str, (size_t)ctx->prec);
}

inline static void	__get_wchar_ptr(t_ctx *const ctx, va_list va)
{
	wchar_t const	*wstr = va_arg(va, wchar_t *);
	int				len;
	int				size;

	if (!wstr)
	{
		putnull(ctx);
		return ;
	}
	len = int_wstrlen(wstr);
	size = int_wstrsize(wstr);
	if (!ctx->precised || ctx->prec > len)
		ctx->prec = len;
	if (ctx->fwidth < ctx->prec)
		ctx->fwidth = ctx->prec;
	ctx->len += size;
	if (size < ctx->fwidth)
		ctx->len += ctx->fwidth;
	if (ctx->fwidth > size)
		__padded_putnwstr_fd(wstr, ctx, len, size);
	else
		while (ctx->prec--)
			ft_putwchar_fd(*wstr++, ctx->fd);
}

void	cvrt_s(t_ctx *const ctx, va_list va)
{
	if (ctx->flags & (1 << 5))
		__get_wchar_ptr(ctx, va);
	else
		__get_char_ptr(ctx, va);
}
