/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_load_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:19:13 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/12 11:46:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "settings.h"
#include "t_config.h"
#include "e_ret.h"

/**
	@brief	Load the exit image
			and store it in the given configuration structure.

	@param	c The configuration structure to fill.
	@param	x The xptr structure to use for image creation.
	@param	ret The profgram status reference.

	@return	The updated program status.
*/
int	config_load_exit(t_config *const c, t_xptr const *const x, int *const ret)
{
	c->exit.ptr = mlx_xpm_file_to_image(
			x->mlx,
			XPM_EXIT,
			(int *)&c->exit.width,
			(int *)&c->exit.height);
	if (!c->exit.ptr)
		return (*ret = MLX_ERR);
	c->exit.addr = (uint32_t *)mlx_get_data_addr(
			c->exit.ptr,
			(int *)&c->exit.bpp,
			(int *)&c->exit.line_len,
			(int *)&c->exit.endian);
	if (!c->exit.addr)
		return (*ret = MLX_ERR);
	return (*ret = SUCCESS);
}
