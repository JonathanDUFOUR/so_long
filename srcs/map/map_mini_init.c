/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mini_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:57:44 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/01 06:57:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "settings.h"
#include "t_map.h"
#include "e_ret.h"

/**
	@brief Initialize the minimap image, and let it empty for now.

	@param	m The map structure containing the minimap to initialize.
	@param	x The xptr structure containing the display and window pointers.
	@param	ret The program status reference.

	@return	The updated program status.
*/
int	map_mini_init(t_map *const m, t_xptr const *const x, int *const ret)
{
	m->mini.width = WIN_W;
	m->mini.height = WIN_H - SIDEBAR_H;
	m->mini.ptr = mlx_new_image(
			x->mlx,
			m->mini.width,
			m->mini.height);
	if (!m->mini.ptr)
		return (*ret = MLX_ERR);
	m->mini.addr = (uint32_t *)mlx_get_data_addr(
			m->mini.ptr,
			(int *)&m->mini.bpp,
			(int *)&m->mini.line_len,
			(int *)&m->mini.endian);
	if (!m->mini.addr)
		return (*ret = MLX_ERR);
	return (*ret = SUCCESS);
}
