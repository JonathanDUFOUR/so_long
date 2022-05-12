/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hhintlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:12:24 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:05:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_int.h"

/*
	Return the length of the given t_hhint `nb`
*/
t_uint	ft_hhintlen(t_hhint nb)
{
	t_uint	len;

	len = 1 + (nb < 0);
	while (nb / 10)
	{
		++len;
		nb /= 10;
	}
	return (len);
}
