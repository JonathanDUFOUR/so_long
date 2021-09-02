/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_draw_enemy_up.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 07:25:52 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/02 07:39:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "type/t_int.h"
#include "enum/e_ret.h"

/*
**	draw the enemy_up image loaded in block to window at position:
**	x * img_width
**	y * img_height
*/
int	sl_block_draw_enemy_up(t_huint x, t_huint y)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();
	t_img const		enemy_up = block->enemy_up;

	mlx_put_image_to_window(xptr->mlx, xptr->win, enemy_up.ptr,
		x * enemy_up.width, y * enemy_up.height);
	return (SUCCESS);
}
