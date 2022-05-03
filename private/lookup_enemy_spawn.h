/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_enemy_spawn.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:25:35 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/03 18:26:59 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_ENEMY_SPAWN_H
# define LOOKUP_ENEMY_SPAWN_H

# include <stdint.h>
# include "settings.h"
# include "e_action.h"
# include "e_map_char.h"

typedef struct s_enemy_spawn	t_enemy_spawn;

struct s_enemy_spawn
{
	char const		c;
	uint8_t const	mask;
};

static t_enemy_spawn const		g_enemy_spawn[] = {
{MAP_CHAR[ENEMY_EAST], 1 << MOVE_EAST},
{MAP_CHAR[ENEMY_NORTH], 1 << MOVE_NORTH},
{MAP_CHAR[ENEMY_WEST], 1 << MOVE_WEST},
{MAP_CHAR[ENEMY_SOUTH], 1 << MOVE_SOUTH},
{0}
};

#endif
