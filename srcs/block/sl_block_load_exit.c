/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_load_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 13:09:00 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/29 22:31:58 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "config.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	load exit block data from xpm file
*/
int	sl_block_load_exit(void)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();
	t_img			exit;

	exit.ptr = mlx_xpm_file_to_image(xptr->mlx, EXIT_XPM,
			&exit.width, &exit.height);
	if (!exit.ptr)
		return (MLX_ERR);
	exit.addr = mlx_get_data_addr(exit.ptr, &exit.bpp,
			&exit.line_len, &exit.endian);
	if (!exit.addr)
	{
		mlx_destroy_image(xptr->mlx, exit.ptr);
		return (MLX_ERR);
	}
	block->exit = exit;
	return (SUCCESS);
}