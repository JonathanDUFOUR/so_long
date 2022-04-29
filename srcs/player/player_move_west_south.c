/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_west_south.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:50:04 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/29 03:28:45 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_config.h"
#include "t_map.h"
#include "t_player.h"
#include "e_axis.h"
#include "e_cardinal.h"
#include "e_map_char.h"

/* DBG */
#include <stdio.h>

static double const	g_offset = 0.70710678118 * PLAYER_SPEED;

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
	t_uint	axis[2];

	fprintf(stderr, "%s\n", __func__);
	p->img = &c->player[WEST_SOUTH][p->animate_idx];
	axis[X] = (p->axis[X] - g_offset) / IMG_W;
	axis[Y] = (p->axis[Y] + g_offset) / IMG_H;
	if (m->ptr[axis[X] + (int)p->axis[Y] / IMG_H * m->width] != MAP_CHAR[WALL]
		&& \
		m->ptr[(int)p->axis[X] / IMG_W + axis[Y] * m->width] != MAP_CHAR[WALL]
		&& \
		m->ptr[axis[X] + axis[Y] * m->width] != MAP_CHAR[WALL])
	{
		p->axis[X] -= g_offset;
		p->axis[Y] += g_offset;
		p->distance += PLAYER_SPEED;
	}
	printf("p->axis: {%f, %f}\n", p->axis[X], p->axis[Y]);
}
