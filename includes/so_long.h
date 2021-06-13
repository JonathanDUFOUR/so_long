/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:15:56 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/13 04:14:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdint.h>
# include <string.h>
# include "t_lst.h"

enum	e_ret
{
	SUCCESS,
	AC_ERRNO,
	GNL_ERRNO,
	OPEN_ERRNO,
	MALLOC_ERRNO,
	INVALID_MAP_ERRNO
};

typedef struct s_free	t_free;
typedef struct s_map	t_map;

struct	s_free
{
	void	*addr;
	t_free	*next;
};

struct	s_map
{
	uint32_t	w;
	uint32_t	h;
	char		*elems;
};

int		sl_errno_msg(int const errno);
int		sl_get_map(char const *file, t_map *map);
int		sl_lstadd_back(void *addr);
int		sl_multifree(int ret);
int		sl_run_game(char const *file);

size_t	sl_strlen(char const *s);

char	*sl_strjoin(char const *s1, char const *s2);

t_lst	*sl_get_lst(void);

#endif
