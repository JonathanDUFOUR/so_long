/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 00:34:27 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 00:39:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "type/t_map.h"
#include "enum/e_map_char.h"

void	sl_map_update(char *const player, char *const togo, t_uint new_idx_p)
{
	t_map *const	map = sl_map();

	if (map->idx_p == map->idx_e)
		*player = MAP_CHAR[EXIT];
	else
		*player = MAP_CHAR[FLOOR];
	if (*togo == MAP_CHAR[COLLECT])
		--map->cnt_c;
	*togo = MAP_CHAR[PLAYER];
	map->idx_p = new_idx_p;
}
