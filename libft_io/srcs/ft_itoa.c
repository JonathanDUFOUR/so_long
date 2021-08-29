/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 06:23:21 by jdufour           #+#    #+#             */
/*   Updated: 2021/07/22 20:09:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_io.h"

char	*ft_itoa(int n)
{
	char	*output;
	t_uint	len;

	len = ft_intlen(n);
	output = malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	output += len;
	*output-- = 0;
	if (!n)
		*output-- = '0';
	else
	{
		while (n && len--)
		{
			*output-- = (-(n < 0) | 1) * (n % 10) + '0';
			n /= 10;
		}
		if (len)
			*output-- = '-';
	}
	return (++output);
}
