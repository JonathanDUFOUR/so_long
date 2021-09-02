/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_load_collect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 13:06:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 21:48:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "config.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	load collect block data from xpm file
*/
int	sl_block_load_collect(void)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();
	t_img			collect;

	collect.ptr = mlx_xpm_file_to_image(xptr->mlx, COLLECT_XPM,
			(int *)&collect.width, (int *)&collect.height);
	if (!collect.ptr)
		return (MLX_ERR);
	collect.addr = mlx_get_data_addr(collect.ptr, (int *)&collect.bpp,
			(int *)&collect.line_len, (int *)&collect.endian);
	if (!collect.addr)
	{
		mlx_destroy_image(xptr->mlx, collect.ptr);
		return (MLX_ERR);
	}
	block->collect = collect;
	return (SUCCESS);
}
