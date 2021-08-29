/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:02:19 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/22 20:11:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_io.h"

static size_t	ft_strlen(char const *s)
{
	register char const	*p = s;

	while (*p)
		++p;
	return (p - s);
}

static size_t	get_o_len(t_luint n, size_t b_len)
{
	if (n < b_len)
		return (1);
	return (get_o_len(n / b_len, b_len) + 1);
}

char	*ft_lutoa_base(t_luint n, char const *base)
{
	char	*output;
	char	*p;
	size_t	b_len;
	size_t	o_len;

	if (ft_wrong_base(base))
		return (NULL);
	b_len = ft_strlen(base);
	o_len = get_o_len(n, b_len);
	output = malloc((o_len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	p = output + o_len;
	*p = 0;
	while (o_len--)
	{
		--p;
		*p = base[n % b_len];
		n /= b_len;
	}
	return (output);
}
