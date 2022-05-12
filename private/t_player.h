/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 05:01:23 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/13 01:06:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PLAYER_H
# define T_PLAYER_H

# include <stdbool.h>
# include <stdint.h>
# include "t_anim.h"

typedef struct s_player	t_player;

struct s_player
{
	double			axis[2];
	double			distance;
	bool			is_dead;
	bool			is_exited;
	t_uint			animate_clock;
	uint8_t			action_field;
	uint8_t			prev_action_field;
	t_anim const	*anim;
};

void	player_clear(t_player *const p)
		__attribute__((nonnull));

#endif
