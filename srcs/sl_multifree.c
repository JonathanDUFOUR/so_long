/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_multifree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 14:25:37 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/13 03:43:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"

int	sl_multifree(int ret)
{
	t_lst *const	lst = sl_get_lst();
	t_free			*next;

	while (lst->head)
	{
		next = ((t_free *)lst->head)->next;
		free(((t_free *)lst->head)->addr);
		((t_free *)lst->head)->addr = NULL;
		free(lst->head);
		lst->head = next;
	}
	lst->size = 0;
	lst->tail = NULL;
	return (ret);
}
