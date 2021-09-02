/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_draw_lookup.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 01:10:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/02 07:10:28 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOCK_DRAW_LOOKUP_H
# define BLOCK_DRAW_LOOKUP_H

# include <stddef.h>
# include "config.h"
# include "type/t_int.h"
# include "enum/e_map_char.h"

typedef struct s_block_draw	t_block_draw;

struct s_block_draw
{
	char const	c;
	int			(*f)(t_huint x, t_huint y);
};

int	sl_block_draw_collect(t_huint x, t_huint y);
int	sl_block_draw_enemy_down(t_huint x, t_huint y);
int	sl_block_draw_enemy_left(t_huint x, t_huint y);
int	sl_block_draw_enemy_right(t_huint x, t_huint y);
int	sl_block_draw_enemy_up(t_huint x, t_huint y);
int	sl_block_draw_exit(t_huint x, t_huint y);
int	sl_block_draw_floor(t_huint x, t_huint y);
int	sl_block_draw_player(t_huint x, t_huint y);
int	sl_block_draw_wall(t_huint x, t_huint y);

static t_block_draw const	g_block_draw[] = {
	{MAP_CHAR[COLLECT], sl_block_draw_collect},
	{MAP_CHAR[ENEMY_DOWN], sl_block_draw_enemy_down},
	{MAP_CHAR[ENEMY_LEFT], sl_block_draw_enemy_left},
	{MAP_CHAR[ENEMY_RIGHT], sl_block_draw_enemy_right},
	{MAP_CHAR[ENEMY_UP], sl_block_draw_enemy_up},
	{MAP_CHAR[EXIT], sl_block_draw_exit},
	{MAP_CHAR[FLOOR], sl_block_draw_floor},
	{MAP_CHAR[PLAYER], sl_block_draw_player},
	{MAP_CHAR[WALL], sl_block_draw_wall},
	{0, NULL}
};

#endif
