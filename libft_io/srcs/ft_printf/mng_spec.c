/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_spec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:20:34 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/18 05:16:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ptf.h"
#include "dispatch_lookup.h"
#include "enum/e_ret.h"

char const	*mng_spec(char const *format, t_ctx *ctx, va_list va)
{
	t_cvrt const	*curr;

	curr = g_cvrt;
	while (curr->c && curr->c != *format)
		++curr;
	if (!curr->fct || curr->fct(ctx, va) != SUCCESS)
		return (NULL);
	return (format + 1);
}
