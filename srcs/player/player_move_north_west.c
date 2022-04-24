/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_north_west.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:48:58 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/24 16:27:38 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_config.h"
#include "t_map.h"
#include "t_player.h"
#include "e_cardinal.h"

/* DBG */
#include <stdio.h>

void	player_move_north_west(
	t_player *const p,
	t_map *const m,
	t_config const *const c)
{
	fprintf(stderr, "%s\n", __func__);
	p->img = &c->player[NORTH_WEST][p->animate_idx];
	player_print(p);
}
