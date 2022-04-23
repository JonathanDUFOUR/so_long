/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:42:31 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/12 10:47:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "t_config.h"
#include "e_cardinal.h"

/**
	@brief	Free the allocated memory in the given configuration structure.
	
	@param	c The configuration structure containing the memory to free.
	@param	x The xptr structure containing the display and window pointers.
*/
void	config_clear(t_config *const c, t_xptr const *const x)
{
	t_uint	cardinal;

	cardinal = EAST;
	while (cardinal <= SOUTH)
	{
		if (c->enemy[cardinal].ptr)
			mlx_destroy_image(x->mlx, c->enemy[cardinal].ptr);
		++cardinal;
	}
	if (c->exit.ptr)
		mlx_destroy_image(x->mlx, c->exit.ptr);
	if (c->floor.ptr)
		mlx_destroy_image(x->mlx, c->floor.ptr);
	cardinal = EAST;
	while (cardinal <= SOUTH_EAST)
	{
		if (c->player[cardinal].ptr)
			mlx_destroy_image(x->mlx, c->player[cardinal].ptr);
		++cardinal;
	}
	if (c->wall.ptr)
		mlx_destroy_image(x->mlx, c->wall.ptr);
}
