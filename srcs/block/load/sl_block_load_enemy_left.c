/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_load_enemy_left.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 07:12:50 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/02 07:14:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "config.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	load enemy_left block data from xpm file
*/
int	sl_block_load_enemy_left(void)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();
	t_img			enemy_left;

	enemy_left.ptr = mlx_xpm_file_to_image(xptr->mlx, ENEMY_LEFT_XPM,
			(int *)&enemy_left.width, (int *)&enemy_left.height);
	if (!enemy_left.ptr)
		return (MLX_ERR);
	enemy_left.addr = mlx_get_data_addr(enemy_left.ptr,
			(int *)&enemy_left.bpp,
			(int *)&enemy_left.line_len,
			(int *)&enemy_left.endian);
	if (!enemy_left.addr)
	{
		mlx_destroy_image(xptr->mlx, enemy_left.ptr);
		return (MLX_ERR);
	}
	block->enemy_left = enemy_left;
	return (SUCCESS);
}
