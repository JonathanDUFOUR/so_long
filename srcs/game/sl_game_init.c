/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 04:04:36 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 06:12:50 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
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
		ret = sl_xptr_init();
	if (ret == SUCCESS)
		ret = sl_hook_set();
	if (ret == SUCCESS)
		ret = sl_map_draw();
	return (ret);
}
