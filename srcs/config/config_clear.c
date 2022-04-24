/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:42:31 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/24 17:14:33 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "settings.h"
#include "t_config.h"
#include "e_cardinal.h"

inline static void	__clear_enemy(t_config *const c, t_xptr const *const x)
{
	t_uint	cardinal;
	t_uint	animate_idx;

	cardinal = EAST;
	while (cardinal <= SOUTH)
	{
		animate_idx = 0;
		while (animate_idx < ANIMATE_CNT)
		{
			if (c->enemy[cardinal][animate_idx].ptr)
				mlx_destroy_image(x->mlx, c->enemy[cardinal][animate_idx].ptr);
			animate_idx++;
		}
		cardinal++;
	}
}

inline static void	__clear_player(t_config *const c, t_xptr const *const x)
{
	t_uint	cardinal;
	t_uint	animate_idx;

	cardinal = EAST;
	while (cardinal <= SOUTH_EAST)
	{
		animate_idx = 0;
		while (animate_idx < ANIMATE_CNT)
		{
			if (c->player[cardinal][animate_idx].ptr)
				mlx_destroy_image(x->mlx, c->player[cardinal][animate_idx].ptr);
			animate_idx++;
		}
		cardinal++;
	}
}

/**
	@brief	Free the allocated memory in the given configuration structure.
	
	@param	c The configuration structure containing the memory to free.
	@param	x The xptr structure containing the display and window pointers.
*/
void	config_clear(t_config *const c, t_xptr const *const x)
{
	__clear_enemy(c, x);
	if (c->exit.ptr)
		mlx_destroy_image(x->mlx, c->exit.ptr);
	if (c->floor.ptr)
		mlx_destroy_image(x->mlx, c->floor.ptr);
	__clear_player(c, x);
	if (c->wall.ptr)
		mlx_destroy_image(x->mlx, c->wall.ptr);
}
