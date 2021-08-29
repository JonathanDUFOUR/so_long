/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_xptr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 04:15:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/28 05:52:01 by jodufour         ###   ########.fr       */
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

int		sl_xptr_init(void);

void	sl_xptr_clear(void);

t_xptr	*sl_xptr(void);

#endif
