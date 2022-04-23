/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_north.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:48:12 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/23 22:25:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_map.h"
#include "t_player.h"

/* DBG */
#include <stdio.h>

void	player_move_north(t_player *const p, t_map *const m)
{
	fprintf(stderr, "%s\n", __func__);
	player_print(p);
}
