/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xptr_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 05:24:57 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/12 10:32:29 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "settings.h"
#include "t_xptr.h"
#include "e_ret.h"

/**
	@brief	Initialize the display and the window.

	@param	x The xptr structure to containing the display and window pointers.
	@param	ret The program status reference.

	@return	The updated program status.
 */
int	xptr_init(t_xptr *const x, int *const ret)
{
	x->mlx = mlx_init();
	if (!x->mlx)
		return (*ret = MLX_ERR);
	x->win = mlx_new_window(x->mlx, WIN_W, WIN_H, WIN_TITLE);
	if (!x->win)
		return (*ret = MLX_ERR);
	return (*ret = SUCCESS);
}
