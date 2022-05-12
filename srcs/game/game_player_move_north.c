/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_player_move_north.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:48:12 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/13 01:14:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_game.h"
#include "e_axis.h"
#include "e_cardinal.h"
#include "e_map_char.h"

static inline void	__init(
	t_player *const p,
	t_config const *const c,
	t_uint hit[2][2])
{
	if (p->prev_action_field != p->action_field)
		p->anim = c->player[NORTH].head;
	p->prev_action_field = p->action_field;
	hit[0][X] = (p->axis[X] + HITBOX) / IMG_W;
	hit[0][Y] = (p->axis[Y] - HITBOX - PLAYER_SPEED) / IMG_H;
	hit[1][X] = (p->axis[X] - HITBOX) / IMG_W;
	hit[1][Y] = (p->axis[Y] - HITBOX - PLAYER_SPEED) / IMG_H;
}

/**
	@brief	Move the player to its north axis if available.
			Update the data of the given game accordingly.

	@param	g The game structure to update.
	@param	c The configuration structure to load the current player image.
*/
void	game_player_move_north(t_game *const g, t_config const *const c)
{
	t_uint	hit[2][2];

	__init(&g->p, c, hit);
	if (g->m.ptr[hit[0][X] + hit[0][Y] * g->m.width] != MAP_CHAR[WALL] && \
		g->m.ptr[hit[1][X] + hit[1][Y] * g->m.width] != MAP_CHAR[WALL])
	{
		g->p.axis[Y] -= PLAYER_SPEED;
		g->p.distance += PLAYER_SPEED;
		game_player_interact_tile(g, c, hit[0]);
		game_player_interact_tile(g, c, hit[1]);
	}
}
