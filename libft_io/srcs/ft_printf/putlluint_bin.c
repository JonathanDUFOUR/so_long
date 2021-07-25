/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlluint_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 01:54:06 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/22 23:42:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "typedefs/t_int.h"

void	putlluint_bin(t_lluint n)
{
	char	d;

	if (n > 1)
		putlluint_bin(n / 2);
	d = n % 2 + '0';
	write(1, &d, 1);
}
