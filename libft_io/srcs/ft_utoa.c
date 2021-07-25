/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 05:31:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/21 03:13:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_io.h"

char	*ft_utoa(t_uint n)
{
	char	*output;
	size_t	len;

	len = ft_uintlen(n);
	output = malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	output[len] = 0;
	while (len && n)
	{
		output[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (output);
}
