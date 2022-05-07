/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_pplane_fill_background.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:29:12 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/06 22:12:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_game.h"
#include "e_axis.h"

inline static void	__copy_pixel_from_maxi(
	t_game *const g,
	t_uint const axis[2],
	t_uint const offset[2])
{
	g->pplane.addr[
		axis[X]
		+ axis[Y] * g->pplane.width
	] = g->m.maxi.addr[
		offset[X]
		+ offset[Y] * g->m.maxi.width
		+ axis[X]
		+ axis[Y] * g->m.maxi.width
	];
}

inline static void	__empty_pixel(t_game *const g, t_uint const axis[2])
{
	g->pplane.addr[
		axis[X]
		+ axis[Y] * g->pplane.width
	] = 0x00000000;
}

/**
	@brief	Fill the projection plane image with the map background.

	@param	g The game structure containing the projection plane to fill
			and the map data.
*/
void	game_pplane_fill_background(t_game *const g)
{
	t_uint			axis[2];
	t_uint const	offset[2] = {
		g->p.axis[X] - g->pplane.width / 2,
		g->p.axis[Y] - g->pplane.height / 2};

	axis[X] = 0U;
	while (axis[X] < g->pplane.width)
	{
		axis[Y] = 0U;
		while (axis[Y] < g->pplane.height)
		{
			if (offset[X] + axis[X] < g->m.maxi.width && \
				offset[Y] + axis[Y] < g->m.maxi.height)
				__copy_pixel_from_maxi(g, axis, offset);
			else
				__empty_pixel(g, axis);
			++axis[Y];
		}
		++axis[X];
	}
}
