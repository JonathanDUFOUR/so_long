/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_pplane_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:17:23 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/06 21:20:59 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "t_game.h"
#include "e_ret.h"

/**
	@brief Initialize the projection plane image, and let it empty for now.

	@param	g The game structure containing the projection plane to initialize.
	@param	x The xptr structure containing the display and window pointers.
	@param	ret The program status reference.

	@return	The updated program status.
*/
int	game_pplane_init(t_game *const g, t_xptr const *const x, int *const ret)
{
	g->pplane.width = WIN_W;
	g->pplane.height = WIN_H - SIDEBAR_H;
	g->pplane.ptr = mlx_new_image(
			x->mlx,
			g->pplane.width,
			g->pplane.height);
	if (!g->pplane.ptr)
		return (*ret = MLX_ERR);
	g->pplane.addr = (uint32_t *)mlx_get_data_addr(
			g->pplane.ptr,
			(int *)&g->pplane.bpp,
			(int *)&g->pplane.line_len,
			(int *)&g->pplane.endian);
	if (!g->pplane.addr)
		return (*ret = MLX_ERR);
	return (*ret = SUCCESS);
}
