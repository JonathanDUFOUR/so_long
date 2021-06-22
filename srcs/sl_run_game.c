/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_run_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:57:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/22 08:14:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "t_map.h"
#include "so_long.h"

int	sl_run_game(char const *file)
{
	t_map	map;
	int		ret;

	map.elems = NULL;
	map.h = 0;
	map.w = 0;
	ret = sl_lstadd_back(map.elems);
	if (ret != SUCCESS)
		return (sl_multifree(ret));
	ret = sl_get_map(file, &map);
	if (ret != SUCCESS)
		return (sl_multifree(ret));
	ret = sl_check_map(map);
	if (ret != SUCCESS)
		return (sl_multifree(ret));
	sl_print_map(map);
	return (sl_multifree(ret));
}
