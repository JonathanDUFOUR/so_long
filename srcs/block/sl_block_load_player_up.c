/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_load_player_up.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 22:23:10 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 22:33:50 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "config.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	load player_up block data from xpm file
*/
int	sl_block_load_player_up(void)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();
	t_img			player_up;

	player_up.ptr = mlx_xpm_file_to_image(xptr->mlx, PLAYER_UP_XPM,
			(int *)&player_up.width, (int *)&player_up.height);
	if (!player_up.ptr)
		return (MLX_ERR);
	player_up.addr = mlx_get_data_addr(player_up.ptr,
			(int *)&player_up.bpp,
			(int *)&player_up.line_len,
			(int *)&player_up.endian);
	if (!player_up.addr)
	{
		mlx_destroy_image(xptr->mlx, player_up.ptr);
		return (MLX_ERR);
	}
	block->player_up = player_up;
	return (SUCCESS);
}
