/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 19:38:05 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 21:28:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_io.h"
#include "ft_string.h"
#include "type/t_map.h"
#include "enum/e_ret.h"

static char	*_strjoin(char const *s0, char const *s1)
{
	char	*output;
	char	*ptr;
	size_t	len;

	len = 0;
	if (s0)
		len = ft_strlen(s0);
	if (s1)
		len += ft_strlen(s1);
	output = malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	ptr = output;
	while (s0 && *s0)
		*ptr++ = *s0++;
	while (s1 && *s1)
		*ptr++ = *s1++;
	*ptr = 0;
	return (output);
}

/*
**	read map from file descriptor and check its width
**	return an error if open, read, or gnl fails
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
		dent = map->ptr;
		ret = (!(map->ptr = _strjoin(map->ptr, line)) * MALLOC_ERR);
		free(dent);
		if (ret != SUCCESS)
			break ;
		ft_memdel(&line);
		++map->height;
		ret = get_next_line(fd, &line);
	}
	ft_memdel(&line);
	dent = NULL;
	gnl_clear();
	return (ret);
}
