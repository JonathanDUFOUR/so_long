/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_run_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:57:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/09 17:28:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

int	sl_run_game(char const *file)
{
	t_map	map;
	int		ret;

	map.elems = NULL;
	map.h = 0;
	map.w = 0;
	ret = sl_get_map(file, &map);
	if (ret == SUCCESS)
		printf("map:\n%s\n", map.elems);
	free(map.elems);
	return (ret);
}
