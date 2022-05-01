/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_fill_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 04:52:15 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/01 05:05:29 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "t_img.h"
#include "e_axis.h"

void	img_fill_img(
	t_img *const dst,
	t_img const *const src,
	t_uint const offset)
{
	t_uint	y;

	y = 0U;
	while (y < src->height)
	{
		ft_memcpy(
			dst->addr + offset + y * dst->width,
			src->addr + y * src->width,
			src->line_len);
		++y;
	}
}
