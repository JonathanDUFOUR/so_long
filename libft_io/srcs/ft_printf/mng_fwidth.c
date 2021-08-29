/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_fwidth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 23:43:37 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/23 01:25:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_ptf.h"

char const	*mng_fwidth(char const *format, t_ctx *ctx, va_list va)
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
		ctx->fwidth = ft_atou(format);
		while (ft_isdigit(*format))
			++format;
	}
	return (format);
}
