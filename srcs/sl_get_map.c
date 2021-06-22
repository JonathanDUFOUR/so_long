/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:07:28 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/22 08:16:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "t_map.h"
#include "so_long.h"
#include "get_next_line.h"

static int	sl_update(t_map *map, uint32_t linelen)
{
	++map->h;
	if (!map->w)
		map->w = linelen;
	else if (map->w != linelen)
		return (INVALID_MAP_ERRNO);
	return (SUCCESS);
}

static int	sl_close_quit(int fd, int ret)
{
	gnl_clear();
	close (fd);
	return (ret);
}

int	sl_get_map(char const *file, t_map *map)
{
	char	*line;
	int		ret;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (OPEN_ERRNO);
	ret = get_next_line(fd, &line);
	sl_lstadd_back(line);
	while (ret == 1)
	{
		if (sl_update(map, sl_strlen(line)) != SUCCESS)
			return (sl_close_quit(fd, INVALID_MAP_ERRNO));
		sl_lstadd_back(map->elems = sl_strjoin(map->elems, line));
		if (!map->elems)
			return (sl_close_quit(fd, MALLOC_ERRNO));
		ret = get_next_line(fd, &line);
		sl_lstadd_back(line);
	}
	if (!ret)
		sl_lstadd_back(map->elems = sl_strjoin(map->elems, line));
	if (!map->elems)
		return (sl_close_quit(fd, MALLOC_ERRNO));
	sl_free(line);
	return (sl_close_quit(fd, GNL_ERRNO * !!ret));
}
