/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_north.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:48:12 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 08:52:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "settings.h"
#include "t_config.h"
#include "t_map.h"
#include "t_player.h"
#include "e_axis.h"
#include "e_cardinal.h"
#include "e_map_char.h"

/* DBG */
#include <stdio.h>

void	player_move_north(
	t_player *const p,
	t_map *const m,
	t_config const *const c)
{
	t_uint	axis[2];

	fprintf(stderr, "%s\n", __func__);
	p->img = &c->player[NORTH][p->animate_idx];
	axis[X] = p->axis[X] / IMG_W;
	axis[Y] = (p->axis[Y] - PLAYER_SPEED) / IMG_H;
	if (m->ptr[axis[X] + axis[Y] * m->width] == MAP_CHAR[WALL])
	{
		p->axis[Y] -= fabs((axis[Y] + 1) * IMG_H - p->axis[Y]) - 0.01;
		p->distance += fabs((axis[Y] + 1) * IMG_H - p->axis[Y]) - 0.01;
	}
	else
	{
		p->axis[Y] -= PLAYER_SPEED;
		p->distance += PLAYER_SPEED;
	}
	printf("p->axis: {%f, %f}\n", p->axis[X], p->axis[Y]);
}
