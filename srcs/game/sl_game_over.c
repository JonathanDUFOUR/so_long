/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 22:04:45 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/01 19:40:19 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "so_long.h"
#include "type/t_xptr.h"

/*
**	print a custom game over message in terminal + total moves done
**	end the mlx_loop
*/
void	sl_game_over(char const *s)
{
	t_xptr *const	xptr = sl_xptr();
	t_uint *const	step = sl_step();

	printf("%s\n", s);
	printf("Total moves done: %u\n", *step);
	mlx_loop_end(xptr->mlx);
}
