/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:58:43 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/02 17:03:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "internal.h"
#include "t_ctx.h"
#include "e_ret.h"

static void	__reset(t_ctx *const ctx)
{
	ctx->flags = 0;
	ctx->fwidth = 0;
	ctx->prec = 1;
	ctx->precised = false;
}

/*
	Print text and conversions on stdout
	Return the number of bytes printed
	Return -1 upon failure
*/
int	ft_printf(char const *format, ...)
{
	t_ctx	ctx;
	va_list	va;

	ctx.fd = STDOUT_FILENO;
	ctx.len = 0;
	va_start(va, format);
	while (*format)
	{
		__reset(&ctx);
		if (*format == '%')
			format = manage_cvrt(format + 1, &ctx, va);
		else
			format = manage_text(format, &ctx);
		if (!format)
		{
			va_end(va);
			return (-!!MALLOC_ERR);
		}
	}
	va_end(va);
	return (ctx.len);
}

int	ft_dprintf(int const fd, char const *format, ...)
{
	t_ctx	ctx;
	va_list	va;

	ctx.fd = fd;
	ctx.len = 0;
	va_start(va, format);
	while (*format)
	{
		__reset(&ctx);
		if (*format == '%')
			format = manage_cvrt(format + 1, &ctx, va);
		else
			format = manage_text(format, &ctx);
		if (!format)
		{
			va_end(va);
			return (-!!MALLOC_ERR);
		}
	}
	va_end(va);
	return (ctx.len);
}
