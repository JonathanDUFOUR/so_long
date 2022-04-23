/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_xptr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 04:15:42 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/12 04:53:06 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_XPTR_H
# define T_XPTR_H

typedef struct s_xptr	t_xptr;

struct	s_xptr
{
	void	*mlx;
	void	*win;
};

int		xptr_init(t_xptr *const x, int *const ret)
		__attribute__((nonnull));

void	xptr_clear(t_xptr *const x)
		__attribute__((nonnull));

#endif
