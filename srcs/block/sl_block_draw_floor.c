/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_draw_floor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 01:30:08 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 02:13:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "type/t_int.h"
#include "enum/e_ret.h"

/*
**	draw the floor image loaded in block to window at position:
**	x * img_width
**	y * img_height
*/
int	sl_block_draw_floor(t_uint x, t_uint y)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();
	t_img const		floor = block->floor;

	mlx_put_image_to_window(xptr->mlx, xptr->win, floor.ptr,
		x * floor.width, y * floor.height);
	return (SUCCESS);
}
