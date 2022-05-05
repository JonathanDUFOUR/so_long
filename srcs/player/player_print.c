/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:09:19 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/05 23:25:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_io.h"
#include "t_player.h"
#include "e_axis.h"

/**
	@brief	Print every data stored in the given player structure.

	@param	p The player structure to print.
*/
void	player_print(t_player const *const p)
{
	fprintf(stderr, "%s:\n", __func__);
	printf("\t         p.axis: {%.2f, %.2f}\n", p->axis[X], p->axis[Y]);
	printf("\t     p.distance: %f\n", p->distance);
	printf("\t      p.is_dead: %d\n", p->is_dead);
	printf("\t    p.is_exited: %d\n", p->is_exited);
	printf("\t  p.animate_idx: %u\n", p->animate_idx);
	printf("\tp.animate_clock: %u\n", p->animate_clock);
	printf("\t p.action_field: ");
	fflush(stdout);
	ft_putbyte_fd(p->action_field, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
