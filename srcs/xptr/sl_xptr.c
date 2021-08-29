/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_xptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 05:21:43 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/28 05:23:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "type/t_xptr.h"

t_xptr	*sl_xptr(void)
{
	static t_xptr	xptr = {NULL, NULL};

	return (&xptr);
}
