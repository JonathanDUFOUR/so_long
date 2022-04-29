/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_count.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:36:40 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:40:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_COUNT_H
# define T_COUNT_H

# include "t_int.h"

typedef struct s_count	t_count;

struct s_count
{
	t_huint	collect;
	t_huint	exit;
	t_huint	player;
};

#endif
