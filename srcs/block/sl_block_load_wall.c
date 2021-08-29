/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_load_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 13:11:10 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/28 14:36:06 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "config.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	load wall block data from xpm file
*/
int	sl_block_load_wall(void)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();
	t_img			wall;

	wall.ptr = mlx_xpm_file_to_image(xptr->mlx, FLOOR_XPM,
		&wall.width, &wall.height);
	if (!wall.ptr)
		return (MLX_ERR);
	wall.addr = mlx_get_data_addr(wall.ptr, &wall.bpp,
		&wall.line_len, &wall.endian);
	if (!wall.addr)
	{
		mlx_destroy_image(xptr->mlx, wall.ptr);
		return (MLX_ERR);
	}
	block->wall = wall;
	return (SUCCESS);
}
