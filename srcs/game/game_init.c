/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 06:01:05 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/05 00:51:19 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_io.h"
#include "ft_string.h"
#include "mlx.h"
#include "lookup_enemy_spawn.h"
#include "t_game.h"
#include "e_axis.h"
#include "e_cardinal.h"
#include "e_ret.h"

inline static int	__save_player(
	t_game *const g,
	t_config const *const c,
	t_uint const idx)
{
	if (g->p.axis[X] && g->p.axis[Y])
		return (EXIT_FAILURE);
	g->p.axis[X] = idx % g->m.width * IMG_W + IMG_W / 2;
	g->p.axis[Y] = idx / g->m.width * IMG_H + IMG_H / 2;
	g->p.img = &c->player[SOUTH][0];
	g->m.ptr[idx] = MAP_CHAR[FLOOR];
	return (EXIT_SUCCESS);
}

inline static int	__save_enemy(
	t_game *const g,
	t_config const *const c,
	t_uint const idx,
	int *const ret)
{
	double const	axis[2] = {
		idx % g->m.width * IMG_W + IMG_W / 2,
		idx / g->m.width * IMG_H + IMG_H / 2};
	t_uint			i;

	i = 0U;
	while (g_enemy_spawn[i].c && g->m.ptr[idx] != g_enemy_spawn[i].c)
		++i;
	if (enemy_lst_add_back(&g->el, axis, g_enemy_spawn[i].mask))
		return (*ret = MALLOC_ERR);
	g->el.tail->img = &c->enemy[g_enemy_spawn[i].img_idx][0];
	g->m.ptr[idx] = MAP_CHAR[FLOOR];
	return (*ret = SUCCESS);
}

inline static int	__check(
	t_game *const g,
	t_config const *const c,
	int *const ret)
{
	t_uint	idx;

	idx = 0U;
	while (g->m.ptr[idx])
	{
		if (!ft_strchr(MAP_CHAR, g->m.ptr[idx])
			|| ((idx % g->m.width == 0
					|| idx % g->m.width == g->m.width - 1
					|| idx / g->m.width == 0
					|| idx / g->m.width == g->m.height - 1)
				&& g->m.ptr[idx] != MAP_CHAR[WALL])
			|| (g->m.ptr[idx] == MAP_CHAR[PLAYER] && __save_player(g, c, idx)))
			return (*ret = MAP_ERR);
		g->m.ptr[idx] == MAP_CHAR[COLLECT] && ++g->m.collect_cnt;
		if (g->m.ptr[idx] == MAP_CHAR[ENEMY_EAST] || \
			g->m.ptr[idx] == MAP_CHAR[ENEMY_NORTH] || \
			g->m.ptr[idx] == MAP_CHAR[ENEMY_WEST] || \
			g->m.ptr[idx] == MAP_CHAR[ENEMY_SOUTH])
			if (__save_enemy(g, c, idx, ret))
				return (*ret);
		++idx;
	}
	if (!g->m.collect_cnt || !g->p.axis[X] || !g->p.axis[Y])
		return (*ret = MAP_ERR);
	return (*ret = SUCCESS);
}

/**
	@brief	Initialize the given game structure with the given map file.

	@param	g The game structure to initialize.
	@param	x The xptr structure to use.
	@param	c The configuration structure
			containing the map filename and the tile images.
	@param	ret The program status reference.

	@return	The updated program status.
*/
int	game_init(
	t_game *const g,
	t_xptr const *const x,
	t_config const *const c,
	int *const ret)
{
	if (map_load(&g->m, c->filename, ret)
		|| __check(g, c, ret)
		|| map_maxi_init(&g->m, x, c, ret)
		|| map_mini_init(&g->m, x, ret))
		return (*ret);
	return (*ret = SUCCESS);
}
