/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstrlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:39:10 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/18 02:37:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "type/t_int.h"

t_uint	wstrlen(wchar_t *s)
{
	register wchar_t const	*p = s;

	while (*p)
		++p;
	return (p - s);
}
