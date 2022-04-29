/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 16:22:21 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:40:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MAP_H
# define T_MAP_H

# include "t_int.h"
# include "t_img.h"
# include "t_xptr.h"

typedef struct s_map	t_map;

struct s_map
{
	char		*ptr;
	t_huint		width;
	t_huint		height;
	t_img		maxi;
	t_img		mini;
	t_huint		collect_cnt;
};

void	map_clear(t_map *const m, t_xptr const *const x)
		__attribute__((nonnull));

int		map_load(t_map *const m, char const *filename, int *const ret)
		__attribute__((nonnull));

#endif
