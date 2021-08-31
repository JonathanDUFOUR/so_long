/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_draw_player.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 01:31:08 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 02:14:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "type/t_int.h"
#include "enum/e_ret.h"

/*
**	draw the player image loaded in block to window at position:
**	x * img_width
**	y * img_height
*/
int	sl_block_draw_player(t_uint x, t_uint y)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();
	t_img const		player = block->player;

	mlx_put_image_to_window(xptr->mlx, xptr->win, player.ptr,
		x * player.width, y * player.height);
	return (SUCCESS);
}
