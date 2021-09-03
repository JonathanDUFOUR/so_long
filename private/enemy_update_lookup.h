/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_update_lookup.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 22:44:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/03 00:12:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_UPDATE_LOOKUP_H
# define ENEMY_UPDATE_LOOKUP_H

# include <stddef.h>
# include "config.h"
# include "type/t_int.h"
# include "enum/e_map_char.h"

typedef struct s_enemy_update	t_enemy_update;

struct s_enemy_update
{
	char const	c;
	void		(*f)(t_huint enemy_idx);
};

void	sl_map_update_enemy_down(t_huint enemy_idx);
void	sl_map_update_enemy_left(t_huint enemy_idx);
void	sl_map_update_enemy_right(t_huint enemy_idx);
void	sl_map_update_enemy_up(t_huint enemy_idx);

static t_enemy_update const		g_enemy_update[] = {
	{MAP_CHAR[ENEMY_DOWN], sl_map_update_enemy_down},
	{MAP_CHAR[ENEMY_LEFT], sl_map_update_enemy_left},
	{MAP_CHAR[ENEMY_RIGHT], sl_map_update_enemy_right},
	{MAP_CHAR[ENEMY_UP], sl_map_update_enemy_up},
	{0, NULL}
};

#endif
