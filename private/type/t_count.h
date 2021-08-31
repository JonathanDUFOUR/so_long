/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_count.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:36:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 20:23:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_COUNT_H
# define T_COUNT_H

# include "type/t_int.h"

typedef struct s_count	t_count;

struct s_count
{
	t_huint	collect;
	t_huint	exit;
	t_huint	player;
};

#endif
