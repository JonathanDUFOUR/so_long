/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:15:56 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/11 02:50:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdint.h>
# include <string.h>

enum	e_ret
{
	SUCCESS = 0,
	AC_ERRNO,
	OPEN_ERRNO,
	GNL_ERRNO,
	INVALID_MAP_ERRNO
};

typedef struct s_map	t_map;

struct	s_map
{
	uint32_t	w;
	uint32_t	h;
	char		*elems;
};

int		sl_errno_msg(int const errno);
int		sl_run_game(char const *file);
int		sl_get_map(char const *file, t_map *map);
char	*sl_strjoin(char const *s1, char const *s2);
size_t	sl_strlen(char const *s);

#endif
