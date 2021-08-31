/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 23:21:23 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 01:59:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "type/t_map.h"
#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	draw the entiere map to the window using images loaded in block
*/
int	sl_map_draw(void)
{
	t_map *const	map = sl_map();
	char const		*e = map->e;
	int				ret;

	ret = SUCCESS;
	while (*e && ret == SUCCESS)
	{
		ret = sl_block_draw(e - map->e, *e);
		++e;
	}
	return (ret);
}
