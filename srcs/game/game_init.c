/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 06:01:05 by jodufour          #+#    #+#             */
/*   Updated: 2023/11/24 11:30:02 by jodufour         ###   ########.fr       */
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

inline static bool	__is_border_or_corner(
	t_huint const width,
	t_huint const height,
	t_huint const i)
{
	t_huint const	x = i % width;
	t_huint const	y = i / width;

	return (x == 0 || x == width - 1 || y == 0 || y == height - 1);
}

inline static int	__save_player(
	t_game *const g,
	t_config const *const c,
	t_uint const idx)
{
	if (g->p.axis[X] && g->p.axis[Y])
		return (EXIT_FAILURE);
	g->p.axis[X] = idx % g->m.width * IMG_W + IMG_W / 2;
	g->p.axis[Y] = idx / g->m.width * IMG_H + IMG_H / 2;
	g->p.anim = c->player[SOUTH].head;
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
	g->el.tail->anim = c->enemy[g_enemy_spawn[i].img_idx].head;
	g->m.ptr[idx] = MAP_CHAR[FLOOR];
	return (*ret = SUCCESS);
}

inline static int	__check(
	t_game *const g,
	t_config const *const c,
	int *const ret)
{
	t_uint	i;

	if (!g->m.ptr)
		return (*ret = MAP_ERR);
	i = 0U;
	while (g->m.ptr[i])
	{
		if (!ft_strchr(MAP_CHAR, g->m.ptr[i])
			|| (__is_border_or_corner(g->m.width, g->m.height, i)
				&& g->m.ptr[i] != MAP_CHAR[WALL])
			|| (g->m.ptr[i] == MAP_CHAR[PLAYER] && __save_player(g, c, i)))
			return (*ret = MAP_ERR);
		if (g->m.ptr[i] == MAP_CHAR[COLLECT])
			++g->m.collect_cnt;
		if (g->m.ptr[i] == MAP_CHAR[ENEMY_EAST] || \
			g->m.ptr[i] == MAP_CHAR[ENEMY_NORTH] || \
			g->m.ptr[i] == MAP_CHAR[ENEMY_WEST] || \
			g->m.ptr[i] == MAP_CHAR[ENEMY_SOUTH])
			if (__save_enemy(g, c, i, ret))
				return (*ret);
		++i;
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
		|| game_pplane_init(g, x, ret))
		return (*ret);
	return (*ret = SUCCESS);
}
