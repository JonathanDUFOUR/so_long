/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 01:20:07 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/15 03:04:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "t_map.h"

static int	sl_check_cells(t_map map)
{
	int	exit;
	int	start;
	int	collect;

	start = 0;
	exit = 0;
	collect = 0;
	while (*map.elems)
	{
		if (*map.elems == MAP_CHAR[PLAYER])
			++start;
		else if (*map.elems == MAP_CHAR[COLLECT])
			++collect;
		else if (*map.elems == MAP_CHAR[EXIT])
			++exit;
		else if (*map.elems != MAP_CHAR[WALL] && *map.elems != MAP_CHAR[EMPTY])
			return (INVALID_MAP_ERRNO);
		++map.elems;
	}
	if (start != 1 || exit != 1 || !collect)
		return (INVALID_MAP_ERRNO);
	return (SUCCESS);
}

static int	sl_check_walls(t_map map)
{
	uint32_t	i;

	i = 0;
	while (i < map.w)
	{
		if (map.elems[i] != MAP_CHAR[WALL]
			|| map.elems[i + map.h * map.w - map.w] != MAP_CHAR[WALL])
			return (INVALID_MAP_ERRNO);
		++i;
	}
	i = 0;
	while (i < map.h)
	{
		if (map.elems[i * map.w] != MAP_CHAR[WALL]
			|| map.elems[map.w * (i + 1) - 1] != MAP_CHAR[WALL])
			return (INVALID_MAP_ERRNO);
		++i;
	}
	return (SUCCESS);
}

int	sl_check_map(t_map map)
{
	if (sl_check_cells(map) != SUCCESS || sl_check_walls(map) != SUCCESS)
		return (INVALID_MAP_ERRNO);
	return (SUCCESS);
}
