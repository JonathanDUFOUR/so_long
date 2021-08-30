/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_check_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 03:46:22 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/30 18:59:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "type/t_map.h"
#include "enum/e_map_char.h"
#include "enum/e_ret.h"

/*
**	check map chars
**	return an error if at least one of the following:
**		collect count == 0
**		player count != 1
**		exit count != 1
**		there is a unrecognized char in map
*/
int	sl_map_check_chars(void)
{
	t_map *const	map = sl_map();
	char const		*e = map->e;

	while (*e)
	{
		if (*e == MAP_CHAR[COLLECT])
			++map->cnt_c;
		else if (*e == MAP_CHAR[EXIT])
		{
			map->idx_e = e - map->e;
			++map->cnt_e;
		}
		else if (*e == MAP_CHAR[PLAYER])
		{
			map->idx_p = e - map->e;
			++map->cnt_p;
		}
		else if (*e != MAP_CHAR[WALL] && *e != MAP_CHAR[FLOOR])
			return (MAP_ERR);
		++e;
	}
	if (!map->cnt_c || map->cnt_e != 1 || map->cnt_p != 1)
		return (MAP_ERR);
	return (SUCCESS);
}
