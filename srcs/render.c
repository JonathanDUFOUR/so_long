/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:07:27 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/24 17:23:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "settings.h"
#include "t_all.h"
#include "e_ret.h"

/**
	@brief	Display the current game image on the window.

	@param	a The all structure containing the game and display data.

	@return	The updated program status, always SUCCESS.
*/
int	render(t_all *const a)
{
	mlx_put_image_to_window(
		a->x.mlx,
		a->x.win,
		a->g.p.img->ptr,
		WIN_W / 2 - IMG_W / 2,
		WIN_H / 2 - IMG_H / 2);
	return (a->ret = SUCCESS);
}
