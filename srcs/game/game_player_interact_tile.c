/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_player_interact.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:42:04 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/03 23:45:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_game.h"
#include "e_axis.h"
#include "e_map_char.h"

/**
	@brief	Make the player interact with the tile at the given axis,
			updating the player's and map's data accordingly.

	@param	g The game structure to update.
	@param	c The configuration structure containing the tiles images.
	@param	axis The axis of the tile to interact with.
*/
void	game_player_interact_tile(
	t_game *const g,
	t_config const *const c,
	t_uint const axis[2])
{
	if (g->m.ptr[axis[X] + axis[Y] * g->m.width] == MAP_CHAR[COLLECT])
	{
		g->m.ptr[axis[X] + axis[Y] * g->m.width] = MAP_CHAR[FLOOR];
		img_fill_img(
			&g->m.maxi,
			&c->floor,
			axis[X] * IMG_W + axis[Y] * IMG_H * g->m.maxi.width);
		--g->m.collect_cnt;
	}
	else if (!g->m.collect_cnt
		&& g->m.ptr[axis[X] + axis[Y] * g->m.width] == MAP_CHAR[EXIT])
		g->p.is_exited = true;
}
