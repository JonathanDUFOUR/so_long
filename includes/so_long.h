/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:15:56 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/09 15:05:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

enum	e_ret
{
	SUCCESS = 0,
	AC_ERRNO
};

enum	e_dim
{
	H,
	W
};

int	errno_msg(int errno);
int	run_game(char *file);

#endif
