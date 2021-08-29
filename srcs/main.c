/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:14:09 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/29 22:45:20 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "enum/e_ret.h"

int	main(int ac, char **av)
{
	int	ret;

	if (ac == 2)
	{
		ret = sl_game_init(av[1]);
		if (ret == SUCCESS)
			ret = sl_game_run();
	}
	else
		ret = AC_ERR;
	sl_game_clear();
	if (ret != SUCCESS)
		sl_err_msg(ret);
	return (SUCCESS);
}
