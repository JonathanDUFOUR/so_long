/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llintlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 00:30:54 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:08:08 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_int.h"

/*
	Return the length of the given t_llint `nb`
*/
t_uint	ft_llintlen(t_llint nb)
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
