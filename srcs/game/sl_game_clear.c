/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 22:39:10 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/29 22:44:03 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_map.h"
#include "type/t_block.h"
#include "type/t_xptr.h"

/*
**	free and bzero everything needed to run the game
*/
void	sl_game_clear(void)
{
	sl_map_clear();
	sl_block_clear();
	sl_xptr_clear();
}
