/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:14:09 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/06 23:56:29 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"
#include "mlx.h"
#include "so_long.h"
#include "e_cardinal.h"

inline static int	__run(t_all *const a)
{
	mlx_string_put(a->x.mlx, a->x.win, 15, 15, 0x00ffffff, "Distance: ");
	mlx_do_key_autorepeatoff(a->x.mlx);
	mlx_loop(a->x.mlx);
	mlx_do_key_autorepeaton(a->x.mlx);
	return (a->ret);
}

int	main(int const ac, char const **av)
{
	t_all	a;

	ft_bzero(&a, sizeof(t_all));
	if (arg_check(ac, av, &a.ret)
		|| xptr_init(&a.x, &a.ret)
		|| config_load(&a.c, &a.x, av[1], &a.ret)
		|| game_init(&a.g, &a.x, &a.c, &a.ret)
		|| hook_init(&a, &a.ret)
		|| __run(&a))
		return (game_clear(&a.g, &a.x),
			config_clear(&a.c, &a.x),
			xptr_clear(&a.x),
			err_msg(a.ret),
			EXIT_FAILURE);
	return (game_clear(&a.g, &a.x),
		config_clear(&a.c, &a.x),
		xptr_clear(&a.x),
		EXIT_SUCCESS);
}
