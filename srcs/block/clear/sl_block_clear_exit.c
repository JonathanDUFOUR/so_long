/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_clear_exit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 01:45:34 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/02 01:51:35 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "type/t_xptr.h"
#include "type/t_block.h"

/*
**	free exit image
*/
void	sl_block_clear_exit(void)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();

	if (block->exit.ptr)
		mlx_destroy_image(xptr->mlx, block->exit.ptr);
}
