/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 22:00:17 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/28 05:04:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "type/t_map.h"

/*
**	print a map var in terminal
*/
static void	sl_map_print_data(char const *name, t_uint val)
{
	ft_putstr_fd(name, 1);
	ft_putuint_fd(val, 1);
	write(1, "\n", 1);
}

/*
**	print the map in terminal
*/
void	sl_map_print(void)
{
	t_map *const	map = sl_map();
	char const		*e = map->e;

	while (*e)
	{
		write(1, e, map->w);
		write(1, "\n", 1);
		e += map->w;
	}
	sl_map_print_data("map->w: ", map->w);
	sl_map_print_data("map->h: ", map->h);
	sl_map_print_data("map->cnt_c: ", map->cnt_c);
	sl_map_print_data("map->cnt_e: ", map->cnt_e);
	sl_map_print_data("map->cnt_p: ", map->cnt_p);
}
