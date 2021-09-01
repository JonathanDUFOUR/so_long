/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_xptr_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 05:24:57 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/01 18:14:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "config.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "type/t_map.h"
#include "enum/e_ret.h"

/*
**	init mlx_ptr
**	load block images from xpm files and check it
**	init win_ptr
*/
int	sl_xptr_init(void)
{
	t_xptr *const	xptr = sl_xptr();
	t_block *const	block = sl_block();
	t_map *const	map = sl_map();
	int				ret;

	xptr->mlx = mlx_init();
	if (!xptr->mlx)
		return (MLX_ERR);
	ret = sl_block_load();
	if (ret == SUCCESS)
		xptr->win = mlx_new_window(xptr->mlx,
				block->wall.width * map->width,
				block->wall.height * (map->height + 1),
				WIN_TITLE);
	if (ret == SUCCESS && !xptr->win)
		return (MLX_ERR);
	return (ret);
}
