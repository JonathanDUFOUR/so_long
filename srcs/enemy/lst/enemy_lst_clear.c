/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_lst_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:34:04 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/03 15:52:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_enemy_lst.h"

/**
	@brief	Release all resources contained in the given list.

	@param el The enemy list to clear.
*/
void	enemy_lst_clear(t_enemy_lst *const el)
{
	t_enemy	*next;

	while (el->size)
	{
		next = el->head->next;
		enemy_del_one(el->head);
		free(el->head);
		el->head = next;
		--el->size;
	}
	el->tail = NULL;
}
