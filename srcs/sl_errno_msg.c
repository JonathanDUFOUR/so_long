/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_errno_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:41:25 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/22 08:49:33 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#ifdef __APPLE__
# include <stdlib.h>
#endif
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
	else if (errno == MLX_ERRNO)
		printf("Minilibx function failed\n");
	printf("\e[0m\n");
	fflush(stdout);
#ifdef __APPLE__
	system("leaks so_long");
#endif
	return (errno);
}
