/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 06:37:06 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/02 15:08:08 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "internal.h"
#include "t_ctx.h"

char	*manage_text(char const *format, t_ctx *const ctx)
{
	char	*next;

	next = int_strchr(format, '%');
	if (next)
		ctx->fwidth = (int)(next - format);
	else
		ctx->fwidth = int_strlen(format);
	write(ctx->fd, format, (size_t)ctx->fwidth);
	ctx->len += ctx->fwidth;
	format += ctx->fwidth;
	return ((char *)format);
}
