/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlluint_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 01:52:02 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/22 23:50:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "typedefs/t_int.h"

void	putlluint_oct(t_lluint n)
{
	char	d;

	if (n > 7)
		putlluint_oct(n / 8);
	d = n % 8 + '0';
	write(1, &d, 1);
}
