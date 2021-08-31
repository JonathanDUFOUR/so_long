/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 22:00:17 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 20:25:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "type/t_map.h"

/*
**	display the map and its data in terminal
*/
void	sl_map_print(void)
{
	t_map *const	map = sl_map();
	char const		*ptr = map->ptr;

	while (*ptr)
	{
		printf("%.*s\n", map->width, ptr);
		ptr += map->width;
	}
	printf("map->width:  %hu\n", map->width);
	printf("map->height: %hu\n", map->height);
	printf("map->count.collect: %hu\n", map->count.collect);
	printf("map->count.exit:    %hu\n", map->count.exit);
	printf("map->count.player:  %hu\n", map->count.player);
	printf("map->idx_exit:   %hu\n", map->idx_exit);
	printf("map->idx_player: %hu\n", map->idx_player);
}
