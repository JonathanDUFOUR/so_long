/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 04:04:36 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/29 20:48:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_map.h"
#include "type/t_xptr.h"
#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	init and load everything needed to run the game
*/
int	sl_game_init(char const *ber)
{
	int	ret;

	ret = sl_map_load(ber);
	if (ret == SUCCESS)
		sl_map_print();
	if (ret == SUCCESS)
		ret = sl_xptr_init();
	sl_map_clear();
	sl_block_clear();
	sl_xptr_clear();
	return (ret);
}
