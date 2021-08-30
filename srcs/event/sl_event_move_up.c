/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_event_move_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 01:34:19 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/30 20:04:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEBUG */
#include <stdio.h>
/*********/

#include "config.h"
#include "type/t_map.h"
#include "enum/e_map_char.h"
#include "enum/e_ret.h"

static void	sl_update(char *const player, char *const up)
{
	t_map *const	map = sl_map();

	if (map->idx_p == map->idx_e)
		*player = MAP_CHAR[EXIT];
	else
		*player = MAP_CHAR[FLOOR];
	*up = MAP_CHAR[PLAYER];
	map->idx_p -= map->w;
}

int	sl_event_move_up(void)
{
	t_map *const	map = sl_map();
	char *const		player = map->e + map->idx_p;
	char *const		up = player - map->w;

	printf("player moves up: ");
	if (*up != MAP_CHAR[WALL])
	{
		printf(GREEN "[OK]" WHITE "\n");
		sl_update(player, up);
	}
	else
	{
		printf(RED "[KO]" WHITE "\n");
	}
	sl_map_print();
	return (SUCCESS);
}
