/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_load_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:20:01 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/24 16:54:56 by jodufour         ###   ########.fr       */
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
	t_uint const animate_idx)
{
	c->player[cardinal][animate_idx].ptr = mlx_xpm_file_to_image(
			x->mlx,
			(char *)g_xpm_player[cardinal][animate_idx],
			(int *)&c->player[cardinal][animate_idx].width,
			(int *)&c->player[cardinal][animate_idx].height);
	if (!c->player[cardinal][animate_idx].ptr)
		return (EXIT_FAILURE);
	c->player[cardinal][animate_idx].addr = (uint32_t *)mlx_get_data_addr(
			c->player[cardinal][animate_idx].ptr,
			(int *)&c->player[cardinal][animate_idx].bpp,
			(int *)&c->player[cardinal][animate_idx].line_len,
			(int *)&c->player[cardinal][animate_idx].endian);
	if (!c->player[cardinal][animate_idx].addr)
		return (EXIT_FAILURE);
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
	t_uint	animate_idx;

	cardinal = EAST;
	while (cardinal <= SOUTH_EAST)
	{
		animate_idx = 0U;
		while (animate_idx < ANIMATE_CNT)
		{
			if (__load_one(c, x, cardinal, animate_idx))
				return (*ret = MLX_ERR);
			++animate_idx;
		}
		++cardinal;
	}
	return (*ret = SUCCESS);
}
