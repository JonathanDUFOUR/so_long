/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:15:56 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/15 02:42:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdint.h>
# include <string.h>

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
	INVALID_MAP_ERRNO
};

int		sl_errno_msg(int const errno);
int		sl_lstadd_back(void *addr);
int		sl_multifree(int ret);
int		sl_run_game(char const *file);

char	*sl_strjoin(char const *s1, char const *s2);

size_t	sl_strlen(char const *s);

#endif
