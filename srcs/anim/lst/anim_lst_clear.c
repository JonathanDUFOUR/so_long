/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_lst_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:30:18 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/11 21:36:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"
#include "t_anim_lst.h"

/**
	@brief	Release all resources contained in the given anim list.

	@param	al The anim list to clear.
	@param	x The xptr structure containing the display and window pointers.
*/
void	anim_lst_clear(t_anim_lst *const al, t_xptr const *const x)
{
	t_anim	*next;
	size_t	iter;

	iter = 0U;
	while (iter < al->size)
	{
		next = al->head->next;
		anim_del_one(al->head, x);
		free(al->head);
		al->head = next;
		++iter;
	}
	ft_bzero(al, sizeof(t_anim_lst));
}
