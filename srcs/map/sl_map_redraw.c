/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_redraw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 04:49:36 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 23:15:28 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_map.h"
#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	
*/
int	sl_map_redraw(t_huint old_idx, t_huint new_idx)
{
	t_map *const	map = sl_map();
	char const		*ptr = map->ptr;
	int				ret;

	ret = sl_block_draw(old_idx, ptr[old_idx]);
	if (ret == SUCCESS)
		ret = sl_block_draw(new_idx, ptr[new_idx]);
	return (ret);
}
