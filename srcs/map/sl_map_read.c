/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 19:38:05 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/28 05:06:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_io.h"
#include "ft_string.h"
#include "type/t_map.h"
#include "enum/e_ret.h"

/*
**	read map from file descriptor and check its width
*/
int	sl_map_read(int const fd)
{
	t_map *const	map = sl_map();
	char			*line;
	char			*dent;
	int				ret;

	line = NULL;
	ret = get_next_line(fd, &line);
	while (ret == 1)
	{
		ret = sl_map_check_width(line);
		if (ret != SUCCESS)
			break ;
		dent = map->e;
		map->e = ft_strjoin(map->e, line);
		++map->h;
		free(line);
		free(dent);
		line = NULL;
		ret = get_next_line(fd, &line);
	}
	free(line);
	line = NULL;
	dent = NULL;
	gnl_clear();
	return (ret);
}
