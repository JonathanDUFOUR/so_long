/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 06:01:05 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/01 05:32:59 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_io.h"
#include "ft_string.h"
#include "mlx.h"
#include "t_game.h"
#include "e_axis.h"
#include "e_map_char.h"
#include "e_ret.h"

inline static int	__save_player(
	t_game *const g,
	t_uint const idx)
{
	if (g->p.axis[X] && g->p.axis[Y])
		return (EXIT_FAILURE);
	g->p.axis[X] = idx % g->m.width * IMG_W + IMG_W / 2;
	g->p.axis[Y] = idx / g->m.width * IMG_H + IMG_H / 2;
	g->m.ptr[idx] = MAP_CHAR[FLOOR];
	return (EXIT_SUCCESS);
}

inline static int	__check(t_game *const g, int *const ret)
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
			|| (g->m.ptr[idx] == MAP_CHAR[PLAYER] && __save_player(g, idx)))
			return (*ret = MAP_ERR);
		if (g->m.ptr[idx] == MAP_CHAR[COLLECT])
			++g->m.collect_cnt;
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
		|| __check(g, ret)
		|| map_maxi_init(&g->m, x, c, ret)
		|| map_mini_init(&g->m, x, ret))
		return (*ret);
	return (*ret = SUCCESS);
}
