/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_north.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:48:12 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/03 00:31:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "settings.h"
#include "t_config.h"
#include "t_map.h"
#include "t_player.h"
#include "e_axis.h"
#include "e_cardinal.h"
#include "e_map_char.h"

static inline void	__init(
	t_player *const p,
	t_config const *const c,
	t_uint hit[2][2])
{
	p->img = &c->player[NORTH][p->animate_idx];
	hit[0][X] = (p->axis[X] + HITBOX_W) / IMG_W;
	hit[0][Y] = (p->axis[Y] - HITBOX_H - PLAYER_SPEED) / IMG_H;
	hit[1][X] = (p->axis[X] - HITBOX_W) / IMG_W;
	hit[1][Y] = (p->axis[Y] - HITBOX_H - PLAYER_SPEED) / IMG_H;
}

/**
	@brief	Move the given player to its north axis if available.
			Update the data of the given player accordingly.

	@param	p The player structure to update.
	@param	m The map structure to check walls.
	@param	c The configuration structure to load the current player image.
*/
void	player_move_north(
	t_player *const p,
	t_map *const m,
	t_config const *const c)
{
	t_uint	hit[2][2];

	__init(p, c, hit);
	if (m->ptr[hit[0][X] + hit[0][Y] * m->width] != MAP_CHAR[WALL] && \
		m->ptr[hit[1][X] + hit[1][Y] * m->width] != MAP_CHAR[WALL])
	{
		p->axis[Y] -= PLAYER_SPEED;
		p->distance += PLAYER_SPEED;
		player_interact_tile(p, m, c, hit[0]);
		player_interact_tile(p, m, c, hit[1]);
	}
}
