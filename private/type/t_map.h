/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 16:22:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 22:55:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MAP_H
# define T_MAP_H

# include "type/t_count.h"
# include "type/t_int.h"

typedef struct s_map	t_map;

struct s_map
{
	char		*ptr;
	t_count		count;
	t_huint		width;
	t_huint		height;
	t_huint		idx_exit;
	t_huint		idx_player;
	t_hhuint	direction_player;
};

int		sl_map_check_borders(void);
int		sl_map_check_chars(void);
int		sl_map_check_width(char const *line);
int		sl_map_check(void);
int		sl_map_draw(void);
int		sl_map_load(char const *ber);
int		sl_map_read(int const fd);
int		sl_map_redraw(t_huint old_idx, t_huint new_idx);

void	sl_map_clear(void);
void	sl_map_print(void);
void	sl_map_update(char *const player, char *const togo, t_huint new_idx_p);

t_map	*sl_map(void);

#endif
