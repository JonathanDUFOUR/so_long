/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_event_move_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 01:34:19 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/02 07:47:40 by jodufour         ###   ########.fr       */
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
**	move player up
**	update map data
**	redraw map
*/
int	sl_event_move_up(void)
{
	t_map *const	map = sl_map();
	char *const		player = map->ptr + map->idx_player;
	char *const		up = player - map->width;
	int				ret;

	map->direction_player = UP;
	if (*up != MAP_CHAR[WALL])
	{
		if (*up == MAP_CHAR[ENEMY_DOWN] || *up == MAP_CHAR[ENEMY_LEFT]
			|| *up == MAP_CHAR[ENEMY_RIGHT] || *up == MAP_CHAR[ENEMY_UP])
			sl_game_over(RED ">>> FAILURE <<<" WHITE);
		sl_map_update(player, up, map->idx_player - map->width);
		ret = sl_map_redraw(player - map->ptr, up - map->ptr);
		if (ret == SUCCESS)
			ret = sl_step_update();
	}
	else
		ret = sl_block_draw(map->idx_player, *player);
	if (map->idx_player == map->idx_exit && !map->count.collect)
		sl_game_over(GREEN ">>> SUCCESS <<<" WHITE);
	return (ret);
}
