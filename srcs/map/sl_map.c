/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 16:38:31 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/27 22:38:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "type/t_map.h"

/*
**	singleton to get the map
*/
t_map	*sl_map(void)
{
	static t_map	map = {NULL, 0, 0, 0, 0, 0};

	return (&map);
}
