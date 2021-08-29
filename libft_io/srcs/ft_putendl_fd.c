/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 02:04:40 by jdufour           #+#    #+#             */
/*   Updated: 2021/07/30 22:25:46 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

static size_t	ft_strlen(char const *s)
{
	register char const	*p = s;

	while (*p)
		++p;
	return (p - s);
}

ssize_t	ft_putendl_fd(char const *s, int fd)
{
	if (!s || write(fd, "", 0) == -1)
		return (-1);
	return (write(fd, s, ft_strlen(s)) + write(fd, "\n", 1));
}
