/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:50:17 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/05 23:24:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_enemy.h"
#include "e_axis.h"

/**
	@brief	Allocate and initialize a new enemy node.

	@param	axis The enemy's axis.
	@param	action_field The enemy's action field.

	@return	The new enemy node address.
			Upon failure, NULL is returned.
*/
t_enemy	*enemy_new(double const axis[2], uint8_t const action_field)
{
	t_enemy *const	output = malloc(sizeof(t_enemy));

	if (!output)
		return (NULL);
	output->axis[X] = axis[X];
	output->axis[Y] = axis[Y];
	output->animate_idx = 0U;
	output->animate_clock = 0U;
	output->action_field = action_field;
	output->img = NULL;
	output->next = NULL;
	return (output);
}
