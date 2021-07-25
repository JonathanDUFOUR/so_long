/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:43:20 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/23 01:22:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_ptf.h"
#include "enums/e_ret.h"

int	padded_putnstr(char *s, t_ctx *ctx);

int	putnull(t_ctx *ctx)
{
	t_uint	len;

	len = 6;
	if (!ctx->precised || ctx->prec > len)
		ctx->prec = len;
	if (ctx->fwidth < ctx->prec)
		ctx->fwidth = ctx->prec;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > ctx->prec)
		return (padded_putnstr("(null)", ctx));
	write(1, "(null)", ctx->prec);
	return (SUCCESS);
}
