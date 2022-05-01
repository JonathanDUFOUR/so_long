/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:33:58 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/30 18:39:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "t_img.h"

/**
	@brief	Print every data stored in the given image structure.

	@param	i The image structure to print.
*/
void	img_print(t_img const *const i)
{
	fprintf(stderr, "%s\n", __func__);
	printf("\t     i.ptr: %p\n", i->ptr);
	printf("\t    i.addr: %p\n", i->addr);
	printf("\t   i.width: %hu\n", i->width);
	printf("\t  i.height: %hu\n", i->height);
	printf("\t     i.bpp: %hu\n", i->bpp);
	printf("\ti.line_len: %hu\n", i->line_len);
	printf("\t  i.endian: %hu\n", i->endian);
}
