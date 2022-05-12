/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_action.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:50:16 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/13 00:18:20 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_ACTION_H
# define LOOKUP_ACTION_H

# include <stdint.h>
# include "t_game.h"
# include "e_action.h"

typedef struct s_action	t_action;
typedef void			(*t_player_fct)(
	t_game *const g,
	t_config const *const c);
typedef void			(*t_enemy_fct)(
	t_game *const g,
	t_config const *const c,
	t_enemy *const e);

struct s_action
{
	uint8_t const		mask;
	t_player_fct const	p_fct;
	t_enemy_fct const	e_fct;
};

static t_action const	g_action[] = {
{1 << MOVE_EAST, game_player_move_east, game_enemy_move_east},
{1 << MOVE_NORTH, game_player_move_north, game_enemy_move_north},
{1 << MOVE_WEST, game_player_move_west, game_enemy_move_west},
{1 << MOVE_SOUTH, game_player_move_south, game_enemy_move_south},
{1 << MOVE_EAST | 1 << MOVE_NORTH, game_player_move_east_north, NULL},
{1 << MOVE_NORTH | 1 << MOVE_WEST, game_player_move_north_west, NULL},
{1 << MOVE_WEST | 1 << MOVE_SOUTH, game_player_move_west_south, NULL},
{1 << MOVE_SOUTH | 1 << MOVE_EAST, game_player_move_south_east, NULL},
{0}
};

#endif
