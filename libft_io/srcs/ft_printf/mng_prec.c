/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_prec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 22:36:48 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/22 23:07:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ptf.h"
#include "ft_io.h"

char const	*mng_prec(char const *format, t_ctx *ctx, va_list va)
{
	if (*format == '.')
	{
		if (*++format == '*')
		{
			ctx->prec = va_arg(va, uint32_t);
			if (ctx->prec >> 31)
				ctx->prec = 1;
			else
			{
				ctx->precised = true;
				ctx->flags &= ~(1 << 1);
			}
			++format;
		}
		else
		{
			ctx->precised = true;
			ctx->flags &= ~(1 << 1);
			ctx->prec = ft_atou(format);
			while (ft_isdigit(*format))
				++format;
		}
	}
	return (format);
}
