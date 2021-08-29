/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_check_square.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:53:09 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/29 20:46:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	Return true if the image is a square
**	Return false if it is not
*/
static bool	sl_is_square(t_img img)
{
	return (img.width == img.height);
}

/*
**	Check if all image are squares
*/
int	sl_block_check_square(void)
{
	t_block *const	block = sl_block();

	if (!sl_is_square(block->collect)
		|| !sl_is_square(block->exit)
		|| !sl_is_square(block->floor)
		|| !sl_is_square(block->player)
		|| !sl_is_square(block->wall))
		return (IMG_DIM_ERR);
	return (SUCCESS);
}
