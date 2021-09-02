/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_load_enemy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:48:12 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/02 05:03:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_xptr.h"
#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	load enemy block data from xpm files
*/
int	sl_block_load_enemy(void)
{
	int	ret;

	ret = sl_block_load_enemy_down();
	if (ret == SUCCESS)
		ret = sl_block_load_enemy_left();
	if (ret == SUCCESS)
		ret = sl_block_load_enemy_right();
	if (ret == SUCCESS)
		ret = sl_block_load_enemy_up();
	return (ret);
}
