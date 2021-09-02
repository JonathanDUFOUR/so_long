/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_draw_enemy_right.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 07:25:18 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/02 07:25:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "type/t_int.h"
#include "enum/e_ret.h"

/*
**	draw the enemy_right image loaded in block to window at position:
**	x * img_width
**	y * img_height
*/
int	sl_block_draw_enemy_right(t_huint x, t_huint y)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();
	t_img const		enemy_right = block->enemy_right;

	mlx_put_image_to_window(xptr->mlx, xptr->win, enemy_right.ptr,
		x * enemy_right.width, y * enemy_right.height);
	return (SUCCESS);
}
