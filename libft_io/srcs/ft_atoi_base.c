/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 06:21:19 by jdufour           #+#    #+#             */
/*   Updated: 2021/07/22 20:01:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

static size_t	ft_strlen(char const *s)
{
	register char const	*p = s;

	while (*p)
		++p;
	return (p - s);
}

int	ft_atoi_base(char const *s, char const *base)
{
	int	res;
	int	sign;
	int	b_len;

	if (!s)
		return (0);
	if (ft_wrong_base(base))
		return (0);
	res = 0;
	sign = 1;
	b_len = ft_strlen(base);
	while (ft_isspace(*s))
		++s;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign ^= ~1u;
	while (*s && ft_indexof(*s, base) != -1)
		res = res * b_len + ft_indexof(*s++, base);
	return (sign * res);
}
