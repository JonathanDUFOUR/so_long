/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_anim_lst.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:05:21 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/11 21:38:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ANIM_LST_H
# define T_ANIM_LST_H

# include <stddef.h>
# include "t_anim.h"

typedef struct s_anim_lst	t_anim_lst;

struct s_anim_lst
{
	t_anim	*head;
	t_anim	*tail;
	size_t	size;
};

int		anim_lst_add_back(t_anim_lst *const al, t_img const *const img)
		__attribute__((nonnull));

void	anim_lst_clear(t_anim_lst *const al, t_xptr const *const x)
		__attribute__((nonnull));
void	anim_lst_push_back(t_anim_lst *const al, t_anim *const a)
		__attribute__((nonnull));

#endif
