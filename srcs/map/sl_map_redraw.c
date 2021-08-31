/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_redraw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 04:49:36 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 05:03:22 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_map.h"
#include "type/t_block.h"
#include "enum/e_ret.h"

int	sl_map_redraw(t_uint old_idx, t_uint new_idx)
{
	t_map *const	map = sl_map();
	char const		*e = map->e;
	int				ret;

	ret = sl_block_draw(old_idx, e[old_idx]);
	if (ret == SUCCESS)
		ret = sl_block_draw(new_idx, e[new_idx]);
	return (ret);
}
