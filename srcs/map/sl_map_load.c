/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 16:34:08 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 21:28:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "so_long.h"
#include "type/t_map.h"
#include "enum/e_ret.h"

/*
**	load map from ber file and check it
*/
int	sl_map_load(char const *file)
{
	int	fd;
	int	ret;

	ret = sl_file_check_ext(file);
	if (ret != SUCCESS)
		return (ret);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (OPEN_ERR);
	ret = sl_map_read(fd);
	close(fd);
	if (ret == SUCCESS)
		ret = sl_map_check();
	return (ret);
}
