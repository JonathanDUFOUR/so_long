/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:51:06 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/05 02:03:03 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include "t_all.h"
#include "e_axis.h"

/**
	@brief	Display every enemies having their axis close enough to the player.

	@param	a The all structure containing the game and display data.
*/
void	render_enemy(t_all const *const a)
{
	t_enemy const	*e = a->g.el.head;
	double			pdist[2];

	while (e)
	{
		pdist[X] = e->axis[X] - a->g.p.axis[X];
		pdist[Y] = e->axis[Y] - a->g.p.axis[Y];
		if (fabs(pdist[X]) < WIN_W / 2 + IMG_W && \
			fabs(pdist[Y]) < WIN_H / 2 + IMG_H)
		{
			mlx_put_image_to_window(
				a->x.mlx,
				a->x.win,
				e->img->ptr,
				WIN_W / 2 + pdist[X] - IMG_W / 2,
				WIN_H / 2 + pdist[Y] - IMG_H / 2 + SIDEBAR_H / 2);
		}
		e = e->next;
	}
}
