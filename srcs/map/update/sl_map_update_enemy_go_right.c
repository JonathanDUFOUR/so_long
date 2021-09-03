/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_update_enemy_go_right.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 02:32:15 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/03 03:20:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "type/t_map.h"
#include "enum/e_map_char.h"

/*
**	make right char becoming an enemy_right
**	make enemy char becoming a floor/exit
*/
void	sl_map_update_enemy_go_right(t_huint enemy_idx, char *const right)
{
	t_map *const	map = sl_map();

	if (enemy_idx == map->idx_exit)
		map->ptr[enemy_idx] = MAP_CHAR[EXIT];
	else
		map->ptr[enemy_idx] = MAP_CHAR[FLOOR];
	*right = ENEMY_RIGHT;
}
