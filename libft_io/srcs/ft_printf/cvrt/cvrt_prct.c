/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvrt_prct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 06:58:39 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/02 16:24:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include "internal.h"
#include "e_ret.h"

inline static void	__padded_putprct_fd(
	uint16_t const flags,
	int const padlen,
	int const fd)
{
	if (!(flags & (1 << 0)) && !(flags & (1 << 1)))
		padding_fd(' ', padlen, fd);
	if (flags & (1 << 1))
		padding_fd('0', padlen, fd);
	write(fd, "%", 1);
	if (flags & (1 << 0))
		padding_fd(' ', padlen, fd);
}

void	cvrt_prct(t_ctx *const ctx)
{
	if (!ctx->fwidth)
		ctx->fwidth = 1;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > 1)
		__padded_putprct_fd(ctx->flags, ctx->fwidth - 1, ctx->fd);
	else
		write(ctx->fd, "%", 1);
}
