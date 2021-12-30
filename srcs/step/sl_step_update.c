/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_step_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 18:36:51 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 21:29:45 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_io.h"
#include "ft_string.h"
#include "so_long.h"
#include "type/t_map.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	Increase step count and redraw it
*/
int	sl_step_update(void)
{
	t_uint *const	step = sl_step();
	int				ret;

	ret = sl_step_draw_count(0x00000000);
	if (ret != SUCCESS)
		return (ret);
	++*step;
	ret = sl_step_draw_count(0x00FFFFFF);
	return (ret);
}
