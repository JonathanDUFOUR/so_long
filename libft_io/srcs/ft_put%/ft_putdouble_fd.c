/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:24:15 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/02 17:09:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_io.h"

int	ft_putdouble_fd(double const nb, t_uint const prec, int const fd)
{
	t_lluint	upart;
	t_lluint	fpart;

	if (write(fd, "", 0) == -1)
		return (-1);
	if (isnan(nb))
		return ((int)write(fd, "nan", 3));
	if (isinf(nb))
		return ((int)write(fd, "-", nb < 0) + (int)write(fd, "inf", 3));
	upart = (t_lluint)fabs(nb);
	if (!prec)
		return ((int)write(fd, "-", nb < 0) + ft_putlluint_fd(upart, fd));
	fpart = (t_lluint)((fabs(nb) - upart) * pow(10, prec));
	return ((int)write(fd, "-", nb < 0) + ft_dprintf(fd, "%llu.%.*llu",
			upart, prec, fpart));
}
