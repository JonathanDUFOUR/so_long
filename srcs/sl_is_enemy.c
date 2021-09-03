/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_is_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 04:40:35 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/03 04:41:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "config.h"
#include "enum/e_map_char.h"

bool	sl_is_enemy(char const c)
{
	return (c == MAP_CHAR[ENEMY_DOWN]
		|| c == MAP_CHAR[ENEMY_LEFT]
		|| c == MAP_CHAR[ENEMY_RIGHT]
		|| c == MAP_CHAR[ENEMY_UP]);
}
