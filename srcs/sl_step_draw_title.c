/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_step_draw_title.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 20:17:06 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/01 20:20:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "type/t_map.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	draw the moves count at the top of the window
*/
int	sl_step_draw_title(void)
{
	t_xptr *const	xptr = sl_xptr();
	t_huint const	x = (sl_map()->width / 2 - 1) * sl_block()->wall.width - 42;
	t_huint const	y = sl_block()->wall.height / 2;

	mlx_string_put(xptr->mlx, xptr->win, x, y, 0x00FFFFFF, "Moves: ");
	return (SUCCESS);
}
