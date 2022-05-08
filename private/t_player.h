/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 05:01:23 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/08 06:13:04 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PLAYER_H
# define T_PLAYER_H

# include <stdbool.h>
# include <stdint.h>
# include "t_img.h"

typedef struct s_player	t_player;

struct s_player
{
	double		axis[2];
	double		distance;
	bool		is_dead;
	bool		is_exited;
	t_uint		animate_idx;
	t_uint		animate_clock;
	uint8_t		action_field;
	t_img const	*img;
};

void	player_clear(t_player *const p)
		__attribute__((nonnull));

#endif
