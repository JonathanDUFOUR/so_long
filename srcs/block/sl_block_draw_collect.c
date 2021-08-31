/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_draw_collect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 01:27:51 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 21:39:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "type/t_int.h"
#include "enum/e_ret.h"

/*
**	draw the collect image loaded in block to window at position:
**	x * img_width
**	y * img_height
*/
int	sl_block_draw_collect(t_huint x, t_huint y)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();
	t_img const		collect = block->collect;

	mlx_put_image_to_window(xptr->mlx, xptr->win, collect.ptr,
		x * collect.width, y * collect.height);
	return (SUCCESS);
}
