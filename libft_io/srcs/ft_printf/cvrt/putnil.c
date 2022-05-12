/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnil.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:15:14 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/02 16:59:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "t_ctx.h"
#include "e_ret.h"

void	padded_putnstr_fd(char const *str, t_ctx *const ctx);

void	putnil(t_ctx *const ctx)
{
	int	len;

	len = 5;
	if (!ctx->precised || ctx->prec > len)
		ctx->prec = len;
	if (ctx->fwidth < ctx->prec)
		ctx->fwidth = ctx->prec;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > ctx->prec)
		return (padded_putnstr_fd("(nil)", ctx));
	write(ctx->fd, "(nil)", (size_t)ctx->prec);
}
