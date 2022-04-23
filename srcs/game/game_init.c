/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 06:01:05 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/12 11:46:03 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_io.h"
#include "ft_string.h"
#include "mlx.h"
#include "settings.h"
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

inline static int	__images(
	t_game *const g,
	t_xptr const *const x,
	int *const ret)
{
	g->m.maxi.ptr = mlx_new_image(x->mlx,
			IMG_W * g->m.width,
			IMG_H * g->m.height);
	if (!g->m.maxi.ptr)
		return (*ret = MLX_ERR);
	g->m.maxi.addr = (uint32_t *)mlx_get_data_addr(g->m.maxi.ptr,
			(int *)&g->m.maxi.bpp,
			(int *)&g->m.maxi.line_len,
			(int *)&g->m.maxi.endian);
	if (!g->m.maxi.addr)
		return (*ret = MLX_ERR);
	g->m.mini.ptr = mlx_new_image(x->mlx,
			WIN_W,
			WIN_H);
	if (!g->m.mini.ptr)
		return (*ret = MLX_ERR);
	g->m.mini.addr = (uint32_t *)mlx_get_data_addr(g->m.mini.ptr,
			(int *)&g->m.mini.bpp,
			(int *)&g->m.mini.line_len,
			(int *)&g->m.mini.endian);
	if (!g->m.mini.addr)
		return (*ret = MLX_ERR);
	return (*ret = SUCCESS);
}

/**
	@brief	Initialize the given game structure with the given map file.
	
	@param	g The game structure to initialize.
	@param	x The xptr structure to use.
	@param	filename The name of the map file to load.
	@param	ret The program status reference.

	@return	The updated program status.
*/
int	game_init(
	t_game *const g,
	t_xptr const *const x,
	char const *filename,
	int *const ret)
{
	if (map_load(&g->m, filename, ret)
		|| __check(g, ret)
		|| __images(g, x, ret))
		return (*ret);
	return (*ret = SUCCESS);
}
