/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_interact_tile.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:42:04 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/03 00:39:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "settings.h"
#include "t_player.h"
#include "e_axis.h"
#include "e_map_char.h"

/**
	@brief	Make the player interact with the tile at the given axis,
			updating the player's and map's data accordingly.

	@param	p The player structure to update.
	@param	m The map structure to update.
	@param	c The configuration structure containing the tiles images.
	@param	axis The axis of the tile to interact with.
*/
void	player_interact_tile(
	t_player *const p,
	t_map *const m,
	t_config const *const c,
	t_uint const axis[2])
{
	if (m->ptr[axis[X] + axis[Y] * m->width] == MAP_CHAR[COLLECT])
	{
		m->ptr[axis[X] + axis[Y] * m->width] = MAP_CHAR[FLOOR];
		img_fill_img(
			&m->maxi,
			&c->floor,
			axis[X] * IMG_W + axis[Y] * IMG_H * m->maxi.width);
		--m->collect_cnt;
	}
	else if (!m->collect_cnt
		&& m->ptr[axis[X] + axis[Y] * m->width] == MAP_CHAR[EXIT])
		p->is_exited = true;
}
