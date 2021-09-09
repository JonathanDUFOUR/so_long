/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_redraw_enemy_up.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 03:53:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/03 04:58:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "type/t_map.h"
#include "type/t_block.h"
#include "enum/e_map_char.h"
#include "enum/e_ret.h"

/*
**	redraw the enemy_up image to window
**	at its [x][y] position related to its idx
*/
int	sl_block_redraw_enemy_up(t_huint idx_enemy)
{
	t_map *const	map = sl_map();
	int const		idx_old = idx_enemy + map->width;
	char const		old = map->ptr[idx_old];
	int				ret;

	ret = sl_block_draw(idx_old, old);
	if (ret == SUCCESS)
		ret = sl_block_draw(idx_enemy, MAP_CHAR[ENEMY_UP]);
	return (ret);
}