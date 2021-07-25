/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 19:14:18 by jdufour           #+#    #+#             */
/*   Updated: 2021/07/22 20:14:46 by jodufour         ###   ########.fr       */
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

ssize_t	ft_putstr_fd(char const *s, int fd)
{
	if (!s)
		return (-1);
	return (write(fd, s, ft_strlen(s)));
}
