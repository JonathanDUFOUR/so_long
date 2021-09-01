/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 23:21:23 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/01 20:19:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "type/t_map.h"
#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	draw the moves count to the window
**	draw the entiere map to the window using images loaded in block
*/
int	sl_map_draw(void)
{
	t_map *const	map = sl_map();
	char const		*ptr = map->ptr;
	int				ret;

	ret = sl_step_draw_title();
	ret = sl_step_draw_count(0x00FFFFFF);
	while (*ptr && ret == SUCCESS)
	{
		ret = sl_block_draw(ptr - map->ptr, *ptr);
		++ptr;
	}
	return (ret);
}
