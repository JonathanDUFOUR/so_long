/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 18:59:05 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 21:27:28 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "type/t_block.h"

/*
**	free block and bzero its variables
*/
void	sl_block_clear(void)
{
	t_block *const	block = sl_block();

	sl_block_clear_collect();
	sl_block_clear_enemy();
	sl_block_clear_exit();
	sl_block_clear_floor();
	sl_block_clear_player();
	sl_block_clear_wall();
	ft_bzero(block, sizeof(t_block));
}
