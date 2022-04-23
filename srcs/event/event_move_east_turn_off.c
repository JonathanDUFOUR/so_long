/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move_east_turn_off.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:28:41 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/23 20:16:38 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_all.h"
#include "e_action.h"

/**
	@brief	Set the east movement bit of the player to 0.
	
	@param	a The all structure containing the player.
*/
void	event_move_east_turn_off(t_all *const a)
{
	a->g.p.action_field &= ~(1 << MOVE_EAST);
}
