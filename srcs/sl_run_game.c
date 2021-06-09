/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_run_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:57:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/09 17:03:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

static	int	free_n_quit(char *map, int ret)
{
	free(map);
	return (ret);
}

int	sl_run_game(char const *file)
{
	uint32_t	dim[2];
	char		*map;
	int			ret;

	dim[W] = 0;
	map = NULL;
	ret = sl_get_map(file, &map, dim);
	if (ret != SUCCESS)
		return (free_n_quit(map, ret));
	printf("map:\n%s\n", map);
	free(map);
	return (SUCCESS);
}
