/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_event_quit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 00:53:51 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/30 00:55:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "type/t_xptr.h"
#include "enum/e_ret.h"

/*
**	break the mlx_loop
*/
int	sl_event_quit(void)
{
	t_xptr *const	xptr = sl_xptr();

	mlx_loop_end(xptr->mlx);
	return (SUCCESS);
}
