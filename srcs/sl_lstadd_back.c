/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 14:04:58 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/15 02:17:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"
#include "t_free.h"
#include "t_lst.h"

int	sl_lstadd_back(void *addr)
{
	t_lst *const	lst = sl_get_lst();
	t_free			*new;

	new = malloc(sizeof(t_free));
	if (!new)
		return (MALLOC_ERRNO);
	new->addr = addr;
	new->next = NULL;
	if (lst->tail)
	{
		((t_free *)lst->tail)->next = new;
		lst->tail = ((t_free *)lst->tail)->next;
	}
	else
	{
		lst->head = new;
		lst->tail = lst->head;
	}
	++lst->size;
	return (SUCCESS);
}
