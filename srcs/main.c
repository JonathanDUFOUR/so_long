/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:14:09 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/11 02:44:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

int	main(int ac, char **av)
{
	int	ret;

	if (ac == 2)
	{
		ret = sl_run_game(av[1]);
		if (ret != SUCCESS)
			return (sl_errno_msg(ret));
	}
	else
		return (sl_errno_msg(AC_ERRNO));
#ifdef __APPLE__
	system("leaks so_long");
#endif
	return (0);
}
