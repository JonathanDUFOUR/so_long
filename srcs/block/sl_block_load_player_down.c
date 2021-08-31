/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_load_player_down.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 13:10:29 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 22:32:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "config.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	load player_down block data from xpm file
*/
int	sl_block_load_player_down(void)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();
	t_img			player_down;

	player_down.ptr = mlx_xpm_file_to_image(xptr->mlx, PLAYER_DOWN_XPM,
			(int *)&player_down.width, (int *)&player_down.height);
	if (!player_down.ptr)
		return (MLX_ERR);
	player_down.addr = mlx_get_data_addr(player_down.ptr,
			(int *)&player_down.bpp,
			(int *)&player_down.line_len,
			(int *)&player_down.endian);
	if (!player_down.addr)
	{
		mlx_destroy_image(xptr->mlx, player_down.ptr);
		return (MLX_ERR);
	}
	block->player_down = player_down;
	return (SUCCESS);
}
