/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:07:27 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/01 11:27:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_io.h"
#include "mlx.h"
#include "settings.h"
#include "t_all.h"
#include "e_axis.h"
#include "e_ret.h"

inline static int	__score(t_all *const a)
{
	static double	old;
	char const		*str = ft_dtoa(old, 2);

	if (!str)
		return (a->ret = MALLOC_ERR);
	mlx_string_put(a->x.mlx, a->x.win, 84, 21, 0x00000000, (char *)str);
	free((void *)str);
	str = ft_dtoa(a->g.p.distance, 2);
	if (!str)
		return (a->ret = MALLOC_ERR);
	mlx_string_put(a->x.mlx, a->x.win, 84, 21, 0x00ffffff, (char *)str);
	free((void *)str);
	old = a->g.p.distance;
	return (a->ret = SUCCESS);
}

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

	@return	The updated program status.
*/
int	render(t_all *const a)
{
	if (__score(a))
		return (a->ret);
	__fill_mini(&a->g);
	mlx_put_image_to_window(
		a->x.mlx,
		a->x.win,
		a->g.m.mini.ptr,
		0,
		SIDEBAR_H);
	mlx_put_image_to_window(
		a->x.mlx,
		a->x.win,
		a->g.p.img->ptr,
		WIN_W / 2 - IMG_W / 2,
		WIN_H / 2 - IMG_H / 2 + SIDEBAR_H / 2);
	return (a->ret = SUCCESS);
}
