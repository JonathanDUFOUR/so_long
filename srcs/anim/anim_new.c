/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:12:09 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/11 21:17:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_anim.h"

/**
	@brief	Allocate and initialize a new anim node.

	@param	img The anim's image.
*/
t_anim	*anim_new(t_img const *const img)
{
	t_anim *const	output = malloc(sizeof(t_anim));

	if (!output)
		return (NULL);
	output->img = *img;
	output->next = NULL;
	return (output);
}
