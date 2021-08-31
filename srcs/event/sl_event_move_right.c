/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_event_move_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 01:33:43 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 23:28:08 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEBUG */
#include <stdio.h>
/*********/

#include "config.h"
#include "so_long.h"
#include "type/t_map.h"
#include "type/t_block.h"
#include "enum/e_direction.h"
#include "enum/e_map_char.h"
#include "enum/e_ret.h"

/*
**	move player right
**	update map data
**	redraw map
*/
int	sl_event_move_right(void)
{
	t_uint *const	step = sl_step();
	t_map *const	map = sl_map();
	char *const		player = map->ptr + map->idx_player;
	char *const		right = player + 1;
	int				ret;

	map->direction_player = RIGHT;
	ret = SUCCESS;
	if (*right != MAP_CHAR[WALL])
	{
		sl_map_update(player, right, map->idx_player + 1);
		ret = sl_map_redraw(player - map->ptr, right - map->ptr);
		++*step;
		printf("Moves done: %u\n", *step);
	}
	else
		ret = sl_block_draw(map->idx_player, *player);
	if (map->idx_player == map->idx_exit && !map->count.collect)
		sl_game_over("Victory !\n");
	return (ret);
}
