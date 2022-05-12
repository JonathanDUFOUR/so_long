/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 08:31:49 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/02 14:18:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "ft_io.h"

inline static char	*__nanftoa(void)
{
	char *const	output = malloc(4 * sizeof(char));

	if (!output)
		return (NULL);
	output[0] = 'n';
	output[1] = 'a';
	output[2] = 'n';
	output[3] = 0;
	return (output);
}

inline static char	*__infftoa(bool const is_neg)
{
	char *const	output = malloc((4 + is_neg) * sizeof(char));
	char		*ptr;	

	if (!output)
		return (NULL);
	ptr = output;
	if (is_neg)
		*ptr++ = '-';
	ptr[0] = 'i';
	ptr[1] = 'n';
	ptr[2] = 'f';
	ptr[3] = 0;
	return (output);
}

inline static void	__fractional(
	char **const output,
	t_lluint fpart,
	t_uint prec)
{
	while (prec--)
	{
		*(*output)-- = (fpart % 10) + '0';
		fpart /= 10;
	}
	*(*output)-- = '.';
}

inline static void	__integer(
	char **const output,
	t_lluint upart,
	t_uint upart_len,
	bool const is_neg)
{
	while (upart_len--)
	{
		*(*output)-- = (upart % 10) + '0';
		upart /= 10;
	}
	if (is_neg)
		*(*output)-- = '-';
}

char	*ft_ftoa(float const nb, t_uint const prec)
{
	t_lluint	upart;
	t_lluint	fpart;
	t_uint		upart_len;
	char		*output;

	if (isnan(nb))
		return (__nanftoa());
	if (isinf(nb))
		return (__infftoa(nb < 0));
	upart = (t_lluint)fabs(nb);
	fpart = (t_lluint)((fabs(nb) - upart) * pow(10, prec));
	upart_len = ft_lluintlen(upart);
	output = malloc(((nb < 0) + upart_len + !!prec + prec + 1) * sizeof(char));
	if (!output)
		return (NULL);
	output += (nb < 0) + upart_len + !!prec + prec;
	*output-- = 0;
	if (prec)
		__fractional(&output, fpart, prec);
	__integer(&output, upart, upart_len, nb < 0);
	return (++output);
}
