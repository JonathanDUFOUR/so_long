/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_load_player_right.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 22:21:59 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 22:33:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "config.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	load player_right block data from xpm file
*/
int	sl_block_load_player_right(void)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();
	t_img			player_right;

	player_right.ptr = mlx_xpm_file_to_image(xptr->mlx, PLAYER_RIGHT_XPM,
			(int *)&player_right.width, (int *)&player_right.height);
	if (!player_right.ptr)
		return (MLX_ERR);
	player_right.addr = mlx_get_data_addr(player_right.ptr,
			(int *)&player_right.bpp,
			(int *)&player_right.line_len,
			(int *)&player_right.endian);
	if (!player_right.addr)
	{
		mlx_destroy_image(xptr->mlx, player_right.ptr);
		return (MLX_ERR);
	}
	block->player_right = player_right;
	return (SUCCESS);
}
