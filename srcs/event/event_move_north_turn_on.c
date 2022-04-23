/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move_north_turn_on.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:29:38 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/23 20:16:16 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_all.h"
#include "e_action.h"

/**
	@brief	Set the north movement bit of the player to 1.

	@param	a The all structure containing the player. 
*/
void	event_move_north_turn_on(t_all *const a)
{
	a->g.p.action_field |= 1 << MOVE_NORTH;
}
