/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_load_enemy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:18:29 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/11 21:50:28 by jodufour         ###   ########.fr       */
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
	c->enemy[cardinal][animate_idx].ptr = mlx_xpm_file_to_image(
			x->mlx,
			(char *)g_xpm_enemy[cardinal][animate_idx],
			(int *)&c->enemy[cardinal][animate_idx].width,
			(int *)&c->enemy[cardinal][animate_idx].height);
	if (!c->enemy[cardinal][animate_idx].ptr)
		return (EXIT_FAILURE);
	c->enemy[cardinal][animate_idx].addr = (uint32_t *)mlx_get_data_addr(
			c->enemy[cardinal][animate_idx].ptr,
			(int *)&c->enemy[cardinal][animate_idx].bpp,
			(int *)&c->enemy[cardinal][animate_idx].line_len,
			(int *)&c->enemy[cardinal][animate_idx].endian);
	if (!c->enemy[cardinal][animate_idx].addr)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

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
	t_uint	idx;

	cardinal = EAST;
	while (cardinal <= SOUTH)
	{
		idx = 0U;
		while (g_xpm_enemy[cardinal][idx])
		++cardinal;
	}
	return (*ret = SUCCESS);
}
