/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_lst_push_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:00:58 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/03 16:13:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_enemy_lst.h"

/**
	@brief	Set the given enemy node as the last node of the given enemy list. 

	@param	el The enemy list to push the node to.
	@param	e The enemy node to push.
*/
void	enemy_lst_push_back(t_enemy_lst *const el, t_enemy *const e)
{
	if (!el->size)
		el->head = e;
	else
		el->tail->next = e;
	el->tail = e;
	++el->size;
}
