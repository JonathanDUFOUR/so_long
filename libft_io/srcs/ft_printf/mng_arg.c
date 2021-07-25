/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:11:17 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/23 01:25:04 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ptf.h"

char const	*mng_arg(char const *format, t_ctx *ctx, va_list va)
{
	format = mng_flags(format, ctx);
	format = mng_fwidth(format, ctx, va);
	format = mng_prec(format, ctx, va);
	format = mng_lmod(format, ctx);
	format = mng_spec(format, ctx, va);
	ctx->flags = 0;
	ctx->fwidth = 0;
	ctx->prec = 1;
	ctx->precised = false;
	return (format);
}
