/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_lst_add_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:52:18 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/03 17:59:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_enemy_lst.h"

/**
	@brief	Allocate a new enemy node and push it back to the given enemy list.

	@param	el The enemy list to push the new enemy node to.
	@param	axis The axis of the new enemy node.
	@param	action_field The action field of the new enemy node.

	@return	EXIT_SUCCESS.
			Upon failure, EXIT_FAILURE is returned.
*/
int	enemy_lst_add_back(
	t_enemy_lst *const el,
	double const axis[2],
	uint8_t const action_field)
{
	t_enemy *const	e = enemy_new(axis, action_field);

	if (!e)
		return (EXIT_FAILURE);
	enemy_lst_push_back(el, e);
	return (EXIT_SUCCESS);
}
