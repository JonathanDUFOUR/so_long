/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:43:38 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/05 00:05:16 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "t_all.h"

/**
	@brief	Display the player image in the middle of the window.

	@param	a The all structure containing the game and display data.
*/
void	render_player(t_all const *const a)
{
	mlx_put_image_to_window(
		a->x.mlx,
		a->x.win,
		a->g.p.img->ptr,
		WIN_W / 2 - IMG_W / 2, WIN_H / 2 - IMG_H / 2 + SIDEBAR_H / 2);
}
