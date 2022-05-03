/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_lst_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:07:22 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/04 00:23:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_enemy_lst.h"

/**
	@brief	Print every data stored in the given enemy list.

	@param	el The enemy list to print.
*/
void	enemy_lst_print(t_enemy_lst const *const el)
{
	t_enemy const	*e = el->head;

	while (e)
	{
		enemy_print(e);
		e = e->next;
	}
}
