/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_pplane_fill_enemy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 23:12:30 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/12 23:57:07 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_string.h"
#include "t_game.h"
#include "e_axis.h"

enum	e_mess
{
	WIDTH,
	HEIGHT,
	ITERATOR,
	OFFSET_EIMG,
	OFFSET_PPLANE,
	MESS_SIZE
};

inline static void	__entire_enemy(
	t_img *const pplane,
	t_img const *const eimg,
	double const pdist[2])
{
	img_fill_img(
		pplane,
		eimg,
		pplane->width / 2 - IMG_W / 2 + pdist[X]
		+ (t_uint)(pplane->height / 2 - IMG_H / 2 + pdist[Y]) * pplane->width);
}

inline static void	__vertical_truncate(
	t_img const *const pplane,
	t_img const *const eimg,
	double const pdist[2],
	t_uint m[MESS_SIZE])
{
	m[WIDTH] -= fabs(pdist[X]) - pplane->width / 2 + IMG_W / 2;
	if (pdist[X] < 0)
	{
		m[OFFSET_EIMG] = eimg->width - m[WIDTH];
		m[OFFSET_PPLANE] += eimg->width - m[WIDTH];
	}
}

inline static void	__horizontal_truncate(
	t_img const *const pplane,
	t_img const *const eimg,
	double const pdist[2],
	t_uint m[MESS_SIZE])
{
	m[HEIGHT] -= fabs(pdist[Y]) - pplane->height / 2 + IMG_H / 2;
	if (pdist[Y] < 0)
	{
		m[OFFSET_EIMG] += (eimg->height - m[HEIGHT]) * eimg->width;
		m[OFFSET_PPLANE] += (eimg->height - m[HEIGHT]) * pplane->width;
	}
}

inline static void	__truncate_enemy(
	t_img *const pplane,
	t_img const *const eimg,
	double const pdist[2])
{
	t_uint	m[MESS_SIZE];

	m[WIDTH] = eimg->width;
	m[HEIGHT] = eimg->height;
	m[OFFSET_EIMG] = 0U;
	m[OFFSET_PPLANE]
		= pplane->width / 2 - IMG_W / 2 + pdist[X]
		+ (t_uint)(pplane->height / 2 - IMG_H / 2 + pdist[Y]) * pplane->width;
	if (fabs(pdist[X]) >= pplane->width / 2 - IMG_W / 2)
		__vertical_truncate(pplane, eimg, pdist, m);
	if (fabs(pdist[Y]) >= pplane->height / 2 - IMG_H / 2)
		__horizontal_truncate(pplane, eimg, pdist, m);
	m[ITERATOR] = 0U;
	while (m[ITERATOR] < m[HEIGHT])
	{
		ft_memcpy(
			pplane->addr + m[OFFSET_PPLANE] + m[ITERATOR] * pplane->width,
			eimg->addr + m[OFFSET_EIMG] + m[ITERATOR] * eimg->width,
			m[WIDTH] * sizeof(uint32_t));
		++m[ITERATOR];
	}
}

/**
	@brief	Fill the projection plane image with the enemies sprites.

	@param	g The game structure containing the projection plane to fill
			and the enemies data.
*/
void	game_pplane_fill_enemy(t_game *const g)
{
	t_enemy const	*e = g->el.head;
	double			pdist[2];

	while (e)
	{
		pdist[X] = e->axis[X] - g->p.axis[X];
		pdist[Y] = e->axis[Y] - g->p.axis[Y];
		if (fabs(pdist[X]) < g->pplane.width / 2 + IMG_W / 2 && \
			fabs(pdist[Y]) < g->pplane.height / 2 + IMG_H / 2)
		{
			if (fabs(pdist[X]) < g->pplane.width / 2 - IMG_W / 2 && \
				fabs(pdist[Y]) < g->pplane.height / 2 - IMG_H / 2)
				__entire_enemy(&g->pplane, &e->anim->img, pdist);
			else
				__truncate_enemy(&g->pplane, &e->anim->img, pdist);
		}
		e = e->next;
	}
}
