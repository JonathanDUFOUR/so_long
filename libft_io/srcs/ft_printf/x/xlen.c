/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xlen.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 06:29:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/23 01:24:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs/t_int.h"

t_uint	xlen(t_lluint n)
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
