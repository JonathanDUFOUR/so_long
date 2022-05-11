/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:42:31 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/11 21:41:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "settings.h"
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

	if (c->collect.ptr)
		mlx_destroy_image(x->mlx, c->collect.ptr);
	cardinal = EAST;
	while (cardinal <= SOUTH)
	{
		anim_lst_clear(&c->enemy[cardinal], x);
		++cardinal;
	}
	if (c->exit.ptr)
		mlx_destroy_image(x->mlx, c->exit.ptr);
	if (c->floor.ptr)
		mlx_destroy_image(x->mlx, c->floor.ptr);
	cardinal = EAST;
	while (cardinal <= SOUTH_EAST)
	{
		anim_lst_clear(&c->player[cardinal], x);
		++cardinal;
	}
	if (c->wall.ptr)
		mlx_destroy_image(x->mlx, c->wall.ptr);
}
