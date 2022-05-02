/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_all.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:20:21 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/02 23:44:58 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ALL_H
# define T_ALL_H

# include "t_game.h"

typedef struct s_all	t_all;

struct s_all
{
	t_config	c;
	t_game		g;
	t_xptr		x;
	int			ret;
};

#endif
