/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:41:12 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/29 23:19:34 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_block.h"
#include "enum/e_ret.h"

/*
**	check if all images are valid
**	return an error if at least one is not
*/
int	sl_block_check(void)
{
	int	ret;

	ret = sl_block_check_square();
	if (ret == SUCCESS)
		ret = sl_block_check_same_dim();
	return (ret);
}
