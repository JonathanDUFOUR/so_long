/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_load_floor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 13:09:52 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 21:52:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "config.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	load floor block data from xpm file
*/
int	sl_block_load_floor(void)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();
	t_img			floor;

	floor.ptr = mlx_xpm_file_to_image(xptr->mlx, FLOOR_XPM,
			(int *)&floor.width, (int *)&floor.height);
	if (!floor.ptr)
		return (MLX_ERR);
	floor.addr = mlx_get_data_addr(floor.ptr, (int *)&floor.bpp,
			(int *)&floor.line_len, (int *)&floor.endian);
	if (!floor.addr)
	{
		mlx_destroy_image(xptr->mlx, floor.ptr);
		return (MLX_ERR);
	}
	block->floor = floor;
	return (SUCCESS);
}
