/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fwidth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 23:43:37 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/13 01:42:04 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_io.h"
#include "t_ctx.h"

char	*parse_fwidth(char const *format, t_ctx *const ctx, va_list va)
{
	int	tmp;

	if (*format == '*')
	{
		tmp = va_arg(va, int);
		if (tmp >> 31)
		{
			ctx->flags |= 1 << 0;
			ctx->flags &= ~(1 << 1);
			ctx->fwidth = -tmp;
		}
		else
			ctx->fwidth = tmp;
		++format;
	}
	else
	{
		ctx->fwidth = ft_atoi(format);
		while (ft_isdigit(*format))
			++format;
	}
	return ((char *)format);
}
