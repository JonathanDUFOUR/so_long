/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 00:34:27 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 20:27:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "type/t_map.h"
#include "enum/e_map_char.h"

/*
**	update map chars and player index
*/
void	sl_map_update(char *const player, char *const togo,
	t_huint new_idx_player)
{
	t_map *const	map = sl_map();

	if (map->idx_player == map->idx_exit)
		*player = MAP_CHAR[EXIT];
	else
		*player = MAP_CHAR[FLOOR];
	if (*togo == MAP_CHAR[COLLECT])
		--map->count.collect;
	*togo = MAP_CHAR[PLAYER];
	map->idx_player = new_idx_player;
}
