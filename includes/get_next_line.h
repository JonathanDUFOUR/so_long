/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 23:52:53 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/13 02:24:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdbool.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_elem	t_elem;

struct s_elem
{
	int		fd;
	char	*rest;
	t_elem	*next;
};

int		get_next_line(int fd, char **line);
bool	gnl_fd_del(int fd);
void	gnl_clear(void);

#endif
