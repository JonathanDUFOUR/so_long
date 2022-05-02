/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maxi_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:48:55 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/03 00:38:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "t_map.h"
#include "e_axis.h"
#include "e_map_char.h"
#include "e_ret.h"

typedef struct s_filler	t_filler;

struct s_filler
{
	char const			c;
	t_img const *const	i;
};

inline static void	__fill(t_map *const m, t_config const *const c)
{
	t_filler const	lookup[] = {
	{MAP_CHAR[COLLECT], &c->collect},
	{MAP_CHAR[EXIT], &c->exit},
	{MAP_CHAR[FLOOR], &c->floor},
	{MAP_CHAR[WALL], &c->wall}};
	t_uint			axis[2];
	t_uint			idx;

	axis[X] = 0U;
	while (axis[X] < m->width)
	{
		axis[Y] = 0U;
		while (axis[Y] < m->height)
		{
			idx = 0U;
			while (lookup[idx].c != m->ptr[axis[X] + axis[Y] * m->width])
				++idx;
			img_fill_img(
				&m->maxi,
				lookup[idx].i,
				axis[X] * IMG_W + axis[Y] * IMG_H * m->maxi.width);
			++axis[Y];
		}
		++axis[X];
	}
}

/**
	@brief Initialize the maximap image, and fill it using the tiles images.

	@param	m	The map structure containing the maximap to initialize.
	@param	x	The xptr structure containing the display and window pointers.
	@param	c	The configuration structure containing the tiles images.
	@param	ret The program status reference.

	@return	The updated program status.
*/
int	map_maxi_init(
	t_map *const m,
	t_xptr const *const x,
	t_config const *const c,
	int *const ret)
{
	m->maxi.width = m->width * IMG_W;
	m->maxi.height = m->height * IMG_H;
	m->maxi.ptr = mlx_new_image(
			x->mlx,
			m->maxi.width,
			m->maxi.height);
	if (!m->maxi.ptr)
		return (*ret = MLX_ERR);
	m->maxi.addr = (uint32_t *)mlx_get_data_addr(
			m->maxi.ptr,
			(int *)&m->maxi.bpp,
			(int *)&m->maxi.line_len,
			(int *)&m->maxi.endian);
	if (!m->maxi.addr)
		return (*ret = MLX_ERR);
	return (__fill(m, c), *ret = SUCCESS);
}
