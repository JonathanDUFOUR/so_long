/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_pplane_fill_player.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:58:38 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/07 00:38:45 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_game.h"

/**
	@brief	Fill the projection plane image with the current player sprite.

	@param	g The game structure containing the projection plane to fill
			and the player data.
*/
void	game_pplane_fill_player(t_game *const g)
{
	img_fill_img(
		&g->pplane,
		g->p.img,
		g->pplane.width / 2 - IMG_W / 2
		+ (g->pplane.height / 2 - IMG_H / 2) * g->pplane.width);
}
