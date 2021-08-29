/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_xptr_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 05:24:57 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/29 20:28:27 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "config.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	Init mlx_ptr, load block images from xpm files, and check it
*/
int	sl_xptr_init(void)
{
	t_xptr *const	xptr = sl_xptr();
	int				ret;

	xptr->mlx = mlx_init();
	if (!xptr->mlx)
		return (MLX_ERR);
	ret = sl_block_load();
	if (ret == SUCCESS)
		ret = sl_block_check();
	return (ret);
}
