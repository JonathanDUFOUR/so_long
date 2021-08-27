/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:14:09 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/27 04:04:04 by jodufour         ###   ########.fr       */
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
		if (ret != SUCCESS)
			return (sl_err_msg(ret));
	}
	else
		return (sl_err_msg(AC_ERR));
	return (SUCCESS);
}
