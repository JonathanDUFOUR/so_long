/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrong_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 06:28:43 by jdufour           #+#    #+#             */
/*   Updated: 2021/07/22 20:26:40 by jodufour         ###   ########.fr       */
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

bool	ft_wrong_base(char const *base)
{
	char const	*p;

	if (!base || ft_strlen(base) < 2)
		return (true);
	while (*base)
	{
		if (*base == '-' || *base == '+' || ft_isspace(*base))
			return (true);
		p = base;
		while (*++p)
			if (*base == *p)
				return (true);
	}
	return (false);
}
