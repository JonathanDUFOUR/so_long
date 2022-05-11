/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_del_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:46:30 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/11 18:49:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "mlx.h"
#include "t_anim.h"

/**
	@brief	Release all resources contained in the given anim structure.

	@param a The anim structure to delete.
	@param x The xptr structure containing the display and window pointers.
*/
void	anim_del_one(t_anim *const a, t_xptr const *const x)
{
	if (a->img.ptr)
		mlx_destroy_image(x->mlx, a->img.ptr);
	ft_bzero(a, sizeof(t_anim));
}
