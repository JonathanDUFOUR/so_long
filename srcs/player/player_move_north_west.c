/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_north_west.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:48:58 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/23 22:25:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_map.h"
#include "t_player.h"

/* DBG */
#include <stdio.h>

void	player_move_north_west(t_player *const p, t_map *const m)
{
	fprintf(stderr, "%s\n", __func__);
	player_print(p);
}
