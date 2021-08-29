/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_load_player.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 13:10:29 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/29 22:33:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "config.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	load player block data from xpm file
*/
int	sl_block_load_player(void)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();
	t_img			player;

	player.ptr = mlx_xpm_file_to_image(xptr->mlx, PLAYER_XPM,
			&player.width, &player.height);
	if (!player.ptr)
		return (MLX_ERR);
	player.addr = mlx_get_data_addr(player.ptr, &player.bpp,
			&player.line_len, &player.endian);
	if (!player.addr)
	{
		mlx_destroy_image(xptr->mlx, player.ptr);
		return (MLX_ERR);
	}
	block->player = player;
	return (SUCCESS);
}
