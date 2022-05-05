/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_load_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:20:29 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/05 01:17:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "settings.h"
#include "t_config.h"
#include "e_ret.h"

/**
	@brief	Load the wall image
			and store it in the given configuration structure.

	@param	c The configuration structure to fill.
	@param	x The xptr structure to use for image creation.
	@param	ret The profgram status reference.

	@return	The updated program status.
*/
int	config_load_wall(t_config *const c, t_xptr const *const x, int *const ret)
{
	c->wall.ptr = mlx_xpm_file_to_image(
			x->mlx,
			XPM_WALL,
			(int *)&c->wall.width,
			(int *)&c->wall.height);
	if (!c->wall.ptr)
		return (*ret = MLX_ERR);
	if (c->wall.width != IMG_W || c->wall.height != IMG_H)
		return (*ret = IMG_DIM_ERR);
	c->wall.addr = (uint32_t *)mlx_get_data_addr(
			c->wall.ptr,
			(int *)&c->wall.bpp,
			(int *)&c->wall.line_len,
			(int *)&c->wall.endian);
	if (!c->wall.addr)
		return (*ret = MLX_ERR);
	return (*ret = SUCCESS);
}
