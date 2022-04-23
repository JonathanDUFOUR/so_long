/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xptr_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 05:37:21 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/12 05:24:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "mlx.h"
#include "t_xptr.h"

/**
	@brief	Call destructors for display and window pointers
			contained in the given xptr structure.
	
	@param	x The xptr structure containing the pointers to destroy.
*/
void	xptr_clear(t_xptr *const x)
{
	if (x->win)
		mlx_destroy_window(x->mlx, x->win);
	if (x->mlx)
		mlx_destroy_display(x->mlx);
	ft_bzero(x, sizeof(t_xptr));
}
