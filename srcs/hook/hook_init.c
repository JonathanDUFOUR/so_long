/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:11:54 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/23 16:26:06 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include "mlx.h"
#include "so_long.h"
#include "e_ret.h"

/**
	@brief	Setup hooks to trigger events on user input.

	@param	a The all structure to use.
	@param	ret The program status reference.

	@return	The updated program status, always SUCCESS.
*/
int	hook_init(t_all *const a, int *const ret)
{
	mlx_hook(a->x.win, KeyPress, KeyPressMask, &hook_key_press, a);
	mlx_hook(a->x.win, KeyRelease, KeyReleaseMask, &hook_key_release, a);
	mlx_hook(a->x.win, DestroyNotify, StructureNotifyMask, &mlx_loop_end,
		a->x.mlx);
	mlx_hook(a->x.win, Expose, ExposureMask, &render, a);
	mlx_loop_hook(a->x.mlx, &event_none, a);
	return (*ret = SUCCESS);
}
