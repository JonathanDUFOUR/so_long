/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_load_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 13:11:10 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 21:57:35 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "config.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	load wall img data from xpm file
*/
int	sl_block_load_wall(void)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();
	t_img			wall;

	wall.ptr = mlx_xpm_file_to_image(xptr->mlx, WALL_XPM,
			(int *)&wall.width, (int *)&wall.height);
	if (!wall.ptr)
		return (MLX_ERR);
	wall.addr = mlx_get_data_addr(wall.ptr, (int *)&wall.bpp,
			(int *)&wall.line_len, (int *)&wall.endian);
	if (!wall.addr)
	{
		mlx_destroy_image(xptr->mlx, wall.ptr);
		return (MLX_ERR);
	}
	block->wall = wall;
	return (SUCCESS);
}
