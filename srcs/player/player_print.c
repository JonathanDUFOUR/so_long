/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:09:19 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/24 14:52:01 by jodufour         ###   ########.fr       */
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
	printf("\t        p.axis: {%.2f, %.2f}\n", p->axis[X], p->axis[Y]);
	printf("\t    p.distance: %f\n", p->distance);
	printf("\tp.action_field: ");
	fflush(stdout);
	ft_putbyte_fd(p->action_field, STDOUT_FILENO);
	printf("\n");
}
