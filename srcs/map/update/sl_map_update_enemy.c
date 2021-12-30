/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_update_enemy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 22:37:39 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 21:38:38 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "so_long.h"
#include "lookup_enemy_update.h"
#include "type/t_map.h"
#include "enum/e_map_char.h"

/*
**	update enemies positions and directions in map
**	trigger game over if at least one of them encounter the player
*/
void	sl_map_update_enemy(void)
{
	t_map *const	map = sl_map();
	char			*ptr;
	int				i;

	if ((*sl_sleep())++ % SLEEP_TIME)
		return ;
	ptr = map->ptr;
	while (*ptr)
	{
		i = 0;
		while (g_enemy_update[i].f && g_enemy_update[i].c != *ptr)
			++i;
		if (g_enemy_update[i].f)
			g_enemy_update[i].f(ptr - map->ptr);
		++ptr;
	}
	ptr = map->ptr;
	while (*ptr)
	{
		if (*ptr == ENEMY_DOWN)
			*ptr = MAP_CHAR[ENEMY_DOWN];
		if (*ptr == ENEMY_RIGHT)
			*ptr = MAP_CHAR[ENEMY_RIGHT];
		++ptr;
	}
}
