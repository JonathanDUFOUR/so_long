/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_draw_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 01:28:58 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 02:13:14 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "type/t_int.h"
#include "enum/e_ret.h"

/*
**	draw the exit image loaded in block to window at position:
**	x * img_width
**	y * img_height
*/
int	sl_block_draw_exit(t_uint x, t_uint y)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();
	t_img const		exit = block->exit;

	mlx_put_image_to_window(xptr->mlx, xptr->win, exit.ptr,
		x * exit.width, y * exit.height);
	return (SUCCESS);
}
