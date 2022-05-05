/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:29:12 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/04 23:49:16 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "t_all.h"
#include "e_axis.h"

inline static void	__copy_pixel_from_maxi(
	t_game *const g,
	t_uint const axis[2],
	t_uint const offset[2])
{
	g->m.mini.addr[
		axis[X]
		+ axis[Y] * g->m.mini.width
	] = g->m.maxi.addr[
		offset[X]
		+ offset[Y] * g->m.maxi.width
		+ axis[X]
		+ axis[Y] * g->m.maxi.width
	];
}

inline static void	__empty_pixel(t_game *const g, t_uint const axis[2])
{
	g->m.mini.addr[
		axis[X]
		+ axis[Y] * g->m.mini.width
	] = 0x00000000;
}

/**
	@brief	Fill the background image and display it on the window.

	@param	a The all structure containing the game and display data.
*/
void	render_background(t_all *const a)
{
	t_uint			axis[2];
	t_uint const	offset[2] = {
		a->g.p.axis[X] - a->g.m.mini.width / 2,
		a->g.p.axis[Y] - a->g.m.mini.height / 2};

	axis[X] = 0U;
	while (axis[X] < a->g.m.mini.width)
	{
		axis[Y] = 0U;
		while (axis[Y] < a->g.m.mini.height)
		{
			if (offset[X] + axis[X] < a->g.m.maxi.width && \
				offset[Y] + axis[Y] < a->g.m.maxi.height)
				__copy_pixel_from_maxi(&a->g, axis, offset);
			else
				__empty_pixel(&a->g, axis);
			++axis[Y];
		}
		++axis[X];
	}
	mlx_put_image_to_window(
		a->x.mlx,
		a->x.win,
		a->g.m.mini.ptr,
		0, SIDEBAR_H);
}
