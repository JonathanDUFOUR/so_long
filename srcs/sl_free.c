/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 07:45:28 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/22 08:08:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_free.h"
#include "t_lst.h"

static void	sl_update_lst(t_free *curr, t_free *prev)
{
	t_lst *const	lst = sl_get_lst();

	if (curr == (t_free *)lst->head)
		lst->head = ((t_free *)lst->head)->next;
	else if (curr == (t_free *)lst->tail)
		lst->tail = prev;
	--lst->size;
}

void	sl_free(void *addr)
{
	t_lst *const	lst = sl_get_lst();
	t_free			*curr;
	t_free			*prev;

	curr = (t_free *)lst->head;
	prev = NULL;
	while (curr)
	{
		if (addr == curr->addr)
		{
			if (prev)
				prev->next = curr->next;
			free(curr->addr);
			sl_update_lst(curr, prev);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}
