/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_hook_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 22:51:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/30 01:11:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <stddef.h>
#include "mlx.h"
#include "so_long.h"
#include "type/t_xptr.h"
#include "enum/e_ret.h"

/*
**	set hooks to wanted events
*/
int	sl_hook_set(void)
{
	t_xptr *const	xptr = sl_xptr();

	mlx_loop_hook(xptr->mlx, sl_event_none, NULL);
	mlx_hook(xptr->win, KeyPress, KeyPressMask, sl_hook_key, NULL);
	mlx_hook(xptr->win, DestroyNotify, StructureNotifyMask, mlx_loop_end,
		xptr->mlx);
	return (SUCCESS);
}
