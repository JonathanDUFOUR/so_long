/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_load_enemy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:18:29 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/12 11:46:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "settings.h"
#include "t_config.h"
#include "e_cardinal.h"
#include "e_ret.h"

/**
	@brief	Load the enemy images
			and store them in the given configuration structure.

	@param	c The configuration structure to fill.
	@param	x The xptr structure to use for image creation.
	@param	ret The profgram status reference.

	@return	The updated program status.
*/
int	config_load_enemy(t_config *const c, t_xptr const *const x, int *const ret)
{
	t_uint	cardinal;

	cardinal = EAST;
	while (cardinal <= SOUTH)
	{
		c->enemy[cardinal].ptr = mlx_xpm_file_to_image(
				x->mlx,
				(char *)g_xpm_enemy[cardinal],
				(int *)&c->enemy[cardinal].width,
				(int *)&c->enemy[cardinal].height);
		if (!c->enemy[cardinal].ptr)
			return (*ret = MLX_ERR);
		c->enemy[cardinal].addr = (uint32_t *)mlx_get_data_addr(
				c->enemy[cardinal].ptr,
				(int *)&c->enemy[cardinal].bpp,
				(int *)&c->enemy[cardinal].line_len,
				(int *)&c->enemy[cardinal].endian);
		if (!c->enemy[cardinal].addr)
			return (*ret = MLX_ERR);
		++cardinal;
	}
	return (*ret = SUCCESS);
}
