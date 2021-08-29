/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlluint_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 01:47:48 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/18 02:37:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "type/t_int.h"

void	putlluint_hexa(t_lluint n, char c)
{
	int		mod;
	char	d;

	if (n > 15)
		putlluint_hexa(n / 16, c);
	mod = n % 16;
	if (mod > 9)
		d = mod - 10 + c;
	else
		d = mod + '0';
	write(1, &d, 1);
}
