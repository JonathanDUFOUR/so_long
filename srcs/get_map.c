/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:07:28 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/09 15:10:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "so_long.h"

int	get_map(char *file, char **map)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	
	return (SUCCESS);
}
