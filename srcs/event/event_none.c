/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_none.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:49:11 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/24 22:58:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "settings.h"
#include "lookup_player_action.h"
#include "t_all.h"
#include "e_ret.h"

/**
	@brief	Define what to do when no input event is triggered.

	@param	a The all structure containing the game and display data.

	@return	The updated program status, always SUCCESS.
*/
int	event_none(t_all *const a)
{
	static t_uint	clock = 0U;
	t_uint			idx;

	idx = 0U;
	while (g_action[idx].mask && a->g.p.action_field != g_action[idx].mask)
		++idx;
	if (g_action[idx].fct)
	{
		g_action[idx].fct(&a->g.p, &a->g.m, &a->c);
		if (clock++ == SLEEP_TIME)
		{
			a->g.p.animate_idx = ++a->g.p.animate_idx % ANIMATE_CNT;
			clock = 0U;
		}
		render(a);
	}
	return (a->ret = SUCCESS);
}
