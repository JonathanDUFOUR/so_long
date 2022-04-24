/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_player_action.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:50:16 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/24 16:17:35 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_PLAYER_ACTION_H
# define LOOKUP_PLAYER_ACTION_H

# include <stdint.h>
# include "t_map.h"
# include "t_player.h"
# include "e_action.h"

typedef struct s_action	t_action;
typedef void			(*t_fct)(
	t_player *const p,
	t_map *const m,
	t_config const *const c);

struct s_action
{
	uint8_t const	mask;
	t_fct const		fct;
};

void	player_move_east(t_player *const p, t_map *const m,
			t_config const *const c)
		__attribute__((nonnull));
void	player_move_north(t_player *const p, t_map *const m,
			t_config const *const c)
		__attribute__((nonnull));
void	player_move_west(t_player *const p, t_map *const m,
			t_config const *const c)
		__attribute__((nonnull));
void	player_move_south(t_player *const p, t_map *const m,
			t_config const *const c)
		__attribute__((nonnull));
void	player_move_east_north(t_player *const p, t_map *const m,
			t_config const *const c)
		__attribute__((nonnull));
void	player_move_north_west(t_player *const p, t_map *const m,
			t_config const *const c)
		__attribute__((nonnull));
void	player_move_west_south(t_player *const p, t_map *const m,
			t_config const *const c)
		__attribute__((nonnull));
void	player_move_south_east(t_player *const p, t_map *const m,
			t_config const *const c)
		__attribute__((nonnull));

static t_action const	g_action[] = {
{1 << MOVE_EAST, player_move_east},
{1 << MOVE_NORTH, player_move_north},
{1 << MOVE_WEST, player_move_west},
{1 << MOVE_SOUTH, player_move_south},
{1 << MOVE_EAST | 1 << MOVE_NORTH, player_move_east_north},
{1 << MOVE_NORTH | 1 << MOVE_WEST, player_move_north_west},
{1 << MOVE_WEST | 1 << MOVE_SOUTH, player_move_west_south},
{1 << MOVE_SOUTH | 1 << MOVE_EAST, player_move_south_east},
{0}
};

#endif
