/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_lst_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:14:01 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/11 21:28:45 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_anim_lst.h"

/**
	@brief	Allocate a new anim node and push it back to the given anim list.

	@param	el The anim list to push the new enemy node to.
	@param	img The image of the new anim node.

	@return	EXIT_SUCCESS.
			Upon failure, EXIT_FAILURE is returned.
*/
int	anim_lst_add_back(t_anim_lst *const al, t_img const *const img)
{
	t_anim *const	a = anim_new(img);

	if (!a)
		return (EXIT_FAILURE);
	anim_lst_push_back(al, a);
	return (EXIT_SUCCESS);
}
