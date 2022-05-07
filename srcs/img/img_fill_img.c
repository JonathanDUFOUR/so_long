/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_fill_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 04:52:15 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/07 01:27:59 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "t_img.h"
#include "e_axis.h"

/**
	@brief	Fill the given `dst` image with the given `src` image.

	@param	dst The image to fill.
	@param	src The image to use.
	@param	offset The starting pixel to fill in the `dst` image.
*/
void	img_fill_img(
	t_img *const dst,
	t_img const *const src,
	t_uint const offset)
{
	t_uint	i;

	i = 0U;
	while (i < src->height)
	{
		ft_memcpy(
			dst->addr + offset + i * dst->width,
			src->addr + i * src->width,
			src->line_len);
		++i;
	}
}
