/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 05:01:23 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/23 22:26:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PLAYER_H
# define T_PLAYER_H

# include <stdint.h>

typedef struct s_player	t_player;

struct s_player
{
	double		axis[2];
	double		distance;
	uint8_t		action_field;
};

void	player_clear(t_player *const p)
		__attribute__((nonnull));
void	player_print(t_player const *const p)
		__attribute__((nonnull));

#endif
