/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:24:08 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/29 22:57:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "type/t_block.h"

/*
**	singleton to get block
*/
t_block	*sl_block(void)
{
	static t_block	block = {
		{NULL, NULL, 0, 0, 0, 0, 0},
		{NULL, NULL, 0, 0, 0, 0, 0},
		{NULL, NULL, 0, 0, 0, 0, 0},
		{NULL, NULL, 0, 0, 0, 0, 0},
		{NULL, NULL, 0, 0, 0, 0, 0},
	};

	return (&block);
}
