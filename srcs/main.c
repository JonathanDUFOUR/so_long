/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:14:09 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/22 21:55:50 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int	ret;

	if (ac == 2)
	{
		ret = sl_init_game(av[1]);
		if (ret != SUCCESS)
			return (sl_errno_msg(ret));
	}
	else
		return (sl_errno_msg(AC_ERRNO));
	return (SUCCESS);
}
