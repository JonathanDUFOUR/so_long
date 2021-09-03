/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_check_borders.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 04:36:30 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 20:21:16 by jodufour         ###   ########.fr       */
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
static bool	sl_is_border(t_huint idx, t_huint width, t_huint height)
{
	return (idx < width
		|| !(idx % width)
		|| idx % width == width - 1
		|| idx >= (height - 1) * width);
}

/*
**	check if borders are walls
**	return an error if at least one is not
*/
int	sl_map_check_borders(void)
{
	t_map *const	map = sl_map();
	char const		*ptr = map->ptr;

	while (*ptr)
	{
		if (sl_is_border(ptr - map->ptr, map->width, map->height)
			&& *ptr != MAP_CHAR[WALL])
			return (MAP_ERR);
		++ptr;
	}
	return (SUCCESS);
}
