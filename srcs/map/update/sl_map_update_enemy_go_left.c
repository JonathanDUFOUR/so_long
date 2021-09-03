/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_update_enemy_go_left.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 02:33:25 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/03 03:19:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "type/t_map.h"
#include "enum/e_map_char.h"

/*
**	make left char becoming an enemy_left
**	make enemy char becoming a floor/exit
*/
void	sl_map_update_enemy_go_left(t_huint enemy_idx, char *const left)
{
	t_map *const	map = sl_map();

	if (enemy_idx == map->idx_exit)
		map->ptr[enemy_idx] = MAP_CHAR[EXIT];
	else
		map->ptr[enemy_idx] = MAP_CHAR[FLOOR];
	*left = MAP_CHAR[ENEMY_LEFT];
}
