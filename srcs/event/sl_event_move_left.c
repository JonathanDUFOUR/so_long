/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_event_move_left.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 01:32:51 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/30 20:03:45 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEBUG */
#include <stdio.h>
/*********/

#include "config.h"
#include "type/t_map.h"
#include "enum/e_map_char.h"
#include "enum/e_ret.h"

static void	sl_update(char *const player, char *const left)
{
	t_map *const	map = sl_map();

	if (map->idx_p == map->idx_e)
		*player = MAP_CHAR[EXIT];
	else
		*player = MAP_CHAR[FLOOR];
	*left = MAP_CHAR[PLAYER];
	map->idx_p -= 1;
}

int	sl_event_move_left(void)
{
	t_map *const	map = sl_map();
	char *const		player = map->e + map->idx_p;
	char *const		left = player - 1;

	printf("player moves left: ");
	if (*left != MAP_CHAR[WALL])
	{
		printf(GREEN "[OK]" WHITE "\n");
		sl_update(player, left);
	}
	else
	{
		printf(RED "[KO]" WHITE "\n");
	}
	sl_map_print();
	return (SUCCESS);
}
