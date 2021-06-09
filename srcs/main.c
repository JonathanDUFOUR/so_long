/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:14:09 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/09 14:56:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "so_long.h"

int	main(int ac, char **av)
{
	int	ret;

	if (ac == 2)
	{
		ret = run_game(av[1]);
		if (ret != SUCCESS)
			return (errno_msg(ret));
	}
	else
		return (errno_msg(AC_ERRNO));
	system("leaks so_long");
	return (0);
}
