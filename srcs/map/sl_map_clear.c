/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:36:52 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 19:33:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_mem.h"
#include "type/t_map.h"

/*
**	free map and bzero its variables
*/
void	sl_map_clear(void)
{
	t_map *const	map = sl_map();

	free(map->ptr);
	ft_bzero(map, sizeof(t_map));
}
