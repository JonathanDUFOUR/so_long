/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_east.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:43:35 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/24 16:26:28 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_config.h"
#include "t_map.h"
#include "t_player.h"
#include "e_cardinal.h"

/* DBG */
#include <stdio.h>

void	player_move_east(
	t_player *const p,
	t_map *const m,
	t_config const *const c)
{
	fprintf(stderr, "%s\n", __func__);
	p->img = &c->player[EAST][p->animate_idx];
	player_print(p);
}
