/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:05:40 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/03 15:22:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_io.h"
#include "t_enemy.h"
#include "e_axis.h"

/**
	@brief Print every data stored in the given enemy structure.

	@param e The enemy structure to print.
*/
void	enemy_print(t_enemy const *const e)
{
	fprintf(stderr, "%s:\n", __func__);
	printf("\t        e.axis: {%.2f, %.2f}\n", e->axis[X], e->axis[Y]);
	printf("\t e.animate_idx: %u\n", e->animate_idx);
	printf("\te.action_field: ");
	fflush(stdout);
	ft_putbyte_fd(e->action_field, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
