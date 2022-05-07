/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 05:50:49 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/06 21:16:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "t_game.h"

/**
	@brief	Free the allocated memory in the given game structure.

	@param	g The game structure containing the memory to free.
	@param	x The xptr structure containing the display and window pointers.
*/
void	game_clear(t_game *const g, t_xptr const *const x)
{
	enemy_lst_clear(&g->el);
	map_clear(&g->m, x);
	player_clear(&g->p);
	if (g->pplane.ptr)
		mlx_destroy_image(x->mlx, g->pplane.ptr);
}
