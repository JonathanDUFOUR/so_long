/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_enemy.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:46:02 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/12 22:39:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ENEMY_H
# define T_ENEMY_H

# include "t_anim.h"

typedef struct s_enemy	t_enemy;

struct s_enemy
{
	double			axis[2];
	t_uint			animate_clock;
	uint8_t			action_field;
	t_anim const	*anim;
	t_enemy			*next;
};

void	enemy_del_one(t_enemy *const e)
		__attribute__((nonnull));

t_enemy	*enemy_new(double const axis[2], uint8_t const action_field);

#endif
