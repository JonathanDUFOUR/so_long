/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 06:37:06 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/22 23:04:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_ptf.h"

char const	*mng_text(char const *format, t_ctx *ctx)
{
	char	*next;

	next = ptf_strchr(format, '%');
	if (next)
		ctx->fwidth = next - format;
	else
		ctx->fwidth = ptf_strlen(format);
	write(1, format, ctx->fwidth);
	ctx->len += ctx->fwidth;
	while (*format && *format != '%')
		++format;
	return (format);
}
