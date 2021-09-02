/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_clear_player.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 01:48:06 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/02 01:52:03 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "type/t_xptr.h"
#include "type/t_block.h"

/*
**	free player images
*/
void	sl_block_clear_player(void)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();

	if (block->player_down.ptr)
		mlx_destroy_image(xptr->mlx, block->player_down.ptr);
	if (block->player_left.ptr)
		mlx_destroy_image(xptr->mlx, block->player_left.ptr);
	if (block->player_right.ptr)
		mlx_destroy_image(xptr->mlx, block->player_right.ptr);
	if (block->player_up.ptr)
		mlx_destroy_image(xptr->mlx, block->player_up.ptr);
}
