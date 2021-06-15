/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 01:20:51 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/15 01:36:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MAP_H
# define T_MAP_H

# include <stdint.h>

typedef struct s_map	t_map;

struct	s_map
{
	uint32_t	w;
	uint32_t	h;
	char		*elems;
};

int		sl_check_map(t_map map);
int		sl_get_map(char const *file, t_map *map);

void	sl_print_map(t_map map);

#endif
