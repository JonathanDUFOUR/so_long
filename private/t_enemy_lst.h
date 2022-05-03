/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_enemy_lst.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:45:17 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/03 18:03:38 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ENEMY_LST_H
# define T_ENEMY_LST_H

# include <stddef.h>
# include "t_enemy.h"

typedef struct s_enemy_lst	t_enemy_lst;

struct s_enemy_lst
{
	t_enemy	*head;
	t_enemy	*tail;
	size_t	size;
};

int		enemy_lst_add_back(t_enemy_lst *const el, double const axis[2],
			uint8_t const action_field);

void	enemy_lst_clear(t_enemy_lst *const el)
		__attribute__((nonnull));
void	enemy_lst_print(t_enemy_lst const *const el)
		__attribute__((nonnull));
void	enemy_lst_push_back(t_enemy_lst *const el, t_enemy *const e)
		__attribute__((nonnull));

#endif
