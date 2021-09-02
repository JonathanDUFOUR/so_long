/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_load_enemy_right.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 07:15:17 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/02 07:15:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "config.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	load enemy_right block data from xpm file
*/
int	sl_block_load_enemy_right(void)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();
	t_img			enemy_right;

	enemy_right.ptr = mlx_xpm_file_to_image(xptr->mlx, ENEMY_RIGHT_XPM,
			(int *)&enemy_right.width, (int *)&enemy_right.height);
	if (!enemy_right.ptr)
		return (MLX_ERR);
	enemy_right.addr = mlx_get_data_addr(enemy_right.ptr,
			(int *)&enemy_right.bpp,
			(int *)&enemy_right.line_len,
			(int *)&enemy_right.endian);
	if (!enemy_right.addr)
	{
		mlx_destroy_image(xptr->mlx, enemy_right.ptr);
		return (MLX_ERR);
	}
	block->enemy_right = enemy_right;
	return (SUCCESS);
}
