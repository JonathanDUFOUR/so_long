/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_xptr_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 05:37:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 21:29:59 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "ft_string.h"
#include "type/t_xptr.h"

/*
**	free xptr and bzero its variables
*/
void	sl_xptr_clear(void)
{
	t_xptr *const	xptr = sl_xptr();

	if (xptr->win)
		mlx_destroy_window(xptr->mlx, xptr->win);
	if (xptr->mlx)
	{
		mlx_destroy_display(xptr->mlx);
		free(xptr->mlx);
	}
	ft_bzero(xptr, sizeof(t_xptr));
}
