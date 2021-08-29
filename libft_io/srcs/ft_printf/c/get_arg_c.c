/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:29:36 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/18 02:37:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"
#include "ft_ptf.h"
#include "enum/e_ret.h"

static int	get_char(t_ctx *ctx, va_list va)
{
	char	c;

	c = (char)va_arg(va, int);
	if (!ctx->fwidth)
		ctx->fwidth = 1;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > 1)
		return (padded_putchar(c, ctx->flags, ctx->fwidth - 1));
	write(1, &c, 1);
	return (SUCCESS);
}

static int	get_wchar(t_ctx *ctx, va_list va)
{
	wchar_t	c;
	t_uint	len;

	c = va_arg(va, wchar_t);
	len = wclen(c);
	if (ctx->fwidth < len)
		ctx->fwidth = len;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > 1)
		return (padded_putwchar(c, ctx->flags, ctx->fwidth - len));
	ft_putchar_fd(c, 1);
	return (SUCCESS);
}

int	get_arg_c(t_ctx *ctx, va_list va)
{
	if (ctx->flags & (1 << 5))
		return (get_wchar(ctx, va));
	else
		return (get_char(ctx, va));
}
