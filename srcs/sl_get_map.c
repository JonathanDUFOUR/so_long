/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:07:28 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/09 20:43:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "so_long.h"
#include "get_next_line.h"

int	sl_get_map(char const *file, t_map *map)
{
	char	*line;
	char	*dent;
	int		ret;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (OPEN_ERRNO);
	ret = get_next_line(fd, &line);
	while (ret == 1)
	{
		dent = map->elems;
		map->elems = sl_strjoin(map->elems, line);
		if (++map->h && !map->w)
			map->w = sl_strlen(line);
		free(line);
		free(dent);
		ret = get_next_line(fd, &line);
	}
	if (!ret)
	{
		dent = map->elems;
		map->elems = sl_strjoin(map->elems, line);
		free(dent);
	}
	free(line);
	close(fd);
	if (!ret)
		return (SUCCESS);
	return (GNL_ERRNO);
}
