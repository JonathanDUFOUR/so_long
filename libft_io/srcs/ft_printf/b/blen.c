/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blen.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:10:24 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/22 23:51:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs/t_int.h"

t_uint	blen(t_lluint n)
{
	t_uint	len;

	len = 1;
	while (n > 1)
	{
		++len;
		n /= 2;
	}
	return (len);
}