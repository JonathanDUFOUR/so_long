/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_load_enemy_down.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 05:04:16 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/02 05:05:29 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "config.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	load enemy_down block data from xpm file
*/
int	sl_block_load_enemy_down(void)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();
	t_img			enemy_down;

	enemy_down.ptr = mlx_xpm_file_to_image(xptr->mlx, ENEMY_DOWN_XPM,
			(int *)&enemy_down.width, (int *)&enemy_down.height);
	if (!enemy_down.ptr)
		return (MLX_ERR);
	enemy_down.addr = mlx_get_data_addr(enemy_down.ptr,
			(int *)&enemy_down.bpp,
			(int *)&enemy_down.line_len,
			(int *)&enemy_down.endian);
	if (!enemy_down.addr)
	{
		mlx_destroy_image(xptr->mlx, enemy_down.ptr);
		return (MLX_ERR);
	}
	block->enemy_down = enemy_down;
	return (SUCCESS);
}
