/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 00:52:30 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 20:19:07 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "block_draw_lookup.h"
#include "type/t_map.h"
#include "enum/e_ret.h"

/*
**	draw the image related to 'c' to window
**	at its [x][y] position related to its idx
*/
int	sl_block_draw(t_huint idx, char const c)
{
	t_map *const	map = sl_map();
	t_huint const	x = idx % map->width;
	t_huint const	y = idx / map->width;
	int				i;

	i = 0;
	while (g_block_draw[i].f && c != g_block_draw[i].c)
		++i;
	if (g_block_draw[i].f)
		return (g_block_draw[i].f(x, y));
	return (SUCCESS);
}
