/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_check_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 19:59:34 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 19:33:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "type/t_map.h"
#include "enum/e_ret.h"

/*
**	check width of a parsed map line
**	return an error if the len is different from a previous len
*/
int	sl_map_check_width(char const *line)
{
	t_map *const	map = sl_map();
	size_t const	len = ft_strlen(line);

	if (!map->width)
		map->width = len;
	else if (map->width != len)
		return (MAP_ERR);
	return (SUCCESS);
}
