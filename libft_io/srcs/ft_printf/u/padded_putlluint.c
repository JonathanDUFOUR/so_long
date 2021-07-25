/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padded_putlluint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 00:54:46 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/23 01:23:08 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_ptf.h"
#include "enums/e_ret.h"

int	padded_putlluint(t_lluint n, t_uint len, t_ctx *ctx)
{
	t_uint	padlen;

	padlen = ctx->fwidth - ctx->prec;
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1))
		&& padding(' ', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	if (ctx->flags & (1 << 1) && padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	padlen = ctx->prec - len;
	if (padlen && padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	ft_putlluint_fd(n, 1);
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->fwidth - ctx->prec;
		if (padding(' ', padlen) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
	}
	return (SUCCESS);
}
