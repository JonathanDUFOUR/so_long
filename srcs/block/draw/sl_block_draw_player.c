/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_draw_player.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 22:37:53 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 23:11:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "player_draw_lookup.h"
#include "type/t_map.h"
#include "type/t_int.h"
#include "enum/e_ret.h"

/*
**	draw the player image loaded in block to window at position:
**	x * img_width
**	y * img_height
*/
int	sl_block_draw_player(t_huint x, t_huint y)
{
	t_hhuint const	direction = sl_map()->direction_player;
	int				i;

	i = 0;
	while (g_player_draw[i].f && direction != g_player_draw[i].direction)
		++i;
	if (g_player_draw[i].f)
		return (g_player_draw[i].f(x, y));
	return (SUCCESS);
}
