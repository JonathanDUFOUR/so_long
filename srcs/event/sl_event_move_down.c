/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_event_move_down.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 01:31:54 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 01:43:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEBUG */
#include <stdio.h>
/*********/

#include "config.h"
#include "so_long.h"
#include "type/t_map.h"
#include "enum/e_map_char.h"
#include "enum/e_ret.h"

/*
**	move player down
**	update map data
**	redraw map
*/
int	sl_event_move_down(void)
{
	t_map *const	map = sl_map();
	char *const		player = map->e + map->idx_p;
	char *const		down = player + map->w;

	printf("player moves down: ");
	if (*down != MAP_CHAR[WALL])
	{
		printf(GREEN "[OK]" WHITE "\n");
		sl_map_update(player, down, map->idx_p + map->w);
	}
	else
	{
		printf(RED "[KO]" WHITE "\n");
	}
	sl_map_print();
	if (map->idx_p == map->idx_e && !map->cnt_c)
		sl_game_over("Victory !\n");
	return (SUCCESS);
}
