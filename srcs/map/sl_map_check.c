/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 22:14:31 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/29 23:21:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_map.h"
#include "enum/e_ret.h"

/*
**	check if map is valid
**	return an error if it is not
*/
int	sl_map_check(void)
{
	int	ret;

	ret = sl_map_check_cep();
	if (ret == SUCCESS)
		ret = sl_map_check_borders();
	return (ret);
}
