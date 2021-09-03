/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_step.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 04:05:56 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 04:08:33 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_int.h"

/*
**	singleton to get player's step count
*/
t_uint	*sl_step(void)
{
	static t_uint	step = 0;

	return (&step);
}
