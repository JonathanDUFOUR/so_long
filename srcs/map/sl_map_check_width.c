/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_check_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 19:59:34 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/29 20:48:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "type/t_map.h"
#include "enum/e_ret.h"

/*
**	check width of a parsed map line
*/
int	sl_map_check_width(char const *line)
{
	t_map *const	map = sl_map();
	size_t const	len = ft_strlen(line);

	if (!map->w)
		map->w = len;
	else if (map->w != len)
		return (MAP_ERR);
	return (SUCCESS);
}
