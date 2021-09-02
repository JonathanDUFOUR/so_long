/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_clear_collect.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 01:40:24 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/02 01:50:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "type/t_xptr.h"
#include "type/t_block.h"

/*
**	free collect image
*/
void	sl_block_clear_collect(void)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();

	if (block->collect.ptr)
		mlx_destroy_image(xptr->mlx, block->collect.ptr);
}
