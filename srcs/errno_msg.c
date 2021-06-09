/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errno_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:41:25 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/09 15:04:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "so_long.h"

int	errno_msg(int errno)
{
	printf("\e[31mError\n");
	if (errno == AC_ERRNO)
		printf("Wrong argument count\n");
	printf("\e[0m\n");
	fflush(stdout);
	system("leaks so_long");
	return (errno);
}
