/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 00:39:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/15 01:41:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "t_map.h"
#include "so_long.h"

void	sl_print_map(t_map map)
{
	uint32_t	i;

	i = 0;
	write(1, "\n", 1);
	while (i < map.h)
	{
		write(1, map.elems + i * map.w, map.w);
		write(1, "\n", 1);
		++i;
	}
	write(1, "\n", 1);
	printf("width  -> %u\n", map.w);
	printf("height -> %u\n", map.h);
	fflush(stdout);
}
