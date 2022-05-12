/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_player_move_west_south.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:50:04 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/13 01:13:22 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_game.h"
#include "e_axis.h"
#include "e_cardinal.h"
#include "e_map_char.h"

static double const	g_offset = 0.70710678118 * PLAYER_SPEED;

inline static void	__init(
	t_player *const p,
	t_config const *const c,
	t_uint hit[3][2])
{
	if (p->prev_action_field != p->action_field)
		p->anim = c->player[WEST_SOUTH].head;
	p->prev_action_field = p->action_field;
	hit[0][X] = (p->axis[X] - HITBOX - g_offset) / IMG_W;
	hit[0][Y] = (p->axis[Y] - HITBOX + g_offset) / IMG_H;
	hit[1][X] = (p->axis[X] - HITBOX - g_offset) / IMG_W;
	hit[1][Y] = (p->axis[Y] + HITBOX + g_offset) / IMG_H;
	hit[2][X] = (p->axis[X] + HITBOX - g_offset) / IMG_W;
	hit[2][Y] = (p->axis[Y] + HITBOX + g_offset) / IMG_H;
}

/**
	@brief	Move the player to its west south axis if available.
			Update the data of the given game accordingly.

	@param	g The game structure to update.
	@param	c The configuration structure to load the current player image.
*/
void	game_player_move_west_south(t_game *const g, t_config const *const c)
{
	t_uint	hit[3][2];

	__init(&g->p, c, hit);
	if (g->m.ptr[hit[0][X] + hit[0][Y] * g->m.width] != MAP_CHAR[WALL] && \
		g->m.ptr[hit[1][X] + hit[1][Y] * g->m.width] != MAP_CHAR[WALL] && \
		g->m.ptr[hit[2][X] + hit[2][Y] * g->m.width] != MAP_CHAR[WALL])
	{
		g->p.axis[X] -= g_offset;
		g->p.axis[Y] += g_offset;
		g->p.distance += PLAYER_SPEED;
		game_player_interact_tile(g, c, hit[0]);
		game_player_interact_tile(g, c, hit[1]);
		game_player_interact_tile(g, c, hit[2]);
	}
}
