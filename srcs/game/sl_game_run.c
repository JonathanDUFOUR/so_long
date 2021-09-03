/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 22:48:03 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/03 05:05:16 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "type/t_xptr.h"
#include "enum/e_ret.h"

int	sl_game_run(void)
{
	t_xptr *const	xptr = sl_xptr();

	mlx_loop(xptr->mlx);
	return (SUCCESS);
}
