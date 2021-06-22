/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:15:56 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/22 08:52:50 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdint.h>
# include <string.h>
# include "t_map.h"

# define MAP_CHAR	"10PCE"

enum	e_map_chars
{
	WALL,
	EMPTY,
	PLAYER,
	COLLECT,
	EXIT
};

enum	e_ret
{
	SUCCESS,
	AC_ERRNO,
	GNL_ERRNO,
	OPEN_ERRNO,
	MALLOC_ERRNO,
	INVALID_MAP_ERRNO,
	MLX_ERRNO
};

int		sl_errno_msg(int const errno);
int		sl_init_game(char const *file);
int		sl_lstadd_back(void *addr);
int		sl_multifree(int ret);
int		sl_run_game(t_map map);

void	sl_free(void *addr);

char	*sl_strjoin(char const *s1, char const *s2);

size_t	sl_strlen(char const *s);

#endif
