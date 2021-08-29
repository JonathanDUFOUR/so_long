/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_check_borders.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 04:36:30 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/29 20:48:14 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "config.h"
#include "type/t_map.h"
#include "enum/e_ret.h"
#include "enum/e_map_char.h"

/*
**	return true if map[idx] is a border
**	return false if it is not
*/
static bool	sl_is_border(t_uint idx, t_uint w, t_uint h)
{
	return (idx < w
		|| !(idx % w)
		|| idx % w == w - 1
		|| idx >= (h - 1) * w);
}

/*
**	check if borders are walls
*/
int	sl_map_check_borders(void)
{
	t_map *const	map = sl_map();
	char const		*e = map->e;

	while (*e)
	{
		if (sl_is_border(e - map->e, map->w, map->h) && *e != MAP_CHAR[WALL])
			return (MAP_ERR);
		++e;
	}
	return (SUCCESS);
}
