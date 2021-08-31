/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_draw_lookup.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 22:41:27 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 23:11:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_DRAW_LOOKUP_H
# define PLAYER_DRAW_LOOKUP_H

# include <stddef.h>
# include "type/t_int.h"
# include "enum/e_direction.h"

typedef struct s_player_draw	t_player_draw;

struct s_player_draw
{
	t_hhuint	direction;
	int			(*f)(t_huint x, t_huint y);
};

int	sl_block_draw_player_down(t_huint x, t_huint y);
int	sl_block_draw_player_left(t_huint x, t_huint y);
int	sl_block_draw_player_right(t_huint x, t_huint y);
int	sl_block_draw_player_up(t_huint x, t_huint y);

static t_player_draw const		g_player_draw[] = {
	{DOWN, sl_block_draw_player_down},
	{LEFT, sl_block_draw_player_left},
	{RIGHT, sl_block_draw_player_right},
	{UP, sl_block_draw_player_up},
	{0, NULL}
};

#endif
