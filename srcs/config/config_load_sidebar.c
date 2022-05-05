/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_load_sidebar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 01:03:42 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/05 01:13:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "t_config.h"
#include "e_ret.h"

/**
	@brief	Load the sidebar image
			and store it in the given configuration structure.

	@param	c The configuration structure to fill.
	@param	x The xptr structure to use for image creation.
	@param	ret The program status reference.

	@return	The updated program status.
*/
int	config_load_sidebar(
	t_config *const c,
	t_xptr const *const x,
	int *const ret)
{
	c->sidebar.ptr = mlx_xpm_file_to_image(
			x->mlx,
			XPM_SIDEBAR,
			(int *)&c->sidebar.width,
			(int *)&c->sidebar.height);
	if (!c->sidebar.ptr)
		return (*ret = MLX_ERR);
	if (c->sidebar.width != WIN_W || c->sidebar.height != SIDEBAR_H)
		return (*ret = IMG_DIM_ERR);
	c->sidebar.addr = (uint32_t *)mlx_get_data_addr(
			c->sidebar.ptr,
			(int *)&c->sidebar.bpp,
			(int *)&c->sidebar.line_len,
			(int *)&c->sidebar.endian);
	if (!c->sidebar.addr)
		return (*ret = MLX_ERR);
	return (*ret = SUCCESS);
}
