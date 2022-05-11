/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_anim.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:03:58 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/11 16:11:33 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ANIM_H
# define T_ANIM_H

# include "t_img.h"
# include "t_xptr.h"

typedef struct s_anim	t_anim;

struct s_anim
{
	t_img	img;
	t_anim	*next;
};

void	anim_del_one(t_anim *const a, t_xptr const *const x)
		__attribute__((nonnull));

t_anim	*anim_new(t_img const *const img)
		__attribute__((nonnull));

#endif
