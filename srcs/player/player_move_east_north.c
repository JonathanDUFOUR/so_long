/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_east_north.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:47:14 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/24 16:27:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_config.h"
#include "t_map.h"
#include "t_player.h"
#include "e_cardinal.h"

/* DBG */
#include <stdio.h>

void	player_move_east_north(
	t_player *const p,
	t_map *const m,
	t_config const *const c)
{
	fprintf(stderr, "%s\n", __func__);
	p->img = &c->player[EAST_NORTH][p->animate_idx];
	player_print(p);
}
