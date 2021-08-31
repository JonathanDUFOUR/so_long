/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_event_move_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 01:34:19 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 23:28:32 by jodufour         ###   ########.fr       */
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
**	move player up
**	update map data
**	redraw map
*/
int	sl_event_move_up(void)
{
	t_uint *const	step = sl_step();
	t_map *const	map = sl_map();
	char *const		player = map->ptr + map->idx_player;
	char *const		up = player - map->width;
	int				ret;

	map->direction_player = UP;
	ret = SUCCESS;
	if (*up != MAP_CHAR[WALL])
	{
		sl_map_update(player, up, map->idx_player - map->width);
		ret = sl_map_redraw(player - map->ptr, up - map->ptr);
		++*step;
		printf("Moves done: %u\n", *step);
	}
	else
		ret = sl_block_draw(map->idx_player, *player);
	if (map->idx_player == map->idx_exit && !map->count.collect)
		sl_game_over("Victory !\n");
	return (ret);
}
