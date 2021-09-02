/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_clear_enemy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 01:42:28 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/02 07:18:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "type/t_xptr.h"
#include "type/t_block.h"

/*
**	free enemy images
*/
void	sl_block_clear_enemy(void)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();

	if (block->enemy_down.ptr)
		mlx_destroy_image(xptr->mlx, block->enemy_down.ptr);
	if (block->enemy_left.ptr)
		mlx_destroy_image(xptr->mlx, block->enemy_left.ptr);
	if (block->enemy_right.ptr)
		mlx_destroy_image(xptr->mlx, block->enemy_right.ptr);
	if (block->enemy_up.ptr)
		mlx_destroy_image(xptr->mlx, block->enemy_up.ptr);
}
