/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_load_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:20:01 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/12 11:47:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "settings.h"
#include "t_config.h"
#include "e_cardinal.h"
#include "e_ret.h"

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

	cardinal = EAST;
	while (cardinal <= SOUTH_EAST)
	{
		c->player[cardinal].ptr = mlx_xpm_file_to_image(
				x->mlx,
				(char *)g_xpm_player[cardinal],
				(int *)&c->player[cardinal].width,
				(int *)&c->player[cardinal].height);
		if (!c->player[cardinal].ptr)
			return (*ret = MLX_ERR);
		c->player[cardinal].addr = (uint32_t *)mlx_get_data_addr(
				c->player[cardinal].ptr,
				(int *)&c->player[cardinal].bpp,
				(int *)&c->player[cardinal].line_len,
				(int *)&c->player[cardinal].endian);
		if (!c->player[cardinal].addr)
			return (*ret = MLX_ERR);
		++cardinal;
	}
	return (*ret = SUCCESS);
}
