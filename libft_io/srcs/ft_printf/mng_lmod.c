/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_lmod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 23:12:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/22 22:34:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ptf.h"

char const	*mng_lmod(char const *format, t_ctx *ctx)
{
	if (*format == 'l')
	{
		++format;
		if (*format == 'l' && ++format)
			ctx->flags |= 1 << 6;
		else
			ctx->flags |= 1 << 5;
	}
	else if (*format == 'h')
	{
		++format;
		if (*format == 'h' && ++format)
			ctx->flags |= 1 << 8;
		else
			ctx->flags |= 1 << 7;
	}
	return (format);
}
