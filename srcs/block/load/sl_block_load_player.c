/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_load_player.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 20:45:18 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/02 05:03:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	load player block data from xpm files
*/
int	sl_block_load_player(void)
{
	int	ret;

	ret = sl_block_load_player_down();
	if (ret == SUCCESS)
		ret = sl_block_load_player_left();
	if (ret == SUCCESS)
		ret = sl_block_load_player_right();
	if (ret == SUCCESS)
		ret = sl_block_load_player_up();
	return (ret);
}
