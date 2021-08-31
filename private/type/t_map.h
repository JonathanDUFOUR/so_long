/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 16:22:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 04:56:14 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MAP_H
# define T_MAP_H

# include "type/t_int.h"

typedef struct s_map	t_map;

struct s_map
{
	char	*e;
	t_uint	w;
	t_uint	h;
	t_uint	cnt_c;
	t_uint	cnt_e;
	t_uint	cnt_p;
	t_uint	idx_e;
	t_uint	idx_p;
};

int		sl_map_check_borders(void);
int		sl_map_check_chars(void);
int		sl_map_check_width(char const *line);
int		sl_map_check(void);
int		sl_map_draw(void);
int		sl_map_load(char const *ber);
int		sl_map_read(int const fd);
int		sl_map_redraw(t_uint old_idx, t_uint new_idx);

void	sl_map_clear(void);
void	sl_map_print(void);
void	sl_map_update(char *const player, char *const togo, t_uint new_idx_p);

t_map	*sl_map(void);

#endif
