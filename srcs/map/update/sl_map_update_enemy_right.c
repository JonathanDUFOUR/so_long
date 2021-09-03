/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_update_enemy_right.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 22:58:30 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/03 03:11:58 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "so_long.h"
#include "type/t_map.h"
#include "enum/e_map_char.h"

/*
**	update the position and the direction of the enemy at enemy_idx
**	according to its current direction
*/
void	sl_map_update_enemy_right(t_huint enemy_idx)
{
	t_map *const	map = sl_map();
	char *const		right = map->ptr + enemy_idx + 1;
	char *const		left = map->ptr + enemy_idx - 1;

	if (*right == MAP_CHAR[PLAYER])
		sl_game_over(RED DEFEAT_MSG WHITE);
	else if (*right == MAP_CHAR[FLOOR] || *right == MAP_CHAR[EXIT])
		sl_map_update_enemy_go_right(enemy_idx, right);
	else if (*left == MAP_CHAR[PLAYER])
		sl_game_over(RED DEFEAT_MSG WHITE);
	else if (*left == MAP_CHAR[FLOOR] || *left == MAP_CHAR[EXIT])
		sl_map_update_enemy_go_left(enemy_idx, left);
	else
		map->ptr[enemy_idx] = MAP_CHAR[ENEMY_LEFT];
}
