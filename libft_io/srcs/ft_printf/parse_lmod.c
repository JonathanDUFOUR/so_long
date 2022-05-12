/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lmod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 23:12:21 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/02 15:22:59 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_ctx.h"

/*
**	(1 << 5) -> l
**	(1 << 6) -> ll
**	(1 << 7) -> h
**	(1 << 8) -> hh
*/
char	*parse_lmod(char const *format, t_ctx *ctx)
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
	return ((char *)format);
}
