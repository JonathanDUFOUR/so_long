/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_errno_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:41:25 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/13 03:45:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

int	sl_errno_msg(int const errno)
{
	printf("\e[31mError\n");
	if (errno == AC_ERRNO)
		printf("Wrong argument count\n");
	else if (errno == OPEN_ERRNO)
		printf("Open failed\n");
	else if (errno == GNL_ERRNO)
		printf("Get_next_line failed\n");
	else if (errno == INVALID_MAP_ERRNO)
		printf("Invalid map\n");
	else if (errno == MALLOC_ERRNO)
		printf("Malloc failed\n");
	printf("\e[0m\n");
	fflush(stdout);
#ifdef __APPLE__
	system("leaks so_long");
#endif
	return (errno);
}
