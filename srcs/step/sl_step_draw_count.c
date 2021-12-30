/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_step_draw_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:49:12 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 21:29:33 by jodufour         ###   ########.fr       */
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
**	draw the moves count at the top of the window
*/
int	sl_step_draw_count(int color)
{
	t_xptr *const	xptr = sl_xptr();
	t_uint *const	step = sl_step();
	t_huint const	x = (sl_map()->width / 2 - 1) * sl_block()->wall.width;
	t_huint const	y = sl_block()->wall.height / 2;
	char			*str;

	str = ft_utoa(*step);
	if (!str)
		return (MALLOC_ERR);
	mlx_string_put(xptr->mlx, xptr->win, x, y, color, str);
	ft_memdel(&str);
	return (SUCCESS);
}
