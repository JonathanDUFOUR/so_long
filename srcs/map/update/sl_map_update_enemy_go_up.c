/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_update_enemy_go_up.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 02:44:07 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/03 03:20:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "type/t_map.h"
#include "enum/e_map_char.h"

/*
**	make up char becoming an enemy_up
**	make enemy char becoming a floor/exit
*/
void	sl_map_update_enemy_go_up(t_huint enemy_idx, char *const up)
{
	t_map *const	map = sl_map();

	if (enemy_idx == map->idx_exit)
		map->ptr[enemy_idx] = MAP_CHAR[EXIT];
	else
		map->ptr[enemy_idx] = MAP_CHAR[FLOOR];
	*up = MAP_CHAR[ENEMY_UP];
}
