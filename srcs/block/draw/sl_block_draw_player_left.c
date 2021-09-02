/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_draw_player_left.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 22:14:29 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 22:15:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "type/t_int.h"
#include "enum/e_ret.h"

/*
**	draw the player_left image loaded in block to window at position:
**	x * img_width
**	y * img_height
*/
int	sl_block_draw_player_left(t_huint x, t_huint y)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();
	t_img const		player_left = block->player_left;

	mlx_put_image_to_window(xptr->mlx, xptr->win, player_left.ptr,
		x * player_left.width, y * player_left.height);
	return (SUCCESS);
}
