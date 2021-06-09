/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:07:28 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/09 17:28:17 by jodufour         ###   ########.fr       */
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
	while (ret > 0)
	{
		dent = map->elems;
		map->elems = sl_strjoin(map->elems, line);
		free(line);
		free(dent);
		ret = get_next_line(fd, &line);
	}
	dent = map->elems;
	if (!ret)
		map->elems = sl_strjoin(map->elems, line);
	free(line);
	free(dent);
	close(fd);
	if (!ret)
		return (SUCCESS);
	return (GNL_ERRNO);
}
