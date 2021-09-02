/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_load_enemy_up.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 07:16:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/02 07:16:20 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "config.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	load enemy_up block data from xpm file
*/
int	sl_block_load_enemy_up(void)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();
	t_img			enemy_up;

	enemy_up.ptr = mlx_xpm_file_to_image(xptr->mlx, ENEMY_UP_XPM,
			(int *)&enemy_up.width, (int *)&enemy_up.height);
	if (!enemy_up.ptr)
		return (MLX_ERR);
	enemy_up.addr = mlx_get_data_addr(enemy_up.ptr,
			(int *)&enemy_up.bpp,
			(int *)&enemy_up.line_len,
			(int *)&enemy_up.endian);
	if (!enemy_up.addr)
	{
		mlx_destroy_image(xptr->mlx, enemy_up.ptr);
		return (MLX_ERR);
	}
	block->enemy_up = enemy_up;
	return (SUCCESS);
}
