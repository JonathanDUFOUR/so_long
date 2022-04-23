/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_west_south.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:50:04 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/23 22:24:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_map.h"
#include "t_player.h"

/* DBG */
#include <stdio.h>

void	player_move_west_south(t_player *const p, t_map *const m)
{
	fprintf(stderr, "%s\n", __func__);
	player_print(p);
}
