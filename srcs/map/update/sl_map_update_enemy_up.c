/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_update_enemy_up.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 23:24:03 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/03 03:12:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "so_long.h"
#include "type/t_map.h"
#include "enum/e_map_char.h"

/*
**	update the position and the direction of the enemy at enemy_idx
**	accordint to its current direction
*/
void	sl_map_update_enemy_up(t_huint enemy_idx)
{
	t_map *const	map = sl_map();
	char *const		up = map->ptr + enemy_idx - map->width;
	char *const		down = map->ptr + enemy_idx + map->width;

	if (*up == MAP_CHAR[PLAYER])
		sl_game_over(RED DEFEAT_MSG WHITE);
	else if (*up == MAP_CHAR[FLOOR] || *up == MAP_CHAR[EXIT])
		sl_map_update_enemy_go_up(enemy_idx, up);
	else if (*down == MAP_CHAR[PLAYER])
		sl_game_over(RED DEFEAT_MSG WHITE);
	else if (*down == MAP_CHAR[FLOOR] || *down == MAP_CHAR[EXIT])
		sl_map_update_enemy_go_down(enemy_idx, down);
	else
		map->ptr[enemy_idx] = MAP_CHAR[ENEMY_DOWN];
}
