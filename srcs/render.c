/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:07:27 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/01 05:44:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "settings.h"
#include "t_all.h"
#include "e_axis.h"
#include "e_ret.h"

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

inline static void	__fill_mini(t_game *const g)
{
	t_uint			axis[2];
	t_uint const	offset[2] = {
		g->p.axis[X] - g->m.mini.width / 2,
		g->p.axis[Y] - g->m.mini.height / 2};

	axis[X] = 0U;
	while (axis[X] < g->m.mini.width)
	{
		axis[Y] = 0U;
		while (axis[Y] < g->m.mini.height)
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

/**
	@brief	Display the current game image on the window.

	@param	a The all structure containing the game and display data.

	@return	The updated program status, always SUCCESS.
*/
int	render(t_all *const a)
{
	__fill_mini(&a->g);
	mlx_put_image_to_window(
		a->x.mlx,
		a->x.win,
		a->g.m.mini.ptr, 0, 0);
	mlx_put_image_to_window(
		a->x.mlx,
		a->x.win,
		a->g.p.img->ptr,
		WIN_W / 2 - IMG_W / 2,
		WIN_H / 2 - IMG_H / 2);
	return (a->ret = SUCCESS);
}
