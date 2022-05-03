/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_none.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:49:11 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/04 00:17:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colors.h"
#include "mlx.h"
#include "so_long.h"
#include "settings.h"
#include "lookup_player_action.h"
#include "t_all.h"
#include "e_ret.h"

inline static bool	__routine_player(t_all *const a)
{
	static t_uint	clock = 0U;
	t_uint			idx;

	idx = 0U;
	while (g_action[idx].mask && a->g.p.action_field != g_action[idx].mask)
		++idx;
	if (g_action[idx].fct)
	{
		g_action[idx].fct(&a->g, &a->c);
		if (clock++ == SLEEP_TIME)
		{
			a->g.p.animate_idx = ++a->g.p.animate_idx % ANIMATE_CNT;
			clock = 0U;
		}
		return (true);
	}
	return (false);
}

inline static bool	__routine_enemy(t_all *const a)
{
	static t_uint	clock = 0U;
	t_uint			idx;

	idx = 0U;
	return (false);
}

/**
	@brief	Define what to do when no input event is triggered.

	@param	a The all structure containing the game and display data.

	@return	The updated program status, always SUCCESS.
*/
int	event_none(t_all *const a)
{
	static t_uint	clock = 0U;
	t_uint			idx;

	if (a->g.p.is_exited)
		game_over(GREEN VICTORY_MSG RESET, a->g.p.distance, &a->x);
	else if (a->g.p.is_dead)
		game_over(RED DEFEAT_MSG RESET, a->g.p.distance, &a->x);
	if ((__routine_player(a) || __routine_enemy(a)) && render(a))
		mlx_loop_end(a->x.mlx);
	return (a->ret = SUCCESS);
}
