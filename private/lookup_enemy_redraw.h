/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_enemy_redraw.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 03:41:30 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 21:33:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_ENEMY_REDRAW_H
# define LOOKUP_ENEMY_REDRAW_H

# include <stddef.h>
# include "config.h"
# include "type/t_int.h"
# include "enum/e_map_char.h"

typedef struct s_enemy_redraw	t_enemy_redraw;

struct s_enemy_redraw
{
	char const	c;
	int			(*f)(t_huint idx_enemy);
};

int	sl_block_redraw_enemy_down(t_huint idx_enemy);
int	sl_block_redraw_enemy_left(t_huint idx_enemy);
int	sl_block_redraw_enemy_right(t_huint idx_enemy);
int	sl_block_redraw_enemy_up(t_huint idx_enemy);

static t_enemy_redraw const		g_enemy_redraw[] = {
{MAP_CHAR[ENEMY_DOWN], sl_block_redraw_enemy_down},
{MAP_CHAR[ENEMY_LEFT], sl_block_redraw_enemy_left},
{MAP_CHAR[ENEMY_RIGHT], sl_block_redraw_enemy_right},
{MAP_CHAR[ENEMY_UP], sl_block_redraw_enemy_up},
{0, NULL},
};

#endif
