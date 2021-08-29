/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_check_same_dim.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 20:32:57 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/29 23:19:55 by jodufour         ###   ########.fr       */
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
		|| block->collect.width != block->player.width
		|| block->collect.width != block->wall.width
		|| block->collect.height != block->exit.height
		|| block->collect.height != block->floor.height
		|| block->collect.height != block->player.height
		|| block->collect.height != block->wall.height)
		return (IMG_DIM_ERR);
	return (SUCCESS);
}
