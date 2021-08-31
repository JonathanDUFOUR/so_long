/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_check_same_dim.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 20:32:57 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 22:29:58 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	check if all images have the same dimensions
**	return an error if at least one has not
*/
int	sl_block_check_same_dim(void)
{
	t_block *const	block = sl_block();

	if (block->collect.width != block->exit.width
		|| block->collect.width != block->floor.width
		|| block->collect.width != block->player_down.width
		|| block->collect.width != block->player_left.width
		|| block->collect.width != block->player_right.width
		|| block->collect.width != block->player_up.width
		|| block->collect.width != block->wall.width
		|| block->collect.height != block->exit.height
		|| block->collect.height != block->floor.height
		|| block->collect.height != block->player_down.height
		|| block->collect.height != block->player_left.height
		|| block->collect.height != block->player_right.height
		|| block->collect.height != block->player_up.height
		|| block->collect.height != block->wall.height)
		return (IMG_DIM_ERR);
	return (SUCCESS);
}
