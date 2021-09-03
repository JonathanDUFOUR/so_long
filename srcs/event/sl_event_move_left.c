/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_event_move_left.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 01:32:51 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/03 04:43:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "so_long.h"
#include "type/t_map.h"
#include "type/t_block.h"
#include "enum/e_direction.h"
#include "enum/e_map_char.h"
#include "enum/e_ret.h"

/*
**	move player left
**	update map data
**	redraw map
*/
int	sl_event_move_left(void)
{
	t_map *const	map = sl_map();
	char *const		player = map->ptr + map->idx_player;
	char *const		left = player - 1;
	int				ret;

	map->direction_player = LEFT;
	if (*left != MAP_CHAR[WALL])
	{
		if (sl_is_enemy(*left))
			sl_game_over(RED ">>> FAILURE <<<" WHITE);
		sl_map_update(player, left, map->idx_player - 1);
		ret = sl_map_redraw(player - map->ptr, left - map->ptr);
		if (ret == SUCCESS)
			ret = sl_step_update();
	}
	else
	{
		sl_map_update_enemy();
		ret = sl_block_redraw_enemy();
		if (ret == SUCCESS)
			ret = sl_block_draw(map->idx_player, *player);
	}
	if (map->idx_player == map->idx_exit && !map->count.collect)
		sl_game_over(GREEN ">>> SUCCESS <<<" WHITE);
	return (ret);
}
