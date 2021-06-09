/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:07:28 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/09 17:03:20 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "so_long.h"
#include "get_next_line.h"

int	sl_get_map(char const *file, char **map, uint32_t *dim)
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
		dent = *map;
		*map = sl_strjoin(*map, line);
		free(line);
		free(dent);
		ret = get_next_line(fd, &line);
	}
	dent = *map;
	if (!ret)
		*map = sl_strjoin(*map, line);
	free(line);
	free(dent);
	close(fd);
	if (!ret)
		return (SUCCESS);
	return (GNL_ERRNO);
}
