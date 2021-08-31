/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_event_move_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 01:33:43 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 01:44:14 by jodufour         ###   ########.fr       */
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
**	move player right
**	update map data
**	redraw map
*/
int	sl_event_move_right(void)
{
	t_map *const	map = sl_map();
	char *const		player = map->e + map->idx_p;
	char *const		right = player + 1;

	printf("player moves right: ");
	if (*right != MAP_CHAR[WALL])
	{
		printf(GREEN "[OK]" WHITE "\n");
		sl_map_update(player, right, map->idx_p + 1);
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
