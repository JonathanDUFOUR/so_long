/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_load_collect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 01:40:36 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/01 01:42:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "settings.h"
#include "t_config.h"
#include "e_ret.h"

/**
	@brief	Load the collectible image
			and store it in the given configuration structure.

	@param	c The configuration structure to fill.
	@param	x The xptr structure to use for image creation.
	@param	ret The profgram status reference.

	@return	The updated program status.
*/
int	config_load_collect(
	t_config *const c,
	t_xptr const *const x,
	int *const ret)
{
	c->collect.ptr = mlx_xpm_file_to_image(
			x->mlx,
			XPM_COLLECT,
			(int *)&c->collect.width,
			(int *)&c->collect.height);
	if (!c->collect.ptr)
		return (*ret = MLX_ERR);
	c->collect.addr = (uint32_t *)mlx_get_data_addr(
			c->collect.ptr,
			(int *)&c->collect.bpp,
			(int *)&c->collect.line_len,
			(int *)&c->collect.endian);
	if (!c->collect.addr)
		return (*ret = MLX_ERR);
	return (*ret = SUCCESS);
}
