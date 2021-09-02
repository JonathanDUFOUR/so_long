/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 05:53:09 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/01 23:47:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	load block from xpm files and check it
*/
int	sl_block_load(void)
{
	int	ret;

	ret = sl_block_load_collect();
	if (ret == SUCCESS)
		ret = sl_block_load_enemy();
	if (ret == SUCCESS)
		ret = sl_block_load_exit();
	if (ret == SUCCESS)
		ret = sl_block_load_floor();
	if (ret == SUCCESS)
		ret = sl_block_load_player();
	if (ret == SUCCESS)
		ret = sl_block_load_wall();
	if (ret == SUCCESS)
		ret = sl_block_check();
	return (ret);
}
