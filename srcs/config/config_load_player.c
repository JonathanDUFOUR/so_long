/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_load_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:20:01 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/13 03:09:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "settings.h"
#include "t_config.h"
#include "e_cardinal.h"
#include "e_ret.h"

inline static int	__load_one(
	t_config *const c,
	t_xptr const *const x,
	t_uint const cardinal,
	t_uint const idx)
{
	t_img	tmp;

	tmp.ptr = mlx_xpm_file_to_image(
			x->mlx,
			(char *)g_xpm_player[idx],
			(int *)&tmp.width,
			(int *)&tmp.height);
	if (!tmp.ptr)
		return (EXIT_FAILURE);
	tmp.addr = (uint32_t *)mlx_get_data_addr(
			tmp.ptr,
			(int *)&tmp.bpp,
			(int *)&tmp.line_len,
			(int *)&tmp.endian);
	if (!tmp.addr || anim_lst_add_back(&c->player[cardinal], &tmp))
		return (mlx_destroy_image(x->mlx, tmp.ptr), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
	@brief	Load the player images
			and store them in the given configuration structure.

	@param	c The configuration structure to fill.
	@param	x The xptr structure to use for image creation.
	@param	ret The profgram status reference.

	@return	The updated program status.
*/
int	config_load_player(t_config *const c, t_xptr const *const x, int *const ret)
{
	t_uint	cardinal;
	t_uint	idx;

	cardinal = EAST;
	idx = 0U;
	while (cardinal <= SOUTH_EAST)
	{
		while (g_xpm_player[idx])
		{
			if (__load_one(c, x, cardinal, idx))
				return (*ret = MLX_ERR);
			++idx;
		}
		++cardinal;
		++idx;
	}
	return (*ret = SUCCESS);
}
