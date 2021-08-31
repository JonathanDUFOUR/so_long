/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 22:00:17 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 04:18:29 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "type/t_map.h"

/*
**	print the map in terminal
*/
void	sl_map_print(void)
{
	t_map *const	map = sl_map();
	char const		*e = map->e;

	while (*e)
	{
		printf("%.*s\n", map->w, e);
		e += map->w;
	}
	printf("map->w: %u\n", map->w);
	printf("map->h: %u\n", map->h);
	printf("map->cnt_c: %u\n", map->cnt_c);
	printf("map->cnt_e: %u\n", map->cnt_e);
	printf("map->cnt_p: %u\n", map->cnt_p);
	printf("map->idx_e: %u\n", map->idx_e);
	printf("map->idx_p: %u\n", map->idx_p);
}