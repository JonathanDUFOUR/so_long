/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_load_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:19:36 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/05 01:16:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "settings.h"
#include "t_config.h"
#include "e_ret.h"

/**
	@brief	Load the floor image
			and store it in the given configuration structure.

	@param	c The configuration structure to fill.
	@param	x The xptr structure to use for image creation.
	@param	ret The profgram status reference.

	@return	The updated program status.
*/
int	config_load_floor(t_config *const c, t_xptr const *const x, int *const ret)
{
	c->floor.ptr = mlx_xpm_file_to_image(
			x->mlx,
			XPM_FLOOR,
			(int *)&c->floor.width,
			(int *)&c->floor.height);
	if (!c->floor.ptr)
		return (*ret = MLX_ERR);
	if (c->floor.width != IMG_W || c->floor.height != IMG_H)
		return (*ret = IMG_DIM_ERR);
	c->floor.addr = (uint32_t *)mlx_get_data_addr(
			c->floor.ptr,
			(int *)&c->floor.bpp,
			(int *)&c->floor.line_len,
			(int *)&c->floor.endian);
	if (!c->floor.addr)
		return (*ret = MLX_ERR);
	return (*ret = SUCCESS);
}
