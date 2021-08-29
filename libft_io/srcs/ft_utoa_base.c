/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 01:19:22 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/22 20:17:43 by jodufour         ###   ########.fr       */
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

static size_t	get_o_len(t_uint abs, t_uint b_len)
{
	if (abs < b_len)
		return (1);
	return (get_o_len(abs / b_len, b_len) + 1);
}

char	*ft_utoa_base(t_uint n, char const *base)
{
	char	*output;
	char	*p;
	t_uint	b_len;
	t_uint	o_len;

	if (!base || ft_wrong_base(base))
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
