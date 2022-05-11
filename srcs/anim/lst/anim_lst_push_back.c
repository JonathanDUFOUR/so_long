/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_lst_push_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:02:58 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/11 21:13:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_anim_lst.h"

/**
	@brief	Set the given anim node as the last node of the given anim list.

	@param	al The anim list to push the node to.
	@param	a The anim node to push.
*/
void	anim_lst_push_back(t_anim_lst *const al, t_anim *const a)
{
	if (!al->size)
		al->head = a;
	else
	{
		al->tail->next = a;
		a->next = al->head;
	}
	al->tail = a;
	++al->size;
}
