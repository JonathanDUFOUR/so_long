/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_none.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:49:11 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/05 01:50:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_colors.h"
#include "mlx.h"
#include "so_long.h"
#include "lookup_action.h"
#include "e_axis.h"
#include "e_ret.h"

inline static bool	__is_player_dead(t_game const *const g)
{
	t_enemy const	*e = g->el.head;
	double			pdist[2];

	while (e)
	{
		pdist[X] = g->p.axis[X] - e->axis[X];
		pdist[Y] = g->p.axis[Y] - e->axis[Y];
		if (fabs(pdist[X]) < 2 * HITBOX && \
			fabs(pdist[Y]) < 2 * HITBOX)
			return (true);
		e = e->next;
	}
	return (false);
}

inline static bool	__routine_player(t_game *const g, t_config const *const c)
{
	static t_uint	clock = 0U;
	t_uint			idx;

	idx = 0U;
	while (g_action[idx].mask && g->p.action_field != g_action[idx].mask)
		++idx;
	if (g_action[idx].p_fct)
	{
		g_action[idx].p_fct(g, c);
		if (clock++ == SLEEP_TIME)
		{
			g->p.animate_idx = ++g->p.animate_idx % ANIMATE_CNT;
			clock = 0U;
		}
		return (true);
	}
	return (false);
}

inline static bool	__is_enemy_on_window(
	t_player const *const p,
	t_enemy const *const e)
{
	double const	pdist[2] = {
		e->axis[X] - p->axis[X],
		e->axis[Y] - p->axis[Y]};

	return (fabs(pdist[X]) < WIN_W / 2 + IMG_W && \
			fabs(pdist[Y]) < WIN_H / 2 + IMG_H);
}

inline static bool	__routine_enemy(t_all *const a)
{
	static t_uint	clock = 0U;
	t_uint			idx;
	bool			ret;
	t_enemy			*e;

	ret = false;
	e = a->g.el.head;
	while (e)
	{
		idx = 0U;
		while (g_action[idx].mask && e->action_field != g_action[idx].mask)
			++idx;
		if (g_action[idx].e_fct)
		{
			g_action[idx].e_fct(&a->g, &a->c, e);
			if (clock++ == SLEEP_TIME)
			{
				e->animate_idx = ++e->animate_idx % ANIMATE_CNT;
				clock = 0U;
			}
			ret |= __is_enemy_on_window(&a->g.p, e);
		}
		e = e->next;
	}
	return (ret);
}

/**
	@brief	Define what to do when no input event is triggered.

	@param	a The all structure containing the game and display data.

	@return	The updated program status, always SUCCESS.
*/
int	event_none(t_all *const a)
{
	if (a->g.p.is_exited)
		game_over(GREEN VICTORY_MSG RESET, a->g.p.distance, &a->x);
	else if (__is_player_dead(&a->g))
		game_over(RED DEFEAT_MSG RESET, a->g.p.distance, &a->x);
	if ((__routine_player(&a->g, &a->c) | __routine_enemy(a)) && render(a))
		return (mlx_loop_end(a->x.mlx), a->ret);
	return (a->ret = SUCCESS);
}
