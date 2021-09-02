/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_load_player_left.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 22:21:05 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 22:32:20 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "config.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	load player_left block data from xpm file
*/
int	sl_block_load_player_left(void)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();
	t_img			player_left;

	player_left.ptr = mlx_xpm_file_to_image(xptr->mlx, PLAYER_LEFT_XPM,
			(int *)&player_left.width, (int *)&player_left.height);
	if (!player_left.ptr)
		return (MLX_ERR);
	player_left.addr = mlx_get_data_addr(player_left.ptr,
			(int *)&player_left.bpp,
			(int *)&player_left.line_len,
			(int *)&player_left.endian);
	if (!player_left.addr)
	{
		mlx_destroy_image(xptr->mlx, player_left.ptr);
		return (MLX_ERR);
	}
	block->player_left = player_left;
	return (SUCCESS);
}
