/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_redraw_enemy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 04:22:35 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/03 04:59:03 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_map.h"
#include "enemy_redraw_lookup.h"
#include "enum/e_ret.h"

/*
**	redraw all enemies images to window at their new positions
*/
int	sl_block_redraw_enemy(void)
{
	t_map *const	map = sl_map();
	char const		*ptr = map->ptr;
	int				ret;
	int				i;

	ret = SUCCESS;
	while (*ptr && ret == SUCCESS)
	{
		i = 0;
		while (g_enemy_redraw[i].f && *ptr != g_enemy_redraw[i].c)
			++i;
		if (g_enemy_redraw[i].f)
			ret = g_enemy_redraw[i].f(ptr - map->ptr);
		++ptr;
	}
	return (ret);
}
