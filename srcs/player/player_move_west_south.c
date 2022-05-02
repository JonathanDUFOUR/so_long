/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_west_south.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:50:04 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/03 00:30:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_config.h"
#include "t_map.h"
#include "t_player.h"
#include "e_axis.h"
#include "e_cardinal.h"
#include "e_map_char.h"

static double const	g_offset = 0.70710678118 * PLAYER_SPEED;

inline static void	__init(
	t_player *const p,
	t_config const *const c,
	t_uint hit[3][2])
{
	p->img = &c->player[WEST_SOUTH][p->animate_idx];
	hit[0][X] = (p->axis[X] - HITBOX_W - g_offset) / IMG_W;
	hit[0][Y] = (p->axis[Y] - HITBOX_H + g_offset) / IMG_H;
	hit[1][X] = (p->axis[X] - HITBOX_W - g_offset) / IMG_W;
	hit[1][Y] = (p->axis[Y] + HITBOX_H + g_offset) / IMG_H;
	hit[2][X] = (p->axis[X] + HITBOX_W - g_offset) / IMG_W;
	hit[2][Y] = (p->axis[Y] + HITBOX_H + g_offset) / IMG_H;
}

/**
	@brief	Move the given player to its west south axis if available.
			Update the data of the given player accordingly.

	@param	p The player structure to update.
	@param	m The map structure to check walls.
	@param	c The configuration structure to load the current player image.
*/
void	player_move_west_south(
	t_player *const p,
	t_map *const m,
	t_config const *const c)
{
	t_uint	hit[3][2];

	__init(p, c, hit);
	if (m->ptr[hit[0][X] + hit[0][Y] * m->width] != MAP_CHAR[WALL] && \
		m->ptr[hit[1][X] + hit[1][Y] * m->width] != MAP_CHAR[WALL] && \
		m->ptr[hit[2][X] + hit[2][Y] * m->width] != MAP_CHAR[WALL])
	{
		p->axis[X] -= g_offset;
		p->axis[Y] += g_offset;
		p->distance += PLAYER_SPEED;
		player_interact_tile(p, m, c, hit[0]);
		player_interact_tile(p, m, c, hit[1]);
		player_interact_tile(p, m, c, hit[2]);
	}
}
