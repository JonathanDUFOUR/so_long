/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_free.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 01:34:00 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/15 03:11:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FREE_H
# define T_FREE_H

typedef struct s_free	t_free;

struct	s_free
{
	void	*addr;
	t_free	*next;
};

#endif
