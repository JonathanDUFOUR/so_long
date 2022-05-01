/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 05:49:15 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/01 00:42:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_GAME_H
# define T_GAME_H

# include "t_map.h"
# include "t_player.h"
# include "t_xptr.h"

typedef struct s_game	t_game;

struct s_game
{
	t_map		m;
	t_player	p;
};

int		game_init(t_game *const g, t_xptr const *const x,
			t_config const *const c, int *const ret)
		__attribute__((nonnull));

void	game_clear(t_game *const g, t_xptr const *const x)
		__attribute__((nonnull));

#endif
