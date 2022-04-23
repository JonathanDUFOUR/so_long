/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_img.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 16:11:04 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/12 10:28:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_IMG_H
# define T_IMG_H

# include <stdint.h>
# include "type/t_int.h"

typedef struct s_img	t_img;

struct s_img
{
	void		*ptr;
	uint32_t	*addr;
	t_huint		width;
	t_huint		height;
	t_huint		bpp;
	t_huint		line_len;
	t_huint		endian;
};

#endif
