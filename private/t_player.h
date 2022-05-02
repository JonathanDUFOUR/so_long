/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 05:01:23 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/03 00:30:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PLAYER_H
# define T_PLAYER_H

# include <stdbool.h>
# include <stdint.h>
# include "t_img.h"
# include "t_map.h"

typedef struct s_player	t_player;

struct s_player
{
	double		axis[2];
	double		distance;
	bool		is_dead;
	bool		is_exited;
	t_uint		animate_idx;
	uint8_t		action_field;
	t_img const	*img;
};

void	player_clear(t_player *const p)
		__attribute__((nonnull));
void	player_interact_tile(t_player *const p, t_map *const m,
			t_config const *const c, t_uint const axis[2])
		__attribute__((nonnull));
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
void	player_print(t_player const *const p)
		__attribute__((nonnull));

#endif
