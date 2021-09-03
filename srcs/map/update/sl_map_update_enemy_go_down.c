/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_update_enemy_go_down.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 02:42:04 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/03 03:19:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "type/t_map.h"
#include "enum/e_map_char.h"

/*
**	make down char becoming an enemy_down
**	make enemy char becoming a floor/exit
*/
void	sl_map_update_enemy_go_down(t_huint enemy_idx, char *const down)
{
	t_map *const	map = sl_map();

	if (enemy_idx == map->idx_exit)
		map->ptr[enemy_idx] = MAP_CHAR[EXIT];
	else
		map->ptr[enemy_idx] = MAP_CHAR[FLOOR];
	*down = ENEMY_DOWN;
}
