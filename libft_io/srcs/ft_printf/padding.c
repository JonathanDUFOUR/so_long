/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:10:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/18 02:37:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "type/t_int.h"
#include "enum/e_ret.h"

int	padding(int c, t_uint padlen)
{
	char	*padding;
	char	*p;

	padding = malloc((padlen + 1) * sizeof(char));
	if (!padding)
		return (MALLOC_ERRNO);
	p = padding;
	while (padlen--)
		*p++ = c;
	*p = 0;
	write(1, padding, p - padding);
	free(padding);
	return (SUCCESS);
}
