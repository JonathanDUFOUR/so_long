/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_event_move_left.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 01:32:51 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 05:07:43 by jodufour         ###   ########.fr       */
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
**	move player left
**	update map data
**	redraw map
*/
int	sl_event_move_left(void)
{
	t_uint *const	step = sl_step();
	t_map *const	map = sl_map();
	char *const		player = map->e + map->idx_p;
	char *const		left = player - 1;
	int				ret;

	ret = SUCCESS;
	if (*left != MAP_CHAR[WALL])
	{
		sl_map_update(player, left, map->idx_p - 1);
		ret = sl_map_redraw(player - map->e, left - map->e);
		++*step;
		printf("Moves done: %u\n", *step);
	}
	if (map->idx_p == map->idx_e && !map->cnt_c)
		sl_game_over("Victory !\n");
	return (ret);
}
