/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 16:22:21 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/08 06:12:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MAP_H
# define T_MAP_H

# include "t_int.h"
# include "t_img.h"
# include "t_config.h"
# include "t_xptr.h"

typedef struct s_map	t_map;

struct s_map
{
	char		*ptr;
	t_huint		width;
	t_huint		height;
	t_huint		collect_cnt;
	t_img		maxi;
};

int		map_load(t_map *const m, char const *filename, int *const ret)
		__attribute__((nonnull));
int		map_maxi_init(t_map *const m, t_xptr const *const x,
			t_config const *const c, int *const ret)
		__attribute__((nonnull));

void	map_clear(t_map *const m, t_xptr const *const x)
		__attribute__((nonnull));

#endif
