/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 18:59:05 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/29 20:55:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_mem.h"
#include "type/t_xptr.h"
#include "type/t_block.h"

/*
**	free block and bzero its variables
*/
void	sl_block_clear(void)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();

	if (block->collect.ptr)
		mlx_destroy_image(xptr->mlx, block->collect.ptr);
	if (block->exit.ptr)
		mlx_destroy_image(xptr->mlx, block->exit.ptr);
	if (block->floor.ptr)
		mlx_destroy_image(xptr->mlx, block->floor.ptr);
	if (block->player.ptr)
		mlx_destroy_image(xptr->mlx, block->player.ptr);
	if (block->wall.ptr)
		mlx_destroy_image(xptr->mlx, block->wall.ptr);
	ft_bzero(block, sizeof(t_block));
}
