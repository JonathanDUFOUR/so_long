/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_clear_floor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 01:47:25 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/02 01:51:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "type/t_xptr.h"
#include "type/t_block.h"

/*
**	free floor image
*/
void	sl_block_clear_floor(void)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();

	if (block->floor.ptr)
		mlx_destroy_image(xptr->mlx, block->floor.ptr);
}
