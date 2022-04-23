/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 07:04:18 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/12 07:22:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_io.h"
#include "ft_string.h"
#include "t_map.h"
#include "e_ret.h"

inline static int	__first_line(
	t_map *const m,
	char *line,
	int *const ret)
{
	m->ptr = line;
	m->width = ft_strlen(line);
	return (*ret = SUCCESS);
}

inline static int	__next_lines(
	t_map *const m,
	char const *line,
	int *const ret)
{
	char const *const	dent = m->ptr;

	if (ft_strlen(line) != m->width)
		return (free((void *)line), *ret = MAP_ERR);
	m->ptr = ft_strjoin(m->ptr, line);
	free((void *)line);
	free((void *)dent);
	if (!m->ptr)
		return (*ret = MALLOC_ERR);
	return (*ret = SUCCESS);
}

/**
	@brief Fill the given map structure reading from the given file.

	@param	m The map structure to fill.
	@param	filename The name of the file to read.
	@param	ret The program status reference.

	@return	The updated program status.
*/

int	map_load(t_map *const m, char const *filename, int *const ret)
{
	int const	fd = open(filename, O_RDONLY);
	char		*line;

	if (fd == -1)
		return (*ret = OPEN_ERR);
	*ret = get_next_line(fd, &line);
	while (*ret == 1)
	{
		if (!m->ptr)
		{
			if (__first_line(m, line, ret))
				return (close(fd), *ret);
		}
		else if (__next_lines(m, line, ret))
			return (close(fd), *ret);
		++m->height;
		*ret = get_next_line(fd, &line);
	}
	if (*ret == -1)
		return (close(fd), *ret = GNL_ERR);
	if (!*line)
		free(line);
	else if (__next_lines(m, line, ret))
		return (close(fd), *ret);
	return (close(fd), *ret = SUCCESS);
}
