/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_check_cep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 03:46:22 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/29 23:08:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "type/t_map.h"
#include "enum/e_map_char.h"
#include "enum/e_ret.h"

/*
**	check collect, player, and exit count in map
**	return an error if at least one of those have an invalid count
*/
int	sl_map_check_cep(void)
{
	t_map *const	map = sl_map();
	char const		*e = map->e;

	while (*e)
	{
		if (*e == MAP_CHAR[COLLECT])
			++map->cnt_c;
		else if (*e == MAP_CHAR[EXIT])
			++map->cnt_e;
		else if (*e == MAP_CHAR[PLAYER])
			++map->cnt_p;
		++e;
	}
	if (!map->cnt_c || map->cnt_e != 1 || map->cnt_p != 1)
		return (MAP_ERR);
	return (SUCCESS);
}
