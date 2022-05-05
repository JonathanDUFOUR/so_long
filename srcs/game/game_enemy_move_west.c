/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enemy_move_west.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:24:47 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/05 00:37:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_game.h"
#include "e_action.h"
#include "e_axis.h"
#include "e_cardinal.h"
#include "e_map_char.h"

inline static void	__init(
	t_enemy *const e,
	t_config const *const c,
	t_uint hit[2][2])
{
	e->img = &c->enemy[WEST][e->animate_idx];
	hit[0][X] = (e->axis[X] - HITBOX - ENEMY_SPEED) / IMG_W;
	hit[0][Y] = (e->axis[Y] + HITBOX) / IMG_H;
	hit[1][X] = (e->axis[X] - HITBOX - ENEMY_SPEED) / IMG_W;
	hit[1][Y] = (e->axis[Y] - HITBOX) / IMG_H;
}

/**
	@brief	Move the given enemy to its west axis if available.
			Update the data of the given game accordingly.

	@param	g The game structure to update.
	@param	c The configuration structure to load the current enemy image.
	@param	e The enemy structure to update.
*/
void	game_enemy_move_west(
	t_game *const g,
	t_config const *const c,
	t_enemy *const e)
{
	t_uint	hit[2][2];

	__init(e, c, hit);
	if (g->m.ptr[hit[0][X] + hit[0][Y] * g->m.width] != MAP_CHAR[WALL] && \
		g->m.ptr[hit[1][X] + hit[1][Y] * g->m.width] != MAP_CHAR[WALL])
	{
		e->axis[X] -= ENEMY_SPEED;
	}
	else
	{
		e->action_field = 1 << MOVE_EAST;
	}
}
