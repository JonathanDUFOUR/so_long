/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 05:49:15 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/06 23:58:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_GAME_H
# define T_GAME_H

# include "t_enemy_lst.h"
# include "t_map.h"
# include "t_player.h"

typedef struct s_game	t_game;

struct s_game
{
	t_enemy_lst	el;
	t_map		m;
	t_player	p;
	t_img		pplane;
};

int		game_init(t_game *const g, t_xptr const *const x,
			t_config const *const c, int *const ret)
		__attribute__((nonnull));
int		game_pplane_init(t_game *const g, t_xptr const *const x, int *const ret)
		__attribute__((nonnull));

void	game_clear(t_game *const g, t_xptr const *const x)
		__attribute__((nonnull));
void	game_enemy_move_east(t_game *const g, t_config const *const c,
			t_enemy *const e)
		__attribute__((nonnull));
void	game_enemy_move_north(t_game *const g, t_config const *const c,
			t_enemy *const e)
		__attribute__((nonnull));
void	game_enemy_move_west(t_game *const g, t_config const *const c,
			t_enemy *const e)
		__attribute__((nonnull));
void	game_enemy_move_south(t_game *const g, t_config const *const c,
			t_enemy *const e)
		__attribute__((nonnull));
void	game_enemy_move_east_north(t_game *const g, t_config const *const c,
			t_enemy *const e)
		__attribute__((nonnull));
void	game_enemy_move_north_west(t_game *const g, t_config const *const c,
			t_enemy *const e)
		__attribute__((nonnull));
void	game_enemy_move_west_south(t_game *const g, t_config const *const c,
			t_enemy *const e)
		__attribute__((nonnull));
void	game_enemy_move_south_east(t_game *const g, t_config const *const c,
			t_enemy *const e)
		__attribute__((nonnull));
void	game_player_interact_tile(t_game *const g, t_config const *const c,
			t_uint const axis[2])
		__attribute__((nonnull));
void	game_player_move_east(t_game *const g, t_config const *const c)
		__attribute__((nonnull));
void	game_player_move_north(t_game *const g, t_config const *const c)
		__attribute__((nonnull));
void	game_player_move_west(t_game *const g, t_config const *const c)
		__attribute__((nonnull));
void	game_player_move_south(t_game *const g, t_config const *const c)
		__attribute__((nonnull));
void	game_player_move_east_north(t_game *const g, t_config const *const c)
		__attribute__((nonnull));
void	game_player_move_north_west(t_game *const g, t_config const *const c)
		__attribute__((nonnull));
void	game_player_move_west_south(t_game *const g, t_config const *const c)
		__attribute__((nonnull));
void	game_player_move_south_east(t_game *const g, t_config const *const c)
		__attribute__((nonnull));
void	game_pplane_fill_background(t_game *const g)
		__attribute__((nonnull));
void	game_pplane_fill_enemy(t_game *const g)
		__attribute__((nonnull));
void	game_pplane_fill_player(t_game *const g)
		__attribute__((nonnull));

#endif
