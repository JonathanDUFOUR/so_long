/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plen.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 07:30:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/23 01:21:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "typedefs/t_int.h"

t_uint	plen(uintptr_t n)
{
	t_uint	len;

	len = 1;
	while (n > 15)
	{
		++len;
		n /= 16;
	}
	return (len);
}
